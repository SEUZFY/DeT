# DeT

Delaunay triangulation and visualised using `OpenGL`.

## info

The algorithm is so called [Bowyer-Watson algorithm](https://en.wikipedia.org/wiki/Bowyer%E2%80%93Watson_algorithm), see [here](http://paulbourke.net/papers/triangulate/) for more details.

**Under construction**.

The OpenGL example code and environment set up is heavily inspired by:

1. environment set up
	[ OpenGL graphics in C++ from scratch [CMake + GLFW + GLEW] ](https://www.youtube.com/watch?v=Nzp77cOMmfg)

2. OpenGL example code(to draw an example triangle)
	[Setting up OpenGL and Creating a Window in C++](https://www.youtube.com/watch?v=OR4fNpBjmq8)

There is actually one implementation for `Bowyer-Watson algorithm`: 
[build DT incrementally](https://github.com/jbegaint/delaunay-cpp)

This project is inspired by it and tries to re-write the code based on the understanding of the incremental delaunay algorithm 
with some improvements.

## some improvements

- Use pointers as the members of edge class to improve the efficiency (especially for storage, i.e. won't store the same point twice, store
its pointers instead).

- Add `collinear check` before calculating the circumcircle of a triangle.

	