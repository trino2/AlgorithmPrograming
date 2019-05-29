/* 
    TITLE: all_subsets.cpp
    ABSTRACT: Takes in a number imput and then takes in that
    number of characters and displays all subsets of the input set
    AUTHOR: JOSE T. AGUIRRE
    ID 1123
    DATE 9/22/2017
*/

#include <math.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int e = 0;
    int ranege = 0;
    int characters = 0;
    bool first = false;
    typedef int* IntArrayPtr;
    
    cout << "Number of input characters: ";
    cin >> characters;
    
    char charString[characters];
    cout << "Enter " << characters << " characters: ";
    for (int y = 0; y < characters; y++){
        cin >> charString[y];
    }
    
    for (int d = 0; d < characters - 1; d++){
        for (e = d + 1; e < characters; e++){
            if (charString[e] == charString[d]){
                cout << "Duplicate Values ar not allowed!" << endl;
                return 0;
            }
        }
    }
    
    ranege = pow(2, characters);
    ranege = ranege - 1;
    IntArrayPtr *matrix = new IntArrayPtr[ranege];

    for (int i = 0; i <= ranege; i++)
        matrix[i] = new int[characters];
    
    for (int z = 0; z <= ranege; z++){
        for (int q = 0; q < characters; q++){
            if (z >> q & 1){
                matrix[z][q] = (z >> q & 1);
            }else{
                matrix[z][q] = 0;
            }
        }
    }

    cout << "========== All Subsets ===========" << endl;
    for (int i = 0; i <= ranege; i++){
        cout << "{";
        for (int j = 0; j < characters; j++){
            if (matrix[i][j] == 1 && first != false){
                cout << ", " << charString[j];
                } else if (matrix[i][j] == 1 && first == false){
                    cout << charString[j];
                    first = true;
            }
        }
        cout << "}" << endl;
        first = false;
    }
    
    return EXIT_SUCCESS;
}