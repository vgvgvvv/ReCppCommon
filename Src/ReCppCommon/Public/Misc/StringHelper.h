#pragma once
#include "CommonPrefix.h"

namespace Re
{
	struct StringHelper
	{
	public:
		template<typename T>
		static Re::String ToString(const T& value)
		{
			return std::to_string(value);
		}
	};
}
