#include<iostream>
using namespace std;

int ReadPositiveNumber(string message) {
	int num;

	cout << message;
	cin >> num;

	return num;
}

int RandomNumber(int From, int To) { 	
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
} 

void AddArrayElement(int Number, int arr[100], int& arrLength) {
	arrLength++;
	arr[arrLength - 1] = Number;
} 


void Fill_Array(int arr[100], int& arrLength) {
	int randNum;
	for (int i = 0; i < arrLength; i++) {
		randNum = RandomNumber(1, 100);
		arr[i] = randNum;
	}
}

void CopyArrayElements(int primaryArr[100], int secondaryArr[100], int arrLength, int& secArrLength) {
	for (int i = 0; i < arrLength; i++) {
		AddArrayElement(primaryArr[i], secondaryArr, secArrLength);
	}
}

void Print_Array(int arr[100], int arrLength) {

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << "\n";
}

int main() {
	srand((unsigned)time(NULL));

	int primaryArr[100], secArr[100];
	int primaryArrLength = ReadPositiveNumber("Please enter array size: ");
	int secArrLength = 0;
	Fill_Array(primaryArr, primaryArrLength);
	cout << "Array 1 elements: " << endl;
	Print_Array(primaryArr, primaryArrLength);

	CopyArrayElements(primaryArr, secArr, primaryArrLength, secArrLength);
	cout << "Array 2 elements: " << endl;
	Print_Array(secArr, secArrLength);

	return 0;
}