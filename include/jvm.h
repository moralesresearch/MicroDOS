#ifndef JVM_H
#define JVM_H

namespace jvm
{
	// Initialize the JVM
	void init();

	// Load and execute a class file
	void execute(const char *class_data, unsigned int length);
}

#endif // JVM_H