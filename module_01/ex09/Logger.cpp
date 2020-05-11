#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <ctime> 


Logger::Logger(): filename("log.txt"){}
Logger::Logger(std::string filename): filename(filename){}

std::string Logger::makeLogEntry(std::string raw)
{
    time_t tt; 
    struct tm * ti;
    std::string out;
    std::string year;
    std::string month;
    std::string day;
    std::string hour;
    std::string min;
    std::string sec;
   
    time (&tt); 
    ti = localtime(&tt);

    year = std::to_string(ti->tm_year + 1900);
    month = std::to_string(ti->tm_mon);
    day = std::to_string(ti->tm_wday);
    hour = std::to_string(ti->tm_hour);
    min = std::to_string(ti->tm_min);
    sec = std::to_string(ti->tm_sec);

    month = month.length() < 2 ? "0" + month : month;
    day = day.length() < 2 ? "0" + day : day;
    hour = hour.length() < 2 ? "0" + hour : hour;
    min = min.length() < 2 ? "0" + min : min;
    sec = sec.length() < 2 ? "0" + sec : sec;

    return ("[" + year + month + day + "-" + hour + min + sec + "] " + raw);
}

void Logger::logToConsole(std::string entry){
    std::string str;

    str = this->makeLogEntry(entry);
    std::cout << str << std::endl;
}

void Logger::logToFile(std::string entry){
    std::string str;

    str = this->makeLogEntry(entry);
    try {
    std::ofstream myFile(filename, std::ios::app);
    myFile << str << std::endl;
    }
    catch (...){
            std::cerr << "log to file error: file handling" << std::endl;
        }
}

void    Logger::log(std::string const & dest, std::string const & message)
{
    int i, j, len;
    void (Logger::* actions[3])(std::string trgt) = {
        NULL,
        &Logger::logToConsole,
        &Logger::logToFile
    };

    len = dest.length();
    i = !dest.find("console") * !(len - 7) * 1;
    i += !dest.find("file") * !(len - 4) * 2;
    while (i > 0 && i < 3)
    {
        (this->*actions[i])(message);
        return ;
    }
    std::cout << "invalid option (" << dest << ")" << std::endl;
}