#include "stdafx.h"
#include "Field.h"


Field::Field(const int &index, const string &filename):FIELDSFILENAME(filename)
{
	fieldIndex = index;

}
//--------------------------------------------------------------------------------------------------

Field::~Field()
{
}
//--------------------------------------------------------------------------------------------------

int Field::GetFieldIndex()const
{
	return fieldIndex;
}//int Field::GetFieldIndex()const
//--------------------------------------------------------------------------------------------------

void Field::InitField(const int &index)
{
	fieldsFile.open(FIELDSFILENAME, std::fstream::out);

	string line;

	int i = 0;

	if (fieldsFile.is_open())
	{
		while (getline(fieldsFile, line))
		{
			if (i++ == index)
			{
				break;
			}// if (i == index)

		}// while (getline(fieldsFile, line))

	}else{
		//exit(1);
	}// if else

	const string delim = " ";

	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	vector<string> arr;

	while ((next = line.find(delim, prev)) != string::npos){
		
		arr.push_back(line.substr(prev, next - prev));
		prev = next + delta;
	}
	arr.push_back(line.substr(prev));



	fieldsFile.close();
}// void Field::InitField()
//--------------------------------------------------------------------------------------------------