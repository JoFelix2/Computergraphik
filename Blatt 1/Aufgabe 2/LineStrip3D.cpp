// CG Assignment 1 Exercise 2 WS 18/19

#include "LineStrip3D.hpp"
#include <cmath>

bool LineStrip3D::operator<(LineStrip3D const& rhs)
{
	///////
	// TODO
	// Implement comparison based on length.
	return this->computeLength() < rhs.computeLength();
}

void LineStrip3D::addPoint(Point3D p)
{
	///////
	// TODO
	// Implement adding a given point to the line strip.
	this->points.push_back(p);
}

void LineStrip3D::removePoint(size_t idx)
{
	///////
	// TODO
	// Implement the removal of the point with the given index.
	this->points.erase(points.begin() + idx);
}

size_t	LineStrip3D::getPointCount() const
{
	///////
	// TODO
	// Return the number of points of the line strip.
	return this->points.size();
}

float LineStrip3D::computeLength() const
{
	///////
	// TODO
	// Implement computation of the line strip's length,
	// that is, the sum of the lengths of all segements.
	if (getPointCount() == 0) return 0;
	float length = 0;
	Point3D prev = this->points[0];
	for (int i = 1; i < this->getPointCount(); i++)
	{
		Point3D curr = this->points[i];
		length += sqrt((prev.x() - curr.x()) * (prev.x() - curr.x()) + (prev.y() - curr.y()) * (prev.y() - curr.y()) + (prev.z() - curr.z()) * (prev.z() - curr.z()));
		prev = curr;
	}
	return length;
}
