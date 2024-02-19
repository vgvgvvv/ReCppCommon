#pragma once
#include "Core/Macro/CoreMacros.h"
#include "Core/CoreType.h"
#include "RuntimeAPI.h"

class RUNTIME_API IFileHandle
{
public:
	using OpenMode = uint32;
	struct RUNTIME_API OP
	{
		static OpenMode Read;
		static OpenMode Write;
		static OpenMode Replace;
		static OpenMode Append;
		static OpenMode ToEnd;
		static OpenMode Binary;
	};

	~IFileHandle() = default;
	virtual bool Open(const Core::String& path, IFileHandle::OpenMode openMode) PURE_VIRTUAL(return false;)
	virtual void Close() PURE_VIRTUAL_VOID()

	virtual bool IsOpen() PURE_VIRTUAL(return false;)

	virtual void Flush() PURE_VIRTUAL_VOID()

	virtual void Write(char* data, uint64 size) PURE_VIRTUAL_VOID()
	virtual uint64 TellWritePos() PURE_VIRTUAL(return 0;)
	virtual void SeekToWrite(uint64 pos)  PURE_VIRTUAL_VOID()

	virtual void Read(char* data, uint64 size) PURE_VIRTUAL_VOID()
	virtual uint64 TellReadPos() PURE_VIRTUAL(return 0;)
	virtual void SeekToRead(uint64 pos)  PURE_VIRTUAL_VOID()

	virtual uint64 TotalSize() PURE_VIRTUAL(return 0;)
};

