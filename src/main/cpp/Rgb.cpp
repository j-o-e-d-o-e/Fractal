#include <Rgb.h>

namespace FractalSpace {

    Rgb::Rgb(double r, double g, double b) : r(r), g(g), b(b) {}

    Rgb operator-(const Rgb &first, Rgb &second) {
        return Rgb(first.r - second.r, first.g - second.g, first.b - second.b);
    }
}
