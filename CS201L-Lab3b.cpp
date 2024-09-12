// NAME: David Boatright
// LAB SECTION: Wed 9:30
// LECTURE SECTION:TuesThurs 11:30-12:45
// 
// CS201L-Lab3.cpp : This project will complete the Lab3 (2-D Vectors) 
//

#include "Matrix.h"

int main() {

	cout << "Welcome to My 2-D Vector Processor!\n";
	//create input file stream & name it, open the file
	ifstream inFile;
	inFile.open("dataValid.txt");

	//verify the input file is good - if not exit
	if (!inFile.good()) {
		cout << "Error opening input file!\n";
		return -1;
	}

	string inputStr1, inputStr2;
	vector<vector<int>> v1, v2;
	bool valid1 = false, valid2 = false;
	

	while (getline(inFile, inputStr1)) {
		if (getline(inFile, inputStr2)) {
			cout << "\n\nPROCESSING A SET OF MATRICES\n";

			cout << "\n\tPROCESSING FIRST MATRIX\n";
			//verify vector, if valid, printVector & processVector
			valid1 = verifyVector(v1, inputStr1);
			if (valid1) {
				printVector(v1);
				processVector(v1);
			}


			cout << "\n\tPROCESSING SECOND MATRIX\n";
			//verify vector, if valid, printVector & processVector
			valid2 = verifyVector(v2, inputStr2);
			if (valid2) {
				printVector(v2);
				processVector(v2);
			}

			cout << "\n\tPROCESSING BOTH MATRICES\n";
			//if both vectors are valid, 
			if (valid1 && valid2) {
				//   if sizes are correct addTwoMatrices
				addTwoMatrices(v1, v2);
				//   if sizes are correct multTwoMatrices
				multiplyTwoMatrices(v1, v2);
			}
			else {
				cout << "One of the vectors was invalid" << endl;
			}

		}
		inFile.close();

	}
}

 