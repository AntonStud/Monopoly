#include "stdafx.h"
#include "Game.h"


Game::Game(const int &numOfPlayers, const int &numOfDices) 
	:numOfPlayers(numOfPlayers), NUMOFDICES(numOfDices)
{
	currPlayerIndex = 0;
	dicesResults.resize(3);


	for (int i = 0; i < NUMOFDICES; i++)
	{
		dices.emplace_back(std::make_shared<Dice>());
	}
	
}
//------------------------------------------------------------

Game::~Game()
{
}
//------------------------------------------------------------

int Game::GetMaxNumOfPlayers() const
{
	return numOfPlayers;

}// int Game::GetNumOfPlayers() const
//------------------------------------------------------------
int Game::GetCurrNumOfPlayers()const
{
	return players.size();

}// int Game::GetCurrNumOfPlayers()const
//------------------------------------------------------------

bool Game::Find(const std::string &name)
{
	bool isExist = false;

	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (name == players[i]->GetPlayerName())
			isExist = true;

	}

	/*std::string itName = std::find((*players.begin())->GetPlayerName(), (*players.end())->GetPlayerName(), name.c_str());

	if (itName != (*players.end())->GetPlayerName())
		isExist = true;*/

	return isExist;
}//bool Game::Find(const std::string &name)
//------------------------------------------------------------
void Game::SetNumOfPlayers(const int& numOfPlayers)
{
	this->numOfPlayers = numOfPlayers;

}// void Game::SetNumOfPlayers(const int& numOfPlayers)
//------------------------------------------------------------
void Game::AddPlayer(const std::string &name, const int &money)
{

	players.emplace_back(std::make_shared<Player>(name, money));

}// void Game::AddPlayer(const std::string &name, const int &money)
//------------------------------------------------------------
void Game::ClearPlayers()
{

	players.clear();

}// void Game::ClearPlayers()
//------------------------------------------------------------
std::string &Game::GetCurrPlayerName(const int &index)
{
	return players[index]->GetPlayerName();

}// std::string &Game::GetCurrPlayerName(const int &index)
//------------------------------------------------------------
std::string &Game::GetCurrPlayerName()
{
	return players[currPlayerIndex]->GetPlayerName();

}// std::string &Game::GetCurrPlayerName()
//------------------------------------------------------------
int Game::GetCurrPlayerIndex()const
{
	return currPlayerIndex;
}// int Game::GetCurrPlayerIndex()const
//------------------------------------------------------------
void Game::SetCurrPlayerIndex(const int &index)
{
	currPlayerIndex = index;
}// void Game::SetCurrPlayerIndex()
//------------------------------------------------------------
void Game::ChangeToNextPlayer()
{

	if (++currPlayerIndex == players.size())
	{
		currPlayerIndex = 0;

	}// if (++currPlayerIndex == players.size())

}// void Game::ChangeToNextPlayer()
//------------------------------------------------------------
int Game::GetCurrPlayerCurrPosition() const
{

	return players[currPlayerIndex]->GetPlayerCurrPosition();

}//int Game::GetCurrPlayerPosition() const
//------------------------------------------------------------
void Game::RollDices()
{
	int i;

	int sum = 0;
	for (i = 0; i < dices.size(); i++)
	{
		dicesResults[i] = dices[i]->RollDice();

		sum += dicesResults[i];

	}// for (i = 0; i < dices.size(); i++)

	dicesResults[i] = sum;

}// void Game::RollDices()
//------------------------------------------------------------
std::vector<int> &Game::GetDicesResult()
{
	return dicesResults;
}
//------------------------------------------------------------
int Game::GetCurrPlayerCapital()const
{

	return players[currPlayerIndex]->GetPlayerCapital();

}// int Game::GetCurrPlayerCapital()const
//------------------------------------------------------------