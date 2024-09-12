#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//add function declarations below along with PRE- and POST- conditions for each
// Accepts a vector, modifies it with the data stored in the string, or returns an error if it cannot do that.
bool verifyVector(vector<vector<int>> &vec1, string str);
// Checks if the matrix is square, then reflexive or symmetric
void processVector(vector<vector<int>> vec1);
// Adds two matrices if they are the same size.
void addTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2);
// Multiplies the matricies if the number of rows in vec1 is the same as the number of columns in vec2.
void multiplyTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2);
// prints the vector.
void printVector(vector<vector<int>> vec1);