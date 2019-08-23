#ifndef CDREND_H_
#define CDREND_H_

#include <string>
#include <fstream>

//todo: move to aprropriate classes later
const uint32_t SIGNATURE_LOCAL_FILE_HEADER = 0x04034b50;
const uint32_t SIGNATURE_CENTRAL_DIRECTORY_FILE_HEAADER = 0x02014b50;

class CDREnd {

private:
    uint32_t signature = 0x06054b50;
    uint16_t commentLen;
public:
    uint16_t diskNumber;
    uint16_t diskWithCD;
    uint16_t diskEntries;
    uint16_t totalEntries;
    uint32_t CDSize;
    uint32_t CDOffset;
    std::string comment;

public:
    void writeToOFS(std::ofstream &ofs);

};

#endif
