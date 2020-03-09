#include <iostream>
#include <stdlib.h>
#include <memory>
#include <cstdint>
#include <Mandelbrot.h>
#include "Bitmap.h"

using namespace std;
using namespace BitmapSpace;

//std::string Fractal::Greeter::greeting() {
//    return std::string("Hello, World!");
//}

int main() {
//    Fractal::Greeter greeter;
//    std::cout << greeter.greeting() << std::endl;

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);
    double min = 9999999;
    double max = -9999999;
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH / 2.0 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2.0) * 2.0 / HEIGHT;
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            fractal[y * WIDTH + x] = iterations;
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = fractal[y * WIDTH + x];
            double hue = 0.0;
            for (int i = 0; i <= iterations; i++) {
                hue += ((double) histogram[i]) / total;
            }
            uint8_t red = 0;
            uint8_t green = hue * 255;
            uint8_t blue = 0;

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");
    cout << "Finished." << endl;
    return 0;
}
