/* 
    TITLE: heap.cpp
    ABSTRACT: Read's in integer and makes array
    of that size, then it wants those many values.
    It then checks if its a heap and if not it makes it.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 11/3/2017
*/

#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;
typedef int* IntArrayPtr;

void heapSort(IntArrayPtr heapArray, int &size){
    int x = 0;
    int n = 0;
    int j = 0;

    for (x = size; x >= 2; x--){
        n = x / 2;
        if (heapArray[n] < heapArray[x]){
            j = heapArray[n];
            heapArray[n] = heapArray[x];
            heapArray[x] = j;
        }
    }
}

int main(){
    
    int x = 0;
    int size = 0;
    int value = 0;
    int option = 0;
    bool heap = true;
    bool redo = true;
    int leftChild = 0;
    int rightChild = 0;
    
    cout << "Input size: ";
    cin >> size;
    
    IntArrayPtr heapArray;
    heapArray = new int[size];

    cout << "Enter " << size << " numbers: ";
    for(x = 1; x <= size; x++)
        cin >> heapArray[x];
    
    for (x = 1; x <= size; x++){
        leftChild = 2 * x;
        rightChild = (2 * x) + 1;
        if (rightChild <= size){
            if (heapArray[x] < leftChild)
                heap = false;
        }else if (leftChild <= size){
            if (heapArray[x] < rightChild)
                heap = false;
        }
    }
    if(!heap){
        cout << "Not a heap!" << endl;
        heapSort(heapArray, size);
        cout <<"Heap constructed: ";
        for (x = 1; x <= size; x++)
            cout << heapArray[x] << " ";
            cout << endl;
    }else if (heap){
        cout << "This is a heap." << endl;
    }
        do {
        cout << "Select a operation" << endl;
        cout << "1: Insert a number" << endl;
        cout << "2: Delete the max value" << endl;
        cout << "3: Heapsort and Quit" << endl;
        cin >> option;
        
        switch(option){
            case 1: cout << "Enter a number: ";
                    cin >> value;
                    size = size + 1;
                    heapArray[size] = value;
                    heapSort(heapArray, size);
                    cout << "Updated Heap: ";
                    for (x = 1; x <= size; x++)
                    cout << heapArray[x] << " ";
                    cout << endl;
                    redo = true;
                    break;
            case 2: for (x = 1; x < size; x++)
                    heapArray[x] = heapArray[x+1];
                    if(size > 0)
                    size = size - 1;
                    cout << "Updated Heap: ";
                    heapSort(heapArray, size);
                    for (x = 1; x <= size; x++)
                    cout << heapArray[x] << " ";
                    cout << endl;
                    redo = true;
                    break;
            case 3: cout << "Heapsort: ";
                    for (x = 1; x <= size; x++)
                    cout << heapArray[x] << " ";
                    cout << endl;
                    cout << "Bye!" << endl;
                    redo = false;
                    break;
            default: cout << "That is not a option try again!" << endl;
                    redo = true;
                    break;
            }
        }while(redo);

    return EXIT_SUCCESS;
}