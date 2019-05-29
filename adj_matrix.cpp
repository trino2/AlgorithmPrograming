/*
    TITLE: adj_matrix.cpp 
    ABSTRACT: Takes in input from text file
    and converts input into directed graph 
    using an adjacency matrix format
    AUTHOR: JOSE T. AGUIRRE
    ID: 1123
    DATE: 9/8/2017
*/
#include <sstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;

int main()
{
	string file;
	int size = 50;
    int edges = 0;
    int vertices = 0;
    
    cout << "Enter input file name " << endl;
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
	
	for (int i = 0; i < size; i++){
	    in_file >> allString[i];
	}

	vertices = allString[0];
	edges = allString[1];
	in_file.close();
	
	IntArrayPtr *graph = new IntArrayPtr[vertices];
	
	for (int i = 0; i < vertices; i++){
	    graph[i] = new int [vertices];
	}
	for (int x = 0; x < vertices; x++){
	    for (int y = 0; y < vertices; y++)
	          graph[x][y] = 0;
	}
	
	edges = edges * 2;

	for (int z = 2; z <= edges; z = z+2){
		int row = 0;
	    int column = 0;
	    row = allString[z];
	    int q = z + 1;
	    column = allString[q];
	    graph[row][column] = 1;
	}
	
	edges = edges / 2;

    cout << "Number of vertices: " << vertices << endl;
    cout << "Number of edges: " << edges << endl;
    cout << "Adjacency matrix: " << endl;
    
        for (int x = 0; x < vertices; x++){
        	for (int y = 0; y < vertices; y++)
			cout << graph[x][y] << "  ";
			cout << endl;
	}

	return EXIT_SUCCESS;
	
}