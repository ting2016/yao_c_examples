#include "streamlogger.h"

void StreamLogger::test(){
    StreamLogger logger;
    logger << "hello\t" << "world" << std::endl;
    logger << "num:\t" << 10 << std::endl;
    logger << StreamLogger::endl;
}
