#include <queue>
#include <iostream>
#include <vector>
using namespace std;


vector<int> kclosest(const vector<int>& HouseNumbers, int N, int X, int K) {

    // Heap erstellen (Bestehend aus Paaren Hausnummer & Abstand) - Priority Queue ist Quasi ein Heap
    // Heap kann dann als Min Heap sortiert werden (Erstes Element des Paares, hier der Abstand)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    // Heap wird mit den Hausnummern und den berechneten Abständen befüllt
        for (int i = 0; i < N; ++i) {
            int distance = abs(HouseNumbers[i] - X);
            min_heap.push({ distance, HouseNumbers[i] });
        }

    // Die K ersten Elemente werden Ausgelesen
    // Dank Min-Heap entsprechen sie den K nächsten Häusern
    vector<int> closest;
    for (int i = 0; i < K; ++i) {
        closest.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return closest;
}

int main()
{
    // Alle Hausnummern der Nachbarn
    vector<int> HouseNumbers = { 22, 34, 20, 1, 54, 3, 9, 15, 10, 11};
    int N = HouseNumbers.size();

    int X = 10;     // Karls Hausnummer
    int K = 3;      // Nächste Häuser

    // Funktionsaufruf und Rückgabe der Werte
    vector<int> ClosestHouses = kclosest(HouseNumbers, N, X, K);

    // Ausgabe
    cout << "Die " << K << " naechsten Haeuser sind: ";
    for (int House : ClosestHouses) {
        cout << House << " ";
    }
    cout << endl;

    return 0;
}
