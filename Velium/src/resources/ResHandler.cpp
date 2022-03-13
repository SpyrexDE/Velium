#include <sys/param.h>
#include "ResHandler.h"

const char* ResHandler::GetFilePath(std::string path)
{
    path = get_working_path().append("/res/" + path);
    return path.c_str();
}

std::string ResHandler::get_working_path()
{
    char temp[MAXPATHLEN];
    return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
}
