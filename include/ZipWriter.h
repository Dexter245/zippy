#ifndef ZIPWRITER_H_
#define ZIPWRITER_H_

#include <vector>
#include <string>
#include <fstream>
#include "ZipFileWriter.h"

class ZipWriter {
private:
    std::vector<ZipFileWriter> fileWriters = std::vector<ZipFileWriter>();
    std::string filepath;
    std::ofstream ofs;

    void writeCentralDirectory();

public:
    explicit ZipWriter(std::string filepath);

    ~ZipWriter();

    void addFile(std::string filepath);

    void writeZipFile();

    std::string to_string() { return filepath; };

};

#endif //ZIPPY_ZIPWRITER_H
