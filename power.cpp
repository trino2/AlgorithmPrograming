/* 
    TITLE: power.cpp
    ABSTRACT: A recursion fuction to calculate
    2 raised to the power of the input value.
    AUTHOR: Jose T. Aguirre
    ID 1123
    DATE 10/20/2017
*/

#include <cstdlib>
#include <iostream>

using namespace std;

double power (double value){
    if (value >= 1)
    return (2 * (power(value-1)));
        else
            return 1;
}

int main()
{
    double value = 0;
    double answer = 0;
    cout << "Enter a number: ";
    cin >> value;
    
    answer = power(value);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(0);

    cout << "Result: " << answer << endl;
    
    return EXIT_SUCCESS;

}