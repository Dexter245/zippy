#include "ZipReader.h"
#include <iostream>
#include "Utils.h"

ZipReader::ZipReader(std::string filepath) :
        filepath(filepath) {

}

ZipReader::~ZipReader() {
    if (ifs.is_open())
        ifs.close();
}

void ZipReader::readZipFile() {
    ifs.open(filepath, std::ios::binary);

    readEndOfCDR();

    ifs.close();
}

void ZipReader::readEndOfCDR() {

    CDREnd cdrEnd;
    ifs.seekg(-4, std::ios::end);

    while (true) {
        uint32_t sig = Utils::readUint32FromFS(ifs);
        if (sig == CDREnd::SIGNATURE) {
            std::cout << "signature of CDREnd found" << std::endl;
            break;
        }
        ifs.seekg(-5, std::ios::cur);
    }

    cdrEnd.readFromFS(ifs);
    std::cout << "cdrEnd: " << cdrEnd << std::endl;


}
