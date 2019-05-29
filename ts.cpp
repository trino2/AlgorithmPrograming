/* 
    TITLE: ts.cpp
    ABSTRACT: Implements the topological sorting algorithm 
    based on the DFS. Reads in text file from input address and
    processes 2d array of nodes visited by storing into a tack.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 10/20/2017
*/

#include <stack>
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
	int size = 100;
    int nodes = 0;
    int run = 1;
    int i = 0;
    int x = 0;
    int y = 0;
    
    cout << "Enter a file name: ";
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
	
	for (i = 0; i < size; i++)
	    in_file >> allString[i];

	nodes = allString[0];
	in_file.close();
	
	IntArrayPtr *graph = new IntArrayPtr[nodes];
	
	for (i = 0; i < nodes; i++)
	    graph[i] = new int [nodes];

	for (x = 0; x < nodes; x++){
	    for (y = 0; y < nodes; y++){
	          graph[x][y] = allString[run];
	          run++;
	    }
	}
	
	cout << "Start node(s): ";
	bool done = false;
	stack<int> nodeStack;
	stack<int> startNodes;
	for (x = 0; x < nodes; x++){
		done = false;
		for (y = 0; y < nodes; y++){
			if(graph[y][x] == 1){
				done = true;
			}
		}
		if (!done){
			cout << x << " ";
			startNodes.push(x);
		}
	}
	cout << endl;
	int start = startNodes.top() + 1;
	while(!startNodes.empty()){
		nodeStack.push(startNodes.top());
		startNodes.pop();
	}
	
	for (x = start; x < nodes; x++){
		done = false;
		for (y = 0; y < nodes; y++){
			if(graph[x][y] == 1 && done != true){
				nodeStack.push(x);
				done = true;
			}
		}
		if (!done){
			nodeStack.push(x);
		}
	}

/*		
	if(nodeStack.size() < nodes){
		int l = 0;
		bool stop = false;
	do{
		done = false;
		for (y = 0; y < nodes; y++){
			if(graph[l][y] == 1 && done != true){
				nodeStack.push(l);
				done = true;
				}
			}
			if (!done){
				nodeStack.push(l);
				stop = true;
			}
			l++;
		}while(!stop);
	}
	*/
	int count = 0;
	bool first = true;
	int orderArray[nodes];
	cout << "Popping-off order: ";
	for (stack<int> popOrder = nodeStack; !popOrder.empty(); popOrder.pop()){
		orderArray[count] = popOrder.top();
		cout << popOrder.top() << " ";
		count++;
	}
	cout << endl;
	count = count - 1;
	cout << "Topological sort: ";
	for (int sort = count; sort >= 0; sort--){
		if (first){
		cout << orderArray[sort];
		first = false;
		}else if (!first){
			cout << " -> " << orderArray[sort];
		}
	}
	cout << endl;
	return EXIT_SUCCESS;
}