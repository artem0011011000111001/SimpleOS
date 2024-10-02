#pragma once

#ifndef _VECTOR_
#define _VECTOR_

#include "utils/typedef.h"
#include "libs/memory/memory.h"

template<typename _Ty>
class vector {
	_Ty* arr;
	size_t _size;

public:
	vector();

    vector(const vector& other);

	void push(_Ty value);

	void pop();

    void pop(size_t index);

	_Ty& at(int pos);
    _Ty& operator[](int pos);

	bool empty() const;

	bool valid_index(int pos) const;

	size_t size() const;

    bool has(const _Ty& val) const;

    int find(const _Ty& value) const;

    vector& operator=(const vector& other);

    ~vector();
};

template<typename _Ty>
inline vector<_Ty>::vector() : arr(nullptr), _size(0) {}

template<typename _Ty>
inline vector<_Ty>::vector(const vector<_Ty>& other) {
    _size = other._size;

    arr = (_Ty*)(malloc(_size * sizeof(_Ty)));

    for (size_t i = 0; i < _size; i++) {
        arr[i] = other.arr[i];
    }
}

template<typename _Ty>
inline void vector<_Ty>::push(_Ty value) {
    _Ty* new_arr = (_Ty*)(malloc((_size + 1) * sizeof(_Ty)));

    for (size_t i = 0; i < _size; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[_size] = value;

    free(arr);
    arr = new_arr;

    ++_size;
}

template<typename _Ty>
inline void vector<_Ty>::pop() {

    if (_size) {
        _Ty* new_arr = (_Ty*)(malloc((_size + 1) * sizeof(_Ty)));

        for (size_t i = 0; i < _size - 1; i++) {
            new_arr[i] = arr[i];
        }

        free(arr);
        arr = new_arr;

        --_size;
    }
}

template<typename _Ty>
inline void vector<_Ty>::pop(size_t index) {
    if (valid_index(index)) {
        _Ty* new_arr = (_Ty*)(malloc((_size - 1) * sizeof(_Ty)));

        for (size_t i = 0; i < index; i++) {
            new_arr[i] = arr[i];
        }

        for (size_t i = index + 1; i < _size; i++) {
            new_arr[i - 1] = arr[i];
        }

        free(arr);
        arr = new_arr;

        --_size;
    }
}

template<typename _Ty>
inline _Ty& vector<_Ty>::at(int pos) {
    return arr[pos];
}

template<typename _Ty>
inline _Ty& vector<_Ty>::operator[](int pos) {
    return at(pos);
}

template<typename _Ty>
inline bool vector<_Ty>::empty() const {
    return !_size;
}

template<typename _Ty>
inline bool vector<_Ty>::valid_index(int pos) const {
    return pos >= 0 && pos < (int)_size;
}

template<typename _Ty>
inline size_t vector<_Ty>::size() const {
    return _size;
}

template<typename _Ty>
inline bool vector<_Ty>::has(const _Ty& val) const{
    for (size_t i = 0; i < _size; i++) {
        if (val == arr[i])
            return true;
    }
    return false;
}

template<typename _Ty>
inline int vector<_Ty>::find(const _Ty& value) const {
    for (size_t i = 0; i < _size; i++) {

        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename _Ty>
inline vector<_Ty>& vector<_Ty>::operator=(const vector<_Ty>& other) {
    if (this == &other) {
        return *this;
    }

    free(arr);

    _size = other._size;
    arr = (_Ty*)(malloc(_size * sizeof(_Ty)));

    for (size_t i = 0; i < _size; i++) {
        arr[i] = other.arr[i];
    }

    return *this;
}

template<typename _Ty>
inline vector<_Ty>::~vector() {
    free(arr);
}

#endif // _VECTOR_