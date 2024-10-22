#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

using namespace std;

void Create(int** Z, const int rowCount, const int colCount, const int Low,
    const int High);
void Print(int** Z, const int rowCount, const int colCount);
void Sort(int** Z, const int rowCount, const int colCount);
void Change(int** Z, const int row1, const int row2, const int colCount);
void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 4;
    int High = 45;
    int rowCount = 9;
    int colCount = 7;
    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Z[i] = new int[colCount];
    Create(Z, rowCount, colCount, Low, High);
    Print(Z, rowCount, colCount);
    Sort(Z, rowCount, colCount);
    Print(Z, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calc(Z, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Z, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] Z[i];
    delete[] Z;
    return 0;
}


void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Z[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Z, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Z[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** Z, const int rowCount, const int colCount) {
    for (int col1 = 0; col1 < colCount - 1; col1++)
        for (int col2 = 0; col2 < colCount - col1 - 1; col2++)
            if (Z[0][col1] < Z[0][col2])
                ||
                (Z[0][col1] == Z[0][col2] &&
                    Z[1][col1] > Z[1][col2])

                ||
                (Z[0][col1] == Z[0][col2] &&
                    Z[1][col1] == Z[1][col2]
                    && Z[2][col1] < Z[2][col2]);
}

void Change(int** Z, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int j = 0; j < rowCount; j++)
    {
        tmp = Z[j][col1];
        Z[j][col1] = Z[j][col2];
        Z[j][col2] = tmp;
    }


    void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k) {
        S = 0;
        k = 0;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
                    S += Z[i][j];
                    k++;
                    Z[i][j] = 0;
                }
            }
        }
    }