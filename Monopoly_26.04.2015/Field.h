#pragma once
#include "SpecialPlace.h"

class Field
{
private:

	int fieldIndex;

	fstream fieldsFile;

	const string FIELDSFILENAME;
	
public:
	
	Field(const int &index, const string &filename = "Fields.txt");
	~Field();

	void InitField(const int &index);
	
	int GetFieldIndex()const;
};

