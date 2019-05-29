/* 
    TITLE: knapsack.cpp
    ABSTRACT: Solves the Napsack problem by reading the weigh and value 
    of each item and determins the best subset.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 9/29/2017
*/

#include <math.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int e = 0;
    int j = 0;
    int set = 0;
    int range = 0;
    int value = 0;
    int maxValue = 0;
    int capacity = 0;
    int itemsNum = 0;
    int itemsCap = 0;
    bool first = true;
    int capacityValue = 0;
    
    typedef int* IntArrayPtr;
    
    cout << "Enter a number of items: ";
    cin >> itemsNum;
    
    cout << "Enter knapsack capacity: ";
    cin >> itemsCap;
    
    int count = 1;
    int itemArray[itemsNum];
    int valueArray[itemsNum];
    int subsetsArray[range];
    int capacityArray[range];
    int sumValueArray[range];
    
    cout << "Enter weights and values of " << itemsNum << " items:" << endl;
    for (int y = 0; y < itemsNum; y++){
        cout << "Item " << count << ": ";
        cin >> itemArray[y] >> valueArray[y];
        count++;
    }
    
    range = pow(2, itemsNum);
    IntArrayPtr *matrix = new IntArrayPtr[range];

    for (int i = 0; i <= range; i++)
        matrix[i] = new int[itemsNum];
    
    for (int z = 0; z <= range; z++){
        for (int q = 0; q < range; q++){
            if (z >> q & 1){
                matrix[z][q] = (z >> q & 1);
            }else{
                matrix[z][q] = 0;
            }
        }
    }
    
    cout << endl;
    for (int i = 0; i < range; i++){
        value = 0;
        set = i + 1;
        capacity = 0;
        cout << "set " << set << ":  {";
        for ( j = 0; j < itemsNum; j++){
            if (matrix[i][j] == 1 && first != true){
                count = j + 1;
                value += valueArray[j];
                capacity += itemArray[j];
                cout << ", " << count;
                } else if (matrix[i][j] == 1 && first == true){
                    count = j + 1;
                    cout << count;
                    first = false;
                    value += valueArray[j];
                    capacity += itemArray[j];
            }
        }
        if (capacity <= itemsCap){
        cout << "}\t => Capacity: " << capacity << ", value: $" << value << endl;
        sumValueArray[i] = value;
        capacityArray[i] = capacity;
        
        first = true;
        } else if (capacity > itemsCap){
            cout << "}\t => Capacity: " << capacity << " - over capacity, value: N/A" << endl;
            sumValueArray[i] = 0;
            capacityArray[i] = capacity;
            first = true;
        }
    }
    
    int solution = 0;
    for (int d = 0; d < range; d++){
            if (sumValueArray[d] > maxValue){
                maxValue = sumValueArray[d];
                capacityValue = capacityArray[d];
                solution = d;
            }
    }
    
    first = true;
    for (int i = solution; i <= solution; i++){
        cout << "\nSolution: {";
        for ( j = 0; j <= solution+1; j++){
            if (matrix[i][j] == 1 && first != true){
                count = j + 1;
                cout << ", " << count;
                } else if (matrix[i][j] == 1 && first == true){
                    count = j + 1;
                    cout << count;
                    first = false;
            }
        }
        cout << "}\t";
    }

    cout << " => Capacity: " << capacityValue << ", value: $" << maxValue << endl;
    return EXIT_SUCCESS;
}