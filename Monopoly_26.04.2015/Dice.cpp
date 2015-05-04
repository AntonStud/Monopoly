#include "stdafx.h"
#include "Dice.h"


Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)
{
	InitDice();

	srand((unsigned int) time(NULL));

}// Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)

void Dice::InitDice()
{
	for (int i = 1; i <= NUMOFFRINGES; i++)
	{
		dice.push_back(i);

	}// for (int i = 1; i <= NUMOFFRINGES; i++)

}// void Dice::InitDice()


int Dice::RollDice()
{
	int random = rand() % NUMOFFRINGES + 1;

	return random;

}// int Dice::RollDice()


Dice::~Dice()
{
}
