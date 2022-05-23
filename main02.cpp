#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<string, vector<string>    > pq;
    pq.push("Seminario");
    pq.push("Solucion");
    pq.push("De");
    pq.push("Problemas");
    pq.push("Estructuras");
    pq.push("Datos");

    while (!pq.empty())
    {
        auto e = pq.top();
        cout << e << endl;
        pq.pop();       
    }
    

    return 0;
}