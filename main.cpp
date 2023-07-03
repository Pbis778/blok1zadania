#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdio>

using namespace std;

char* alokacjaPamieci(int size) {
    char* dynamicznaTablica = new char[size+2];

    char* zapisRozmiaru = dynamicznaTablica;
    *zapisRozmiaru = char(size & 0xFF);
    *(zapisRozmiaru+1) = char((size >> 8) & 0xFF);

    return dynamicznaTablica+2;
}

void dealokacja(char** tab) {
    if (*tab != nullptr) {
        delete[] *tab;
        *tab = nullptr;
    }
}

/*void odczytPliku(const char* nazwaPliku, int dlugoscLinii) {
    setlocale(LC_ALL, "");
    constexpr size_t ROZMIAR = 100;
    FILE* plik = fopen(nazwaPliku, "r");
    char tekst[ROZMIAR] = {};

    char* buforLinii = alokacjaPamieci(dlugoscLinii);
    char* obecnaLinia = buforLinii;

    int licznikZnakow = 0;
    
    if (plik == nullptr) {
        cout << "Blad otwarcia pliku" << endl;
        return;
    }

    while (!feof(plik)) {
        fgets(tekst, ROZMIAR, plik);
        cout << tekst << endl;
        licznikZnakow++;

        if (licznikZnakow == dlugoscLinii) {
            fputc('\n', plik);
            licznikZnakow = 0;
        }
    }

    fclose(plik);
    dealokacja(&buforLinii);
}*/

ostream& operator<< (ostream& ekr, FILE* plik) {
    char znak;
    int licznikZnakow = 0;
    if (plik != nullptr) {
        rewind(plik);
        while(!feof(plik)) {
            znak = fgetc(plik);
            licznikZnakow++;

            if (licznikZnakow == 20) {
                ekr << endl;
                licznikZnakow = 0;
            }
            ekr << znak;
        }
    }
    return ekr;
}

int main() {
    int dlugosc = 20;
    FILE* plik;
    char bufor[100];

    plik = fopen("tekst.txt", "r");

    cout << plik << endl;

    fclose(plik);

    //odczytPliku("tekst.txt", dlugosc);
}