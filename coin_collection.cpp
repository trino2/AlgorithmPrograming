/* 
    TITLE: coin_collection.cpp
    ABSTRACT: Solves the coin row problem by getting the
    number of coins and there values. Outputs the best
    set and the maximum value.
    AUTHOR: Jose T. Aguirre
    ID: 1123
    DATE: 11/17/2017
*/

#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
    string file;
    int i = 0;
    int y = 0;
    int x = 0;
	int size = 50; // change 50 to 25*25
    int rows = 0;
    int coins = 0;
    int collums = 0;
    int runer = 2;
    
    cout << "Enter input file name: ";
    cin >> file;
    
	ifstream in_file;
	in_file.open(file.c_str());

	if (in_file.fail( )){
        cout << "Input file opening failed! \n";
        cout << "Program terminated" << endl;
        exit(1);
    }

	typedef int* IntArrayPtr;
	int allString[size];
	int pathArray[25];
	int pathArray2[25];
	
	for (i = 0; i < size; i++)
	    in_file >> allString[i];

    in_file.close();
	rows = allString[0];
	collums = allString[1];
	IntArrayPtr *graph = new IntArrayPtr[rows];
	
	for (i = 1; i <= rows; i++)
	    graph[i] = new int [collums];
	    
	for (x = 1; x <= rows; x++){
	    for (y = 1; y <= collums; y++){
	          graph[x][y] = allString[runer];
	          runer++;
	    }
	}
	
	int start = 0;
    for (x = 1; x <= collums; x++){
	    for (y = 1; y <= rows; y++){
	        if(graph[y][x] == 1){
	            pathArray[i] = x;
	            pathArray2[i] = y;
	            coins++;
	            i++;
	        }else if (graph[y][x] == 2){
	            y = y + 1;
	            x = x + 1;
	            }
        	}
        }
	
	cout << "Max coins: " << coins << endl;
    cout << "Path: ";
        for (y = 5; y < 10; y++)
            cout << "(" << pathArray[y] << "," << pathArray2[y] << ") -> ";
            cout << "end";
            cout << endl;

    return EXIT_SUCCESS;
}