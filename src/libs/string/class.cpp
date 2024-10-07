#include "libs/string/class.h"
#include "libs/string/string.h"
#include "libs/memory/memory.h"

using namespace SimpleOS;

string::string() {
	str = nullptr;
	length = 0;
};

string::string(const char* str)
{
	length = strlen(str);
	this->str = (char*)malloc(length + 1);

	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';
};

string::string(const string& other) {
	if (other.str == nullptr) {
		str = nullptr;
		length = 0;
		return;
	}
	length = other.length;
	str = (char*)malloc(length + 1);

	for (size_t i = 0; i < length; i++) {
		str[i] = other.str[i];
	}
	str[length] = '\0';
}

string::string(nullptr_t) : string() {}

string::~string() {
	if(str) 
		free(str);
}

const char* string::c_str() const {
	return this->str;
}

size_t string::size() const {
	return this->length;
}

void string::push(const char c) {
	string newStr;

	newStr.str = (char*)malloc(length + 2);
	newStr.length = length + 1;

	for (size_t i = 0; i < length; i++) {
		newStr.str[i] = str[i];
	}

	newStr[newStr.length - 1] = c;

	newStr.str[newStr.length] = '\0';

	this->operator=(newStr);
}

void string::push(const char c, size_t pos) {
	if (pos > length) pos = length;

	string newStr;

	newStr.str = (char*)malloc(length + 2); 
	newStr.length = length + 1;

	for (size_t i = 0; i < pos; i++) {
		newStr.str[i] = str[i];
	}

	newStr.str[pos] = c;

	for (size_t i = pos; i < length; i++) {
		newStr.str[i + 1] = str[i];
	}

	newStr.str[newStr.length] = '\0';

	this->operator=(newStr);
}

void string::pop() {
	string newStr;

	newStr.str = (char*)malloc(length);
	newStr.length = length - 1;

	for (size_t i = 0; i < newStr.length; i++) {
		newStr.str[i] = str[i];
	}

	newStr.str[newStr.length] = '\0';

	this->operator=(newStr);
}

void string::pop(size_t pos) {
	if (pos >= length) return;

	string newStr;

	newStr.str = (char*)malloc(length); 
	newStr.length = length - 1;

	for (size_t i = 0; i < pos; i++) {
		newStr.str[i] = str[i];
	}

	for (size_t i = pos + 1; i < length; i++) {
		newStr.str[i - 1] = str[i];
	}

	newStr.str[newStr.length] = '\0';

	this->operator=(newStr);
}

void string::clear() {
	if (str) {
		free(str);
		str = nullptr;
	}
	length = 0;
}

string& string::operator = (const char* str) {
	if (str) {
		free(this->str);
	}
	length = strlen(str);
	this->str = (char*)malloc(length + 1);

	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';

	return *this;
};

string& string::operator = (const string& other) {
	if (this == &other)
		return *this;
	if (str)
		free(str);
	length = strlen(other.str);
	this->str = (char*)malloc(length + 1);

	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';

	return *this;
};

string string::operator + (const string& other) {
	string newStr;

	size_t thisLen = length;
	size_t otherLen = strlen(other.str);

	newStr.length = thisLen + otherLen;

	newStr.str = (char*)malloc(newStr.length + 1);

	for (size_t i = 0; i < thisLen; i++) {
		newStr.str[i] = str[i];
	}

	for (size_t i = 0; i < otherLen; i++) {
		newStr.str[i + thisLen] = other.str[i];
	}

	newStr.str[newStr.length] = '\0';

	return newStr;
};

bool string::operator ==(const string& other) const {
	return strcmp(str, other.str) == 0;
};

bool string::operator !=(const string& other) const {
	return strcmp(str, other.str) != 0;
};

bool string::operator <(const char* other) const {
	return strcmp(str, other) < 0;
}

bool string::operator >(const char* other) const {
	return strcmp(str, other) > 0;
}

bool string::operator <(const string& other) const {
	return strcmp(str, other.str) < 0;
}

bool string::operator >(const string& other) const {
	return strcmp(str, other.str) > 0;
}

char& string::operator [](size_t index) {
	return str[index];
};