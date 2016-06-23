#ifndef VERSION_H
#define VERSION_H

#include <sstream>
#include <string>
namespace yao{
    namespace version{
        class VersionGenerator;
        void test();
    }
}

class yao::version::VersionGenerator{
public:
    static const std::string version();
};

#endif // VERSION_H
