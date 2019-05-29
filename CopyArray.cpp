/*#include <iostream>
#include <cstdlib>

using namespace std;

void displayArray(int arr[], int sz);

int main()
{
    int a1[3] = {3, 5, 8};
    int a2[9];

    copy(a1, a1 + 3, a2);
    displayArray(a2, 3);
    copy(a1, a1 + 3, a2 + 3);
    displayArray(a2, 6);
    copy(a1, a1 + 2, a2 + 6);
    displayArray(a2, 8);
    return EXIT_SUCCESS;
}
void displayArray(int arr[], int sz)
{
    for(int i = 0; i<sz; i++)
    cout << "<" << i << ">: " << arr[i] << " ";
    cout << endl << endl;
}*/

//DISPLAY 9.4 Arrays and Pointer Variables
//Program to demonstrate that an array variable is a kind of pointer variable.
#include <iostream>
using namespace std;

typedef int* IntPtr;

int main( )
{
    IntPtr p;
    int a[10];
    int index;

    for (index = 0; index < 10; index++)
        a[index] = index;

    p = a;

    for (index = 0; index < 10; index++)
        cout << p[index] << " ";
        cout << endl;

    for (index = 0; index < 10; index++)
        p[index] = p[index] + 1;

    for (index = 0; index < 10; index++)
        cout << a[index] << " ";
        cout << endl;

    return 0;
}

