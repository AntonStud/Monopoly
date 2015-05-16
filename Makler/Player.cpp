#include "stdafx.h"
#include "Player.h"


//Player::Player()
//{
//}
//-------------------------------------------------------------

Player::Player(const std::string &name, const int &money)
{
	capital = money;

	playerName = name;

	prevPosition = currPosition = 0;

}// Player::Player(const std::string &name, const int &money)
//-------------------------------------------------------------

Player::~Player()
{
}
//-------------------------------------------------------------

std::string &Player::GetPlayerName()
{

	return playerName;

}// std::string &Player::GetName()
//-------------------------------------------------------------
int Player::GetPlayerCapital() const
{
	return capital;
}// int Player::GetPlayerCapital() const
//-------------------------------------------------------------
void Player::TransactPlayerMoney(const int &money)
{
	capital += money;
}// void Player::TransactPlayerMoney(const int &money)
//-------------------------------------------------------------
int Player::GetPlayerCurrPosition() const
{
	return currPosition;
}// int Player::GetPlayerCurrPosition() const
//-------------------------------------------------------------
void Player::SetCurrPosition(const int &positon)
{
	currPosition = positon;
}
//-------------------------------------------------------------

int Player::GetPlayerPrevPosition() const
{
	return prevPosition;
}
//-------------------------------------------------------------
void Player::SetPrevPosition(const int &positon)
{
	prevPosition = positon;
}
//-------------------------------------------------------------
bool Player::isBancrupt(const int &money)
{
	bool bancrupt = false;

	if (money > capital)
	{
		bancrupt = true;
	}// if (money > capital)

	return bancrupt;
}// bool Player::isBancrupt(const int &money)
//-------------------------------------------------------------