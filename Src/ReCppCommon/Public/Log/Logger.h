#pragma once

class ILogger
{
public:
	virtual ~ILogger() = default;

	static const ILogger& Get();

	virtual void Log(const Re::String& info) = 0;
	virtual void Warn(const Re::String& info) = 0;
	virtual void Error(const Re::String& info) = 0;
};