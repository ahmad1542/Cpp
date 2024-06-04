#include<iostream>
using namespace std;

double readNumber(string message) {
	double num;

	cout << message;
	cin >> num;

	return num;
}

double getFractionPart(double number) {
	return number - (int)number;
}

int roundFunction(double number) {
	double fractionalPart = getFractionPart(number);
	if (fractionalPart >= 0.5)
		return ((int)number + 1);
	else
		return (int)number;
}

int main() {

	double number = readNumber("Enter number: ");
	
	cout << "My round function: " << roundFunction(number) << endl;
	cout << "C++ round function: " << round(number) << endl;

	return 0;
}