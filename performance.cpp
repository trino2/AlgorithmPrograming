/* 
    TITLE: performance.cpp
    ABSTRACT: Calculates the performace from 4 different
    sorting algorithms bubble sort, insertion sort, quick sort,
    and merge sort from a random number from the input of the user.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 10/27/2017
*/

#include <ctime>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;

void quickSort(int quickArray[], int l, int r);
void elapseTime(int endSec, int startSec);
int startTimer();
int endTimer();

int main()
{
    int i = 0;
    int j = 0;
    int u = 0;
    int run = 0;
    int temp = 0;
    int reps = 0;
    int value = 0;
    int endSec = 0;
    int looper = 0;
    int maxNum = 0;
    int startSec = 0;
    
    cout << "Enter input reps ";
    cin >> reps;

    cout << "Enter max value of input ";
    cin >> maxNum;
    
    looper = reps;
    srand (time(NULL));
    int arrayList[reps];
    int A[reps];
    int quickArray[reps];
    int insertionArray[reps];
    
    cout << "=====================================" << endl;
    cout << "Generating input data . . ." << endl;
    ofstream outfile;
    outfile.open ("input.txt");
    if (outfile.fail( )){
        cout << "input.txt file not found" << endl;
        cout << "Program terminated" << endl;
        exit(1);
    }
        do {
        value = rand() % maxNum;
        arrayList[run] = value;
        A[run] = value;
        quickArray[run] = value;
        insertionArray[run] = value;
        looper--;
        run++;
        } while(looper > 0);

        for(int x = 0; x < reps; x++)
            outfile << arrayList[x] << " ";
            outfile.close();
            
    cout << "Done." << endl;
    cout << "=====================================" << endl;
    cout << "=====================================" << endl;
		
    cout << "Bubble sort performance " << endl;
    startSec = startTimer();
    
	int flag = 1;
	time_t endTime;
	time_t startTime;
	time(&startTime);
	
	while(flag == 1){
		flag = 0;
		for(int i = 0; i < reps-1; i++){
            if(arrayList[i] > arrayList[i+1]){
                temp = arrayList[i];
                arrayList[i] = arrayList[i+1];
                arrayList[i+1] = temp;
				flag = 1;
            }
        }
    }
    
    endSec = endTimer();
    elapseTime(startSec, endSec);
		
    cout << "Insertion Sort Performance" << endl;
    startSec = startTimer();
		
	for (i = 0; i < reps; i++){
		j = i;
		while (j > 0 && A[j] < A[j-1]){
			  temp = A[j];
			  A[j] = A[j-1];
			  A[j-1] = temp;
			  j--;
		}
	}
	
    endSec = endTimer();
    elapseTime(startSec, endSec);
    
    cout << "Quicksort Performance" << endl;
    startSec = startTimer();
    
    int left = reps - 1;
    quickSort(quickArray, 0,  left);
    
    endSec = endTimer();
    elapseTime(startSec, endSec);
    
    cout << "Insertion Sort Performance" << endl;
    startSec = startTimer();
    
    int n = reps - 1;
    for (i = 1; i <= n; i++){
        u = insertionArray[i];
        j = i-1;
         while (j >= 0 && insertionArray[j] > u){
         insertionArray[j+1] = insertionArray[j];
         j--;
        }
        insertionArray[j+1] = u;
    }
    endSec = endTimer();
    elapseTime(startSec, endSec);
    
    return EXIT_SUCCESS;   
}
void quickSort(int quickArray[], int l, int r){
    int i = l;
    int j = r;
    int s = quickArray[(l + r) / 2];

      while (i <= j){
            while (quickArray[i] < s)
                  i++;
            while (quickArray[j] > s)
                  j--;
            if (i <= j) {
                  s = quickArray[i];
                  quickArray[i] = quickArray[j];
                  quickArray[j] = s;
                  i++;
                  j--;
            }
      }
      if (l < j)
            quickSort(quickArray, l, j);
      if (i < r)
            quickSort(quickArray, i, r);
}
int startTimer(){
    time_t rawtime;
    struct tm *timeStart;
    time(&rawtime);
    timeStart = localtime(&rawtime);
    int startSec = timeStart->tm_sec;
    int startMin = timeStart->tm_min;
    cout << "Start time: " << asctime(timeStart);
    return startSec;
}
int endTimer(){
    time_t rawtime;
    struct tm *timeEnd;
    time (&rawtime);
    timeEnd = localtime(&rawtime);
    int endSec = timeEnd->tm_sec;
    int endMin = timeEnd->tm_min;
    cout << "End time: " << asctime(timeEnd);
    return endSec;
}
void elapseTime(int endSec, int startSec){
    double timeElapsed = endSec - startSec;
    if (timeElapsed < 0){
        while (startSec <= 60){
            endSec++;
            startSec++;
        }
        cout << "Elapse Time: " << startSec << " seconds" << endl;
    }else if (timeElapsed > 0) {
        cout << "Elapse Time: " << timeElapsed << " seconds" << endl;
    } else{
        cout << "Elapse Time: 0 seconds" << endl;
    }
    cout << "=====================================" << endl;
    cout << "=====================================" << endl;
}