#include <iostream>
using namespace std;

class Guerrero
{
private:
    string nombre;
    int nivelDePelea;

public:
    Guerrero(string n, int l)
    {
        nombre = n;
        nivelDePelea = l;
    }

    string getNombre()
    {
        return nombre;
    }

    int getNivelDePelea()
    {
        return nivelDePelea;
    }

    void setNombre(string n)
    {
        nombre = n;
    }

    void setNivelDePelea(int l)
    {
        nivelDePelea = l;
    }

    string fight(Guerrero g)
    {
        if (nivelDePelea > g.nivelDePelea)
        {
            return nombre + " ha ganado!";
        }
        else if (nivelDePelea < g.nivelDePelea)
        {
            return g.nombre + " ha ganado!";
        }
        else
        {
            return "Ha sido un empate!";
        }
    }
};

int main()
{
    Guerrero pepito("pepito", 100);
    Guerrero juanito("juanito", 80);

    cout << pepito.fight(juanito) << endl; // esto seria pepito vs juanito

    juanito.setNivelDePelea(120);
    cout << juanito.getNombre() << " ahora tiene un nivel de pelea de: " << juanito.getNivelDePelea() << endl;

    cout << juanito.fight(pepito) << endl; // revancha

    return 0;
}