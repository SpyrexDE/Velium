#pragma once

#include <string>

class ResHandler
{
public:
    static const char* GetFilePath(std::string path);

    static std::string get_working_path();
};
