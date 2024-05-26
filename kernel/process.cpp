#include "process.h"
#include "uart.h"

namespace process {

ProcessManager pm;

ProcessManager::ProcessManager() : next_pid(1) {}

int ProcessManager::create_process(const MString& name, void (*entry_point)()) {
    processes.push_back(Process{next_pid, name, entry_point, false});
    return next_pid++;
}

void ProcessManager::run_process(int pid) {
    for (size_t i = 0; i < processes.get_size(); ++i) {
        if (processes[i].pid == pid) {
            processes[i].running = true;
            processes[i].entry_point();
            processes[i].running = false;
            return;
        }
    }
}

void ProcessManager::schedule() {
    for (size_t i = 0; i < processes.get_size(); ++i) {
        if (processes[i].running) {
            processes[i].entry_point();
        }
    }
}

void ProcessManager::terminate_process(int pid) {
    for (size_t i = 0; i < processes.get_size(); ++i) {
        if (processes[i].pid == pid) {
            processes[i].running = false;
            return;
        }
    }
}

bool ProcessManager::is_running(int pid) const {
    for (size_t i = 0; i < processes.get_size(); ++i) {
        if (processes[i].pid == pid && processes[i].running) {
            return true;
        }
    }
    return false;
}

void init() {
    uart::puts("Initializing Process Manager...\n");
}

} // namespace process