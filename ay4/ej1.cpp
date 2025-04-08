#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
public:
    virtual void mover(){
        cout << "El vehículo se mueve." << endl;
    }
};

class Auto : public Vehiculo{
public:
    void mover() override{
        cout << "El auto se mueve con motor. 🚗" << endl;
    }
};

class Bicicleta : public Vehiculo{
public:
    void mover() override{
        cout << "La bicicleta se mueve con pedales. 🚲" << endl;
    }
};

void mostrarMovimiento(Vehiculo* v){
    v->mover();
}

int main(){
    Auto RayoMcQueen;
    Bicicleta miBici;

    Vehiculo* pAuto = &RayoMcQueen;
    Vehiculo* pBici = &miBici;

    mostrarMovimiento(pAuto);
    mostrarMovimiento(pBici);

    return 0;
}
