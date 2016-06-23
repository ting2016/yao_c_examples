#include "streamlogger.h"

void yao::stream_logger::test(){
    StreamLogger logger;
    logger << "hello\t" << "world" << std::endl;
    logger << "num:\t" << 10 << std::endl;
    logger << StreamLogger::endl;
}
