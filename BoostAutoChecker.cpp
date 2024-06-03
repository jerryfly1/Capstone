#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include "MerkleTreeHash.h"
using namespace boost::filesystem;

void monitorDirectoryChange(const std::string& directoryPath) {
    path dir(directoryPath);

    if (!exists(dir) || !is_directory(dir)) {
        std::cerr << "Error: Directory " << directoryPath << " does not Exist." << std::endl;
        return;
    }

    std::cout << "Monitoring directory: " << directoryPath << std::endl;
    std::cout << "Start monitoring " << std::endl;
    

    // 현재 디렉토리 파일 정보 초기화
    std::map<std::string, std::time_t> currentFiles;
    for (directory_iterator it(dir); it != directory_iterator(); it++) {
        if (is_regular_file(*it)) {
            currentFiles[it->path().filename().string()] = last_write_time(*it);
        }
    }
    printAllFileHashesAndMerkleTreeHash(directoryPath, currentFiles);
    
    
    // 다렉토리 실시간 감시
    while (true) {
        for (directory_iterator it(dir); it != directory_iterator(); it++) {
            if (is_regular_file(*it)) {
                std::string filename = it->path().filename().string();
                std::time_t lastWriteTime = last_write_time(*it);

                if (currentFiles.find(filename) == currentFiles.end()) {
                    // 새로운 파일 생성될 때
                    std::cout << "New file is created: " << it->path() << std::endl;
                    std::cout << "Created File Hash: " << calculateFileHash(it->path().string()) << std::endl;
                    currentFiles[filename] = lastWriteTime;
                    std::vector <std::string> currentFilesVector;
                    for (auto it = currentFiles.begin(); it != currentFiles.end(); it++) {
                        std::string fileHash = calculateFileHash(directoryPath + "/" + it->first);
                        currentFilesVector.push_back(fileHash);
                }   
                    MerkleNode* rootnode = constructMerkleTree(currentFilesVector);
                    std::cout << "Updated MerkleTree RootNode Hash: " << rootnode->hash << std::endl;
                } 
                else if (currentFiles[filename] != lastWriteTime) {
                    // 기존 파일 수정되었을 때
                    std::cout << "File modified: " << it->path() << std::endl;
                    std::cout << "Modified File Hash: " << calculateFileHash(it->path().string()) << std::endl;
                    currentFiles[filename] = lastWriteTime;
                    std::vector <std::string> currentFilesVector;
                    for (auto it = currentFiles.begin(); it != currentFiles.end(); it++) {
                        std::string fileHash = calculateFileHash(directoryPath + "/" + it->first);
                        currentFilesVector.push_back(fileHash);
                    }
                    MerkleNode* rootnode = constructMerkleTree(currentFilesVector);
                    std::cout << "Updated MerkleTree RootNode Hash: " << rootnode->hash << std::endl;
                }
                //현재 파일 정보 업데이트
                //currentFiles[filename] = lastWriteTime;
                
            }
        }
        // 파일 삭제 감지
        for (auto it = currentFiles.begin(); it != currentFiles.end();) {
            if (!exists(dir / it->first)) {
                // 파일 삭제되었을 때
                std::cout << "File deleted: " << dir / it->first << std::endl;
                //std::cout << "Deleted File Hash: " << calculateFileHash(it->first) << std::endl;
                it = currentFiles.erase(it);
                std::vector <std::string> currentFilesVector;
                for (auto it = currentFiles.begin(); it != currentFiles.end(); it++) {
                    std::string fileHash = calculateFileHash(directoryPath + "/" + it->first);
                    currentFilesVector.push_back(fileHash);
                }
                MerkleNode* rootnode = constructMerkleTree(currentFilesVector);
                std::cout << "Updated MerkleTree RootNode Hash: " << rootnode->hash << std::endl;
            } 
            else {
                it++;
            }
        }
        boost::this_thread::sleep_for(boost::chrono::seconds(1));
    }
}

int main() {
    std::string filePath;
    std::cout << "모니터링할 디렉토리 경로를 입력하세요: ";
    std::getline(std::cin, filePath);
    monitorDirectoryChange(filePath);
}