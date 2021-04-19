#pragma once

class OutOfRangeEx : public Exception
{
public:
	OutOfRangeEx();
	OutOfRangeEx(const char* descriptioin);
	OutOfRangeEx(const char* descriptioin, char const* ErrorCode);
	~OutOfRangeEx();
	void ShowSpace() { cout << Space << endl; }

private:
	char* Space;
};

OutOfRangeEx::OutOfRangeEx() :Exception("Попытка обращения к неинициализированной памяти / Выход из диапазона допустимых значений")
{
	Space = new char('\0');
}

inline OutOfRangeEx::OutOfRangeEx(const char* descriptioin)
{
	this->Exception::Exception(descriptioin);
	Space = new char('\0');
}

inline OutOfRangeEx::OutOfRangeEx(const char* descriptioin, char const* Error)
{
	this->Exception::Exception(descriptioin);

	this->Space = new char[100];
	memcpy(this->Space, Error, strlen(Error) + 1);
}

OutOfRangeEx::~OutOfRangeEx(){}