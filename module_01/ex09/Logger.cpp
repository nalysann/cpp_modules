#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Logger.hpp"

Logger::Logger(const std::string& filename)
    : _filename(filename) {}

void Logger::log(const std::string& dest,
                 const std::string& message) const {
    static const std::string destinations[_NUM_FUNCTIONS] = {
            "console",
            "file",
    };

    static const Logger::log_function functions[_NUM_FUNCTIONS] = {
        &Logger::_logToConsole,
        &Logger::_logToFile,
    };

    for (size_t i = 0; i < _NUM_FUNCTIONS; ++i) {
        if (dest == destinations[i]) {
            (this->*functions[i])(message);
            return;
        }
    }

    std::cout << "Unknown destination" << std::endl;
}

std::string Logger::_get_timestamp() {
    std::ostringstream os;
    time_t now = time(0);
    tm local = *localtime(&now);
    char buf[42];
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &local);
    os << '[' << buf << ']';
    return os.str();
}

std::string Logger::_makeLogEntry(const std::string& message) {
    return _get_timestamp() + ' ' + message;
}

void Logger::_logToConsole(const std::string& message) const {
    std::cout << _makeLogEntry(message) << std::endl;
}

void Logger::_logToFile(const std::string& message) const {
    std::ofstream ofs(_filename, std::ios::app);

    if (ofs.fail()) {
        std::cout << "Error: " << _filename
                  << ": File couldn't be opened" << std::endl;
        return;
    }

    ofs << _makeLogEntry(message) << std::endl;
}


