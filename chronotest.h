#ifndef CHRONOTEST_H
#define CHRONOTEST_H
#include <iostream>
#include <ratio>
#include <ctime>
#include <sstream>

#include <chrono>  // chrono::system_clock
#include <iomanip> // put_time

namespace yao{
    namespace chrono{
        class YaoTime;
        void test();
    }
}
class yao::chrono::YaoTime{
public:
    typedef std::chrono::duration<int64_t, std::ratio<3600*24, 1>>   days;
    YaoTime();
    void recordTime();
    int microSecondsPassed() const;
    int milliSecondsPassed() const;
    int secondsPassed() const;
    int minutesPassed() const;
    int hoursPassed() const;
    int daysPassed() const;

    std::chrono::microseconds microSecondsFromStamp() const;
    std::chrono::milliseconds milliSecondsFromStamp() const;
    std::chrono::seconds secondsFromStamp() const;
    std::chrono::hours hoursFromStamp() const;
    days daysFromStamp() const;

    void someTest(int i) const;

    void printCurrentTime() const;

    std::string getCurrentTimeStr() const;

    days daysFromEpoch() const;
    int daysPassedFromEpoch() const;

private:
    std::chrono::system_clock::time_point stamp;

};


#endif // CHRONOTEST_H
