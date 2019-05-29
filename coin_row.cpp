/* 
    TITLE: coin_row.cpp
    ABSTRACT: Solves the coin row problem by getting the
    number of coins and there values. Outputs the best
    set and the maximum value.
    AUTHOR: Jose T. Aguirre
    ID: 1123
    DATE: 11/17/2017
*/

#include <cstdlib>
#include <cstddef>
#include <iostream>

using namespace std;

int maxValue(int n, int c){
    if (n >= c){
        return n;
    }else if (c > n){
        return c;
    }
}

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    int n = 0;
    int runer = 0;
    int mxValue = 0;
    int coinAmount = 0;

    cout << "Number of Coin(s): ";
    cin >> coinAmount;
    
    int C [coinAmount+1];
    int F [coinAmount+1];
    int setValue[coinAmount];
    
    cout << "Value(s): ";
    for (x = 0; x < coinAmount; x++)
        cin >> C [x];

    for (z = 0; z <= coinAmount; z++){
        x = z - 2;
        n = z - 1;
        if (z == 0){
            F [z] = 0;
        }else if (z == 1){
            F [z] = C [0];
            setValue[runer] = z;
            runer++;
        }else{
            y = F [x] + C [z-1];
            F [z] = maxValue(y, F [n]);
            mxValue = F [z];
            if(mxValue == y && mxValue != F [z-1]){
                setValue[runer] = z;
                runer++;
            }
        }
    }
    for (y = 0; y < runer; y++){
        int secon = setValue[y+1];
        int test = secon - setValue[y];
        if(test == 1){
            for (x = y; x < runer; x++){
                setValue[x] = setValue[x+1];
            }
            runer--;
        }
    }
    cout << "Best set: ";
    for(y = 0; y < runer; y++)
        cout << setValue[y] << " ";
        cout << endl;
    
    cout << "Max value: " << mxValue << endl;

    return EXIT_SUCCESS;
}