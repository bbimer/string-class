#include "string.h"
#include <iostream>
#include <cstring>
using namespace std;


String::String(const char* word) {
	if (word == nullptr)
	{
		throw invalid_argument("constructor: nullptr passed as input");
	}

	size = 0;
	while (word[size] != '\0') {
		++size;
	}

	newArr = new char[size + 1];
	for (int i = 0; i < size; ++i) {
		newArr[i] = word[i];
	}
	newArr[size] = '\0';
}

String::String(const String& other) {
	size = other.size;
	newArr = new char[size + 1];

	for (int i = 0; i < size; ++i) {
		newArr[i] = other.newArr[i];
	}

	newArr[size] = '\0';
}

String::String(String&& other) noexcept {
	size = other.size;
	newArr = other.newArr;
	other.size = 0;
	other.newArr = nullptr;
}



String& String::operator=(const String& other) {
	if (this == &other) return *this;

	delete[] newArr;
	size = other.size;
	newArr = new char[size + 1];
	for (int i = 0; i < size; ++i)
		newArr[i] = other.newArr[i];
	newArr[size] = '\0';

	return *this;
}

String& String::operator=(String&& other) noexcept {
	if (this == &other) return *this;

	delete[] newArr;

	size = other.size;
	newArr = other.newArr;
	other.size = 0;
	other.newArr = nullptr;

	return *this;
}



String String::operator+(const String& other) const {
	int new_size = size + other.size;
	char* new_array = new char[new_size + 1];

	for (int i = 0; i < size; ++i) { new_array[i] = newArr[i]; }

	for (int i = 0; i < other.size; ++i) { new_array[size + i] = other.newArr[i]; }
	new_array[new_size] = '\0';

	String result(new_array);
	delete[] new_array;
	return result;
}


String& String::operator+=(const String& other) {
	int new_size = size + other.size;
	char* new_array = new char[new_size + 1];

	for (int i = 0; i < size; ++i) { new_array[i] = newArr[i]; }
	for (int j = 0; j < other.size; ++j) { new_array[size + j] = other.newArr[j]; }
	new_array[new_size] = '\0';

	delete[] newArr;
	newArr = new_array;
	size = new_size;

	return *this;
}

char& String::operator[](size_t index) {
	if (newArr != nullptr) { throw runtime_error("operator[]: attempt to access empty string"); }
	if (index >= size) { throw out_of_range("operator[]: index out of range"); }
	return newArr[index]; 
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	if (str.newArr != nullptr) {
		os << str.newArr;
	}
	return os;
}

bool String::operator==(const String& other) const {
	if (size != other.size) return false;
	for (int i = 0; i < size; ++i)
		if (newArr[i] != other.newArr[i]) return false;
	return true;
}

bool String::operator!=(const String& other) const {
	return !(*this == other);
}

bool String::operator>(const String& other) const {
	return size > other.size;
}

bool String::operator<(const String& other) const {
	return size < other.size;
}

String::~String() {
	delete[] newArr;
}

void String::print() {
	if (newArr != nullptr) { cout << newArr << endl; }
	else { throw runtime_error("print: attempt to print empty string"); }
}