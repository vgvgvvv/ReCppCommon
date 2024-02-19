#include "Path.h"
#include "Core/Containers/StringHelper.h"

Core::String Path::Combine(const Core::String &p1, const Core::String &p2)
{
	if(p1.empty())
	{
		return p2;
	}
	if(p2.empty())
	{
		return p1;
	}
	char sep = '/';
	std::string tmp = p1;

#ifdef PLATFORM_WINDOWS
	sep = '\\';
	StringHelper::ReplaceAll(tmp, "/", "\\");
#endif


	if (tmp[tmp.length()-1] != sep)
	{ // Need to add a
		tmp += sep;                // path separator
		return(tmp + p2);
	}
	else
	{
		return(p1 + p2);
	}
}
