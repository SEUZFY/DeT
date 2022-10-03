/*
* Bowyer-Watson algorithm
* build Delaunay triangulation incrementally
* 
* inspired by: https://github.com/jbegaint/delaunay-cpp
* 
* Geometry.hpp
* classes with regard to point / edge / circle / triangle in 2D Euclidean space
*/

#pragma once

// header files
#include <iostream>
#include <cmath>
#include <vector>

// everything goes into delaunay namespace
namespace Geometry {



	/* define the epsilon for comparing if two values are the same */
	const double epsilon = 1e-8;



	/*
	* class declarations 
	* --------------------------------------------------------------------------------------------------------------------------
	*/
	template <typename T>
	class Point_2; // store all the 2D points

	template <typename T>
	class Edge_2; // store all the 2D edges

	template <typename T>
	class Circle_2; // circle in 2D Euclidean space, mainly for the circumcircle of a triangle

	template <typename T>
	class Triangle_2; // triangle in 2D Euclidean space, formed by Point_2<T> and Edge_2<T>

	/*--------------------------------------------------------------------------------------------------------------------------*/



	/*
	* Point_2 class - store the 2D points
	* use template
	*/
	template <typename T>
	class Point_2 {
	public:

		/* constructors */
		Point_2() : 
			m_x(T(0)), m_y(T(0)) {} /* default constructor */
		
		Point_2(T x, T y) : 
			m_x(x), m_y(y){} /* constructor with @param */

		template <typename U> /* if the constructor gets different @param types */
		Point_2(T x, T y) : 
			m_x(static_cast<T>(x)), m_y(static_cast<T>(y)){}


		/* get the x coordinate */
		T& x() { return m_x; } // return reference, so that we can both access and modify the x coordinate
		const T& x()const { return m_x; } // const version, for const objects


		/* get the y coordinate */
		T& y() { return m_y; } // return reference, so that we can both access and modify the x coordinate
		const T& y()const { return m_y; } // const version, for const objects


		/* compare if the two points are in the same location */
		bool operator==(const Point_2<T>& rhs)const {
			return ((std::abs(m_x - rhs.x()) < epsilon) &&
				    (std::abs(m_y - rhs.y()) < epsilon));
		} // this function can be declared as `const` since both const and non-const objects can access it


		/* calculate the distance between the two points */
		double distance(const Point_2<T>& rhs)const {
			return std::sqrt((rhs.x() - m_x) * (rhs.x() - m_x) + (rhs.y() - m_y) * (rhs.y() - m_y));
		} // use std::sqrt() to avoid possible overloading of sqrt() function


		/* ostream overloading, for printing the info of the Point_2<T> objects */
		friend std::ostream& operator<<(std::ostream& os, const Point_2<T>& p)
		{
			os << "(" << p.x() << ", " << p.y() << ")";
			return os;
		}

	protected:
		T m_x; // x coordinate
		T m_y; // y coordinate

		/* x and y should not be modified directly outside the class */
	};



	/*
	* Edge_2 class - store the 2D edges
	* use template
	*/
	template <typename T>
	class Edge_2 {

	public:

		/* constructors */
		Edge_2() : ptr0(nullptr), ptr1(nullptr){}

		Edge_2(Point_2<T>* p0, Point_2<T>* p1) {
			if (p0 != nullptr && p1 != nullptr) {
				ptr0 = p0;
				ptr1 = p1;
			}
			else {
				ptr0 = nullptr;
				ptr1 = nullptr;
			}
		}

		Edge_2(const Edge_2<T>& rhs) {
			ptr0 = rhs.ptr0;
			ptr1 = rhs.ptr1;
		}


		/* get the pointer of point p0 */
		Point_2<T>* p0() { return ptr0; }
		const Point_2<T>* p0()const { return ptr0; }


		/* get point p1 */
		Point_2<T>* p1() { return ptr1; }
		const Point_2<T>* p1()const { return ptr1; }


		/* if two edges are in the same location or if two identical edges */
		bool operator==(const Edge_2<T>& rhs) const{
			Point_2<T>& lhs_p0 = *ptr0;
			Point_2<T>& lhs_p1 = *ptr1;

			Point_2<T>& rhs_p0 = *(rhs.ptr0);
			Point_2<T>& rhs_p1 = *(rhs.ptr1);

			return ((lhs_p0 == rhs_p0 && lhs_p1 == rhs_p1) ||
					(lhs_p0 == rhs_p1 && lhs_p1 == rhs_p0));
		}


		/* ostream overloading */
		friend std::ostream& operator<<(std::ostream& os, const Edge_2<T>& e)
		{
			os << "p0:" << *(e.p0()) << " " << "p1:" << *(e.p1());
			return os;
		}


	protected:
		Point_2<T>* ptr0;
		Point_2<T>* ptr1;

		/* store the pointers pointing at Point_2<T> instances instead of sotring instances */

		/* ptr_p0 and ptr_p1 should not be modified directly outside the class */
	};



	/*
	* Circle_2 class - store the 2D circle
	* use template
	*/
	template <typename T>
	class Circle_2 {
	public:

		/* constructors */
		Circle_2(): m_x(T(0)), m_y(T(0)), m_radius(T(0)){}

		Circle_2(T x, T y, T radius) :
			m_x(x), m_y(y), m_radius(radius) {}


		/* get the coordinate of the center */
		T& x() { return m_x; }
		const T& x()const { return m_x; }
		T& y() { return m_y; }
		const T& y()const { return m_y; }


		/* get the radius */
		T& radius() { return m_radius; }
		const T& radius()const { return m_radius; }


		/* point in circle test? */


		/* ostream overloading */
		friend std::ostream& operator<<(std::ostream& os, const Circle_2<T>& c)
		{
			os << "center: " << "(" << c.x() << ", " << c.y() << ")" << " " << "radius: " << c.radius();
			return os;
		}


	protected:
		T m_x; // x coordinate of the center
		T m_y; // y coordinate of the center
		T m_radius; // radius of the circle

		/* the class members should not be directly accessed outside the class */
	};



	/*
	* Triangle_2 class - store the 2D triangle
	* use template
	*/
	template <typename>
	class Triangle_2 {
	public:

	protected:

	};




} // end of namespace Geometry



