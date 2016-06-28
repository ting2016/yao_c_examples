#include "fileio.h"
#include <fstream>
#include <iostream>

void yao::file_io::test(){
    write_textfile ();
    read_textfile ();
}

void yao::file_io::read_textfile (){
    std::string fn = "/tmp/ah.txt";

    //1st way
    std::ifstream is1(fn, std::ios_base::in);
    //if(is1){
    if(is1.is_open ()){
        std::string line;
        std::getline(is1, line);
        std::cout << line << std::endl;
    }else{
        std::cerr << "Failed to open:" << fn << std::endl;
    }

    //2nd way
    std::ifstream is2;
    is2.open (fn, std::ios_base::in);
    if(is2.is_open ()){
        std::string line;
        std::getline(is2, line);
        std::cout << line << std::endl;
    }else{
        std::cerr << "Failed to open:" << fn << std::endl;
    }

}

void yao::file_io::write_textfile (){
    std::string fn = "/tmp/ah.txt";

    //1st way
    std::ofstream os1;
    os1.open (fn); //default mode: std::ios_base::out  create new file even it if exists
    if(os1.is_open ()){
        os1 << "line 1" << std::endl;
        os1.close ();
    }else{
        std::cerr << "Failed to open:" << fn << std::endl;
    }

    //2nd way
    std::ofstream os2(fn, std::ios_base::out | std::ios_base::app); //append if it exists otherwise create new a new file
    if(os2.is_open ()){
        os2 << "line 2" << std::endl;
        os2.close ();
    }else{
        std::cerr << "Failed to open:" << fn << std::endl;
    }
}


