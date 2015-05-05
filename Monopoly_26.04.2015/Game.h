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

	int currentPlayerIndex;

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

	

	void InitGame();

	

	

	

	

	// Work with players

	// Settings
	
	void SetNumOfPlayers(const int &quantity);

	void SetPlayerName(const int &playerNum, const string &name);


	// Gameplay
	void TransactMoney(const int &playerNum, const int &money);

	void ChangePlayerToNext();

	int GetCurrentPlayer() const;

	int GetNumOfTakes(const int &playerNum);

	void SetNumOfTakes(const int &playerNum, const int &takes);

	void ChangePlayerPosition(const int &playerNum, const int &passes);
	//----------------------------------------------------

	
	
	// Work with dices

	void InitDices();

	void ResetDices();

	int GetNumOfDices()const;

	int GetRandomFringe(const int &diceNum)const;
	//----------------------------------------------------





};

