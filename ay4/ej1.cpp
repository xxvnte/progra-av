#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
public:
    virtual void mover(){
        cout << "el vehiculo se mueve" << endl;
    }
};

class Auto : public Vehiculo{
public:
    void mover() override{
        cout << "el auto se mueve" << endl;
    }
};

class Bicicleta : public Vehiculo{
public:
    void mover() override{
        cout << "la bicicleta se mueve" << endl;
    }
};

void mostrarMovimiento(Vehiculo* v){
    v->mover();
}

int main(){
    Auto RayoMcQueen;
    Bicicleta miBici;

    Vehiculo* p1 = &RayoMcQueen;
    Vehiculo* p2 = &miBici;

    mostrarMovimiento(p1);
    mostrarMovimiento(p2);

    return 0;
}
