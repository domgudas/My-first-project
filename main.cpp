#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct Studentai{
    string Var[100];
    string pVar[100];
    float nd[100][10];
    float egz[100];
    float galut[100];
    double counter[100];
};

int main(){
    int nrStud;
    int nrNd;
    char arND;
    char MarV;
    char atsit;
    Studentai stud;

    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> nrStud;
    cout << "Jei namu darbu kieki zinote is anksto, irasykite z, o jei nezinote, irasykite n" << endl;
    cin  >> arND;
    cout << "Jei noresite viska pateikta mediana, irasykite m, o jei vidurkiu, irasykite v" << endl;
    cin  >> MarV;

    if(arND == 'z'){ // namu darbu kiekis is anksto zinomas 
        cout << "Iveskite namu darbu skaiciu" << endl;
        cin  >> nrNd;
        cout << "Ar norite atsitiktinai sugeneruoti egzamino ir namu darbu balus? Jei taip, rasykite t, o jei ne, rasykite n" << endl;
        cin  >> atsit;

        if(atsit == 'n'){ // neatsitiktinai 
            for(int i = 0; i < nrStud; i++){
                cout << "Iveskite " << i+1 << " studento varda" << endl;
                cin  >> stud.Var[i];
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud.pVar[i];
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud.egz[i];
    
                for(int j = 0; j < nrNd; j++){
                    cout << "Iveskite " << i+1 << " studento " << j+1 << "namu darbu bala" << endl;
                    cin  >> stud.nd[i][j];
                }
            }
        }
            else if (atsit == 't'){ // atsitiktinai generuojami skaiciai
                for(int i = 0; i < nrStud; i++){
                    cout << "Iveskite " << i+1 << " studento varda" << endl;
                    cin  >> stud.Var[i];
                    cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                    cin  >> stud.pVar[i];
                    
                    stud.egz[i] = rand() % 10 + 1;
                    for(int j = 0; j < nrNd; j++){
                        stud.nd[i][j] = rand() % 10 + 1;
                    }
                }
            }
    }
        else if(arND == 'n'){ // namu darbu kiekis vedant pasakomas
            for(int i = 0; i < nrStud; i++){
                cout << "Iveskite " << i+1 << " studento varda" << endl;
                cin  >> stud.Var[i];
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud.pVar[i];
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud.egz[i];

                stud.counter[i] = 0;
                for(int j = 0; j < 10000; j++){
                    cout << "Iveskite " << i+1 << "-o studento, " << j+1 << "-o namu darbu bala. Kai noresite baigti, irasykite -1" << endl;
                    cin  >> stud.nd[i][j];

                    if(stud.nd[i][j] == -1){
                        break;
                    }
                        else {
                            stud.counter[i] = stud.counter[i] + 1;
                        }
                }
            }
        }

    if(MarV == 'v'){ // skaiciuojamas vidurkis
        for(int i = 0; i < nrStud; i++){
            float sumND = 0;

            for(int j = 0; j < nrNd || j < stud.counter[i]; j++){
                sumND = sumND + stud.nd[i][j];
            }
            if(arND == 'z'){
                stud.galut[i] = 0.4 * sumND/nrNd + 0.6 * stud.egz[i];
            }
                else if(arND == 'n'){
                    stud.galut[i] = 0.4 * sumND/stud.counter[i] + 0.6 * stud.egz[i];
                }
        }
    } 
        else if (MarV == 'm'){ // skaiciuojama mediana
            for(int i = 0; i < nrStud; i++){
                int c = stud.counter[i];
                if(c % 2 == 0){
                    stud.galut[i] = 0.4 * (stud.nd[i][c/2-1]+stud.nd[i][c/2])/2 + 0.6 * stud.egz[i];
                    cout << (stud.nd[i][c/2-1]+stud.nd[i][c/2])/2 << endl;
                }
                    else {
                        double dydis2 = stud.counter[i]/2;
                        int dydis3 = round(dydis2-1);
                        cout << stud.counter[i] << endl;
                        stud.galut[i] = 0.4 * stud.nd[i][dydis3] + 0.6 * stud.egz[i];
                    }
            }
        }

    cout << "Pavarde                     Vardas                     Galutinis" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for(int i = 0; i < nrStud; i++){ // isvedamas rezultatas
        cout << stud.Var[i] << "                     " << stud.pVar[i] << "                     " << setprecision(3) << stud.galut[i] << endl;
    }
    return 0;
}
