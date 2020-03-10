#ifndef FRACTAL_FRACTALCREATOR_H
#define FRACTAL_FRACTALCREATOR_H

#include <string>
#include "Zoom.h"

using namespace std;
using namespace BitmapSpace;

namespace FractalSpace {
    class FractalCreator {
    public:
        FractalCreator(int width, int height);

        virtual ~FractalCreator();

        void calculateIteration();

        void drawFractal();

        void addZoom(const Zoom &zoom);

        void writeBitmap(string name);
    };
}

#endif //FRACTAL_FRACTALCREATOR_H
