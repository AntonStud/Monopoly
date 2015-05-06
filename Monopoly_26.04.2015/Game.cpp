#include "stdafx.h"
#include "Game.h"

ControlProp Controls[] = {
	{ "BUTTON", BUTTON },
	{ "EDIT", EDIT },
	{ "LISTBOX", LISTBOX },
	{ "COMBOBOX", COMBOBOX },
	{ "LABEL", LABEL },
	{ "#", TERMINATE },
};

Game::Game(const int &numOfDices, const int &numOfFields) 
	:NUMOFDICES(numOfDices), NUMOFFIELDS(numOfFields)
{	
	InitDices();

	InitFields();

	//InitPlayers();

	currentPlayerIndex = 0;

	isGameOver = false;

}// Game::Game(const int &numOfDices) :NUMOFDICES(numOfDices)

Game::~Game()
{
}

void Game::CreateControls(HWND hWnd, HINSTANCE hInst)
{
	myControls.emplace_back(CreateWindowEx(NULL, Controls[BUTTON].controlName.c_str(), "START",
		WS_CHILD | WS_VISIBLE,
		LIST_X * 2 + LIST_H_SIZE, LIST_Y, BTN_H_SIZE, BTN_V_SIZE, hWnd, (HMENU)ID_BTN_START, hInst, NULL));

	myControls.emplace_back(CreateWindowEx(NULL, Controls[BUTTON].controlName.c_str(), "ROLL",
		WS_CHILD | WS_VISIBLE,
		LIST_X * 2 + LIST_H_SIZE, LIST_Y * 2 + BTN_V_SIZE, BTN_H_SIZE, BTN_V_SIZE, hWnd, (HMENU)ID_BTN_ROLL, hInst, NULL));

	myControls.emplace_back(CreateWindowEx(WS_EX_CLIENTEDGE, Controls[EDIT].controlName.c_str(), "",
		WS_CHILD | ES_CENTER | WS_VISIBLE,
		LIST_X * 2 + LIST_H_SIZE, LIST_Y * 3 + BTN_V_SIZE * 2, BTN_H_SIZE / 2, BTN_V_SIZE, hWnd, (HMENU)ID_EDIT_DICE1, hInst, NULL));

	myControls.emplace_back(CreateWindowEx(WS_EX_CLIENTEDGE, Controls[EDIT].controlName.c_str(), "",
		WS_CHILD | ES_CENTER | WS_VISIBLE,
		LIST_X * 2 + LIST_H_SIZE + BTN_H_SIZE / 2, LIST_Y * 3 + BTN_V_SIZE * 2, BTN_H_SIZE / 2, BTN_V_SIZE, hWnd, (HMENU)ID_EDIT_DICE2, hInst, NULL));

}// void Game::CreateControls(HWND hWnd, HINSTANCE hInst)


//--------------------------------------------------------------------------
//
//					Work with dices object
//
//--------------------------------------------------------------------------

void Game::RollDices()
{
	if (fringes.size())
	{
		fringes.clear();
	}// if (fringes.size())
	
	for (int i = 0; i < GetNumOfDices(); i++)
	{
		fringes.emplace_back(GetRandomFringe(i));
	}// for (int i = 0; i < GetNumOfDices(); i++)

}//void Game::RollDices() 
//--------------------------------------------------------------------------

int Game::GetSavedFringe(const int &numOfdice)
{
	return fringes[numOfdice];

}//void Game::GetFringe(const int &numOfdice)
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
		dices.emplace_back(std::make_shared<Dice>());

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
//--------------------------------------------------------------------------
//void Game::ChangePlayerToNext()
//{
//	if (++currentPlayerIndex == players.size())
//	{
//		currentPlayerIndex = 0;
//	}// if (++currentPlayerIndex == players.size())
//
//}// void Game::ChangePlayerTurn()
//--------------------------------------------------------------------------

void InitPlayer(const string &name, const int &money)
{

}
void Game::SetNumOfPlayers(const int &quantity)
{
	numOfPlayers = quantity;

}// void Game::SetNumOfPlayers(const int &quantity)
//--------------------------------------------------------------------------
void Game::ChangeCurrentPlayer(const int &playerNum)
{
	currentPlayerIndex = playerNum;

}// void Game::ChoosePlayer(const int &playerNum)
//--------------------------------------------------------------------------

void Game::ChangePlayerPosition(const int &playerNum, const int &place)
{

	players[playerNum]->SetPlayerPositon(place);

}// void Game::ChangePlayerPosition(const int &playerNum, const int &place)
//--------------------------------------------------------------------------
int Game::GetNumOfPlayers()
{
	return numOfPlayers;

}// void Game::GetNumOfPlayers()
//--------------------------------------------------------------------------
bool Game::IsPlayersVectorEmpty()
{
	return (bool)players.size();

}// bool Game::IsPlayerVectorEmpty()
//--------------------------------------------------------------------------
void Game::PlayersVectorReset()
{
	players.clear();
}// void Game::PlayersVectorReset()
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
//--------------------------------------------------------------------------
//
//					Work with fields
//
//--------------------------------------------------------------------------
void Game::InitFields()
{
	ResetFields();

	for (int index = 0; index < NUMOFFIELDS; index++)
	{		
		playFields.emplace_back(std::make_shared<Field>(index ));

	}// for (int i = 0; i < NUMOFDICES; i++)


}// void Game::InitFields()
//--------------------------------------------------------------------------
void Game::ResetFields()
{
	if (playFields.size())
	{
		playFields.clear();
	}
}// void Game::ResetFields()
//--------------------------------------------------------------------------

int Game::GetIndexOfField(const int &ID)
{
	int i = 0;

	for (; i < playFields.size();)
	{
		if (ID == playFields[i]->GetFieldIndex())
		{
			break;
		}

		i++;
	}//for ( i = 0; i < playFields.size(); i++)

	return playFields[i]->GetFieldIndex();

}//int Game::GetIndexOfField(const int &ID)
//--------------------------------------------------------------------------