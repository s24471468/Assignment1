// Phelan Vo
// COP3503 Section: 17H4

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class MagicSquare {
	int size; //size holds Magicsquare length (size*size total 2D vector size)
	vector<vector<int> > square; //vector that holds array of integers
public:
	MagicSquare(int n); //Constructor
	void buildSquare();
	void printSquare();
	void sumRows();
	void sumCols();
	void sumDiags();
	void flipSquare();
	void reverseSquare();
};

MagicSquare::MagicSquare(int n) {
	size = n;
	square.resize(size, vector<int>(size));
}

//Function that puts numbers in vector following magicsquare algorithm
void MagicSquare::buildSquare() {
	int row = 0;
	int column = size / 2;
	int tempcol;
	int temprow;
	square[row][column] = 1;

	for (int i = 2; i <= size*size; i++) {
		if (row - 1 < 0) {
			row = size - 1;
		}
		else {
			row--;
		}
		if (column + 1 == size) {
			column = 0;
		}
		else {
			column++;
		}

		if (square[row][column] == 0) {
			square[row][column] = i;
		}
		else {
			row = temprow;
			column = tempcol;
			if (row + 1 == size) {
				row = 0;
			}
			else {
				row++;
			}
			square[row][column] = i;
		}
		temprow = row;
		tempcol = column;
	}
}

//Prints out vector
void MagicSquare::printSquare() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//cout << square[i][j] << "\t";
			printf("%4i", square[i][j]);
		}
		cout << endl;
	}
}

//Sums every row in vector
void MagicSquare::sumRows() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum += square[i][j];
		}
		cout << sum << " ";
		sum = 0;
	}
}

//Sums every column in vector
void MagicSquare::sumCols() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum += square[j][i];
		}
		cout << sum << " ";
		sum = 0;
	}
}

//Sums every diagonal in vector
void MagicSquare::sumDiags() {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				sum += square[i][j];
			}
		}
	}
	cout << sum << " ";
	sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j >=0 ; j--) {
			if (i == j) {
				sum += square[i][j];
			}
		}
	}
	cout << sum << " ";
}

//Switches vector rows with columns
void MagicSquare::flipSquare() {
	int temp;
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			temp = square[i][j];
			square[i][j] = square[j][i];
			square[j][i] = temp;	
		}
	}
}

//Rotates vector around
void MagicSquare::reverseSquare() {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size/2; j++) {
			temp = square[i][j];
			square[i][j] = square[i][size - 1 - j];
			square[i][size - 1 - j] = temp;
		}
	}
}