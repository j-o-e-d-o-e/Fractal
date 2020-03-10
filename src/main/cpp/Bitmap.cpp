#include <fstream>
#include "Bitmap.h"
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h"

using namespace BitmapSpace;
using namespace std;

namespace BitmapSpace {

    // {} initializes all to zeros
    Bitmap::Bitmap(int width, int height) : m_width(width),
                                            m_height(height),
                                            m_pPixels(new uint8_t[width * height * 3]{}) {
    }

    bool Bitmap::write(const string& filename) {
        BitmapFileHeader fileHeader;
        fileHeader.fileSize = sizeof(BitmapFileHeader)
                              + sizeof(BitmapInfoHeader)
                              + m_width * m_height * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader)
                                + sizeof(BitmapInfoHeader);

        BitmapInfoHeader infoHeader;
        infoHeader.width = m_width;
        infoHeader.height = m_height;

        ofstream file;
        file.open(filename, ios::out | ios::binary);
        if (!file) {
            return false;
        }
        file.write((char *) &fileHeader, sizeof(fileHeader));
        file.write((char *) &infoHeader, sizeof(infoHeader));
        file.write((char *) m_pPixels.get(), m_width * m_height * 3); // get() gets normal pointer
        file.close();
        return !!file;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        uint8_t *pPixel = m_pPixels.get(); // get normal pointer
        pPixel += (y * 3) * m_width + (x * 3); // *3 because of colors
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }
}