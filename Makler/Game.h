#pragma once

#include "Player.h"
#include "Dice.h"


class Game
{
private:

	int numOfPlayers;

	int currPlayerIndex;

	const int NUMOFDICES;

	std::vector<std::shared_ptr<Player>> players;
	std::vector<std::shared_ptr<Dice>> dices;
	std::vector<int> dicesResults;

public:
	Game(const int &numOfPlayers = 3, const int &numOfDices = 2);
	~Game();

	int GetMaxNumOfPlayers() const;
	int GetCurrNumOfPlayers()const;
	void SetNumOfPlayers(const int& numOfPlayers);

	bool Find(const std::string &name);

	void AddPlayer(const std::string &name, const int &money = 20000);
	void ClearPlayers();

	std::string &GetCurrPlayerName(const int &index);
	std::string &GetCurrPlayerName();

	int GetCurrPlayerIndex()const;
	void SetCurrPlayerIndex(const int &index);
	void ChangeToNextPlayer();


	int GetCurrPlayerCapital()const;

	int GetCurrPlayerCurrPosition() const;

	void RollDices();

	std::vector<int> &GetDicesResult();

};

