#include <string>
#include <sstream>
#include <fstream>

#include "DeT.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h" // mind the orders, include glew.h first and include glfw3.h next -> to use newest OpenGL functions


int main()
{
    delaunay::Point_2<double> p(1.0, 1.0);
    delaunay::Point_2<double> q(1.0, 1.0 + 1e-5);
    std::cout << p << std::endl;
    p.y() = 1.0 + 1e-5;
    std::cout << (p == q) << std::endl;

    return EXIT_SUCCESS;
}
