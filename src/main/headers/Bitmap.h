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
        //equivalent to unsigned char
        unique_ptr<uint8_t[]> m_pPixels{nullptr};
    public:
        Bitmap(int width, int height);

        // unint8 unsigned int
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

        bool write(string filename);

        virtual ~Bitmap();
    };

}
#endif //FRACTAL_BITMAP_H
