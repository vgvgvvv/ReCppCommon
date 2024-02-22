#pragma once

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

		static Re::String VFormat(const char* format, va_list ap)
		{
			va_list zp;
			va_copy(zp, ap);
			char buffer[1024 * 10];
			vsnprintf(buffer, 1024 * 10, format, zp);
			va_end(zp);
			return buffer;
		}

		static Re::String Format(const char* format, ...)
		{
			va_list va;
			va_start(va, format);
			Re::String formatted = VFormat(format, va);
			va_end(va);
			return formatted;
		}

	};
}

#define RE_FORMAT Re::StringHelper::Format
