#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;
using std::left; using std::right; using std::setw;


struct stud {
    string vardas = "", pavarde = "";
    int paz[3] = { 0 }, egz = 0; // paz - pazymiai, egz - egzamino rezultatas
    double vid = 0; // vid - pazymiu vidurkis;
};
void ivestis(stud& temp);
void isvestis(stud& temp);
int main()
{
    stud S;
    stud* masyvas = new stud[3];
    for (int i = 0; i < 3; i++) {
        ivestis(masyvas[i]);
    }
    cout << left << setw(20) << "Pavarde" << left << setw(20) << "Vardas" << left << setw(20) << "Pazymiai" << endl;
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
        cout << " Pazymys " << i + 1 << ":"; cin >> temp.paz[i];
    }
    cout << " Iveskite egzamino ivertinima: "; cin >> temp.egz;

}
void isvestis(stud& temp) {
    cout << left << setw(20)<< temp.pavarde << left << setw(20) << temp.vardas;
    for (int i = 0; i < 3; i++)
        cout << temp.paz[i] << " ";
    cout << temp.egz << endl;

}