#include "chronotest.h"
#include <unistd.h>
YaoTime::YaoTime(){
    stamp = std::chrono::system_clock::now();
}

void YaoTime::recordTime(){
    stamp = std::chrono::system_clock::now();

}

int YaoTime::microSecondsPassed() const{
    //    std::chrono::time_point<std::chrono::system_clock> now_point = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    std::chrono::microseconds t = std::chrono::duration_cast<std::chrono::microseconds> (now_point - stamp);
    return t.count ();
}

int YaoTime::milliSecondsPassed() const{
    std::chrono::time_point<std::chrono::system_clock> now_point = std::chrono::system_clock::now();
    //    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    std::chrono::milliseconds t = std::chrono::duration_cast<std::chrono::milliseconds> (now_point - stamp);
    return t.count ();
}

int YaoTime::secondsPassed() const{
    std::chrono::time_point<std::chrono::system_clock> now_point = std::chrono::system_clock::now();
    std::chrono::seconds t = std::chrono::duration_cast<std::chrono::seconds> (now_point - stamp);
    return t.count ();
}

int YaoTime::minutesPassed () const{
    std::chrono::time_point<std::chrono::system_clock> now_point = std::chrono::system_clock::now();
    std::chrono::minutes t = std::chrono::duration_cast<std::chrono::minutes> (now_point - stamp);
    return t.count ();
}

int YaoTime::hoursPassed () const{
    //    std::chrono::time_point<std::chrono::system_clock> now_point = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    std::chrono::hours t = std::chrono::duration_cast<std::chrono::hours> (now_point - stamp);
    return t.count ();
}

int YaoTime::daysPassed () const{
    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    days t = std::chrono::duration_cast<days> (now_point - stamp);
    return t.count ();
}

std::chrono::microseconds YaoTime::microSecondsFromStamp() const{
    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds> (now_point - stamp);
}

std::chrono::milliseconds YaoTime::milliSecondsFromStamp () const{
    return std::chrono::duration_cast<std::chrono::milliseconds>(microSecondsFromStamp ());
}


std::chrono::seconds YaoTime::secondsFromStamp() const{
    return std::chrono::duration_cast<std::chrono::seconds>(milliSecondsFromStamp ());
}

std::chrono::hours YaoTime::hoursFromStamp () const{
    return std::chrono::duration_cast<std::chrono::hours>(secondsFromStamp ());
}

YaoTime::days YaoTime::daysFromStamp() const{
    return std::chrono::duration_cast<days>(secondsFromStamp ());
}

void YaoTime::someTest(int i) const{
    days d(i);
    std::cout << i << " day(s) equal to " << std::chrono::duration_cast<std::chrono::hours>(d).count() << " hours" << std::endl;
    std::cout << i << " day(s) equal to " << std::chrono::duration_cast<std::chrono::minutes>(d).count() << " mins" << std::endl;
    std::cout << i << " day(s) equal to " << std::chrono::duration_cast<std::chrono::seconds>(d).count() << " secs" << std::endl;
    std::cout << i << " day(s) equal to " << std::chrono::duration_cast<std::chrono::milliseconds>(d).count() << " millisecs" << std::endl;
    std::cout << i << " day(s) equal to " << std::chrono::duration_cast<std::chrono::microseconds>(d).count() << " microsecs" << std::endl;

    using namespace std::chrono_literals;
    auto theHour = 1h; //c++14 or later  1h 2min 3s 4ms....
    auto t1  = std::chrono::duration_cast<std::chrono::minutes> (theHour);
    std::cout << "1 hour:"  << t1.count () << "mins" << std::endl;

    auto t2  = std::chrono::duration_cast<std::chrono::seconds> (theHour);
    std::cout << "1 hour:"  << t2.count () << "secs" << std::endl;

    auto t3  = std::chrono::duration_cast<std::chrono::seconds> (t1);
    std::cout << "1 hour:"  << t3.count () << "secs" << std::endl;

    auto t4  = std::chrono::duration_cast<std::chrono::milliseconds> (theHour);
    std::cout << "1 hour:"  << t4.count () << "millsecs" << std::endl;

    auto t5  = std::chrono::duration_cast<std::chrono::milliseconds> (t3);
    std::cout << "1 hour:"  << t5.count () << "millsecs" << std::endl;
}

void YaoTime::printCurrentTime () const{
    std::chrono::system_clock::time_point now_point = std::chrono::system_clock::now();
    std::time_t thisTime = std::chrono::system_clock::to_time_t(now_point);
    std::cout << "ctime:" << std::ctime(&thisTime);
}

std::string YaoTime::getCurrentTimeStr() const{
    auto now_point = std::chrono::system_clock::now();
    auto thisTime = std::chrono::system_clock::to_time_t(now_point);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&thisTime), "%y-%m-%d %X");
    return ss.str();
}



YaoTime::days YaoTime::daysFromEpoch() const{
    auto now_point = std::chrono::system_clock::now();
    return std::chrono::duration_cast<days>(now_point.time_since_epoch ());
}

int YaoTime::daysPassedFromEpoch() const{
    return daysFromEpoch().count ();
}

void testChrono(){
    YaoTime t;
    std::cout << t.daysPassedFromEpoch () << std::endl;
    std::cout << t.daysFromEpoch ().count ()<< std::endl;
    t.someTest (1);
    std::cout << t.microSecondsFromStamp().count () << std::endl;
    std::cout << t.milliSecondsFromStamp().count () << std::endl;
    std::cout << t.secondsFromStamp().count () << std::endl;
    std::cout << t.hoursFromStamp ().count () << std::endl;
    std::cout << t.daysFromStamp ().count () << std::endl;
    t.printCurrentTime ();
    std::cout << t.getCurrentTimeStr () << std::endl;

    sleep(1);
    std::cout << t.microSecondsPassed () << std::endl;
    std::cout << t.milliSecondsPassed () << std::endl;
    std::cout << t.secondsPassed () << std::endl;
    std::cout << t.daysPassed () << std::endl;


}
