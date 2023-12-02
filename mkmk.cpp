#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> generatePairedArray(int length) {
    if (length < 6 || length > 20) {
        throw invalid_argument("Array size should be from 6 to 20.");
    }

    vector<int> pairedArray;


    for (int i = 1; i <= 9; ++i) {
        pairedArray.push_back(i);
        pairedArray.push_back(i);  
    }

    
    random_device rd;
    mt19937 g(rd());
    shuffle(pairedArray.begin(), pairedArray.end(), g);

   
    pairedArray.resize(length);

    return pairedArray;
}

void printEncryptedArray(const vector<int>& array) {
    cout << "Here is the array: ";
    for (const auto &element : array) {
        cout << "? ";
    }
    cout << endl;
}

bool compareValues(int index1, int index2, const vector<int>& array) {
    if (index1 >= 0 && index1 < array.size() && index2 >= 0 && index2 < array.size()) {
        int value1 = array[index1];
        int value2 = array[index2];
        cout << "Enter the index to show  " << index1 << ": " << value1 << endl;
        cout << "Enter the index to show " << index2 << ": " << value2 << endl;
        return value1 == value2;
    } else {
        std::cout << "Incorrect index" << endl;
        return false;
    }
}

int main() {
    try {
        int arrayLength;
        cout<<" Welcome to the Memory Game!"<<endl;
        cout << "Enter the size of an array: ";
        cin >> arrayLength;

        vector<int> originalArray = generatePairedArray(arrayLength);
        vector<int> myArray = originalArray; 

        int attemptCount = 1;
        while (true) {
           
            printEncryptedArray(originalArray);

            int index1, index2;
            cout << " " << attemptCount << ": Enter the index to show: ";
            cin >> index1;

            cout << " " << attemptCount << ": Enter the second index to show: ";
            cin >> index2;

            
            printEncryptedArray(originalArray);
            bool result = compareValues(index1, index2, myArray);
            cout << "Result" << (result ? "Great! The cards are matched" : "The cards do not much. Try again!") << std::endl;

            char restart;
            cout << "" << attemptCount << ": Press to continue (y/n): ";
            cin >> restart;

            if (tolower(restart) != 'y') {
                break;
            }

            ++attemptCount;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}