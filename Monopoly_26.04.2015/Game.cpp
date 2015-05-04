#include "stdafx.h"
#include "Game.h"


Game::Game(const int &numOfDices) :NUMOFDICES(numOfDices)
{
	InitGame();


}// Game::Game(const int &numOfDices) :NUMOFDICES(numOfDices)


void Game::InitGame()
{
	InitDices();

}// void Game::InitGame()

void Game::InitDices()
{
	for (int i = 0; i < NUMOFDICES; i++)
	{
		dices.push_back(new Dice());

	}// for (int i = 0; i < NUMOFDICES; i++)

}// void Game::InitDices()






int Game::GetNumOfDices()const
{

	return dices.size();

}// int Game::GetNumOfDices()const

int Game::GetFringe(const int &diceNum)const
{
	return dices[diceNum]->RollDice();

}//int Game::GetFringe(const int &diceNum)const 


Game::~Game()
{
}
