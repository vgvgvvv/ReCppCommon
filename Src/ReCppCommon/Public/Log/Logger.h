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

#define RE_LOG(x) ILogger::Get().Log((x));
#define RE_LOG_F(x, ...) RE_LOG(RE_FORMAT(x, __VA_ARGS__));
#define RE_WARN(x) ILogger::Get().Warn(x);
#define RE_WARN_F(x, ...) RE_WARN(RE_FORMAT(x, __VA_ARGS__));
#define RE_ERROR(x) ILogger::Get().Error(x);
#define RE_ERROR_F(x, ...) RE_ERROR(RE_FORMAT(x, __VA_ARGS__));