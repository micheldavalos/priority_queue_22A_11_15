#include <iostream>
#include <queue>

using namespace std;

class Barco
{
    string id;
    double velocidad;
    double combustible;
    double armadura;

public:
    Barco(string i, double v, double c, double a) {
        id = i;
        velocidad = v;
        combustible = c;
        armadura = a;
    }

    friend ostream& operator<<(ostream& out, Barco& b) {
        out << b.id << " "
            << b.velocidad << " "
            << b.combustible << " "
            << b.armadura;
        return out;
    }

    double getVelocidad() { return velocidad; }

    struct cmp {
        bool operator()(Barco* b1, Barco* b2) {
            return b1->getVelocidad() < b2->getVelocidad();
        }
    };
};

class Civilizacion
{
    priority_queue<Barco*, vector<Barco*>, Barco::cmp> batalla;

public:
    Civilizacion() {
        batalla.push(new Barco("1", 10, 100, 90));
        batalla.push(new Barco("2", 2, 100, 80));
        batalla.push(new Barco("3", 9, 100, 70));
        batalla.push(new Barco("4", 5, 100, 50));
    }

    void mostrar() {
        priority_queue<Barco*, 
                        vector<Barco*>, 
                        Barco::cmp> copia(batalla);
        while (!copia.empty())
        {
            auto barco = copia.top();
            cout << *barco << endl;
            copia.pop();
        }
        
    }

};

int main() {
    Civilizacion c;
    c.mostrar();
    return 0;
}