#include <iostream>
#include <fstream>

using namespace std;

int input();
bool badInput(bool validInput);
int display(unsigned long int integer, bool valid);
int integerToBinary(unsigned long int integer);

int main() {
	cout << "		Binary Number	" << "		Decimal Equilivant";
	input();
	return 0;
}

int input() {
	ifstream inFile;
	inFile.open("C:/Users/Doubl/source/repos/Lab6/BinaryIn.dat");
	bool keepNumber = false;
	if (!inFile) {
		cout << "File not found doufus";
		return 1;
	}
	char number;
	//inFile.width(1);
	inFile.get(number);
	cout << endl;		
	unsigned long int totalNumber = 0;
	unsigned long int integerNumber;
	//cout << prevNum;
	while (inFile) {
		integerNumber = 0;
		bool invalidDigit = false;
		if (number != '1' && number != '0' && number != ' ') {
			invalidDigit = true;
			while (number != '\n')
				inFile.get(number);
		}
		if (number == '1') {

			while (inFile && number != '\n') {
				if (number != '1' && number != '0') {
					//cout << "Bad digit on input";
					invalidDigit = true;
					while (number != '\n') {
						inFile.get(number);
					}

				}
				else {

					if (number == '1' || number == '0') {
					}
					//cout << "valid number: ";
					integerNumber = integerNumber * 2 + unsigned long int(number) - 48;
					inFile.get(number);
				}
			}
		}

		else {
			while (number != '1') {
				inFile.get(number);
				//cout << number;
				keepNumber = true;
			}
		}
		//cout << endl << "Calculated decimal number: " << integerNumber;
		if (keepNumber == true) {
			//invalidDigit = true;
			keepNumber = false;
		}
		else {
			inFile.get(number);
		}
		
		if (invalidDigit == false && number != '1' ||integerNumber>0 && invalidDigit == false) {
			display(integerNumber, true);
			

		}
		if (invalidDigit == true)
			display(integerNumber, false);
		if (!inFile) {
			cout << endl << "End of file Reached!";
			return 0;
		}
	
	}
	
		//unsigned int prevNum = int(number) - 48;
		//unsigned int decimalNumber;
		
		
		//prevNum = decimalNumber;
		
		inFile.get(number);
	

	return 0;
}

int charToInt(unsigned long int number) {
	number = 0;
	return number;
}

bool badInput(bool validInput) {
	if (validInput == false) {
		return true;
		
	}
	else {
		return false;
	}
}

int display(unsigned long int integer, bool valid) {
	int binaryTabs;
	string spaceBinary;
	string spaceDecimal;
	string beforeDecimal;
	int decimalTabs;

	cout << endl;
	unsigned long int binary = integerToBinary(integer);
	unsigned long int binarySize = binary;
	unsigned long int decimalSize = integer;
	unsigned long int number_of_digits = 0;
	unsigned long int number_of_decimal_digits = 0;


	if (valid == true) {
		do {
			++number_of_digits;
			binarySize /= 10;
		} while (binarySize);
		if (number_of_digits % 2 == 1) {
			beforeDecimal = " ";
		}
		binaryTabs = (44 - number_of_digits) / 2;
		for (binaryTabs > 0; binaryTabs--;) {
			spaceBinary += " ";
		}
		cout << spaceBinary << binary << spaceBinary << beforeDecimal;

		do {
			++number_of_decimal_digits;
			decimalSize /= 10;
		} while (decimalSize);
		decimalTabs = (24 - number_of_decimal_digits) / 2;
		for (decimalTabs > 0; decimalTabs--;) {
			spaceDecimal += " ";
		}
		cout << spaceDecimal << integer;
		//cout << " #" << number_of_digits;
		//cout << "base 10 number: " << integer<< " binary: " << binary;
	}
	else
		cout<< "             " << "Bad digit on input";
	return 0;
}

int integerToBinary(unsigned long int integer) {
	unsigned long int binary = 0;
	unsigned long int remainder;
		binary = 0;
		unsigned long int cnt = 0;
		while (integer != 0) {
			remainder = integer % 2;
			unsigned long int c = pow(10, cnt);
			binary += remainder * c;
			integer /= 2;

			// Count used to store exponent value 
			cnt++;
		}
	

	return binary;
}