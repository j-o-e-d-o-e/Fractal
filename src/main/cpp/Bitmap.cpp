#include <fstream>
#include "Bitmap.h"
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h"

using namespace BitmapSpace;
using namespace std;

namespace BitmapSpace {
    // {} initializes to all zeros
    Bitmap::Bitmap(int width, int height) : m_width(width),
                                            m_height(height),
                                            m_pPixels(new uint8_t[width * height * 3]{}) {
    }

    Bitmap::~Bitmap() {

    }

    bool Bitmap::write(string filename) {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;
        fileHeader.fileSize = sizeof(BitmapFileHeader)
                              + sizeof(BitmapInfoHeader)
                              + m_width * m_height * 3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader)
                                + sizeof(BitmapInfoHeader);
        infoHeader.width = m_width;
        infoHeader.height = m_height;

        ofstream file;
        file.open(filename, ios::out | ios::binary);
        if (!file) {
            return false;
        }
        file.write((char *) &fileHeader, sizeof(fileHeader));
        file.write((char *) &infoHeader, sizeof(infoHeader));
        // get() gets normal pointer
        file.write((char *) m_pPixels.get(), m_width * m_height * 3);
        file.close();
        if (!file) {
            return false;
        }
        return true;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

    }
}