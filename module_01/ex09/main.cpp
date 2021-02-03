#include "Logger.hpp"

int main() {
    Logger logger("test.log");

    logger.log("console", "nothing happened");
    logger.log("file", "something happened");
    logger.log("website", "wild pepega appeared");
    logger.log("file", "error occurred");
    logger.log("console", "useless message");
    logger.log("brain", "pay rent");
}
