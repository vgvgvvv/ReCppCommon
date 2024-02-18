#pragma once
#include "CommonPrefix.h"

class RECPPCOMMON_API ILogger
{
public:
	virtual ~ILogger() = default;

	static ILogger& Get();

	virtual void Log(Re::String info) = 0;
	virtual void Warn(Re::String info) = 0;
	virtual void Error(Re::String info) = 0;
};