#include <iostream>
using namespace std;

class Animal
{
private:
    string nombre, color, sonido;

public:
    Animal(string n, string c, string s)
    {
        nombre = n;
        color = c;
        sonido = s;
    }

    string hacerSonido()
    {
        return nombre + " hace: " + sonido;
    }
};

int main()
{
    Animal mono("changito", "cafe", "uh uh ah ah");
    Animal gato("michi", "blanco", "miau");
    Animal perro("firulais", "cafe", "wof!");

    cout << mono.hacerSonido() << endl;
    cout << gato.hacerSonido() << endl;
    cout << perro.hacerSonido() << endl;

    return 0;
}