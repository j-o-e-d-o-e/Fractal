#ifndef FRACTAL_FRACTALCREATOR_H
#define FRACTAL_FRACTALCREATOR_H

#include <string>
#include <vector>
#include <bits/unique_ptr.h>
#include "Mandelbrot.h"
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "Rgb.h"

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

        vector<int> m_ranges;
        vector<Rgb> m_colors;
        vector<int> m_rangeTotals;

        bool m_bGotFirstRange{false};
    public:
        void run(const string& name);

        FractalCreator(int width, int height);

        virtual ~FractalCreator() = default;

        void addZoom(const Zoom &zoom);

        void addRange(double rangeEnd, const Rgb &rgb);

        int getRange(int iterations) const;

    private:
        void calculateIteration();

        void calculateTotalIterations();

        void calculateRangeTotals();

        void drawFractal();

        void writeBitmap(const string& name);
    };
}

#endif //FRACTAL_FRACTALCREATOR_H
