#ifndef ZIPFILEWRITER_H_
#define ZIPFILEWRITER_H_

#include <string>

class ZipFileWriter{
private:
    std::string filepath;

public:
    explicit ZipFileWriter(std::string filepath);
    ~ZipFileWriter();

    void writeFile();

    std::string to_string() { return filepath; };
};

#endif //ZIPPY_ZIPFILEWRITER_H
