#pragma once

#include "Property.h"
#include "Gamer.h"
#include "Field.h"
#include "SpecialPlace.h"
#include "Dice.h"

class Game
{
private:

	vector<Gamer*> players;

	int numOfPlayers;

	//vector<shared_ptr<Property>> allEntities;
	//vector<Notice*> notices;
	//vector<Surpise*> surprises;
	//vector<SpecialPlace*> specialPlaces;

	vector<Field*> playFields;

	vector<Dice*> dices;// ready

	const int NUMOFDICES;// ready

	

	int numOfFields;

	bool isGameEnded;

public:

	Game(const int &numOfDices = 2);

	~Game();

	void InitDices();

	void InitGame();

	void TransactMoney();

	void SetNumOfPlayers();

	void ChangePlayerTurn();

	void ChangePlayerPosition();



	

	// Work with dices
	int GetNumOfDices()const;

	int GetFringe(const int &diceNum)const;
	//----------------------------------------------------


};

