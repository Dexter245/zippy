#include <iostream>
#include "ZipWriter.h"
#include "ZipReader.h"

int main(int argc, char **argv) {
    std::cout << "main, num args: " << std::to_string(argc) << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "arg" << std::to_string(i) << ": " << argv[i] << std::endl;
    }

//    ZipWriter zipWriter("test.zip");
//    zipWriter.writeZipFile();

    ZipReader zipReader("test.zip");
    zipReader.readZipFile();

}
