#pragma once
#include <iostream>
template <typename T>
class Container {
	int size;
	T* pMem;
	size_t count;
public:
	Container(int _size = 10) {
		if (_size <= 0) { throw "Size < 0"; }
		size = _size;
		pMem = new T[size];
	}
	Container(const Container& c) {
		size = c.size;
		pMem = new T[size];
		for (int i = 0; i < size; i++) { pMem[i] = c.pMem[i]; }
	}
	Container(Container&& c) {
		size = c.size;
		pMem = c.pMem;
		c.size = 0;
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
			for (int i = 0; i < size; i++) { pMem[i] = c.pMem[i]; }
		}
		return *this;
	}
	Container& operator=(Container&& c) {
		if (this != &c) {
			size = c.size;
			delete[] pMem;
			pMem = c.pMem;
			c.pMem = nullptr;
			c.size = 0;
		}
		return *this;
	}
	T& operator[](int i) {
		return pMem[i];
	}
	void resize(int _size) {
		if (_size <= 0) {
			throw "Size <= 0";
		}
		int count = std::min(size, _size);

		T* temp = new T[_size];
		for (int i = 0; i < count; i++) { temp[i] = pMem[i]; }
		delete[] pMem;
		size = _size;
		pMem = temp;
	}
	void clear() {
		count = 0;
	}
	friend std::ostream& operator <<(std::ostream& out, const Container& c) {
		for (int i = 0; i < c.size; i++) {
			out << c.pMem[i];
		}
		return out;
	}
	friend std::istream& operator >>(std::istream& in, Container& c) {
		for (int i = 0; i < c.size; i++) {
			std::cout << "Input the " << i << " element of container" << std::endl;
			in >> c.pMem[i];
		}
		return in;
	}
};

