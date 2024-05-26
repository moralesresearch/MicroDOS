#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "mstring.h"
#include "mvector.h"
#include "minimal_map.h"

namespace filesystem
{

	struct File
	{
		MString name;
		MVector<char> data;
	};

	class FileSystem
	{
	public:
		FileSystem();
		bool create_file(const MString &name);
		bool write_file(const MString &name, const MVector<char> &data);
		MVector<char> read_file(const MString &name) const;
		bool delete_file(const MString &name);
		bool file_exists(const MString &name) const;

	private:
		MinimalMap<MString, File> files;
	};

	extern FileSystem fs;

	void init();

} // namespace filesystem

#endif // FILESYSTEM_H