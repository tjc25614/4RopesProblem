#include "Rope.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
	std::vector<double> times;
	double timeStep = 0.005;
	srand(std::time(0));
	for (int t = 1; t <= 100000; t++)
	{
		std::cout << t << std::endl;
		Rope rope1, rope2, rope3, rope4;
		double time = 0;
		bool randomize = false;
		rope1.randomize();
		rope2.randomize();
		rope3.randomize();
		rope4.randomize();
		while (rope1.getCanBurn() || rope2.getCanBurn() || rope3.getCanBurn() || rope4.getCanBurn())
		{
			if (rope1.burn(timeStep))
				randomize = true;
			if (rope2.burn(timeStep))
				randomize = true;
			if (rope3.burn(timeStep))
				randomize = true;
			if (rope4.burn(timeStep))
				randomize = true;
			time += timeStep;
			if (time >= 1000)
				break;
			if (randomize)
			{
				rope1.randomize();
				rope2.randomize();
				rope3.randomize();
				rope4.randomize();
				randomize = false;
			}
		}
		bool contains = (time >= 1000);
		for (int i = 0; i < times.size(); i++)
		{
			if (times.at(i) == time)
				contains = true;
		}
		if (!contains)
			times.push_back(time);
	}
	std::cout << "Finished!\n" << std::setprecision(10);
	std::cout << "Number of Time Increments: " << times.size() << std::endl;
	for (int i = 0; i < times.size(); i++)
	{
		std::cout << times.at(i) << ' ';
	}
	std::cout << std::endl;
}