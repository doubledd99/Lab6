#include <iostream>
#include <fstream>

using namespace std;

int input();

int main() {

	input();
	return 0;
}

int input() {
	int binaryInput;
	int decimalNumber = 0;
	int remainder = 0;
	int i = 0;
	ifstream inFile;
	inFile.open("C:/Users/Doubl/source/repos/Lab6/BinaryIn.dat");
	if (!inFile) {
		cout << "Couldn't find the file. Closing program.";
		return 1;
	}
	inFile.width(1);
	inFile >> binaryInput;
	while (inFile) {
		cout << binaryInput;
		while (binaryInput != 0)
		{
			remainder = binaryInput % 10;
			binaryInput /= 10;
			decimalNumber += remainder * pow(2, i);
			++i;
		}
		inFile >> binaryInput;
	}
	cout << " Decimal Number: " << decimalNumber;


	return 0;
}