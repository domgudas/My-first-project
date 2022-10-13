#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct Studentai{
    string Var[10000];
    string pVar[10000];
    float nd[10000][20];
    float egz[10000];
    float galut[10000];
    double counter[10000];
};

int main(){
    int nrStud;
    int nrNd;
    int studSkaic = 0;
    char arND;
    char MarV;
    char atsit;
    char skait;
    char iras;
    Studentai stud;

    cout << "Jei noresite skaityti is failo, irasykite s, jei ne, irasykite n" << endl;
    cin  >> skait;

    if (skait == 's'){
        try{
            ifstream in("studentai10000.txt");

            if(in.eof()){
                throw 0;
            }
        } 
            catch (int x){
                cout << "Duomenu failas yra tuscias ! ERROR NR. " << x << endl;
                
                return -1;
            }

        ifstream in("studentai10000.txt");

        studSkaic = 0;

        while(true){
            if(in.eof()){
                break;
            }

            in >> stud.Var[studSkaic];
            in >> stud.pVar[studSkaic];

            for(int j = 0; j < 15; j++){
                in >> stud.nd[studSkaic][j];
            }

            in >> stud.egz[studSkaic];
            studSkaic = studSkaic + 1;
        }

        in.close();

        cout << "Jei noresite viska pateikta mediana, irasykite m, o jei vidurkiu, irasykite v" << endl;
        cin  >> MarV;

        if(MarV == 'v'){ // skaiciuojamas vidurkis
            for(int i = 0; i < studSkaic; i++){
                float sumND = 0;

                for(int j = 0; j < 15; j++){
                    sumND = sumND + stud.nd[i][j];
                }
                
                stud.galut[i] = 0.4 * sumND/15 + 0.6 * stud.egz[i];
            }
        } 
            else if (MarV == 'm'){ // skaiciuojama mediana
                for(int i = 0; i < studSkaic; i++){
                    sort(stud.nd[i], stud.nd[i]+15);

                    double dydis2 = 15/2;
                    int dydis3 = round(dydis2-1);
                    // cout << stud.counter[i] << endl;
                    stud.galut[i] = 0.4 * stud.nd[i][dydis3] + 0.6 * stud.egz[i];
                        
                }
            }

        cout << "Jei noresite rezultato console, rasykite c, jei faile, rasykite f" << endl;
        cin  >> iras;
    }
    else if (skait == 'n'){
        try{
            cout << "Iveskite studentu skaiciu" << endl;
            cin  >> nrStud;

            if(nrStud <= 0){
                throw 1;
            }
        }
            catch (int x){
                cout << "Ivestas negalimas studentu skaicius! ERROR NR. " << x << endl;

                return -1;
            }

        try{
            cout << "Jei namu darbu kieki zinote is anksto, irasykite z, o jei nezinote, irasykite n" << endl;
            cin  >> arND;

            if(arND != 'z' && arND != 'n'){
                throw 2;
            }
        }
            catch (int x){
                cout << "Ivesta negalima raide! ERROR NR. " << x << endl;

                return -1;
            }

        try{
            cout << "Jei noresite viska pateikta mediana, irasykite m, o jei vidurkiu, irasykite v" << endl;
            cin  >> MarV;

            if(MarV != 'm' && MarV != 'v'){
                throw 3;
            }
        }
            catch (int x){
                cout << "Ivesta negalima raide! ERROR NR. " << x << endl;

                return -1;
            }

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
                }
                    else {
                        double dydis2 = stud.counter[i]/2;
                        int dydis3 = round(dydis2-1);
                        stud.galut[i] = 0.4 * stud.nd[i][dydis3] + 0.6 * stud.egz[i];
                    }
            }
        }
    }

    if(iras == 'c'){
        cout << "Pavarde" << setw(20) << " Vardas " << setw(23) << "Galutinis" << endl;
        cout << "-------------------------------------------------------" << endl;

        for(int i = 0; i < nrStud; i++){ // isvedamas rezultatas
          cout << stud.Var[i] << setw(20) << stud.pVar[i] << setprecision(3) << setw(20) << stud.galut[i] << endl;
        }
    }
        else if(iras == 'f'){
            ofstream out("rezultatai.txt");

            out << "Pavarde" << setw(20) << " Vardas " << setw(23) << "Galutinis" << endl;
            out << "-------------------------------------------------------" << endl;

            for(int i = 0; i < studSkaic; i++){ // isvedamas rezultatas
                out << stud.Var[i] << setw(20) << stud.pVar[i] << setprecision(3) << setw(20) << stud.galut[i] << endl;
            }

            out.close();
        }

    return 0;
}
