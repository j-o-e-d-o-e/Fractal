#ifndef FRACTAL_RGB_H
#define FRACTAL_RGB_H

namespace FractalSpace {

    struct Rgb {
        double r;
        double g;
        double b;

        Rgb(double r, double g, double b);
    };
    Rgb operator-(const Rgb &first, Rgb &second);
}

#endif //FRACTAL_RGB_H
