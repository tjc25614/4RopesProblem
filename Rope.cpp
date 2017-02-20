#include "Rope.h"
#include <cstdlib>

Rope::Rope()
{
	timeToBurn = 60;
	burnLeft = false;
	burnRight = false;
	canBurn = true;
}

bool Rope::burn(double time)
{
	if (canBurn)
	{
		if (burnLeft)
			timeToBurn -= time;
		if (burnRight)
			timeToBurn -= time;
		if (timeToBurn <= 0)
		{
			canBurn = false;
			return true;
		}
	}
	return false;
}

void Rope::randomize()
{
	if (rand() % 2)
		burnLeft = true;
	if (rand() % 2)
		burnRight = true;
}

bool Rope::getCanBurn()
{
	return canBurn;
}
