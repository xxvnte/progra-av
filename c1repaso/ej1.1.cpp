#include <iostream>

using namespace std;

int main() {

    string matriz[3][4] = {
        {"a", "b", "c", "d"},
        {"e", "f", "g", "h"},
        {"i", "j", "k", "l"},
    };

    string aux = matriz[0][3];
    matriz[0][3] = matriz[2][2];
    matriz[2][2] = aux;

    string aux2 = matriz[2][0];
    matriz[2][0] = matriz[0][1];
    matriz[0][1] = aux2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}