#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int pivo(vector<int> &vec, int baixo, int alto) {
    return baixo + (alto - baixo) / 2;
}

int particiona(vector<int> &vec, int baixo, int alto) {
    int index_pivo{pivo(vec, baixo, alto)};
    int pivo{vec[index_pivo]};

    swap(vec[index_pivo], vec[alto]);

    int i = baixo - 1;

    for (int j{baixo}; j <= alto - 1; j++) {
        if (vec[j] < pivo) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[alto]);
    return i + 1;
}

void quickSort(vector<int> &vec, int baixo, int alto) {
    if (baixo < alto) {
        int index_pivo = particiona(vec, baixo, alto);

        quickSort(vec, baixo, index_pivo - 1);
        quickSort(vec, index_pivo + 1, alto);
    }
}

void quickSort(vector<int> &vec) {
    int n = vec.size();
    quickSort(vec, 0, n - 1);
}

void printVec(const vector<int> &vec) {
    int n = vec.size();
    for (int i{0}; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main(void) {
    vector<int> vec;

    int i{100};

    while ( i ) {
        i--;
        vec.push_back(i);
    }


    printVec(vec);
    quickSort(vec);
    printVec(vec);

    return 0;
}
