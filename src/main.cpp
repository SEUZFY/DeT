#include <string>
#include <sstream>
#include <fstream>

#include "DeT.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h" // mind the orders, include glew.h first and include glfw3.h next -> to use newest OpenGL functions

using namespace Geometry;

int main()
{
    Point_2<double> p(1.0, 1.0);
    Point_2<double> q(1.0, 1.0 + 1e-5);
    std::cout << p << std::endl;
    p.y() = 1.0 + 1e-5;
    std::cout << (p == q) << std::endl;

    // construct edges
    Point_2<double> p0(1.0, 1.0);
    Point_2<double> p1(1.0, 2.0);

    Edge_2<double> e0;
    Edge_2<double> e1(p0, p1);

    Point_2<double> p2(1.0, 2.0);
    Point_2<double> p3(1.0, 1.0);
    Edge_2<double> e2(p2, p3);

    std::cout << "edges\n";
    std::cout << e0 << std::endl;
    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;

    std::cout << (e1 == e2) << std::endl;

    Point_2<double> e1_p0 = e1.p0();
    std::cout << e1_p0 << std::endl;
    

    return EXIT_SUCCESS;
}
