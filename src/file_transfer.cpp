
#include "file_transfer.h"

bool uploadFile(const std::string& localFilePath, const std::string& serverFilePath) {
    std::ifstream inputFile(localFilePath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open the local file." << std::endl;
        return false;
    }

    std::ofstream outputFile(serverFilePath, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Failed to create the server file." << std::endl;
        inputFile.close();
        return false;
    }

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();

    return true;
}

bool downloadFile(const std::string& serverFilePath, const std::string& localFilePath) {
    std::ifstream inputFile(serverFilePath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open the server file." << std::endl;
        return false;
    }

    std::ofstream outputFile(localFilePath, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Failed to create the local file." << std::endl;
        inputFile.close();
        return false;
    }

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();

    return true;
}