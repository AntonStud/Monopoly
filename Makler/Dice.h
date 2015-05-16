#pragma once
class Dice
{
private:
	// Number of sides
	const int NUMOFFRINGES;
	
public:

	Dice(const int & fringes = 6);
	~Dice();

	// Roll Dice
	int RollDice();
};

