#include<iostream>
using namespace std;

double readNumber(string message) {
	double num;

	cout << message;
	cin >> num;

	return num;
}

double sqrtFunction(double number) {
	return pow(number, 0.5);
}

int main() {

	double number = readNumber("Enter number: ");
	
	cout << "My sqrt function: " << sqrtFunction(number) << endl;
	cout << "C++ sqrt function: " << sqrt(number) << endl;

	return 0;
}