#include <iostream>
using namespace std;
class Evento
{
private:
    int npc;
    int cd;
    int cf;

public:
    Evento(int npc, int cd, int cf)
    {
        this->npc = npc;
        this->cd = cd;
        this->cf = cf;
    }
    void setCd(int cd)
    {
        this->cd = cd;
    }
    void setCf(int cf)
    {
        this->cf = cf;
    }
    int getNpc()
    {
        return npc;
    }
    int getCd()
    {
        return cd;
    }
    int getCf()
    {
        return cf;
    }
};

class PuntosCriticos
{
private:
    Evento *lista[300];

public:
    PuntosCriticos()
    {
        for (int i = 0; i < 300; i++)
        {
            lista[i] = NULL;
        }
    }
    void registrarEvento(Evento *e)
    {
        int posicion = e->getNpc();
        if (lista[posicion] == NULL)
        {
            lista[posicion] = e;
        }
        else
        {
            int fugados = lista[posicion]->getCf() + e->getCf();
            int detenidos = lista[posicion]->getCd() + e->getCd();
            lista[posicion]->setCf(fugados);
            lista[posicion]->setCd(detenidos);
        }
    }
    void estadisticas()
    {
        int con = 0, sin = 0, may = 0, det = 0, fug = 0;
        for (int i = 0; i < 300; i++)
        {
            if (lista[i] == NULL)
            {
                sin++;
            }
            else
            {
                con++;
                det = det + lista[i]->getCd();
                fug = fug + lista[i]->getCf();
                if (lista[i]->getCf() > lista[i]->getCd())
                {
                    may++;
                }
            }
        }
        cout << "Puntos sin novedad " << sin << " " << sin / 300.0 << "%" << endl;
        cout << "Puntos con novedad " << con << " " << con / 300.0 << "%" << endl;
        cout << "Detenidos " << det << endl;
        cout << "Fugados " << fug << endl;
        cout << "Puntos en los que hay mas fugados que detenidos " << may << endl;
    }
};

int main()
{
    PuntosCriticos *pc = new PuntosCriticos();
    Evento *e1 = new Evento(30, 3, 3);
    Evento *e2 = new Evento(31, 3, 4);
    Evento *e3 = new Evento(33, 4, 3);
    Evento *e4 = new Evento(34, 5, 3);
    Evento *e5 = new Evento(30, 3, 3);
    Evento *e6 = new Evento(60, 1, 12);
    pc->registrarEvento(e1);
    pc->registrarEvento(e2);
    pc->registrarEvento(e3);
    pc->registrarEvento(e4);
    pc->registrarEvento(e5);
    pc->registrarEvento(e6);
    pc->estadisticas();
}