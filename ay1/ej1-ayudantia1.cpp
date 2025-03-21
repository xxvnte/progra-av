#include <iostream>
using namespace std;

void Matriz(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
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