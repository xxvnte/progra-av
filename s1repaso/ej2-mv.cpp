#include <iostream>
#include <math.h>

using namespace std;

class Triangulo{
    private:
        float a;
        float b;
        float c;

    public:
    Triangulo(float a_, float b_, float c_){
        a = a_;
        b = b_;
        c = c_;
    }
    
    bool validar(){
        if(a + b > c && a + c > b && b + c > a){
            return true;    
        } else return false;
    }
    
    string obtieneTipo(){
        if(!validar()){
            return "triangulo invalido";
        } else {
            if(a==b && b==c) return "equilatero";
            if(a==b && b!=c || a==c && a!=b || b==c && a!=c) return "isosceles";
            if(a!=b && b!=c) return "escaleno";
        }
    }
    
    float obPerimetro(){
        if(!validar()){
            return -1;
        } else {
            return a+b+c;
        }
    }
    
    float obArea(){
        float s = obPerimetro()/2;
        if(!validar()){
            return -1;
        } else {
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
    }   
    
};

int main(){
    
    Triangulo t1(2, 3, 3);
    Triangulo t2(3, 3, 3);
    Triangulo t3(2, 1, 3);
    
    cout << t1.obtieneTipo() << endl;
    cout << t1.obPerimetro() << endl;
    cout << t1.obArea() << endl;
}



