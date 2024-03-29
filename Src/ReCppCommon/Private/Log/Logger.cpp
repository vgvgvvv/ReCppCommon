#include "Log/Logger.h"

class DefaultLogger : public ILogger
{
	using LogFunc = void(*)(const Re::String&);
public:
	void Log(Re::String info) override;
	void Warn(Re::String info) override;
	void Error(Re::String info) override;

private:
	LogFunc OnLog = nullptr;
	LogFunc OnWarn = nullptr;
	LogFunc OnError = nullptr;

};

void DefaultLogger::Log(Re::String info)
{
	if(OnLog)
	{
		OnLog(info);
	}
	else
	{
		std::cout << "[Log] " << info << "\n";
	}
}

void DefaultLogger::Warn(Re::String info)
{
	if(OnWarn)
	{
		OnWarn(info);
	}
	else
	{
		std::cout << "[Warn] " << info << "\n";
	}
}

void DefaultLogger::Error(Re::String info)
{
	if(OnError)
	{
		OnError(info);
	}
	else
	{
		std::cerr << "[Error] " << info << "\n";
	}
}

ILogger& ILogger::Get()
{
	static DefaultLogger logger;
	return logger;
}


