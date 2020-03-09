#ifndef FRACTAL_BITMAPFILEHEADER_H
#define FRACTAL_BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(push, 2)
namespace BitmapSpace {

    struct BitmapFileHeader {
        char header[2]{'B', 'M'};
        int32_t fileSize; // 4 bytes for correct file format
        int32_t reserved{0};
        int32_t dataOffset;
    };
}
#pragma pack(pop)

#endif //FRACTAL_BITMAPFILEHEADER_H
