#include <string>
#include <sstream>
#include <fstream>

#include "Geometry.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h" // mind the orders, include glew.h first and include glfw3.h next -> to use newest OpenGL functions

using namespace Geometry;

int main()
{
    Point_2<double> p(1.0, 1.0);
    Point_2<double> q(1.0, 2.0);
    std::cout << p << std::endl;
    //p.y() = 1.0 + 1e-5;
    std::cout << (p == q) << std::endl;
    std::cout << "distance: " << p.distance(q) << std::endl;

    Point_2<double> a(1.0, 1.0);
    Point_2<double> b(1.0, 2.0);

    Point_2<double> c(1.0, 1.0);
    Point_2<double> d(1.0, 2.0);

    // construct edges
    Edge_2<double> e1(&a, &b);
    Edge_2<double> e2(&c, &d);
    std::cout << "edge 1: " << e1 << std::endl;
    std::cout << "edge 2: " << e2 << std::endl;
    std::cout << "same edge? " << (e1 == e2) << std::endl;
    

    return EXIT_SUCCESS;
}
