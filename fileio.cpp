#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "fileio.h"

// Returns false if file couldn't be opened
bool
LoadFileToString(std::string filepath, std::string& str)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filepath << '\n';
        perror("Error");
        return false;
    }
    
    file.seekg(0, std::ios::end);
    str.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());

    file.close();
    return true;
}