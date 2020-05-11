#ifndef LOGGER_HPP
# define LOGGER_HPP
# include <iostream>

class Logger
{
    private:
        std::string filename;
        void logToConsole(std::string entry);
        void logToFile(std::string entry);
        std::string makeLogEntry(std::string raw);
    public:
        void log(std::string const & dest, std::string const & message);
        Logger();
        Logger(std::string filename);
};

#endif