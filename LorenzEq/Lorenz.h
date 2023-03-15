#pragma once

#include <vector>
#include <glm/vec3.hpp>

class Lorenz
{
protected:
	static Lorenz* instance;

public:
	static Lorenz& getInstance();
	Lorenz() { init(); };
	virtual ~Lorenz() {};

	void init();
	void run();
	void input();

	std::vector<glm::vec3> pos;

private:
	glm::vec3 point;
	glm::vec3 vel;
};