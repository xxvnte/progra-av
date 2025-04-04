#include <iostream>
#include <string>
using namespace std;

void esIsograma(string palabra){
    bool aux = true; //inicializamos variable booleana para decidir si la palabra es isograma
    
    for(int i=0;i<palabra.size();i++){
        for(int j=i + 1;j<palabra.size();j++){
            if(palabra[i]==palabra[j]){
                aux = false; //en caso de que se repita una letra, la variable cambia a false
                break;
            }
        } if (!aux) break; //si la variable es false se rompe el ciclo
    }
    
    if(aux){
        cout << palabra << " es un isograma"<< endl;
    } else cout << palabra << " no es un isograma" << endl;
    
}

int main()
{
    esIsograma("perro");
    esIsograma("murciegalo");
    esIsograma("pipshas");

    return 0;
}