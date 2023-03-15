#include "Lorenz.h"

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

Lorenz* Lorenz::instance = nullptr;
Lorenz& Lorenz::getInstance()
{
	// check if instance exists
	if (!instance)
	{
		// create new instance
		instance = new Lorenz();
		if (!instance) throw std::runtime_error("Failed to create Lorenz instance");
	}
	// return instance
	return *instance;
}

constexpr float sigma = 10;
constexpr float rho = 28;
constexpr float beta = 2.66666667f;
constexpr float dt = 1e-3f;

void Lorenz::input()
{
	std::string inPos;
	std::string sX, sY, sZ;

	std::getline(std::cin, inPos); 
	std::stringstream ss(inPos);

	ss >> sX >> sY >> sZ;

	pos.clear();
	point = glm::vec3(stoi(sX), stoi(sY), stoi(sZ));

	printf("Enter the initial position: ");
}

void Lorenz::init()
{
	point = glm::vec3(0, 2, 3);
	printf("Inital position (%.2f, %.2f, %.2f)\n", (float)point.x, (float)point.y, (float)point.z);
	printf("Enter the initial position: ");
}

void Lorenz::run()
{
	if (_kbhit()) input();

	vel = glm::vec3(
		sigma * (point.y - point.x),
		point.x * (rho - point.z) - point.y,
		point.x * point.y - beta * point.z
	);

	//vel = glm::vec3(
	//	x * y - z * x,
	//	x * y + y * z,
	//	- y * z - z * x
	//);

	point += vel * dt;
	pos.emplace_back(point);
	if (pos.size() > 200000) pos.clear();
}