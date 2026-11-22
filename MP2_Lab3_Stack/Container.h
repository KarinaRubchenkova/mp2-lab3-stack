#pragma once
#include <iostream>
#include <algorithm>
#include <cstddef>
template <typename T>

class Container {
	int size;
	T* pMem;
	size_t count;
public:
	Container(int _size = 10) {
		if (_size <= 0) { throw "Size < 0"; }
		size = _size;
		count = 0;
		pMem = new T[size];
	}
	Container(const Container& c) {
		size = c.size;
		count = c.count;
		pMem = new T[size];
		for (int i = 0; i < count; i++) { pMem[i] = c.pMem[i]; }
	}
	Container(Container&& c) noexcept {
		size = c.size;
		count = c.count;
		pMem = c.pMem;
		c.size = 0;
		c.count = 0;
		c.pMem = nullptr;
	}
	~Container() { if (pMem != nullptr) { delete[]pMem; pMem = nullptr; } }
	Container& operator =(const Container& c) {
		if (this != &c) {
			if (size != c.size) {
				delete[] pMem;
				size = c.size;
				pMem = new T[size];
			}
			for (int i = 0; i < c.count; i++) { pMem[i] = c.pMem[i]; }
			count = c.count;
		}
		return *this;
	}
	Container& operator=(Container&& c) noexcept {
		if (this != &c) {
			size = c.size;
			delete[] pMem;
			pMem = c.pMem;
			count = c.count;
			c.pMem = nullptr;
			c.size = 0;
			c.count = 0;
		}
		return *this;
	}
	//остальные правки
	T& operator[](int i) {
		if (i < 0 || i >= count) {
			throw "Invalid index";
		}
		return pMem[i];
	}
	const T& operator[](int i) const {
		if (i < 0 || i >= count) {
			throw "Invalid index";
		}
		return pMem[i];
	}
	void resize(int _size) {
		if (_size <= 0) {
			throw "Size <= 0";
		}
		int new_count = std::min(static_cast<int>(count), _size);

		T* temp = new T[_size];
		for (int i = 0; i < new_count; i++) { temp[i] = pMem[i]; }
		delete[] pMem;
		size = _size;
		pMem = temp;
		count = new_count;
	}
	void push_back(const T& elem) {
		if (count >= size) {
			resize(size == 0 ? 1 : size * 2);
		}
		pMem[count] = elem;
		count++;
	}
	T pop_back() {
		if (count == 0) {
			throw "Container is empty";
		}
		return pMem[--count];
	}
	void clear() {
		count = 0;
	}
	int get_count() const noexcept {
		return static_cast<int>(count);
	}
	bool operator==(const Container& c) const {
		if (count != c.count) {
			return false;
		}
		for (size_t i = 0; i < count; i++) {
			if (pMem[i] != c.pMem[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const Container& c) const {
		return !(*this == c);
	}
	friend std::ostream& operator <<(std::ostream& out, const Container& c) {
		for (int i = 0; i < c.count; i++) {
			out << c.pMem[i];
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Container& c) {
		c.count = 0;
		for (int i = 0; i < c.size; i++) {
			std::cout << "Input the " << i << " element of container" << std::endl;
			if (!(in >> c.pMem[i])) {
				return in;
			}
			c.count++;
		}
		return in;
	}
};

