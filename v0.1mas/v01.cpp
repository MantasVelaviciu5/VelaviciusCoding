#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using std::cout; using std::cin; using std::endl; using std::string;
using std::left; using std::right; using std::setw; using std::vector;


struct Studentas {
    string vardas = "", pavarde = "";
    int kiekpazymiu = 0, paz[100] = { 0 }, egz = 0;
};
void nustatymai();
void ivestis(vector<Studentas>& stud, int ciklas);
void isvestis(vector<Studentas>& stud, int ciklas);
double galutskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri suskaiciuoja mokinio galutini pazymi;
double medskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri randa mediana;

char random, zpaz, rezultatas; /* random - kintamasis, kuris pasako, ar zmogus nores random budu generuoti pazymius ar ne;
                               zpaz - kintamasis, kuris pasako, ar zmogus zino pazymiu skaiciu ar ne; rezultatas - pasako,
                               ar zmogus nores galutini rezultata gauti pagal formule ar kaip moduli; */

int main()
{
    char Status = 't';  // Statuso kintamasis, kuris ziuri, kiek bus mokiniu;
    int ciklas = 0;     // Laikinas kintamasis, kuris pasako, kur esame vektoriuje; 
    vector<Studentas> stud;
    nustatymai(); // Funkcija, kuri zmogui leis pasirinkti sios funkcijos nustatymus;
    while (Status == 't' || Status == 'T') {
        ivestis(stud, ciklas);
        cout << " Itraukti dar viena studenta? [t / n]? "; cin >> Status;
        ciklas++;
    }
    isvestis(stud, ciklas);
    system("pause");
}
void nustatymai() {
    cout << " Ar pazymiu kiekis yra zinomas is anksto? [t / n]?: "; cin >> zpaz;
    cout << " Ar norite, kad ND pazymiai ir egzamino rezultatas butu sugeneruoti automatiskai? [t / n]? : "; cin >> random;
    cout << " Skaiciuojant galutini rezultata norite, kad butu naudojamas pazymiu vidurkis [v] ar pazymiu mediana [m]? [v / m]?: "; cin >> rezultatas;
}

void ivestis(vector<Studentas>& stud, int ciklas) {
    cout << " Iveskite studento Varda: ";
    stud.push_back(Studentas());
    cin >> stud[ciklas].vardas;
    cout << " Iveskite studento Pavarde: "; cin >> stud[ciklas].pavarde;

    if (random == 't' && zpaz == 't' || random == 'T' && zpaz == 'T') {
        cout << " Iveskite pazymiu kieki: "; cin >> stud[ciklas].kiekpazymiu;
        srand(static_cast<unsigned int> (std::time(NULL)));
        int i = 0;
        while (i < stud[ciklas].kiekpazymiu) {
            stud[ciklas].paz[i] = rand() % 10 + 1;
            i++;
        }
        stud[ciklas].egz = rand() % 10 + 1;
        cout << " Sugeneruoti pazymiai: ";
        for (int j = 0; j < i; j++) cout << stud[ciklas].paz[j] << ", ";
        cout << endl << " Sugeneruotas egzamino rezultatas: " << stud[ciklas].egz << endl;
    }
    else if (random == 't' && zpaz == 'n' || random == 'T' && zpaz == 'N') {
        srand(static_cast<unsigned int> (std::time(NULL)));
        char tempraid = 't'; // Laikinas kintamasis
        while (tempraid == 't') {
            stud[ciklas].paz[stud[ciklas].kiekpazymiu] = rand() % 10 + 1;
            cout << "Sugeneruotas pazymys nr. " << stud[ciklas].kiekpazymiu + 1 << ": " << stud[ciklas].paz[stud[ciklas].kiekpazymiu] << endl;
            stud[ciklas].kiekpazymiu++;
            cout << "Ar norite sugeneruoti dar viena pazymi? [t / n]?: "; cin >> tempraid;
        }
        stud[ciklas].egz = rand() % 10 + 1;
        cout << " Sugeneruotas egzamino pazymys: " << stud[ciklas].egz << endl;
    }
    else if (random == 'n' && zpaz == 'n' || random == 'N' && zpaz == 'N') {
        int tempsk = 0; // Laikinas kintamasis
        while (tempsk <= 10 && tempsk >= 0) {
            cout << " Iveskite ND pazymi nr. " << stud[ciklas].kiekpazymiu + 1 << " arba rasykite '-1' jei norite nutraukti pazymiu vedima : "; cin >> tempsk;
            if (tempsk <= 10 && tempsk >= 0) {
                stud[ciklas].paz[stud[ciklas].kiekpazymiu] = tempsk;
                stud[ciklas].kiekpazymiu++;
            }
        }
        cout << " Iveskite egzamino pazymi: "; cin >> stud[ciklas].egz;
    }
    else { // Kai random = n ir zpaz = t;
        cout << " Iveskite pazymiu kieki: "; cin >> stud[ciklas].kiekpazymiu;
        for (int i = 0; i < stud[ciklas].kiekpazymiu; i++) {
            cout << " Iveskite ND pazymi nr. " << i + 1 << ": "; cin >> stud[ciklas].paz[i];
        }
        cout << " Iveskite egzamino pazymi: "; cin >> stud[ciklas].egz;
    }
}
void isvestis(vector<Studentas>& stud, int ciklas) {
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas";
    if (rezultatas == 'v' || rezultatas == 'V') cout << left << setw(20) << "Galutinis (Vid.)" << endl;
    else cout << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << " --------------------------------------------------------- " << endl;
    for (int i = 0; i < ciklas; i++)
        cout << left << setw(20) << stud[i].pavarde << left << setw(20) << stud[i].vardas << left << setw(20) << std::fixed << std::setprecision(2) << galutskaic(stud, i) << endl;
}
double galutskaic(vector<Studentas>& stud, int ciklas) {
    if (rezultatas == 'v' || rezultatas == 'V') {
        int suma = 0;
        for (int i = 0; i < stud[ciklas].kiekpazymiu; i++)
            suma += stud[ciklas].paz[i];
        return 0.4 * (suma / stud[ciklas].kiekpazymiu) + 0.6 * stud[ciklas].egz;
    }
    else
        return 0.4 * (medskaic(stud, ciklas) / stud[ciklas].kiekpazymiu) + 0.6 * stud[ciklas].egz;
}
double medskaic(vector<Studentas>& stud, int ciklas) {
    std::sort(stud[ciklas].paz, stud[ciklas].paz + stud[ciklas].kiekpazymiu);
    if (stud[ciklas].kiekpazymiu % 2 == 0)
        return (stud[ciklas].paz[(stud[ciklas].kiekpazymiu / 2) - 1] + stud[ciklas].paz[stud[ciklas].kiekpazymiu / 2]) / 2.0;
    else return stud[ciklas].paz[(stud[ciklas].kiekpazymiu - 1) / 2];

}