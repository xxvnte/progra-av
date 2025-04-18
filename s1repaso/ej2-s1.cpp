#include <iostream>
#include <math.h>
using namespace std;

class Triangulo
{
private:
    float a;
    float b;
    float c;

public:
    Triangulo(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool validar()
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string obTipo()
    {
        if (validar() == false)
        {
            return "invalido";
        }
        else if (a == b && b == c)
        {
            return "equilatero";
        }
        else if (a == b || a == c || b == c)
        {
            return "isosceles";
        }
        else
        {
            return "escaleno";
        }
    }
    float obPerimetro()
    {
        if (validar() == false)
        {
            return -1;
        }
        else
        {
            return a + b + c;
        }
    }
    float obArea()
    {
        if (validar() == false)
        {
            return -1;
        }
        else
        {
            float semip = obPerimetro() / 2;
            return sqrt(semip * (semip - a) * (semip - b) * (semip - c));
        }
    }
};

int main()
{
    Triangulo *t1 = new Triangulo(7, 7, 7);
    Triangulo *t2 = new Triangulo(7, 7, 5);
    Triangulo *t3 = new Triangulo(7, 6, 5);
    Triangulo *t4 = new Triangulo(70, 6, 5);
    cout << t1->obTipo() << " " << t1->obPerimetro() << " " << t1->obArea() << endl;
    cout << t2->obTipo() << " " << t2->obPerimetro() << " " << t2->obArea() << endl;
    cout << t3->obTipo() << " " << t3->obPerimetro() << " " << t3->obArea() << endl;
    cout << t4->obTipo() << " " << t4->obPerimetro() << " " << t4->obArea() << endl;
}