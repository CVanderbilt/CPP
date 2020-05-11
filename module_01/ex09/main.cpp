#include "Logger.hpp"

int main(void)
{
    Logger log;

    log.log("console", "some message1");
    log.log("console", "some message2");
    log.log("console", "some message3");
    log.log("file", "some message1");
    log.log("file", "some message2");
    log.log("file", "some message3");
    log.log("console", "some message4");
    log.log("console", "some message5");

    log.log("invalid", "invalid :/");

}