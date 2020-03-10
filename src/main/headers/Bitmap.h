#ifndef FRACTAL_BITMAP_H
#define FRACTAL_BITMAP_H

#include <string>
#include <cstdint>
#include <bits/unique_ptr.h>

using namespace std;

namespace BitmapSpace {

    class Bitmap {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr}; // uint8_t equivalent to unsigned char
    public:
        Bitmap(int width, int height);

        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

        bool write(const string &filename);

        virtual ~Bitmap() = default;
    };
}
#endif //FRACTAL_BITMAP_H
