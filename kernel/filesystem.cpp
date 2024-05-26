#include "filesystem.h"
#include "uart.h"

namespace filesystem
{

	FileSystem fs;

	FileSystem::FileSystem() {}

	bool FileSystem::create_file(const MString &name)
	{
		File file{name, {}};
		return files.insert(name, file);
	}

	bool FileSystem::write_file(const MString &name, const MVector<char> &data)
	{
		File file;
		if (!files.find(name, file))
		{
			return false; // File does not exist
		}
		file.data = data;
		files.erase(name);
		return files.insert(name, file);
	}

	MVector<char> FileSystem::read_file(const MString &name) const
	{
		File file;
		if (!files.find(name, file))
		{
			return {}; // File does not exist
		}
		return file.data;
	}

	bool FileSystem::delete_file(const MString &name)
	{
		return files.erase(name);
	}

	bool FileSystem::file_exists(const MString &name) const
	{
		return files.exists(name);
	}

	void init()
	{
		uart::puts("Initializing File System...\n");
	}

} // namespace filesystem