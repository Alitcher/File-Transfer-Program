#ifndef FILE_TRANSFER_H
#define FILE_TRANSFER_H

#include <fstream>
#include <string>
#include <iostream>

bool uploadFile(const std::string& localFilePath, const std::string& serverFilePath);
bool downloadFile(const std::string& serverFilePath, const std::string& localFilePath);

#endif
