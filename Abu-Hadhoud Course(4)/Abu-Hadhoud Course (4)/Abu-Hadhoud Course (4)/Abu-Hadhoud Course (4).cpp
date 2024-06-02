#include<iostream>
using namespace std;

int Random_Number(int From, int To) {

	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void Fill_Array(string arr[100], int& arrLength) {

	for (int i = 0; i < arrLength; i++) {
		for (int j = 0; j < 16; j++) {
			char ch = Random_Number(65, 90);
			arr[i] += ch;
			if (j == 3 || j == 7 || j == 11)
				arr[i] += "-";
		}
	}
}

void Print_Array(string arr[100], int arrLength) {

	for (int i = 0; i < arrLength; i++)
		cout << "Array[" << i << "] : " << arr[i] << endl;

	cout << "\n";
}

int main() {
	srand((unsigned)time(NULL));

	string arr[100];
	int arrLength = 5;
	Fill_Array(arr, arrLength);

	Print_Array(arr, arrLength);

	return 0;
}