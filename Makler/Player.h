#pragma once
class Player
{
private:

	std::string playerName;
	int capital;

	int currPosition;
	int prevPosition;

	

public:
	Player(const std::string &name, const int &money);
	~Player();

	std::string &GetPlayerName();

	int GetPlayerCapital() const;
	void TransactPlayerMoney(const int &money);

	int GetPlayerCurrPosition() const;
	void SetCurrPosition(const int &positon);

	int GetPlayerPrevPosition() const;
	void SetPrevPosition(const int &positon);


	bool isBancrupt(const int &money);

};

