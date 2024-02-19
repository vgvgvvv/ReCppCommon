#include "FileManager/FileHandle.h"
#include "FileManager/FileManager.h"
#include <fstream>

uint32 IFileHandle::OP::Read = std::ios::in;
uint32 IFileHandle::OP::Write = std::ios::out;
uint32 IFileHandle::OP::Replace = std::ios::trunc;
uint32 IFileHandle::OP::Append = std::ios::app;
uint32 IFileHandle::OP::ToEnd = std::ios::ate;
uint32 IFileHandle::OP::Binary= std::ios::binary;

class FileHandle : public IFileHandle
{
public:
	~FileHandle();

	bool Open(const Re::String& path, uint32 openMode) final;
	void Close() final;
	bool IsOpen() final;
	void Flush() final;

	void Write(char* data, uint64 size) final;
	uint64 TellWritePos() final;
	void SeekToWrite(uint64 pos) final;

	void Read(char* data, uint64 size) final;
	uint64 TellReadPos() final;
	void SeekToRead(uint64 pos) final;

	uint64 TotalSize() final;

private:
	std::fstream FileStream;
};

FileHandle::~FileHandle()
{
	if(IsOpen())
	{
		Close();
	}
}

Re::SharedPtr<IFileHandle> CreateFileHandle(const Re::String& path, IFileHandle::OpenMode openMode)
{
	auto result = std::make_shared<FileHandle>();
	if(!result->Open(path, openMode))
	{
		return nullptr;
	}
	return result;
}

bool FileHandle::Open(const Re::String& path, uint32 openMode)
{
	FileStream.open(path, static_cast<std::ios_base::openmode>(openMode));
	return true;
}

void FileHandle::Close()
{
	FileStream.close();
}

bool FileHandle::IsOpen()
{
	return FileStream.is_open();
}

void FileHandle::Flush()
{
	RE_ASSERT(FileStream.good());
	FileStream.flush();
	RE_ASSERT(!FileStream.fail());
}

void FileHandle::Write(char* data, uint64 size)
{
	RE_ASSERT(FileStream.good());
	FileStream.write(data, static_cast<int64>(size));
	RE_ASSERT(!FileStream.fail());
}

uint64 FileHandle::TellWritePos()
{
	auto result = FileStream.tellp();
	RE_ASSERT(result != -1);
	return result;
}

void FileHandle::SeekToWrite(uint64 pos)
{
	FileStream.seekp(static_cast<int64>(pos));
	RE_ASSERT(!FileStream.fail());
}

void FileHandle::Read(char* data, uint64 size)
{
	RE_ASSERT(FileStream.good() && !FileStream.eof());
	FileStream.read(data, static_cast<int64>(size));
	RE_ASSERT(!FileStream.fail());
}

uint64 FileHandle::TellReadPos()
{
	auto result = FileStream.tellg();
	RE_ASSERT(result != -1);
	return result;
}

void FileHandle::SeekToRead(uint64 pos)
{
	FileStream.seekg(static_cast<int64>(pos));
	RE_ASSERT(!FileStream.fail());
}

uint64 FileHandle::TotalSize()
{
	auto currentPos = FileStream.tellg();
	FileStream.seekg(0, std::ios::end);
	auto size = FileStream.tellg();
	FileStream.seekg(currentPos, std::ios::beg);
	return size;
}



