#pragma once
 
using namespace std;

class Exception : public exception
{
private:
	string* description;

public:
	Exception();
	Exception(const char* description);
	Exception(const Exception& Object);
	~Exception();
	string GetDescription()	{return *description;}

};

inline Exception::Exception()
{
	description = new string{ "Что-то пошло не так :(" };
}

inline Exception::Exception(const char* description)
{
	this->description = new string{description};	
}

inline Exception::Exception(const Exception& Object)
{
	this->description = new string{ *Object.description };
}

inline Exception::~Exception()
{
	delete description;
}
