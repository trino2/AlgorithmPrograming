/* 
    TITLE: knapsack.cpp
    ABSTRACT: Solves the Napsack problem by creading a graph
    from reading the weigh and value of each item 
    and determins the best subset.
    AUTHOR: Jose T. Aguirre
    DATE: 12/3/2017
    ID: 1123
*/

#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i = 0;
    int q = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int track = 0;
    int maxValue = 0;
    int itemsNum = 0;
    int itemsCap = 0;
    bool first = true;
    typedef int* IntArrayPtr;
    
    cout << "Enter a number of items: ";
    cin >> itemsNum;
    
    cout << "Enter knapsack capacity: ";
    cin >> itemsCap;
    
    int count = 1;
    int weighArray[itemsNum];
    int valueArray[itemsNum];
    int bestSetArr[itemsNum];
    IntArrayPtr *matrix = new IntArrayPtr[itemsNum];
    
    cout << "Enter weights and values of " << itemsNum << " items:" << endl;
    for (y = 0; y < itemsNum; y++){
        cout << "Item " << count << ": ";
        cin >> weighArray[y] >> valueArray[y];
        count++;
    }

    for (i = 0; i <= itemsNum; i++)
        matrix[i] = new int[itemsCap];
    
    for (z = 0; z <= itemsNum; z++){
        for (q = 0; q <= itemsCap; q++){
            if (z == 0){
                matrix[z][q] = 0;
            }else if (q == 0){
                matrix[z][q] = 0;
            }else if (weighArray[z-1] <= q){
                x = valueArray[z-1] + matrix[z-1][q-weighArray[z-1]];
                y = matrix[z-1][q];
                matrix[z][q] = max(x, y);
            }else{
                matrix[z][q] = matrix[z-1][q];
            }
        }
    }
        
    maxValue = matrix[itemsNum][itemsCap];
    
    cout << endl << "i/j:\t";
    for (i = 0; i <= itemsNum+1; i++){
        if(i == 0 ){
            for (q = 0; q <= itemsNum+1; q++)
                cout << q << "\t";
        }else{
        cout << i-1 << "  :\t";
        for (z = 0; z <= itemsCap; z++){
            cout << matrix[i-1][z] << "\t";
            }
        }
        cout << endl;
    }
    
        for (x = 0; x < itemsCap; x++){
            if(matrix[itemsNum][x] != matrix[itemsNum][x-1]){
                int testAdd = matrix[itemsNum][x-1] + matrix[itemsNum][x-2];
                if (testAdd != matrix[itemsNum][x]){
                    bestSetArr[track] = x;
                    track++;
                }
            }
        }
    
    cout << endl << "Best Set: ";
    for (y = 0; y < track; y++){
        if (bestSetArr[y] != 0){
            if(first){
            cout << bestSetArr[y];
            first = false;
            }else{
                cout << ", " << bestSetArr[y];
            }
        }
    }
    cout << endl << "Max value: " << maxValue << endl << endl;
    
    return EXIT_SUCCESS;
}