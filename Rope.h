#ifndef ROPE_H
#define ROPE_H

class Rope
{
private:
	double timeToBurn;
	bool burnLeft;
	bool burnRight;
	bool canBurn;
public:
	Rope();
	void randomize();
	bool burn(double time);
	bool getCanBurn();
};
#endif
