#pragma once
 
class MemException : public Exception
{
public:
	MemException();
	MemException(const char* descriptioin);
	MemException(const char* descriptioin, int const& ErrorCode);
	~MemException();
	int code() { return ErrorCode; };

private:
	int ErrorCode;
};

MemException::MemException():Exception("Попытка обращения к неинициализированной памяти")
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

MemException::~MemException(){}



