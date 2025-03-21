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
    // desafio
    void BattleRoyale(int cantidadGuerreros, Guerrero gList[100])
    {
        cout << "Comienza la batalla campal!" << endl;

        int tam = cantidadGuerreros;

        while (tam > 1)
        {
            for (int i = 0; i < tam - 1; i++)
            {
                if (gList[i].getNivelDePelea() == 0)
                    continue;

                if (gList[i].nivelDePelea > gList[i + 1].nivelDePelea)
                {
                    cout << gList[i].nombre << " ha ganado el round " << i + 1 << endl;
                    gList[i + 1].setNivelDePelea(0);
                }
                else if (gList[i].nivelDePelea < gList[i + 1].nivelDePelea)
                {
                    cout << gList[i + 1].nombre << " ha ganado el round " << i + 1 << endl;
                    gList[i].setNivelDePelea(0);
                }
                else
                {
                    cout << "Ha sido un empate!" << endl;
                }
            }

            tam = 0;
            for (int i = 0; i < cantidadGuerreros; i++)
            {
                if (gList[i].getNivelDePelea() != 0)
                {
                    tam++;
                }
            }

            for (int i = 0; i < cantidadGuerreros; i++)
            {
                if (gList[i].getNivelDePelea() != 0)
                {
                    cout << gList[i].getNombre() << " es el ganador final!" << endl;
                    break;
                }
            }
        }
    }
};

int main()
{
    Guerrero pepito("pepito", 100);
    Guerrero juanito("juanito", 80);

    cout << pepito.fight(juanito) << endl; // pepito vs juanito

    juanito.setNivelDePelea(120);
    cout << juanito.getNombre() << " ahora tiene un nivel de pelea de: " << juanito.getNivelDePelea() << endl;

    cout << juanito.fight(pepito) << endl; // revancha

    // desafio

    Guerrero pedrito("pedrito", 200);

    Guerrero guerreros[3] = {pepito, juanito, pedrito};

    pepito.BattleRoyale(3, guerreros);

    return 0;
}