#include "CDREnd.h"
#include <iostream>
#include <sstream>
#include "Utils.h"

const uint32_t CDREnd::SIGNATURE = 0x06054b50;

void CDREnd::writeToFS(std::ofstream &ofs) {
    ofs.write((char *) &SIGNATURE, sizeof(SIGNATURE));
    ofs.write((char *) &diskNumber, sizeof(diskNumber));
    ofs.write((char *) &diskWithCD, sizeof(diskWithCD));
    ofs.write((char *) &diskEntries, sizeof(diskEntries));
    ofs.write((char *) &totalEntries, sizeof(totalEntries));
    ofs.write((char *) &CDSize, sizeof(CDSize));
    ofs.write((char *) &CDOffset, sizeof(CDOffset));
    ofs.write((char *) &commentLen, sizeof(commentLen));
    ofs.write((char *) comment.c_str(), commentLen);
}

void CDREnd::readFromFS(std::ifstream &ifs) {
    diskNumber = Utils::readUint16FromFS(ifs);
    diskWithCD = Utils::readUint16FromFS(ifs);
    diskEntries = Utils::readUint16FromFS(ifs);
    totalEntries = Utils::readUint16FromFS(ifs);
    CDSize = Utils::readUint32FromFS(ifs);
    CDOffset = Utils::readUint32FromFS(ifs);
    commentLen = Utils::readUint16FromFS(ifs);

    if (commentLen > 0) {
        char *com = new char[commentLen];
        ifs.read(com, commentLen);
        comment = std::string(com);
        delete[] com;
    }
}

std::ostream &operator<<(std::ostream &os, const CDREnd &cdrEnd){
    os << "diskNumber: " << cdrEnd.diskNumber << ", diskWithCD: " << cdrEnd.diskWithCD << ", diskEntries: " <<
        cdrEnd.diskEntries << ", totalEntries: " << cdrEnd.totalEntries << ", CDSize: " << cdrEnd.CDSize <<
        ", CDOffset: " << cdrEnd.CDOffset << ", commentLen: " << cdrEnd.commentLen << ", comment: '" <<
        cdrEnd.comment << "'" << std::endl;
    return os;
}

