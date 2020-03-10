#include <iostream>
#include "FractalCreator.h"
#include "Zoom.h"

using namespace std;
using namespace FractalSpace;

int main() {
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, Rgb(0, 0, 255));
    fractalCreator.addRange(0.3, Rgb(255, 99, 71)); // iteration 0 to 300
    fractalCreator.addRange(0.5, Rgb(255, 215, 0)); // 300 to 500
    fractalCreator.addRange(1.0, Rgb(255, 255, 255)); // 500 to 1000

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("Fractal.bmp");
    cout << "Finished." << endl;
    return 0;
}
