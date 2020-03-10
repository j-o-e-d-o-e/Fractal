#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef FRACTAL_BITMAPINFOHEADER_H
#define FRACTAL_BITMAPINFOHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(push, 2)
namespace BitmapSpace {

    struct BitmapInfoHeader {
        const int32_t headerSize{40}; // mem size of all ints = 40
        int32_t width{0};
        int32_t height{0};
        const int16_t planes{1};
        const int16_t bitsPerPixel{24}; // one rgb-value per pixel
        const int32_t compression{0};
        const int32_t dataSize{0};
        const int32_t horizontalResolution{2400};
        const int32_t verticalResolution{2400};
        const int32_t colors{0};
        const int32_t importantColors{0};
    };
}
#pragma pack(pop)

#endif //FRACTAL_BITMAPINFOHEADER_H

#pragma clang diagnostic pop