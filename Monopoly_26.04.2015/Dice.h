#pragma once
class Dice
{
private:
	// Number of sides
	const int NUMOFFRINGES;
	// Values of sides
	vector <int> dice;

public:

	Dice(const int & fringes = 6);
	~Dice();

	// Create Dice
	void CreateDice();

	// Roll Dice
	int RollDice();
};

