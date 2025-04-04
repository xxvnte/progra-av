#include <iostream>
#include <string>
using namespace std;

class Episodio{
private:
    string nombre;
    int duracion;

public:
    Episodio(string n, int d){
        nombre = n;
        duracion = d;
    }

    Episodio(){ //constructor por defecto
        nombre = " ";
        duracion = 0;
    }

    string getNombre(){
        return nombre;
    }

    int getDuracion(){
        return duracion;
    }

    void setNombre(string n){
        nombre = n;
    }

    void setDuracion(int d){
        duracion = d;
    }
};

class Serie{
private:
    string nombre;
    int estrellas;
    Episodio episodios[3];

public:
    Serie(string n, int e, Episodio ep[3]){
        nombre = n;
        estrellas = e;
        for (int i = 0; i < 3; i++){
            episodios[i] = ep[i];
        }
    }

    string getNombre(){
        return nombre;
    }

    int getEstrellas(){
        return estrellas;
    }

    Episodio getEpisodio(int i){
        return episodios[i];
    }

    void setNombre(string n) {
        nombre = n;
    }

    void setEstrellas(int e){
        estrellas = e;
    }

    void setEpisodio(Episodio e, int i){
        episodios[i] = e;
    }

    void agregarEpisodio(){
        string nombreEpisodio;
        int duracionEpisodio;

        cout << "ingrese el nombre del episodio: ";
        cin >> nombreEpisodio;
        cout << "ingrese la duracion del episodio: ";
        cin >> duracionEpisodio;

        episodios[2] = Episodio(nombreEpisodio, duracionEpisodio); //se agrega episodio en la ultima posicion del array
    }

    Episodio MayorDuracion(){
        Episodio episodioMayor = episodios[0];
        for (int i = 1; i < 3; i++){
            if (episodios[i].getDuracion() > episodioMayor.getDuracion()){
                episodioMayor = episodios[i];
            }
        }
        return episodioMayor;
    }
};

void ordenarSeries(Serie series[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (series[j].getEstrellas() < series[j + 1].getEstrellas()){
                Serie temp = series[j];
                series[j] = series[j + 1];
                series[j + 1] = temp;
            }
        }
    }
}

int main(){
    Episodio episodios1[3] = {Episodio("ep 1", 30), Episodio("ep 2", 45)}; //aca hago espacio para agregar 1 episodio desde la consola
    Serie serie1("los pulentos", 4, episodios1);

    Episodio episodios2[3] = {Episodio("ep 1", 25), Episodio("ep 2", 35), Episodio("ep 3", 40)};
    Serie serie2("dragon ball z", 3, episodios2);

    Episodio episodios3[3] = {Episodio("ep 1", 20), Episodio("ep 2", 30), Episodio("ep 3", 60)};
    Serie serie3("riki morti", 5, episodios3);

    Serie series[3] = {serie1, serie2, serie3};

    cout << "el episodio de mayor duracion de " << serie1.getNombre() << " es: " << serie1.MayorDuracion().getNombre() << endl;

    ordenarSeries(series, 3);
    
    cout << "series ordenadas por cantidad de estrellas: " << endl;
    for (int i = 0; i < 3; i++){
        cout << series[i].getNombre() << " - Estrellas: " << series[i].getEstrellas() << endl;
    }

    serie1.agregarEpisodio();
    for(int i = 0; i < 3; i++){
        cout << "Episodio " << i + 1 << ": " << serie1.getEpisodio(i).getNombre() << endl;
    }

    return 0;
}