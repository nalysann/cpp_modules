#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
  public:
    explicit Logger(const std::string& filename);

    void log(const std::string& dest,
             const std::string& message) const;

  private:
    typedef void (Logger::*_logFunction)(const std::string& message) const;

    static std::string _getTimestamp();
    static std::string _makeLogEntry(const std::string& message);

    static const size_t NUM_FUNCTIONS = 2;

    void _logToConsole(const std::string& message) const;
    void _logToFile(const std::string& message) const;

    const std::string _filename;
};

#endif
