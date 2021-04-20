#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>

#include "Logger.hpp"

Logger::Logger(const std::string& filename)
        : _filename(filename) {}

void Logger::log(const std::string& dest,
                 const std::string& message) const {
    static const std::string destinations[NUM_FUNCTIONS] = {
            "console",
            "file",
    };

    static const Logger::logFunction functions[NUM_FUNCTIONS] = {
            &Logger::_logToConsole,
            &Logger::_logToFile,
    };

    for (size_t i = 0; i < NUM_FUNCTIONS; ++i) {
        if (dest == destinations[i]) {
            return (this->*functions[i])(message);
        }
    }

    std::cout << "Unknown destination" << std::endl;
}

std::string Logger::_getTimestamp() {
    std::ostringstream os;
    time_t now = time(0);
    tm local = *localtime(&now);
    char buf[42];
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &local);
    os << '[' << buf << ']';
    return os.str();
}

std::string Logger::_makeLogEntry(const std::string& message) {
    return _getTimestamp() + ' ' + message;
}

void Logger::_logToConsole(const std::string& message) const {
    std::cout << _makeLogEntry(message) << std::endl;
}

void Logger::_logToFile(const std::string& message) const {
    struct stat st;

    if (stat(_filename.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) {
        std::cerr << "error: " << _filename
                  << ": Is a directory" << std::endl;
        return;
    }

    std::ofstream ofs(_filename.c_str(), std::ios::app);

    if (!ofs) {
        std::cerr << "error: " << _filename
                  << ": Permission denied" << std::endl;
        return;
    }

    ofs << _makeLogEntry(message) << std::endl;
}
