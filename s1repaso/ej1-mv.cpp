#include <iostream>
using namespace std;

class Evento{
    private:
    int ptc, detenidos, fugados;
    
    public:
    Evento(int p, int d, int f){
        ptc = p;
        detenidos = d;
        fugados = f;
    }
    
    Evento(){//constructor por defecto
        ptc = 0;
        detenidos = 0;
        fugados = 0;
    }
    
    int getPtc(){
        return ptc;
    }
    int getDetenidos(){
        return detenidos;
    }
    int getFugados(){
        return fugados;
    }
    void setPtc(int p){
        ptc = p;
    }
    void setDetenidos(int d){
        detenidos = d;
    }
    void setFugados(int f){
        fugados = f;
    }
    
};

class PuntosCriticos{
    private:
    Evento *ListEvent[300];
    
    public:
    PuntosCriticos(Evento *L[300]){
        for(int i=0; i<300; i++){
            ListEvent[i] = L[i];
        }
    }
    
    PuntosCriticos(){ //constructor por defecto
        for(int i=0; i<300; i++){
            ListEvent[i] = NULL;
        }
    }
    
    Evento* getEvento(int i){
        if(i > 0 && i < 300){
            return ListEvent[i];
        }
    }
    
    void setEvento(Evento *e, int i){
        if(i > 0 && i < 300){
            ListEvent[i] = e;
        }
    }
    
    
    void registrarEvento(Evento *e){
        
        if(ListEvent[e->getPtc()] != NULL){
            
            int newDetenidos = ListEvent[e->getPtc()]->getDetenidos() + e->getDetenidos();
            int newFugados = ListEvent[e->getPtc()]->getFugados() + e->getFugados();
            
            ListEvent[e->getPtc()]->setDetenidos(newDetenidos);
            ListEvent[e->getPtc()]->setFugados(newFugados);
            
        } else if(ListEvent[e->getPtc()] == NULL){
            ListEvent[e->getPtc()] = e;
        }
        
    }
    
    void estadisticas(){
        float sn = 0, ce = 0;
        int td = 0, tf = 0;
        
        for(int i=0; i<300; i++){
            if(ListEvent[i] == NULL){
                sn++;
            }
            
            if(ListEvent[i] != NULL){
                ce++;
                
                if(ListEvent[i]->getDetenidos() != 0){
                    td += ListEvent[i]->getDetenidos();
                }
                
                if(ListEvent[i]->getFugados() != 0){
                    tf+= ListEvent[i]->getFugados();
                }
                if(ListEvent[i]->getFugados() > ListEvent[i]->getDetenidos()){
                    cout << "Punto critico con mas fugados que detenidos: " << ListEvent[i]->getPtc() << endl;
                }
                
            }
            
        }
        
        cout << "porcentaje de puntos criticos sin novedades: " << (sn/300)*100 << "%" << endl;
        cout << "porcentaje de puntos criticos con evento: " << (ce/300)*100 << "%" << endl;
        cout << "total detenidos: " << td << endl;
        cout << "total fugados: " << tf << endl;
        
    }
    
};

int main()
{
   PuntosCriticos pc;
   Evento *e1 = new Evento(1, 21, 33);
   Evento *e2 = new Evento(2, 61, 53);
   Evento *e3 = new Evento(3, 25, 53);
   Evento *e4 = new Evento(4, 22, 63);
   Evento *e5 = new Evento(5, 13, 23);
   
   pc.registrarEvento(e1);
   pc.registrarEvento(e2);
   pc.registrarEvento(e3);
   pc.registrarEvento(e4);
   pc.registrarEvento(e5);
   
   pc.estadisticas();

    return 0;
}