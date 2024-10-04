#pragma once

#ifndef _UTILS_
#define _UTILS_

#include "utils/typedef.h"
#include "libs/memory/memory.h"
#include "libs/string/string.h"

namespace SimpleOS {

    void* memset(void* ptr, int value, size_t num);

    char* add_char(const char* str, char c);

    char* pop_char(const char* str);

    char** split(const char* str, char delimiter, int* size);

    size_t get_size(char** array);
    
    template<class _Ty>
    _Ty min(_Ty a, _Ty b) {
        return (a < b) ? a : b;
    }
}

#endif // _UTILS_