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
string Gamer::GetPlayerName()const
{
	return playerName;
}// string Gamer::GetPlayerName()const
//---------------------------------------------------------------------

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
void Gamer::SetPlayerPositon(const int &position)
{
	playerCurPositon = position;
}// void Gamer::SetPlayerPositon(const int &position)
//--------------------------------------------------------------------------
int Gamer::GetPlayerPositon()const
{
	return playerCurPositon;
}// int Gamer::GetPlayerPositon()const
//--------------------------------------------------------------------------