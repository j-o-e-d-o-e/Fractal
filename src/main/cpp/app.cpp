#include <iostream>
#include <stdlib.h>
#include "Bitmap.h"

using namespace std;
using namespace BitmapSpace;

//std::string Fractal::Greeter::greeting() {
//    return std::string("Hello, World!");
//}

int main () {
//    Fractal::Greeter greeter;
//    std::cout << greeter.greeting() << std::endl;

    Bitmap bitmap(800, 600);
    bitmap.write("test.bmp");
    cout << "Finished." << endl;
    return 0;
}
