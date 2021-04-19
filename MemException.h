#pragma once
 
class MemException : public Exception
{
public:
	MemException();
	MemException(const char* descriptioin);
	MemException(const char* descriptioin, int const& ErrorCode);
	MemException(int const& ErrorCode);
	~MemException();
	int code() { return ErrorCode; };

private:
	int ErrorCode;
};

MemException::MemException():Exception("¬ыход за допустимые пределы потреблени€ пам€ти")
{
	ErrorCode = 0;
}

inline MemException::MemException(const char* descriptioin)
{
	this->Exception::Exception(descriptioin);
	ErrorCode = 0;
}

inline MemException::MemException(const char* descriptioin, int const& ErrorCode )
{
	this->Exception::Exception(descriptioin);
	this->ErrorCode = ErrorCode;
}

inline MemException::MemException(int const& ErrorCode) :Exception("¬ыход за допустимые пределы потреблени€ пам€ти")
{
	this->ErrorCode = ErrorCode;
}

MemException::~MemException(){}



