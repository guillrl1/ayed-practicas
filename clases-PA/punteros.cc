#include <vector>

void invertirVector(std::vector<int>& v) {
    int* inicio = &v[0];
    int* fin = &v[v.size() - 1];

    while (inicio < fin) {
        std::swap(*inicio, *fin);
        inicio++;
        fin--;
    }
}
