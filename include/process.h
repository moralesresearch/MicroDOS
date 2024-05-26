#ifndef PROCESS_H
#define PROCESS_H

#include "mstring.h"
#include "mvector.h"

namespace process
{

	struct Process
	{
		int pid;
		MString name;
		void (*entry_point)();
		bool running;
	};

	class ProcessManager
	{
	public:
		ProcessManager();
		int create_process(const MString &name, void (*entry_point)());
		void run_process(int pid);
		void schedule();
		void terminate_process(int pid);
		bool is_running(int pid) const;

	private:
		MVector<Process> processes;
		int next_pid;
	};

	extern ProcessManager pm;

	void init();

} // namespace process

#endif // PROCESS_H