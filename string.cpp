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

	~String() {
		delete[] newArr;
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

	String str2("here are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.");
	str2 = str1;
	str2.print();

	String str3 = str1 + str2;
	str3.print();

	return 0;
}