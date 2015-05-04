#pragma once
class Dice
{
private:

	const int NUMOFFRINGES;
	vector <int> dice;


public:
	Dice(const int & fringes = 6);
	~Dice();

	void InitDice();
	int RollDice();
};

