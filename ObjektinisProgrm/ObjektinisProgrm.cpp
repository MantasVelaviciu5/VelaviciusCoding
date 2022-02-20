#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cout; using std::cin; using std::endl; using std::string;
using std::left; using std::right; using std::setw;


struct stud {
    string vardas = "", pavarde = "";
    int kiekpaz = 0, paz[10] = { 0 }, egz = 0;  // kiekpaz - pazymiu skaicius, paz - pazymiai, egz - egzamino rezultatas;
    double galut = 0, mediana = 0; // galut - galutinis studento ivertinimas;
};

void ivestis(stud& temp);
void isvestis(stud& temp);
void galutskaic(stud& temp); // Funkcija, kuri suskaiciuoja mokinio galutini pazymi;
void medskaic(stud& temp); // Funkcija, kuri randa mediana;

int kiekstud = 0;

int main()
{   
    kiekstud = 1;
    // cout << "Iveskite studentu skaiciu: "; cin >> kiekstud; // Galima butu padaryti, kad studento skaiciu irgi galima ivesti;
    stud* masyvas = new stud[kiekstud];
    for (int i = 0; i < kiekstud; i++) {
        ivestis(masyvas[i]);
        galutskaic(masyvas[i]);
        medskaic(masyvas[i]);
    }
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas" << left << setw(20) << "Galutinis (Vid.)" << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << " --------------------------------------------------------------------------- " << endl;
    for (int i = 0; i < kiekstud; i++) {
        isvestis(masyvas[i]);
    }
    delete[] masyvas;
    system("pause");
}

void ivestis(stud& temp) {
    cout << " Iveskite studento Varda: "; cin >> temp.vardas;
    cout << " Iveskite studento Pavarde: "; cin >> temp.pavarde;
    cout << " Iveskite ND pazymiu kieki: "; cin >> temp.kiekpaz;
    for (int i = 0; i < temp.kiekpaz; i++) {
        cout << " Iveskite ND pazymi " << i + 1 << ": "; cin >> temp.paz[i];
    }
    cout << " Iveskite egzamino ivertinima: "; cin >> temp.egz;
    
}
void isvestis(stud& temp) {
    cout << left << setw(20) << temp.pavarde << left << setw(20) << temp.vardas << left << setw(20) << std::fixed << std::setprecision(2) << temp.galut <<
        left << setw(20) << std::fixed << std::setprecision(2) << (double) temp.mediana << endl;
}
void galutskaic(stud& temp) {
    int suma = 0;
    for (int i = 0; i < temp.kiekpaz; i++)
        suma += temp.paz[i];
    temp.galut = 0.4 * (suma / temp.kiekpaz) + 0.6 * temp.egz;
}
void medskaic(stud& temp) {
    std::sort(temp.paz, temp.paz+temp.kiekpaz);
    if (temp.kiekpaz % 2 == 0)
        temp.mediana = (double) (temp.paz[(temp.kiekpaz / 2) - 1] + temp.paz[temp.kiekpaz / 2]) / 2.0;
    else temp.mediana = (double) temp.paz[(temp.kiekpaz - 1) / 2];
}