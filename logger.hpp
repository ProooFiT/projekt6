#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

class Logger {
public:

    Logger(const std::string& filename);

    ~Logger();

    void log(const std::string& message);

private:
    std::ofstream logFile;
};

extern Logger logger;

extern Logger loggerError;

extern int loggerErrorCount;

#endif 
