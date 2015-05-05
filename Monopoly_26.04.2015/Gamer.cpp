#include "stdafx.h"
#include "Gamer.h"


Gamer::Gamer(const string &name, const int& capital)
{
	playerCurPositon = 0;

	playerNumOfTakes = 0;

	playerCapital = capital;

	SetPlayerName(name);

	playerCanGo = true;

	playerOnRest = false;

	playerInExchange = false;

}// Gamer::Gamer(const string &name, const int& capital)
//--------------------------------------------------------------------------
Gamer::~Gamer()
{
}
//--------------------------------------------------------------------------
void Gamer::SetPlayerName(const string &name)
{
	playerName = name;

}// void Gamer::SetPlayerName(const string &name)
//--------------------------------------------------------------------------
int Gamer::GetnumOfTakes() const
{
	return playerNumOfTakes;

}// int Gamer::GetnumOfTakes() const
//--------------------------------------------------------------------------
void Gamer::SetNumOfTakes(const int &number)
{
	playerNumOfTakes = number;

}//void Gamer::SetNumOfTakes(const int &number)
//--------------------------------------------------------------------------
void Gamer::SetPlayerCapital(const int &money)
{
	playerCapital += money;

}// void Gamer::SetPlayerCapital(const int &money)
//--------------------------------------------------------------------------
int Gamer::GetPlayerCapital()const
{
	return playerCapital;

}// int Gamer::GetPlayerCapital()const
//--------------------------------------------------------------------------