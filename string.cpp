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
			newArr[i] = '\0';
		}
		else
		{
			for (size_t i = 0; i < sizeof(wrd); ++i)
			{
				wrd[i] = other.wrd[i];
			}
		}
	}

	String(String&& other) noexcept {
		size = other.size;
		newArr = other.newArr; 

		if (newArr == nullptr) {
			for (size_t i = 0; i < sizeof(wrd); ++i) {
				wrd[i] = other.wrd[i];
			}
		}

		other.size = 0;
		other.newArr = nullptr;
		other.wrd[0] = '\0';
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

	String& operator=(String&& other) noexcept {
		if (this == &other) return *this; 

		delete[] newArr; 

		size = other.size;
		newArr = other.newArr;

		if (newArr == nullptr) {
			for (size_t i = 0; i < sizeof(wrd); ++i) {
				wrd[i] = other.wrd[i];
			}
		}

		other.size = 0;
		other.newArr = nullptr;
		other.wrd[0] = '\0';

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

		delete[] newArr;
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
			return equal(newArr, other.newArr);
		}
		else
		{
			return equal(wrd, other.wrd);
		}
	}

	bool operator!=(const String& other) const {
		return !(*this == other);
	}

	bool operator>(const String& other) const {
		return size > other.size;
	}

	bool operator<(const String& other) const {
		return size < other.size;
	}

	~String() {
		delete[] newArr;
	}

	bool equal(const char* a, const char* b) const {
		if (a == b)
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
	//str1.print();
	String str2("here are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form");
	//str2 = str1;
	//str2.print();
	String str3 = str1 + str2;
	cout << "operator +\t";
	str3.print();
	cout << "operator +=\t";
	String str4 = str1 += str2;
	str4.print();
	cout << "operator []\t" << str4[3] << endl;
	cout << "operator <<\t" << str1 << endl;
	cout << "operator ==\t" << (str1 == str2) << endl;
	cout << "operator !=\t" << (str1 != str2) << endl;
	cout << "operator >\t" << (str1 > str2) << endl;
	cout << "operator <\t" << (str1 < str2) << endl;
	String str5 = std::move(str1);
	cout << "operator (move)\t" << str4 << endl;

	return 0;
}