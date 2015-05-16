#include "stdafx.h"
#include "Dice.h"

Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)
{
	//CreateDice();

	srand((unsigned int) time(NULL));

}// Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)
//------------------------------------------------------------------------
int Dice::RollDice()
{
	return rand() % NUMOFFRINGES + 1;

}// int Dice::RollDice()
//------------------------------------------------------------------------
Dice::~Dice()
{
}// Dice::~Dice()
//------------------------------------------------------------------------
