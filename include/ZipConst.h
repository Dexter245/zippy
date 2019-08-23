#ifndef ZIPCONST_H_
#define ZIPCONST_H_

#include <string>

const uint32_t SIGNATURE_LOCAL_FILE_HEADER = 0x04034b50;
const uint32_t SIGNATURE_CENTRAL_DIRECTORY_FILE_HEAADER = 0x02014b50;
const uint32_t SIGNATURE_END_OF_CENTRAL_DIRECTORY = 0x06054b50;

struct CDREnd {
    uint16_t diskNumber;
    uint16_t diskWithCD;
    uint16_t diskEntries;
    uint16_t totalEntries;
    uint32_t CDSize;
    uint32_t CDOffset;
    std::string comment;
private:
    uint32_t signature = SIGNATURE_END_OF_CENTRAL_DIRECTORY;
    uint16_t commentLen;

public:
    void writeToOFS(std::ofstream &ofs);
};

void CDREnd::writeToOFS(std::ofstream &ofs) {
    ofs.write((char*) &signature, sizeof(signature));
    ofs.write((char*) &diskNumber, sizeof(diskNumber));
    ofs.write((char*) &diskWithCD, sizeof(diskWithCD));
    ofs.write((char*) &diskEntries, sizeof(diskEntries));
    ofs.write((char*) &totalEntries, sizeof(totalEntries));
    ofs.write((char*) &CDSize, sizeof(CDSize));
    ofs.write((char*) &CDOffset, sizeof(CDOffset));
    commentLen = comment.length();
    ofs.write((char*) &commentLen, sizeof(commentLen));
    ofs.write((char*) comment.c_str(), commentLen);
}

#endif //ZIPPY_ZIPCONST_H
