#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H

namespace BitmapSpace {
    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;

        Mandelbrot();

        virtual  ~Mandelbrot();

        static int getIterations(double x, double y);
    };

}
#endif //FRACTAL_MANDELBROT_H
