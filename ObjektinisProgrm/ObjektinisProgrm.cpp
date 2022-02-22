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
    int paz[100] = { 0 }, egz = 0;
};
void nustatymai();
void ivestis(vector<Studentas>& stud, int ciklas);
void isvestis(vector<Studentas>& stud, int ciklas);
double galutskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri suskaiciuoja mokinio galutini pazymi;
double medskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri randa mediana;

int kiekpaz = 0;
char random, zpaz, rezultatas; /* random - kintamasis, kuris pasako, ar zmogus nores random budu generuoti pazymius ar ne;
                               zpaz - kintamasis, kuris pasako, ar zmogus zino pazymiu skaiciu ar ne; rezultatas - pasako, 
                               ar zmogus nores galutini rezultata gauti pagal formule ar kaip moduli; */

int main()
{
    char Status = 't';  // Statuso kintamasis, kuris ziuri, kiek bus mokiniu;
    int ciklas = 0;     // Laikinas kintamasis, kuris pasako, kur esame vektoriuje; 
    vector<Studentas> stud;
    nustatymai(); // Funkcija, kuri zmogui leis pasirinkti sios funkcijos nustatymus;
    while (Status == 't') {
        ivestis(stud, ciklas);
        cout << " Itraukti dar viena studenta? [t / n]? "; cin >> Status;
        ciklas++;
    }
    isvestis(stud, ciklas);
    system("pause");
}
void nustatymai() {
    cout << " Ar pazymiu kiekis yra zinomas is anksto? [t / n]?: "; cin >> zpaz;
    if (zpaz == 't') {
        cout << "   Iveskite ta skaiciu: "; cin >> kiekpaz;
        cout << " Ar norite, kad ND pazymiai ir egzamino rezultatas butu sugeneruoti automatiskai? [t / n]? :"; cin >> random;
    }
    cout << " Skaiciuojant galutini rezultata norite, kad butu naudojamas pazymiu vidurkis [v] ar pazymiu mediana [m]? [v / m]?: "; cin >> rezultatas;
}

void ivestis(vector<Studentas>& stud, int ciklas) {
    cout << " Iveskite studento Varda: ";
    stud.push_back(Studentas());
    cin >> stud[ciklas].vardas;
    cout << " Iveskite studento Pavarde: "; cin >> stud[ciklas].pavarde;

    if (random == 't' && zpaz == 't') {
        srand(static_cast<unsigned int> (std::time(NULL)));
        int i = 0;
        while (i < kiekpaz) {
            stud[ciklas].paz[i] = rand() % 10 + 1;
            i++;
        }
        stud[ciklas].egz = rand() % 10 + 1;
    }
    else if (zpaz == 'n') {
        char status = 't';
        while (status == 't') {
            cout << " Iveskite ND pazymi nr. " << kiekpaz + 1 << ": "; cin >> stud[ciklas].paz[kiekpaz];
            kiekpaz++;
            cout << "   Itraukti dar viena pazymi? [t / n]?: "; cin >> status;
        }
        cout << " Iveskite egzamino pazymi: "; cin >> stud[ciklas].egz;
    }
    else {
        for (int i = 0; i < kiekpaz; i++) {
            cout << " Iveskite ND pazymi nr. " << i + 1 << ": "; cin >> stud[ciklas].paz[i];
            } 
        cout << " Iveskite egzamino pazymi: "; cin >> stud[ciklas].egz;
    }
}
void isvestis(vector<Studentas>& stud, int ciklas) {
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas";
    if (rezultatas == 'v') cout << left << setw(20) << "Galutinis (Vid.)" << endl;
    else cout << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << " --------------------------------------------------------- " << endl;
    for(int i = 0; i < ciklas; i++)
        cout << left << setw(20) << stud[i].pavarde << left << setw(20) << stud[i].vardas << left << setw(20) << std::fixed << std::setprecision(2) << galutskaic(stud, i) << endl;
}
double galutskaic(vector<Studentas>& stud, int ciklas) {
    if (rezultatas == 'v') {
        int suma = 0;
        for (int i = 0; i < kiekpaz; i++)
            suma += stud[ciklas].paz[i];
        return 0.4 * (suma / kiekpaz) + 0.6 * stud[ciklas].egz;
    }
    else 
        return 0.4 * (medskaic(stud, ciklas) / kiekpaz) + 0.6 * stud[ciklas].egz;
}
double medskaic(vector<Studentas>& stud, int ciklas) {
    std::sort(stud[ciklas].paz, stud[ciklas].paz + kiekpaz);
    if (kiekpaz % 2 == 0)
        return (stud[ciklas].paz[(kiekpaz / 2) - 1] + stud[ciklas].paz[kiekpaz / 2]) / 2.0;
    else return stud[ciklas].paz[(kiekpaz - 1) / 2];

}