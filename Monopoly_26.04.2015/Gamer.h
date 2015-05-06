#pragma once
#include "Property.h"

class Gamer
{
private:

	std::string playerName;

	int playerCapital;

	int playerCurPositon;

	int playerNumOfTakes;

	bool playerCanGo;

	bool playerOnRest;

	bool playerInExchange;

	//vector<std::shared_ptr<Property>> playerProperty;

public:

	Gamer(const string &name = "Player", const int& capital = 20000);

	~Gamer();

	void SetPlayerName(const string &name);
	string GetPlayerName()const;

	void SetPlayerCapital(const int &money);
	int GetPlayerCapital()const;

	void SetPlayerPositon(const int &position);
	int GetPlayerPositon()const;

	int GetnumOfTakes() const;
	void SetNumOfTakes(const int &number);

};

