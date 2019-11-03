// CG Assignment 1 Exercise 1 WS 18/19

#include <iostream>
#include <cmath>

///////
// TODO
// Write a function that computes the area of a circle given its radius as input.
float circlearea(float radius)
{
	return atan(1) * 4 * radius * radius; // StackOverflow says PI = atan(1) * 4
}

int main()
{
	float radius;

	std::cout << "Insert circle radius:" << std::endl;

	///////
	// TODO
	// Get user input from the command line and store it in radius.
	// Check if input is valid.
	std::cin >> radius;
	
	///////
	// TODO
	// Call the function circlearea and output the computed value to the command line.
	std::cout << circlearea(radius) << std::endl;
}
