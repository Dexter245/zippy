#ifndef CDREND_H_
#define CDREND_H_

#include <string>
#include <fstream>
#include <ostream>

//todo: move to aprropriate classes later
const uint32_t SIGNATURE_LOCAL_FILE_HEADER = 0x04034b50;
const uint32_t SIGNATURE_CENTRAL_DIRECTORY_FILE_HEAADER = 0x02014b50;

class CDREnd {

private:
    uint16_t commentLen = 0;
    std::string comment;
public:
    static const uint32_t SIGNATURE;

    uint16_t diskNumber;
    uint16_t diskWithCD;
    uint16_t diskEntries;
    uint16_t totalEntries;
    uint32_t CDSize;
    uint32_t CDOffset;

    void writeToFS(std::ofstream &ofs);

    void readFromFS(std::ifstream &ifs);

    std::string getComment() { return comment; }

    void setComment(std::string comment) {
        this->comment = comment;
        commentLen = this->comment.length();
    }

    friend std::ostream &operator<<(std::ostream &os, const CDREnd &cdrEnd);


};

#endif
