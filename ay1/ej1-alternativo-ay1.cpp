#include <iostream>
using namespace std;

void Matriz(int n)
{
    int m[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                m[i][j] = 1;
            }
            else
            {
                m[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "ingrese orden" << endl;
    cin >> n;
    Matriz(n);
    return 0;
}