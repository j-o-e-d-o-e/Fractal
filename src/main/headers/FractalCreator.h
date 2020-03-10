#ifndef FRACTAL_FRACTALCREATOR_H
#define FRACTAL_FRACTALCREATOR_H

#include <string>
#include <bits/unique_ptr.h>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"

using namespace std;
using namespace BitmapSpace;

namespace FractalSpace {
    class FractalCreator {
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomList;
        int m_total{0};
    public:
        FractalCreator(int width, int height);

        virtual ~FractalCreator();

        void calculateIteration();

        void calculateTotalIterations();

        void drawFractal();

        void addZoom(const Zoom &zoom);

        void writeBitmap(string name);
    };
}

#endif //FRACTAL_FRACTALCREATOR_H
