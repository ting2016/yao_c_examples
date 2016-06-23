#ifndef FILEIO_H
#define FILEIO_H
#include <string>
namespace yao{
    namespace file_io{
        void test();
        void read_textfile();
        void write_textfile();
    }
}

//TODO #include <boost/filesystem.hpp>  boost::filesystem::create_directories("/tmp/a/b/c");
//TODO #include <experimental/filesystem> bool create_directory( const path& p );
//TODO #include <direct.h> mkdir("c:/myfolder")
//TODO #include <sys/stat.h> mkdir("mydir", S_IRUSR | S_IWUSR | S_IXUSR);

//TODO binary file rw
//TODO random access tellg goback goforward...

//TODO C file io

#endif // FILEIO_H
