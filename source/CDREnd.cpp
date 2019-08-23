#include "CDREnd.h"

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
