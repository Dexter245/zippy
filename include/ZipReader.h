#ifndef ZIPREADER_H_
#define ZIPREADER_H_

#include <string>
#include <fstream>
#include "CDREnd.h"

class ZipReader {
private:
    std::string filepath;
    std::ifstream ifs;
    CDREnd cdrEnd;

    void readEndOfCDR();

public:
    explicit ZipReader(std::string filepath);

    ~ZipReader();

    void readZipFile();
};

#endif
