#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;
using std::left; using std::right; using std::setw;


struct stud {
    string vardas = "", pavarde = "";
    int paz[3] = { 0 }, egz = 0; // paz - pazymiai, egz - egzamino rezultatas
    double galut = 0; // galut - galutinis studento ivertinimas;
};

void ivestis(stud& temp);
void isvestis(stud& temp);
void galutskaic(stud& temp); // Funkcija, kuri suskaiciuoja mokinio galutini pazymi

int main()
{
    stud* masyvas = new stud[3];
    for (int i = 0; i < 3; i++) {
        ivestis(masyvas[i]);
        galutskaic(masyvas[i]);
    }
    
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas" << left << setw(20) << "Galutinis (Vid.)" << endl;
    for (int i = 0; i < 3; i++) {
        isvestis(masyvas[i]);
    }

    delete[] masyvas;
    system("pause");
}

void ivestis(stud& temp) {
    int n = 3;
    cout << " Iveskite studento Varda: "; cin >> temp.vardas;
    cout << " Iveskite studento Pavarde: "; cin >> temp.pavarde;
    for (int i = 0; i < n; i++) {
        cout << " Iveskite ND pazymi " << i + 1 << ": "; cin >> temp.paz[i];
    }
    cout << " Iveskite egzamino ivertinima: "; cin >> temp.egz;
    
}
void isvestis(stud& temp) {
    cout << left << setw(20) << temp.pavarde << left << setw(20) << temp.vardas << left << setw(20) << std::fixed << std::setprecision(2) << temp.galut << endl;
}
void galutskaic(stud& temp) {
    int suma = 0;
    for (int i = 0; i < 3; i++)
        suma += temp.paz[i];
    temp.galut = 0.4 * (suma / 3) + 0.6 * temp.egz;
}