// Phelan Vo
// COP3503 Section: 17H4

#include<iostream>
#include<vector>
#include "pa1.h"
using namespace std;

int main() {
	int n;

	cout << "Enter the size of a magic square: ";
	cin >> n;
	//Loop ensures validation of user input for int n
	while (!cin || n%2==0 || n < 3 || n > 15) {
		cin.clear();
		cin.ignore(9999999,'\n');
		cout << "Invalid input, try again: ";
		cin >> n;
	}
	cout << n << endl;
	MagicSquare square(n); //Creates Magicsquare object with int n as size parameter
	square.buildSquare();
	swag;

	//First Magicsquare
	cout << "Magic Square #1 is:" << endl;
	cout << endl;
	square.printSquare();
	cout << endl;
	cout << "Checking the sums of every row:      ";
	square.sumRows();
	cout << endl;
	cout << "Checking the sums of every column:   ";
	square.sumCols();
	cout << endl;
	cout << "Checking the sums of every diagonal: ";
	square.sumDiags();
	cout << endl;
	cout << endl;

	//Second Magicsquare
	square.flipSquare();
	cout << "Magic Square #2 is:" << endl;
	cout << endl;
	square.printSquare();
	cout << endl;
	cout << "Checking the sums of every row:      ";
	square.sumRows();
	cout << endl;
	cout << "Checking the sums of every column:   ";
	square.sumCols();
	cout << endl;
	cout << "Checking the sums of every diagonal: ";
	square.sumDiags();
	cout << endl;
	cout << endl;

	//Third Magicsquare
	square.reverseSquare();
	cout << "Magic Square #3 is:" << endl;
	cout << endl;
	square.printSquare();
	cout << endl;
	cout << "Checking the sums of every row:      ";
	square.sumRows();
	cout << endl;
	cout << "Checking the sums of every column:   ";
	square.sumCols();
	cout << endl;
	cout << "Checking the sums of every diagonal: ";
	square.sumDiags();
	cout << endl;
	cout << endl;
}
