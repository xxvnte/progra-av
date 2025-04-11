//Código del compañero Angel Ruz

#include <iostream>
using namespace std;

class Trabajador {
protected:
    string nombre;
    float sueldo;

public:
    Trabajador(string n, float s) {
        nombre = n;
        sueldo = s;
    }

    void setNombre(string n) {
        nombre = n;
    }
    void setSueldo(float s) {
        sueldo = s;
    }

    string getNombre() {
        return nombre;
    }
    float getSueldo() {
        return sueldo;
    }

};

class Chef : public Trabajador {
private:
    string plato;

public:
    Chef(string n, float s, string p) : Trabajador(n, s) {
        plato = p;
    }

    void setPlato(string p) { plato = p; }
    string getPlato() { return plato; }

    void mostrarInfo(){
        cout << "Chef de Nombre: " << nombre<<endl;
        cout << "Sueldo: " << sueldo<<endl;
        cout << "Cocina: " << plato << endl;
    }
};

class Mesero : public Trabajador {
private:
    int mesas;
    float propina;

public:
    Mesero(string n, float s, int m, float p) : Trabajador(n, s) {
        mesas = m;
        propina = p;
    }

    void setMesas(int m) {
        mesas = m;
    }
    int getMesas() {
        return mesas;
    }

    void setPropina(float p) {
        propina = p;
    }
    float getPropina() {
        return propina;
    }
    void mostrarInfo() {
        cout << "Mesero de Nombre: " << nombre<<endl;
        cout<< "Sueldo: " << sueldo<<endl;
        cout<< "Mesas atendidas: " << mesas<<endl;
        cout<< "Propina: $" << propina << endl;
    }
};

int main() {
    Chef chef1("Carlitos", 200000, "Once");
    Mesero mesero1("Felipe", 150000, 29, 50000);

    chef1.mostrarInfo();
    cout<<"*************************************************"<<endl;
    mesero1.mostrarInfo();

    return 0;
}