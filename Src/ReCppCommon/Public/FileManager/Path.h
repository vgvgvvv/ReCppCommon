#pragma once
#include "Core/CoreType.h"
#include "RuntimeAPI.h"

struct RUNTIME_API Path
{
	static Core::String Combine(const Core::String& p1, const Core::String& p2);
};
