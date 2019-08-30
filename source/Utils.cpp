#include "Utils.h"

uint16_t Utils::readUint16FromFS(std::ifstream &ifs) {
    char *data = new char[2];
    ifs.read(data, 2);
    uint16_t value = data[1] << 8 | data[0];
    delete[] data;
    return value;
}

uint32_t Utils::readUint32FromFS(std::ifstream &ifs) {
    char *data = new char[4];
    ifs.read(data, 4);
    uint32_t value = data[3] << 24 | data[2] << 16 | data[1] << 8 | data[0];
    delete[] data;
    return value;
}
