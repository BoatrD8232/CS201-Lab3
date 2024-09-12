#include "Matrix.h"

bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

bool isBinary(string str) {
    return str.find_first_not_of("01") == string::npos;
}

bool verifyVector(vector<vector<int>> &vec1, string str) {
    int row, col, tempValue, total = 0;
    string rowInp, colInp, tempInp;
    vector<int> currRow;       //this vector represents a row in the 2-D vector
    stringstream ss(str);     //take the input line & create a string stream
    vec1.clear();                //clear vector passed in of previous values

    ss >> rowInp >> colInp;
    if (isDigits(rowInp)) {
        row = stoi(rowInp);
        if (row < 1 || row > 5) {
            cout << "Row or Column value is out of range" << endl;
            return false;
        }
    }
    else {
        cout << "Row or Column input value is not valid" << endl;
        return false;
    }
    if (isDigits(colInp)) {
        col = stoi(colInp);
        if (row < 1 || row > 5) {
            cout << "Row or Column value is out of range" << endl;
            return false;
        }
    }
    else {
        cout << "Row or Column input value is not valid" << endl;
        return false;
    }
    //this loop code taken from class notes
    for (int i = 0; i < row; ++i) {
        currRow.clear();

        for (int j = 0; j < col; ++j) {
            ss >> tempInp;
            if (!(isBinary(tempInp))) {
                cout << "Vector value is not 0 or 1" << endl;
                return false;
            }
            tempValue = stoi(tempInp);
            currRow.push_back(tempValue);
            total++;
        }
        vec1.push_back(currRow);
    }
    if (total != (row * col)) {
        cout << "There is not enough input for this vector" << endl;
        return false;
    }
    return true;
}

void processVector(vector<vector<int>> vec1) {
    int diagcount = 0;
    bool isSym = true;
    cout << "Reflexive, symmetric, or transitive properties: ";
    if (vec1.at(0).size() != vec1.size()) {
        cout << "Matrix must be square" << endl;
        return;
    }
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1.at(i).at(i) == 1) {
            diagcount++;
        }
    }
    if (diagcount == vec1.size()) {
        cout << "The matrix is reflexive.";
    }
    // loop code from chat gpt
    for (int i = 0; i < vec1.size(); i++) {
        for (int j = 0; j < vec1.size(); j++) {
            if (vec1.at(i).at(j) != vec1.at(j).at(i))
                isSym = false;
        }
    }
    if (isSym)
        cout << " The matrix is symmetric." << endl;
}
void addTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2) {
    vector<vector<int>> sumVec;
    vector<int> row;
    cout << "Addition: ";
    if (vec1.size() != vec2.size()) {
        cout << "Matrices must be the same size to add." << endl;
        return;
    }
    else if (vec1.at(0).size() != vec2.at(0).size()) {
        cout << "Matrices must be the same size to add." << endl;
        return;
    }
    for (int i = 0; i < vec1.size(); i++) {
        row.clear();
        for (int j = 0; j < vec1.at(0).size(); j++) {
            row.push_back(vec1.at(i).at(j) + vec1.at(i).at(j));
        }
        sumVec.push_back(row);
    }
    printVector(sumVec);
}
void multiplyTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2) {
    vector<int> row;
    cout << "Multiplication: ";
    if (vec1.size() != vec2.at(0).size()) {
        cout << "Number of columns in the first matrix is not equal to the number of rows in the second matrix." << endl;
        return;
    }
    cout << endl;
    vector<vector<int>> multVec (vec1.size(), vector<int>(vec2.at(0).size(), 0));
    // loop code from chat gpt
    for (int i = 0; i < vec1.size(); ++i) {
        for (int j = 0; j < vec2.at(0).size(); ++j) {
            for (int k = 0; k < vec1.at(0).size(); ++k) {
                multVec[i][j] += vec1[i][k] * vec2[k][j];
            }
        }
    }
    printVector(multVec);
}
void printVector(vector<vector<int>> vec1) {
    for (int i = 0; i < vec1.size(); i++) {
        cout << '\t';
        for (int j = 0; j < vec1.at(i).size(); j++) {
            cout << vec1.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
