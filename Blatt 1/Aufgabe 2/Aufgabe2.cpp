// CG Assignment 1 Exercise 2 WS 18/19

#include "Point3D.hpp"
#include "LineStrip3D.hpp"

#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <algorithm>

int main()
{

	///////
	// TODO
	// Create a container for linestrips
	std::vector<LineStrip3D> strips = {};

	///////
	// TODO
	// Add three linestrips to the container and add a couple of points to each linestrip
	LineStrip3D strip1 = LineStrip3D();
	strip1.addPoint(Point3D(0, 0, 0));
	strip1.addPoint(Point3D(1, 2, 3));
	strips.push_back(strip1);
	LineStrip3D strip2 = LineStrip3D();
	strip2.addPoint(Point3D(42, 0, 0));
	strip2.addPoint(Point3D(0, 69, 0));
	strip2.addPoint(Point3D(0, 0, 1337));
	strips.push_back(strip2);
	LineStrip3D strip3 = LineStrip3D();
	strip3.addPoint(Point3D(1, 2, 3));
	strip3.addPoint(Point3D(4, 5, 6));
	strip3.addPoint(Point3D(7, 8, 9));
	strips.push_back(strip3);

	std::cout << "==================================" << std::endl;
	std::cout << "Length of all linestrips:" << std::endl;

	///////
	// TODO
	// Print the length of all line strips on the command line
	for (LineStrip3D strip : strips)
	{
	    std::cout << strip.computeLength() << std::endl;
	}

	std::cout << "==================================" << std::endl;
	std::cout << "Length of all linestrips (sorted):" << std::endl;

	///////
	// TODO
	// Sort the line strips in the container based on their length.
	// For validation, print the lengths of all linestrips on the command line one more time.
	std::sort(strips.begin(), strips.end());
	for (LineStrip3D strip : strips)
	{
	    std::cout << strip.computeLength() << std::endl;
	}
}
