/* 
    TITLE: sieve.cpp
    ABSTRACT: THIS PROGRAM IMPLEMENTS THE SIEVE WITH GIVES PRIME NUMBER
    OF A NUMBER FROM 2 TO THE REQUESTED NUMBER
    AUTHOR: JOSE T. AGUIRRE
    ID 1123
    DATE 9/1/2017
*/
    
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cmath>

using namespace std;

int main()
{
    int* A;
    int* L;
    int number = 0;
    bool numberPositive = true;
    
    do{
    cout << "Please enter positive number ";
    cin >> number;
    if(number <= 1){
        cout << "That was not a correct number! Bigger than 1 " << endl;
        numberPositive = false;
        number = 0;
        }else if (number > 1){
        numberPositive = true;
        }
    }while(numberPositive == false);
  
    int p = 0;
    A = new int[number+1];
    for (int x = 0; x <= number; x++){
        A[x] = p;
        p++;
    }

    int count = 0;

    for (p = 2; p <= floor(sqrt(number)); p++){
        if (A[p] != 0){
        int j = 2;
        j = p * p;
        
        do{
            A[j] = 0;
            j = j + p;
            count++;
        }while(j <= number);
            }
        }
    int total = number - count + 1;
    
    int i = 0;
    L = new int[total];
    for (p = 2; p <= number; p++){
        if(A[p] != 0){
        L[i] = A[p];
        i++;
        }
    }
    cout << endl;
    
    for (int x = 0; x <= i; x++){
        if (L[x] != 0){
      cout << L[x] << " ";
                }
            }
            
    cout << endl << endl;

    return EXIT_SUCCESS;
}