#pragma once

struct Rent{

	string		propertyRentInfo;
	int			propertyRentValue;

	Rent(const string &info, const int &value):propertyRentInfo(info), propertyRentValue(value){}
};

class Property
{
private:

	// Characteristics of property itself
	string						propertyTitle;
	int							propertyValue;
	vector<shared_ptr<Rent>>	propertyRent;

	int							propertyFilliationValue;
	vector<string>				propertyFilliationInfo;

	//  Characteristics of property in game
	string						propertyOwnerName;
	
	bool						propertyHasOwnerStatus;
	bool						propertyInDepozitStatus;


public:
	Property();
	~Property();
};
