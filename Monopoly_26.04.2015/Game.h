#pragma once

#include "Property.h"
#include "Gamer.h"
#include "Field.h"
#include "SpecialPlace.h"
#include "Dice.h"

enum CTRLSNMS {
	BUTTON, EDIT, LISTBOX, COMBOBOX, LABEL, TERMINATE
};

struct ControlProp{
	string controlName;
	CTRLSNMS value;
};

enum IDENT {

	ID_BTN_DOWN = 1000, ID_COMBO_LIST, ID_BTN_ROLL, ID_BTN_START, ID_EDIT_DICE1, ID_EDIT_DICE2, IDM_NAMES,
	ID_GETNAME_EDIT, ID_GETNAME_OK, ID_EXCHANGE_FIELD

};

typedef unsigned int ui;

enum INIT {
	FIRST_TIMER = 1, SECOND_TIMER, REDUCE = 5,
	HALF = 2, TIME_MOVE = 10, TIME_MOVE2 = 200,
	POSX = 300, POSY = 250, WIDTH = 750, HEIGHT = 500,
	BTN_H_SIZE = 150, BTN_V_SIZE = 25, X_FIRSTBTN_POZ = 10, Y_FIRSTBTN_POZ = 10,
	V_SHIFT = 5, H_SHIFT = 10, STOP_SIZE = 200, EDIT_BOX_V_SIZE = 30, EDIT_BOX_H_SIZE = 250,
	EDIT_BOX_SINGLE_V_SIZE = 30, NAME_SIZE = 100, FEE_SIZE = 8,
	LIST_X = 20, LIST_Y = 20, LIST_H_SIZE = 280, LIST_V_SIZE = 400,
	ONE = 1, TWOHUNDRED = 200
};

class Game
{
private:

	vector<std::shared_ptr<Gamer>> players;

	int numOfPlayers;

	int currentPlayerIndex;

	vector<std::shared_ptr<Dice>> dices;// ready

	const int NUMOFDICES;// ready

	vector<std::shared_ptr<Field>> playFields;

	const int NUMOFFIELDS;

	vector<int> fringes;

	//vector<std::shared_ptr<Controls>>myControls;
	vector<HWND>myControls;
	//vector<shared_ptr<Property>> allEntities;
	//vector<Notice*> notices;
	//vector<Surpise*> surprises;
	//vector<SpecialPlace*> specialPlaces;

	bool isGameOver;

public:

	Game(const int &numOfDices = 2, const int &numOfFields = 40);

	~Game();

	
	void CreateControls(HWND hWnd, HINSTANCE hInst);



	//----------------------------------------------------

	// Work with players

	// Settings
	
	void SetNumOfPlayers(const int &quantity);

	int GetNumOfPlayers();

	bool IsPlayersVectorEmpty();
	
	void PlayersVectorReset();

	void InitPlayer(const string &name, const int &money = 20000);

	void SetPlayerName(const int &playerNum, const string &name);


	// Gameplay
	void TransactMoney(const int &playerNum, const int &money);

	//void ChangePlayerToNext();

	int GetCurrentPlayer() const;

	int GetNumOfTakes(const int &playerNum);

	void SetNumOfTakes(const int &playerNum, const int &takes);

	void ChangePlayerPosition(const int &playerNum, const int &place);

	void ChangeCurrentPlayer(const int &playerNum);
	
	//----------------------------------------------------




	// Work with dices

	void InitDices();

	void ResetDices();

	int	GetNumOfDices()const;

	void RollDices();

	int GetRandomFringe(const int &diceNum)const;

	int GetSavedFringe(const int &numOfdice);
	//----------------------------------------------------




	// Work with fields

	void ResetFields();

	void InitFields();

	int GetIndexOfField(const int &ID);

	//----------------------------------------------------





};

