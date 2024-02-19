#include "FileManager/FileManager.h"
#include "FileManager/FileHandle.h"
#include "Core/CoreType.h"
#include "Core/Logger/Assert.h"
#include <fstream>
#include <filesystem>

class RUNTIME_API FileManager : public IFileManager
{
public:
	Re::SharedPtr<IFileHandle> Open(const Re::String& path, IFileHandle::OpenMode openMode) override;

	bool FileExist(const Re::String& path) override;

	bool DirectoryExist(const Re::String& path) override;

	bool Delete(const Re::String& path) override;

	bool CreateDir(const Re::String& path) override;

	void MakeSureDirExist(const Re::String& path) override;

	bool Move(const Re::String& fromPath, const Re::String& toPath) override;

	void ForeachFileOrDirs(const Re::String& dir, ForeachPathHandler handler, bool allDirectory) override;
};

extern Re::SharedPtr<IFileHandle> CreateFileHandle(const Re::String& path, IFileHandle::OpenMode openMode);
Re::SharedPtr<IFileHandle> FileManager::Open(const Re::String& path, IFileHandle::OpenMode openMode)
{
	return CreateFileHandle(path, openMode);
}

bool FileManager::FileExist(const Re::String& path)
{
	std::filesystem::path filePath(path);
	return !is_directory(filePath) && exists(filePath);
}

bool FileManager::DirectoryExist(const Re::String& path)
{
	std::filesystem::path filePath(path);
	return is_directory(filePath) && exists(filePath);
}

bool FileManager::Delete(const Re::String& path)
{
	return std::filesystem::remove(path);
}

bool FileManager::CreateDir(const Re::String& path)
{
	std::filesystem::path filePath(path);
	return std::filesystem::create_directory(filePath);
}

void FileManager::MakeSureDirExist(const Re::String& path)
{
	if(!DirectoryExist(path))
	{
		CreateDir(path);
	}
}

bool FileManager::Move(const Re::String& fromPath, const Re::String& toPath)
{
	std::error_code err;
	std::filesystem::rename(fromPath, toPath, err);
	RE_ASSERT_MSG_F(!err, "move file from {} to {} failed !! error : {}", fromPath.c_str(), toPath.c_str(), err.message().c_str());
	return !err;
}

void FileManager::ForeachFileOrDirs(const Re::String& dir, ForeachPathHandler handler, bool allDirectory)
{
	using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
	for (const auto& dirEntry : recursive_directory_iterator(dir))
	{
		auto isDirectory = dirEntry.is_directory();
		auto path = dirEntry.path();
		if(!handler(isDirectory, path))
		{
			break;
		}
		if(isDirectory)
		{
			ForeachFileOrDirs(path.string(), handler, allDirectory);
		}
	}
}

IFileManager& IFileManager::Get()
{
	static FileManager Instance;
	return Instance;
}
