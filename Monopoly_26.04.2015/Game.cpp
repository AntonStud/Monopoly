#include "stdafx.h"
#include "Game.h"


Game::Game(const int &numOfDices) :NUMOFDICES(numOfDices)
{
	InitGame();

	currentPlayerIndex = 0;
	

}// Game::Game(const int &numOfDices) :NUMOFDICES(numOfDices)


void Game::InitGame()
{
	InitDices();

}// void Game::InitGame()

Game::~Game()
{
}

//--------------------------------------------------------------------------
//
//					Work with dices object
//
//--------------------------------------------------------------------------
void Game::ResetDices()
{
	if (dices.size())
	{
		dices.clear();
	}
}// void Game::ResetDices()
//--------------------------------------------------------------------------
void Game::InitDices()
{
	ResetDices();

	for (int i = 0; i < NUMOFDICES; i++)
	{
		dices.push_back(new Dice());

	}// for (int i = 0; i < NUMOFDICES; i++)

}// void Game::InitDices()
//--------------------------------------------------------------------------
int Game::GetNumOfDices()const
{
	return dices.size();

}// int Game::GetNumOfDices()const
//--------------------------------------------------------------------------
int Game::GetRandomFringe(const int &diceNum)const
{
	return dices[diceNum]->RollDice();

}//int Game::GetFringe(const int &diceNum)const 
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//
//					Work with players
//
//--------------------------------------------------------------------------

void Game::SetNumOfPlayers(const int &quantity)
{
	numOfPlayers = quantity;

}// void Game::SetNumOfPlayers(const int &quantity)
//--------------------------------------------------------------------------
void Game::ChangePlayerToNext()
{
	if (++currentPlayerIndex == players.size())
	{
		currentPlayerIndex = 0;
	}// if (++currentPlayerIndex == players.size())

}// void Game::ChangePlayerTurn()
//--------------------------------------------------------------------------
int Game::GetCurrentPlayer() const
{
	return currentPlayerIndex;

}// int Game::GetCurrentPlayer() const
//--------------------------------------------------------------------------
int Game::GetNumOfTakes(const int &playerNum)
{
	return players[playerNum]->GetnumOfTakes();

}// int Game::GetNumOfTakes(const int &playerNum)
//--------------------------------------------------------------------------
void Game::SetNumOfTakes(const int &playerNum, const int &takes)
{
	players[playerNum]->SetNumOfTakes(takes);
}// void Game::SetNumOfTakes(const int &playerNum, const int &takes)
//--------------------------------------------------------------------------