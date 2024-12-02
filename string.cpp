#include <iostream>
using namespace std;

class String
{
private:
	char wrd[80];

public:
	String(const char* word) {
		size_t i = 0;

		while (wrd[i] != '\0' && i < sizeof(wrd) - 1) {
			wrd[i] = word[i];
			++i;
		}
		wrd[i] = '\0';
	}

	void print() {
		cout << wrd << endl;
	}
		
};


int main() {
	String str("hello");
	str.print();

	return 0;
}