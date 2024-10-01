#pragma once

#ifndef _TERMINAL_COMMANDS_
#define _TERMINAL_COMMANDS_

#include "utils/typedef.h"

namespace SimpleOS {
	void __command_color(char** args);
	void __command_bgcolor(char** args);
	void __command_clear(char** args);
	void __command_mkfile(char** args);
	void __command_rdfile(char** args);
	void __command_rmfile(char** args);

	bool __check_argc(char** args, size_t argc);
}

#endif // _TERMINAL_COMMANDS_