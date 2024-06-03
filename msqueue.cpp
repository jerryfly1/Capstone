#include <string>
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <fstream>
std::string usingQueue = "AB";
std::string usingQueue2 = "BA";
AmqpClient::Channel::ptr_t channel;
/* 
 원하는 파일을 원하는 큐를 통해 보내는 함수

 파라미터

 filePath: queue로 전송하려는 파일의 경로
 queue: 사용할 queue의 이름 
 */
void sendFile(const std::string& filePath, const std::string& queue) {
    

    /* 파일 열기 */
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error to open file for read: "<< filePath << std::endl;
        exit(1);
    }
    /* Content객체에 파일내용 담기 */
    std::string content(std::istreambuf_iterator<char>{file}, {});
    file.close();

    /* 원하는 큐에 내용물을 보내는 과정 */
    channel->BasicPublish("", queue, AmqpClient::BasicMessage::Create(content));
}

void receiveFile(const std::string& filePath, const std::string& queue) {
    AmqpClient::Envelope::ptr_t envelope;
    bool no_ack = false; //true일시 메세지를 소비하고 나머지메세지 소비자가 확인하게하지않고 큐에서삭제
    /*
     Queue안의 내용 소모
     no_local: true로 설정시 내용 소모도중 메세지 생성시 이를 무시 (기본 false)
     no_ack: true설정시 메세지 수신후 확인절차를 밟지 않고 메세지를 큐에서 삭제.
     envelope에 반환값 저장
    */
    /* Channel.h 771Line */
    /* 771 */
    std::cout << "a" << std::endl;
    boost::uint16_t message_prefetch_count = 2;
    std::string consumer = channel->BasicConsume(queue, "", no_ack, message_prefetch_count);
    /* 886Line 사용*/
    std::cout << "b" << std::endl;
    bool isConsume = channel->BasicConsumeMessage(consumer, envelope);

    if (!isConsume) {
        std::cerr << "Error to consume the content: " << queue << std::endl;
        exit(1);
    }
    /* Envelope객체로부터 내용을 가져와 content에 저장, Message()메서드와, Body메서드 사용*/
    std::string content = envelope->Message()->Body();

    /* 쓰기 파일 오류시 오류를 출력 */
    std::ofstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error to open file for write" << filePath << std::endl;
        exit(1);
    }
    /* content객체의 데이터를 파일에 쓰고 닫기. */
    file.write(content.data(), content.size());
    file.close();
}
int main () {
    /* RabbitMQ 서버 연결 모듈화시 전역변수로 뺄것 */
    std::cout << "1" << std::endl;
    AmqpClient::Channel::OpenOpts opts;
    std::cout << "1.1" << std::endl;
    //opts.basicAuth = A
    opts.auth = AmqpClient::Channel::OpenOpts::BasicAuth("try1", "1234");
    opts.host = "166.104.245.155";
    opts.vhost = "/1";
    /*opts.auth = AmqpClient::Channel::OpenOpts::BasicAuth("guest", "guest"); 
    opts.host = "127.0.0.1";
    opts.vhost = "/"; */
    opts.port = 5672;
    opts.frame_max = 131072;
    std::cout << "1.2" << std::endl;
    
    channel = AmqpClient::Channel::Open(opts);
    std::cout << "2" << std::endl;

    /* 
     Queue 선언
     Passive: 큐가 존재하지 않으면 에러리턴, False로되어있으며 에러리턴하지않고 Q를 자동으로 만듬.
     Durable: RabbitMq서버가 종료되도 큐가유지(큐안의 메세지는 삭제됨)
     Exclusive: 현재큐를 현재 연결에만 사용가능. 
     Auto_delete: 연결해제시 자동으로 큐삭제
     */
    bool passive = false, durable = true, exclusive = false, auto_delete = false;

    channel->DeclareQueue(usingQueue, passive, durable, exclusive, auto_delete);
    channel->DeclareQueue(usingQueue2, passive, durable, exclusive, auto_delete);
    std::cout << "3" << std::endl;
    std::string sendFilePath = "/home/user/Project/130.file";
    std::string sendFilePath2 = "/home/user/Project/test2.txt";
    sendFile(sendFilePath, usingQueue);
    sendFile(sendFilePath2, usingQueue);
    std::cout << "4" << std::endl;
    std::string receiveFilePath = "/home/user/Project/test/130.file";
    std::string receiveFilePath2 = "/home/user/Project/test/test2.txt";
    receiveFile(receiveFilePath, usingQueue);
    //receiveFile(receiveFilePath2, usingQueue);
    return 0;
}