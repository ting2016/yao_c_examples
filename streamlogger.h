#pragma once

#include <fstream>
#include <iostream>

class StreamLogger{
private:
    std::ofstream log;
public:
    StreamLogger(){
        log.open("/tmp/log.txt");
    }

    template <typename T>
    StreamLogger& operator<<(const T& x){
        std::cout << x;
        log << x;
        return *this;
    }

    // function that takes a custom stream, and returns it
    typedef StreamLogger& (*MyStreamManipulator)(StreamLogger&);

    // take in a function with the custom signature
    StreamLogger& operator<<(MyStreamManipulator manip){
        // call the function, and return it's value
        return manip(*this);
    }

    // define the custom endl for this stream.
    // note how it matches the `MyStreamManipulator`
    // function signature
    static StreamLogger& endl(StreamLogger& stream){
        // do other stuff with the stream
        // std::cout, for example, will flush the stream
        stream << "Called MyStream::endl!" << std::endl;
        return stream;
    }

    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    StreamLogger& operator<<(StandardEndLine manip){
        // call the function, but we cannot return it's value
        manip(std::cout);
        manip(log);
        return *this;
    }
    static void test();
};
