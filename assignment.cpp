/* 
    Title: assignment.cpp
    ABSTRACT: Solves the Assignment prob of getting all posible
    permutations to fill a job n by people of n with lowest cost.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 10/06/2017
*/

#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int);

void permutation(int* permutationsIndex, int size){
    int workNum = 1;
	for(int i = 0; i < size; i++){
	    cout << permutationsIndex[i] <<", ";
	}
	cout << endl;
}

int main()
{
    int jobNum = 0;
    int factorialNum = 0;
    
    cout << "Number of jobs: ";
    cin >> jobNum;
    // This loop will get the index in a array
    int permutationsIndex[jobNum];
    int total = 1;
    for (int p = 0; p < jobNum; p++){
        permutationsIndex[p] = total;
        total++;
    }
    typedef int* IntArrayPtr;
    IntArrayPtr *matrix = new IntArrayPtr[factorialNum];
    for (int i = 1; i <= jobNum; i++)
        matrix[i] = new int[jobNum];
        
    cout << "Enter assignment cost of " << jobNum << " persons:" << endl;
    for (int z = 1; z <= jobNum; z++){
        cout << "Person " << z << ": ";
        for (int q = 1; q <= jobNum; q++){
            cin >> matrix[z][q];
        }
    }
    // This code does the permutations, just figure how to get it with 
    // the index of the matrix 2d array
    sort(permutationsIndex,permutationsIndex+jobNum);
	permutation(permutationsIndex, jobNum);
	while(next_permutation(permutationsIndex,permutationsIndex+jobNum))
		permutation(permutationsIndex, jobNum);
    
    cout << "Here is the matrix" << endl;
    for (int i = 1; i <= jobNum; i++){
        for (int j = 1; j <= jobNum; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return EXIT_SUCCESS;
}
int factorial(int n){
    int carrier = 0;
    if (n <= 1){
        return 1;
    }else{
        carrier = n * factorial(n - 1);
        return carrier;
    }
}