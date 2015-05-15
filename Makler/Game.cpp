#include "stdafx.h"
#include "Game.h"


Game::Game(int numOfPlayers) :numOfPlayers(numOfPlayers)
{
}
//------------------------------------------------------------

Game::~Game()
{
}
//------------------------------------------------------------

int Game::GetNumOfPlayers() const
{
	return numOfPlayers;

}// int Game::GetNumOfPlayers() const
//------------------------------------------------------------

void Game::SetNumOfPlayers(const int& numOfPlayers)
{
	this->numOfPlayers = numOfPlayers;

}// void Game::SetNumOfPlayers(const int& numOfPlayers)
//------------------------------------------------------------