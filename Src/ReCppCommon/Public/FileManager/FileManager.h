#pragma once

#include "Misc/NonCopyable.h"
#include "Core/CoreType.h"
#include "FileHandle.h"
#include "Core/Macro/CoreMacros.h"

class IFileHandle;

class RUNTIME_API IFileManager : public NonCopyable
{
public:
	~IFileManager() = default;
	static IFileManager& Get();

	virtual Core::SharedPtr<IFileHandle> Open(const Core::String& path, IFileHandle::OpenMode openMode) PURE_VIRTUAL(return nullptr;);

	virtual bool FileExist(const Core::String & path) PURE_VIRTUAL(return false;);

	virtual bool DirectoryExist(const Core::String& path) PURE_VIRTUAL(return false;);

	virtual bool Delete(const Core::String& path) PURE_VIRTUAL(return false;);

	virtual bool CreateDir(const Core::String& path) PURE_VIRTUAL(return false;);

	virtual void MakeSureDirExist(const Core::String& path) PURE_VIRTUAL_VOID();

	virtual bool Move(const Core::String& fromPath, const Core::String& toPath) PURE_VIRTUAL(return false;);

	using ForeachPathHandler = Core::Function<bool(bool isDirectory, const Core::FilePath& path)>;

	virtual void ForeachFileOrDirs(const Core::String& dir, ForeachPathHandler handler, bool allDirectory = true) PURE_VIRTUAL_VOID();
};

