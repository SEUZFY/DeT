/*
* Bowyer-Watson algorithm
* build Delaunay triangulation incrementally
* 
* inspired by: https://github.com/jbegaint/delaunay-cpp
*/

#pragma once

// header files
#include <iostream>
#include <vector>

// everything goes into delaunay namespace
namespace delaunay {



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
		Point_2(T px, T py) : 
			m_x(px), m_y(py){} /* constructor with @param */

		template <typename U> /* if the constructor gets different @param types */
		Point_2(T px, T py) : 
			m_x(static_cast<T>(px)), m_y(static_cast<T>(py)){}


		/* get the x coordinate */
		T& x() { return m_x; } // return reference, so that we can both access and modify the x coordinate
		const T& x()const { return m_x; } // const version, for const objects


		/* get the y coordinate */
		T& y() { return m_y; } // return reference, so that we can both access and modify the x coordinate
		const T& y()const { return m_y; } // const version, for const objects


		/* compare if the two points are in the same location */
		bool operator==(const Point_2<T>& rhs)const {
			if (abs(m_x - rhs.x()) < epsilon &&
				abs(m_y - rhs.y()) < epsilon) {
				return true;
			}
			else {
				return false;
			}

		} // this function can be declared as `const` since both const and non-const objects can access it


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




} // end of namespace delaunay



