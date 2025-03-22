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
    void BattleRoyale(int tam, Guerrero gList[])
    {
        cout << "Comienza la batalla campal!" << endl;

        int ronda = 0; // variable solo para mostrar el numero de ronda, no es necesario

        while (tam > 1)
        {
            bool aux = true;
            for (int i = 0; i < tam - 1; i++)
            {
                if (gList[i].getNivelDePelea() != gList[i + 1].getNivelDePelea())
                {
                    aux = false;
                    break;
                }
            }

            if (aux)
            {
                cout << "Todos los guerreros tienen el mismo nivel de pelea, no se puede continuar con la batalla" << endl;
                return;
            }

            for (int i = 0; i < tam - 1; i++)
            {
                cout << "ronda " << ronda + 1 << ": " << gList[i].getNombre() << " vs " << gList[i + 1].getNombre() << endl;

                if (gList[i].getNivelDePelea() > gList[i + 1].getNivelDePelea())
                {
                    cout << gList[i].getNombre() << " ha ganado el round " << ronda + 1 << endl;
                    gList[i + 1] = gList[tam - 1];
                    tam--;
                    ronda++;
                }
                else if (gList[i].getNivelDePelea() < gList[i + 1].getNivelDePelea())
                {
                    cout << gList[i + 1].getNombre() << " ha ganado el round " << ronda + 1 << endl;
                    gList[i] = gList[tam - 1];
                    tam--;
                    ronda++;
                }
                else
                {
                    cout << "el round " << ronda + 1 << " ha sido un empate!" << endl;
                    ronda++;
                }
            }
        }
        cout << gList[0].getNombre() << " es el ganador final!" << endl;
    }
};

int main()
{
    Guerrero pepito("pepito", 100);
    Guerrero juanito("juanito", 500);
    Guerrero pedrito("pedrito", 900);
    Guerrero pablito("pablito", 500);

    Guerrero guerreros[4] = {pablito, juanito, pedrito, pepito};

    pepito.BattleRoyale(4, guerreros);

    return 0;
}