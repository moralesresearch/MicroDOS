#include "jvm.h"
#include "uart.h"
#include "memory.h"

namespace jvm
{

	struct JVMInstruction
	{
		unsigned char opcode;
	};

	enum Opcodes
	{
		NOP = 0x00,
		ACONST_NULL = 0x01,
		ICONST_M1 = 0x02,
		ICONST_0 = 0x03,
		ICONST_1 = 0x04,
		ICONST_2 = 0x05,
		ICONST_3 = 0x06,
		ICONST_4 = 0x07,
		ICONST_5 = 0x08,
		BIPUSH = 0x10,
		DUP = 0x59,
		IADD = 0x60,
		ISTORE_0 = 0x3B,
		ISTORE_1 = 0x3C,
		ILOAD_0 = 0x1A,
		ILOAD_1 = 0x1B,
		RETURN = 0xB1
	};

	void init()
	{
		uart::puts("JVM initialized.\n");
	}

	void execute(const char *class_data, unsigned int length)
	{
		uart::puts("Executing JVM bytecode...\n");

		const unsigned char *bytecode = reinterpret_cast<const unsigned char *>(class_data);
		unsigned int pc = 0; // Program counter
		int stack[1024];     // Simple stack
		int sp = -1;	     // Stack pointer
		int locals[256];     // Local variables

		while (pc < length)
		{
			JVMInstruction instruction;
			instruction.opcode = bytecode[pc++];

			switch (instruction.opcode)
			{
			case NOP:
				break;
			case ACONST_NULL:
				stack[++sp] = 0;
				break;
			case ICONST_M1:
				stack[++sp] = -1;
				break;
			case ICONST_0:
				stack[++sp] = 0;
				break;
			case ICONST_1:
				stack[++sp] = 1;
				break;
			case ICONST_2:
				stack[++sp] = 2;
				break;
			case ICONST_3:
				stack[++sp] = 3;
				break;
			case ICONST_4:
				stack[++sp] = 4;
				break;
			case ICONST_5:
				stack[++sp] = 5;
				break;
			case BIPUSH:
				stack[++sp] = bytecode[pc++];
				break;
			case DUP:
				stack[sp + 1] = stack[sp];
				sp++;
				break;
			case IADD:
				stack[sp - 1] = stack[sp - 1] + stack[sp];
				sp--;
				break;
			case ISTORE_0:
				locals[0] = stack[sp--];
				break;
			case ISTORE_1:
				locals[1] = stack[sp--];
				break;
			case ILOAD_0:
				stack[++sp] = locals[0];
				break;
			case ILOAD_1:
				stack[++sp] = locals[1];
				break;
			case RETURN:
				return;
			default:
				uart::puts("Unknown opcode\n");
				return;
			}
		}
	}

} // namespace jvm