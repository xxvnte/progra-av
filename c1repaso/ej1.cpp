#include <iostream>

using namespace std;

int main()
{

    string matriz[3][4] = {
        {"a", "b", "c", "d"},
        {"e", "f", "g", "h"},
        {"i", "j", "k", "l"},
    };

    string aux = matriz[2][3];
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 3; j > 0; j--)
        {
            matriz[i][j] = matriz[i][j - 1];
        }
        if (i > 0)
        {
            matriz[i][0] = matriz[i - 1][3];
        }
    }
    matriz[0][0] = aux;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}