#include "stdafx.h"
#include "Dice.h"

Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)
{
	CreateDice();

	srand((unsigned int) time(NULL));

}// Dice::Dice(const int & fringes) :NUMOFFRINGES(fringes)
//------------------------------------------------------------------------
void Dice::CreateDice()
{
	for (int i = 1; i <= NUMOFFRINGES; i++)
	{
		dice.push_back(i);

	}// for (int i = 1; i <= NUMOFFRINGES; i++)

}// void Dice::InitDice()
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
