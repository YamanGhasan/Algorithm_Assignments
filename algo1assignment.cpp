#include<iostream>
#include<cmath>
#include <time.h>
#pragma warning(disable : 4996)
using namespace std;

int main() {

    int product[10][10], addition[10][10], r1 , c1 , r2 , c2 , i, j, k;
    cout << "Enter ROW1 and COLUMN1" << endl;
    cin >> r1 >> c1;
    cout << "Enter ROW2 and COLUMN2" << endl;
    cin >> r2 >> c2;
     
    srand(time(0));
    int a[][] ;
    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c1; ++j)
        {
            a[i][j] = rand();
        }
    }
    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c1; ++j)
             cout << a[i][j] << '\t';
         cout << '\n';
    }
    srand(time(0));
    int b[][] ;
    for (i = 0; i < r2; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            b[i][j] = rand();
        }
    }
    for (i = 0; i < r2; ++i)
    {
        for (j = 0; j < c2; ++j)
          cout << b[i][j] << '\t';
         cout << '\n';
    }


    if (c1 != r2) {
        cout << "Column of first matrix should be equal to row of second matrix";
    }
    else {
        cout << "The first matrix is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c1; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << "The second matrix is:" << endl;
        for (i = 0; i < r2; ++i) {
            for (j = 0; j < c2; ++j)
                cout << b[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        clock_t start = clock();
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j) {
                product[i][j] = 0;
            }
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    product[i][j] += a[i][k] * b[k][j];
                }
        
        cout << "Product of the two matrices is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c2; ++j)
                cout << product[i][j] << " ";
            cout << endl;
        }   
    clock_t end = clock();

    clock_t start1 = clock();
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j) {
                addition[i][j] = 0;
            }
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    addition[i][j] += a[i][k] + b[k][j];
                }
        cout << "addition of the two matrices is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c2; ++j)
                cout << addition[i][j] << " ";
            cout << endl;
        }
        clock_t end1 = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;
 printf("Time for product  : %.3f seconds.\n", elapsed);

 double elapsed1 = double(end1 - start1) / CLOCKS_PER_SEC;
 printf("Time for addition  : %.3f seconds.\n", elapsed1);
    }
    

   
    return 0;
}
   
