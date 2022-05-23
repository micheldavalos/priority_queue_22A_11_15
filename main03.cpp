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
};

int main() {
    auto cmp = [](Barco* b1, Barco* b2){
        return b1->getVelocidad() > b2->getVelocidad();
    };
    priority_queue<Barco*, vector<Barco*>, decltype(cmp) > pq(cmp);

    pq.push(new Barco("1", 10, 100, 90));
    pq.push(new Barco("2", 2, 100, 80));
    pq.push(new Barco("3", 9, 100, 70));
    pq.push(new Barco("4", 5, 100, 50));

    while (!pq.empty())
    {
        auto barco = pq.top();
        cout << *barco << endl;
        pq.pop();
        
    }
    
    return 0;
}