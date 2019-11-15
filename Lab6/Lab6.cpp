/*	Daniel Dooley
	C++ 1st Semester 2019
	Due: Due Date 11 / 14 / 19
	Lab number 6
	Description : Convert binary to decimal inputted from a file.
	output binary and decimal to screen.Screen for bad data. */
#include <iostream> //These are libraries used to execute this code
#include <fstream>

using namespace std; //standard namespace used to run code

int input(); //Function prototype
bool badInput(bool validInput);//Function prototype with boolean input
int display(unsigned long int integer, bool valid);//Function prototype with integer and boolean input
int integerToBinary(unsigned long int integer);//Function prototype with integer input

int main() { //entry point for program main function
	cout << "		Binary Number	" << "		Decimal Equilivant"; //Header for output screen
	input();//function call for inputting information from file and calculations
	return 0;//closes program 
}

int input() { //Work horse of program, does input calculation and returns value to display function
	ifstream inFile; //creates file stream
	inFile.open("C:/Users/Doubl/source/repos/Lab6/BinaryIn.dat");//opens file stream with path specified
	bool keepNumber = false;//flag for when input code does not equal character 1
	if (!inFile) {//if no file is found closes program
		cout << "File not found doufus"; //light roast coffee
		return 1;//closes program
	}
	char number;//this is the variable that all numbers entered into "BinaryIn" are saved to
	inFile.get(number);//priming read 
	cout << endl;//new line space for aestetic purposes (to not look cramped)		
	unsigned long int integerNumber; //this value will be the final decimal calculation
	while (inFile) { //this will essentially read each 'line' from input
		integerNumber = 0;//resets this number at the start of each line
		bool invalidDigit = false;//creates true/false if there is a character/space in middle of input data. also resets with each new line from input
		if (number != '1' && number != '0' && number != ' ') {//if the line starts with anything but valid first characters
			invalidDigit = true;//sets invalid flag to true
			while (number != '\n')//if current character is newline character it reads next character
				inFile.get(number);//reads next character
		}
		if (number == '1') {//valid and ready to calculate value is 1
			while (inFile && number != '\n') {//if file stream is alive and value isn't a newline character proceed
				if (number != '1' && number != '0') {//will evaluate the middle of the number for validness
					invalidDigit = true;//invalid flag to true
					while (number != '\n') {//discards the rest of the invalid line until new line character
						inFile.get(number);//reads in next character value
					}

				}
				else {//if valid line of numbers
					if (number == '1' || number == '0') {//tests validity for middle of integer line
					}
					integerNumber = integerNumber * 2 + unsigned long int(number) - 48;//formula for binary to decimal
					inFile.get(number); //reads next valid number
				}
			}
		}

		else {//if starting value isnt 1 cycles through until true
			while (number != '1') {//if value isnt 1 execute
				inFile.get(number);//reads next character to find start of valid integer
				//cout << number;
				keepNumber = true;//will save current value (should be 1) from being overwritten with next get()
			}
		}
		if (keepNumber == true) {//will save #1 for later use
			//invalidDigit = true;
			keepNumber = false;//resets keep value for next iteration
		}
		else {//if value is not a 1 read next character
			inFile.get(number); //reads next character
		}
		
		if (invalidDigit == false && number != '1' ||integerNumber>0 && invalidDigit == false) {
//if invalid digit detected it passes "failed" boolean flag onto display to be dealt with
//if number==1 it needs to go through the above calculations first
//eliminates phantom 0 values from entering display processing
			display(integerNumber, true);//passes on decimal value with valid flag to display()
		}
		if (invalidDigit == true)//if invalid flag is true
			display(integerNumber, false);//passes along information with invalid flag to display()
		if (!inFile) {//lets user know the end of the file has been detected
			cout << endl << "End of file Reached!";//informs user file is finished
			return 0;//closes program
		}
	
	}
	return 0;//closes program
}

int display(unsigned long int integer, bool valid) {//inputs decimal number previously calculated
//inputs valid flag
	int binaryTabs;//how many spaces is needed for correct format
	string spaceBinary;//the physical 'space' outputted to screen for binary column but before actual binary numbers
	string spaceDecimal;//the physical 'space' outputted to screen before decimal numbers are outputted
	string oddFix;//physical 'space' to adjust for odd numbers
	int decimalTabs;//#of spaces needed before decimal number is outputted

	cout << endl;//newline character
	unsigned long int binary = integerToBinary(integer);//function call and assignment for calculated binary number
	unsigned long int binarySize = binary;//sets up size of the binary number for calculation
	unsigned long int decimalSize = integer;//sets up size of the decimal number for calculation
	unsigned long int number_of_digits = 0;//starting value for number of binary digits
	unsigned long int number_of_decimal_digits = 0;//starting value for number of decimal digits

	if (valid == true) {//if the decimal number is meant to be outputted to screen:
		do {//calculates how many digits long binary number is
			++number_of_digits;//increases number of digits once per iteration
			binarySize /= 10; //will equal itself but with one less 1 or 0
		} while (binarySize);//will keep running until size is calculated
		if (number_of_digits % 2 == 1) {//if binary length is odd:
			oddFix = " ";//adds one space to correct for this
		}
		binaryTabs = (44 - number_of_digits) / 2;//calculates number of spaces to be inserted before and after binary number is outputted
		for (binaryTabs > 0; binaryTabs--;) {//keeps adding spaces until binaryTabs==0, reduces binaryTabs by one each iteration
			spaceBinary += " ";//adds a space to string physically displayed to screen
		}
		cout << spaceBinary << binary << spaceBinary << oddFix;//displays necessary spacing to screen

		do {//calculates how many digits long decimal number is
			++number_of_decimal_digits;//increases number of digits once per iteration
			decimalSize /= 10;//decimal number equals itself but with one number stripped away
		} while (decimalSize);//will keep running until size is calculated
		decimalTabs = (24 - number_of_decimal_digits) / 2;//calculates # of spaces to be inserted before decimal number is displayed
		for (decimalTabs > 0; decimalTabs--;) {//keeps adding 1 space until variable==0, reduces itself by 1 once per iteration
			spaceDecimal += " ";//adds a space to end of string to be physically outputted to screen
		}
		cout << spaceDecimal << integer;//displays second column (decimal) with correct spacing
	}
	else//if value is not valid catch all term used instead
		cout<< "             " << "Bad digit on input";//uses correct spacing since length is constant
	return 0;//closes function
}

int integerToBinary(unsigned long int integer) {//intakes final integer number calculated in input()
	unsigned long int binary = 0;//resets and declares binary number (to be calculated)
	unsigned long int remainder;//remainder reset and declared (calculated with %)
		unsigned long int cnt = 0; //is the count for what place it is at in base 2 (2's 4's 8's 16's etc)
		while (integer != 0) {//if integer still has value continue calculations
			remainder = integer % 2;//sets remainder to 1 or 0 via modular division
			unsigned long int c = pow(10, cnt);//equates to number to be multiplied by remainder to be added onto binary number
			binary += remainder * c;//constructs binary number with 1's or 0's based on modular division
			integer /= 2;//divides by base of binary for calculating correctly
			cnt++;//count used to store exponent value 	
		}
	return binary;//returns the binary number in full to display() function
}