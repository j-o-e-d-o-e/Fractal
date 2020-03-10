#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef FRACTAL_BITMAPFILEHEADER_H
#define FRACTAL_BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(push, 2)
namespace BitmapSpace {

    struct BitmapFileHeader {
        const char header[2]{'B', 'M'};
        int32_t fileSize{0}; // 4 bytes for correct file format
        const int32_t reserved{0};
        int32_t dataOffset{0};
    };
}
#pragma pack(pop)

#endif //FRACTAL_BITMAPFILEHEADER_H

#pragma clang diagnostic pop