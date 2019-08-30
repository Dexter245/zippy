#ifndef UTILS_H_
#define UTILS_H_

#include <fstream>

namespace Utils {
    uint16_t readUint16FromFS(std::ifstream &ifs);

    uint32_t readUint32FromFS(std::ifstream &ifs);
}

#endif
