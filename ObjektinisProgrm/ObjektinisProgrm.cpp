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

void ivestis(vector<Studentas>& stud, int ciklas);
void isvestis(vector<Studentas>& stud, int ciklas);
double galutskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri suskaiciuoja mokinio galutini pazymi;
double medskaic(vector<Studentas>& stud, int ciklas); // Funkcija, kuri randa mediana;

int kiekpaz = 0;

int main()
{
    char Status = 't';  // Statuso kintamasis, kuris ziuri, kiek bus mokiniu;
    int ciklas = 0;     // Laikinas kintamasis, kuris pasako, kur esame vektoriuje; 
    vector<Studentas> stud;
    while (Status == 't'){
        ivestis(stud, ciklas);
        cout << " Itraukti dar viena studenta? [t / n]?: "; cin >> Status;
        ciklas++;
    }   
    isvestis(stud, ciklas);
    system("pause");
}

void ivestis(vector<Studentas>&stud, int ciklas) {
    cout << " Iveskite studento Varda: "; 
    stud.push_back(Studentas());
    cin >> stud[ciklas].vardas;
    cout << " Iveskite studento Pavarde: "; cin >> stud[ciklas].pavarde;

    char stat = 't';
    while (stat == 't') {
        cout << " Iveskite ND pazymi " << kiekpaz + 1 << " : "; cin >> stud[ciklas].paz[kiekpaz];
        kiekpaz++;
        cout << " Ar norite ivesti dar viena pazymi? [t / n]?: "; cin >> stat;
    }
    cout << " Iveskite egzamino pazymi: "; cin >> stud[ciklas].egz;
    
}
void isvestis(vector<Studentas>& stud, int ciklas) {
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas" << left << setw(20) << "Galutinis (Vid.)" << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << " --------------------------------------------------------------------------- " << endl;
    for (int i = 0; i < ciklas; i++) 
        cout << endl << left << setw(20) << stud[i].pavarde << left << setw(20) << stud[i].vardas << left << setw(20) << std::fixed << std::setprecision(2) << galutskaic(stud, i) <<
            left << setw(20) << std::fixed << std::setprecision(2) << medskaic(stud, i) << endl;
}
double galutskaic(vector<Studentas>& stud, int ciklas) {
    int suma = 0;
    for (int i = 0; i < kiekpaz; i++)
        suma += stud[ciklas].paz[i];
     return 0.4 * (suma / kiekpaz) + 0.6 * stud[ciklas].egz;
     
}
double medskaic(vector<Studentas>& stud, int ciklas) {
    std::sort(stud[ciklas].paz, stud[ciklas].paz + kiekpaz);
    if (kiekpaz % 2 == 0)
        return (stud[ciklas].paz[(kiekpaz / 2) - 1] + stud[ciklas].paz[kiekpaz / 2]) / 2.0;
    else return stud[ciklas].paz[(kiekpaz - 1) / 2];
     
}