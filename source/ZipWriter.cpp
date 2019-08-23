#include "ZipWriter.h"
#include <iostream>
#include "ZipConst.h"

ZipWriter::ZipWriter(std::string filepath) :
        filepath(filepath) {

}

ZipWriter::~ZipWriter() {
    if (ofs.is_open())
        ofs.close();
}

void ZipWriter::addFile(std::string filepath) {

}

void ZipWriter::writeZipFile() {

//    ofs = std::ofstream(filepath, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
    ofs.open(filepath, std::ios::out | std::ios::binary | std::ios::trunc);

    std::cout << "num files to write into zip: " << std::to_string(fileWriters.size()) << std::endl;
    for (auto fileWriter : fileWriters) {
        std::cout << "writing file: " << fileWriter.to_string() << std::endl;
        //todo: write files
    }

    writeCentralDirectory();

}

void ZipWriter::writeCentralDirectory() {
    for (auto fileWriter : fileWriters) {
        //todo: write file headers
    }

    //todo: DO THIS BELOW WITH A STRUCT!?

    CDREnd cdrEnd;
    cdrEnd.diskNumber = 0;
    cdrEnd.diskWithCD = 0;
    cdrEnd.diskEntries = fileWriters.size();
    cdrEnd.totalEntries = cdrEnd.diskEntries;
    cdrEnd.CDSize = 0;
    cdrEnd.CDOffset = 0;
    cdrEnd.comment = "bla";
    cdrEnd.writeToOFS(ofs);
    ofs.flush();
}
