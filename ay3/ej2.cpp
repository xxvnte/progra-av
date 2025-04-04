#include <iostream>
#include <string>
using namespace std;

class Pizza{
private:
    string nombre;
    string ingredientes[3];

public:
    Pizza(string n, string i[]){
        nombre = n;
        for (int j = 0; j < 3; j++){
            ingredientes[j] = i[j];
        }
    }

    Pizza(){ // constructor por defecto
        nombre = " ";
        for (int j = 0; j < 3; j++){
            ingredientes[j] = " ";
        }
    }

    string getNombre(){
        return nombre;
    }

    string getIngredientes(int i){
        return ingredientes[i];
    }

    void setNombre(string n){
        nombre = n;
    }

    void setIngredientes(string i, int j){
        ingredientes[j] = i;
    }
};

class Pizzeria{
private:
    string nombre;
    int estrellas;
    Pizza pizzas[2];

public:
    Pizzeria(string n, int e, Pizza p[2]){
        nombre = n;
        estrellas = e;
        for (int j = 0; j < 2; j++){
            pizzas[j] = p[j];
        }
    }

    string getNombre(){
        return nombre;
    }

    int getEstrellas(){
        return estrellas;
    }

    Pizza getPizzas(int j){
        return pizzas[j];
    }

    void setNombre(string n){
        nombre = n;
    }

    void setEstrellas(int e){
        estrellas = e;
    }

    void setPizzas(Pizza p, int j){
        pizzas[j] = p;
    }
};

int main(){

    string ingredientes2[3] = {"queso", "jamon", "pimiento"};
    string ingredientes3[3] = {"queso", "jamon", "piña"};

    Pizza pizza2("hawaiana", ingredientes2);
    Pizza pizza3("vegetariana", ingredientes3);

    Pizza pizzas[2] = {pizza2, pizza3};

    Pizzeria p1("pizza Hut", 5, pizzas);

    // mostrar info de la pizzeria
    cout << "nombre de la pizzeria: " << p1.getNombre() << endl;
    cout << "estrellas: " << p1.getEstrellas() << endl;
    cout << "pizzas: " << endl;

    // mostrar las pizzas y sus ingredientes
    for (int i = 0; i < 2; i++){
        cout << p1.getPizzas(i).getNombre() << endl;
        cout << "ingredientes: " << endl;
        for (int j = 0; j < 3; j++){
            cout << p1.getPizzas(i).getIngredientes(j) << ", ";
        }
        cout << endl;
    }

    return 0;
}
