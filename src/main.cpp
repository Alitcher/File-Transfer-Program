#include <iostream>
#include <fstream>
#include <string>
#include "file_transfer.h"
#include <Windows.h>
#include <algorithm> 

std::string GetCurrentDirectory()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    std::string directory = std::string(buffer).substr(0, pos);
    std::replace(directory.begin(), directory.end(), '\\', '/');

    return directory;
}

   const std::string currentDir = GetCurrentDirectory();

int main(int argc, char* argv[]) {

        if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <Please put your full path of files to upload after calling the program.>" << std::endl;
        return 1;
    }


    std::string localFilePath = argv[1];;
std::string serverFilePath = currentDir + "/dummyServer/" + localFilePath.substr(localFilePath.find_last_of("/\\") + 1);
std::string downloadedFilePath = currentDir + "/downloads/" + localFilePath.substr(localFilePath.find_last_of("/\\") + 1);

    std::cout << "localFilePath: " << localFilePath << std::endl;

    // Upload file to the server
    if (uploadFile(localFilePath, serverFilePath)) {
        std::cout << "File uploaded successfully." << std::endl;
    } else {
        std::cerr << "File upload failed." << std::endl;
        return 1;
    }

    // Download file from the server
    if (downloadFile(serverFilePath, downloadedFilePath)) {
        std::cout << "File downloaded successfully." << std::endl;
    } else {
        std::cerr << "File download failed." << std::endl;
        return 1;
    }

    return 0;
}
