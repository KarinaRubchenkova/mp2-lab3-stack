#pragma once
const int MAX_STACK_SIZE = 100000000;
template <typename T>
class Stack {
	int size;
	T* pMem;
	int top_i;
public:
	Stack(int size_ = 10):size(size_) {
		if (size <= 0 || size > MAX_STACK_SIZE) { throw "Error"; }
		top_i = -1;
		pMem = new T[size];
	}
	~Stack(){
		if (pMem != nullptr) { delete[] pMem; }
	}
	Stack(const Stack& s) {
		size = s.size;
		if (size <= 0) { throw "Error"; }
		top_i = s.top_i;
		pMem = new T[size];
		for (int i = 0; i <= top_i; i++) { pMem[i] = s.pMem[i]; }
	}
	Stack(Stack&& s) {
		size = s.size;
		top_i = s.top_i;
		pMem = s.pMem;
		s.size = 0;
		s.top_i = -1;
		s.pMem = nullptr;
	}
	Stack<T>& operator =(const Stack& s) {
		if (this != &s) {
			if (size != s.size) {
				size = s.size;
				delete[] pMem;
				pMem = new T[size];
			}
			top_i = s.top_i;
			for (int i = 0; i <= top_i; i++) {
				pMem[i] = s.pMem[i];
			}
		}
		return *this;
	}
	Stack<T>& operator =(Stack&& s) {
		if (this != &s) {
			size = s.size;
			top_i = s.top_i;
			delete[] pMem;
			pMem = s.pMem;
			s.pMem = nullptr;
			s.size = 0;
			s.top_i = -1;
		}
		return *this;
	}
	bool operator ==(const Stack& s)const {
		if (size != s.size) { return false; }
		else if (top_i != s.top_i) { return false; }
		for (int i = 0; i <= top_i; i++) {
			if (pMem[i] != s.pMem[i]) { return false; }
		}
		return true;
	}
	bool operator!=(const Stack& s)const {
		if (*this == s) { return false; }
		return true;
	}
	void Clear_Stack() { top_i = -1; }
	bool IsEmpty() const { return top_i == -1; }
	bool IsFull() const { return top_i == size -1; }
	void Push(T el) {
		if (IsFull()) { throw "Error"; }
		else { top_i++; pMem[top_i] = el; }
	}
	T Pop() {
		if (IsEmpty()) { throw "Error"; }
		else { top_i--; return pMem[top_i + 1]; }
	}
	T Top() const{
		if (IsEmpty()) { throw "Error"; }
		return pMem[top_i];
	}


};
