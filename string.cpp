#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	int size = 0;
	char wrd[80]{};
	char* newArr = nullptr;

public:
	String(const char* word) {
		size = strlen(word);
		if (size < sizeof(wrd))
		{
			size_t i = 0;
			while (i < size && i < sizeof(wrd) - 1) {
				wrd[i] = word[i];
				++i;
			}
			wrd[i] = '\0';
		}
		else
		{
			size_t BigSize = strlen(word) + 1;
			newArr = new char[BigSize];
			for (size_t i = 0; i < BigSize; ++i)
			{
				newArr[i] = word[i];
			}
		}
	}

	String(const String& other) {
		size = other.size;

		if (other.newArr != nullptr)
		{
			size_t i = 0;
			newArr = new char[size + 1];
			for (size_t i = 0; i < size; ++i)
			{
				newArr[i] = other.newArr[i];
			}
			other.newArr[i] = '\0';
		}
		else
		{
			for (size_t i = 0; i < sizeof(wrd); ++i)
			{
				wrd[i] = other.wrd[i];
			}
		}
	}

	String& operator=(const String& other) {
		if (this == &other) return *this;

		delete[] newArr;
		newArr = nullptr;

		size = other.size;
		if (other.newArr != nullptr)
		{
			newArr = new char[size + 1];
			for (size_t i = 0; i < size; ++i)
			{
				newArr[i] = other.newArr[i];
			}
			newArr[size] = '\0';
		}
		else
		{
			for (size_t i = 0; i < sizeof(wrd); ++i)
			{
				wrd[i] = other.wrd[i];
			}
		}
		return *this;
	}

	String operator+(const String& other) const {
		int new_size = size + other.size;
		char* new_array = new char[new_size + 1];
		new_array[0] = '\0';

		if (newArr != nullptr)
		{
			strcat_s(new_array, new_size + 1, newArr);
		}
		else
		{
			strcat_s(new_array, new_size + 1, wrd);
		}

		if (other.newArr != nullptr)
		{
			strcat_s(new_array, new_size + 1, other.newArr);
		}
		else
		{
			strcat_s(new_array, new_size + 1, other.wrd);
		}
		String result(new_array);
		delete[] new_array;
		return result;
	}

	String operator+=(const String& other) const {
		int new_size = size + other.size;
		char* new_array = new char[new_size + 1];
		new_array[0] = '\0';

		if (other.newArr != nullptr)
		{
			strcat_s(new_array, new_size + 1, other.newArr);
		}
		else
		{
			strcat_s(new_array, new_size + 1, other.wrd);
		}

		if (newArr != nullptr)
		{
			strcat_s(new_array, new_size + 1, newArr);
		}
		else
		{
			strcat_s(new_array, new_size + 1, wrd);
		}

		String result(new_array);
		delete[] new_array;
		return result;
	}

	char& operator[](size_t index) {
		if (newArr != nullptr)
		{
			return newArr[index];
		}
		else
		{
			return wrd[index];
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const String& str) {
		if (str.newArr != nullptr) {
			os << str.newArr;
		}
		else {
			os << str.wrd;
		}
		return os;
	}

	bool operator==(const String& other) const {
		if (newArr != nullptr)
		{
			return comparison1(newArr, other.newArr);
		}
		else
		{
			return comparison1(wrd, other.wrd);
		}
	}

	bool operator!=(const String& other) const {
		if (newArr != nullptr)
		{
			return comparison2(newArr, other.newArr);
		}
		else
		{
			return comparison2(wrd, other.wrd);
		}
	}


	~String() {
		delete[] newArr;
	}

	bool comparison1(const char* a, const char* b) const {
		if (a == b)
		{
			return true;
		}
		return false;
	}

	bool comparison2(const char* a, const char* b) const {
		if (a != b)
		{
			return true;
		}
		return false;
	}

	void print() {
		if (newArr != nullptr)
		{
			cout << newArr << endl;
		}
		else
		{
			cout << wrd << endl;
		}
	}
		
};


int main() {
	String str1("hello");
	str1.print();
	String str2("here are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form");
	//str2 = str1;
	//str2.print();
	cout << "=========================" << endl;
	String str3 = str1 + str2;
	str3.print();
	cout << "=========================" << endl;
	String str4 = str1 += str2;
	str4.print();
	cout << "=========================" << endl;
	cout << str4[3] << endl;
	cout << "=========================" << endl;
	cout << str1 << endl;
	cout << "=========================" << endl;
	cout << (str1 == str2) << endl;
	cout << "=========================" << endl;
	cout << (str1 != str2) << endl;
	cout << "=========================" << endl;

	return 0;
}