// CG Assignment 1 Exercise 2 WS 18/19

#ifndef Point3D_hpp
#define Point3D_hpp

#include <array>
#include <list>
#include <vector>

struct Point3D
{
	///////
	// TODO
	// Implement the constructor
	Point3D(float x, float y, float z)
	{
	    coords = {x, y, z};
	}

	///////
	// TODO
	// Implement access to the three coordinate values.
	float x() const
	{
	    return coords[0];
	}
	
	float y() const
	{
	    return coords[1];
	}
	
	float z() const
	{
	    return coords[2];
	}

private:
	///////
	// TODO
	// Use a suitable STL container to store the three values of a point in 3d space.
	std::array<float, 3> coords;
};

#endif // !Point3D_hpp
