#include "mylib.h"

struct Studentai{
    string Var;
    string pVar;
    float nd[100];
    float egz;
    float galut;
};

int main(){
    int nrStud;
    int nrNd;
    char arND;
    char MarV;
    char atsit;
    int size[10000];

    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> nrStud;
    Studentai stud [nrStud];
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
                cin  >> stud[i].Var;
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud[i].pVar;
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud[i].egz;
    
                for(int j = 0; j < nrNd; j++){
                    cout << "Iveskite " << i+1 << " studento " << j+1 << "namu darbu bala" << endl;
                    cin  >> stud[i].nd[j];
                }
            }
        }
            else if (atsit == 't'){ // atsitiktinai generuojami skaiciai
                for(int i = 0; i < nrStud; i++){
                    cout << "Iveskite " << i+1 << " studento varda" << endl;
                    cin  >> stud[i].Var;
                    cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                    cin  >> stud[i].pVar;
                    
                    stud[i].egz = rand() % 10 + 1;
                    for(int j = 0; j < nrNd; j++){
                        stud[i].nd[j] = rand() % 10 + 1;
                    }
                }
            }
    }
        else if(arND == 'n'){ // namu darbu kiekis vedant pasakomas
            for(int i = 0; i < nrStud; i++){
                cout << "Iveskite " << i+1 << " studento varda" << endl;
                cin  >> stud[i].Var;
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud[i].pVar;
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud[i].egz;

                for(int j = 0; j < 10000; j++){
                    cout << "Iveskite " << i+1 << "-o studento, " << j+1 << "-o namu darbu bala. Kai noresite baigti, irasykite -1" << endl;
                    cin  >> stud[i].nd[j];

                    if(stud[i].nd[j] == -1){
                        break;
                    }
                        else {
                            continue;
                        }
                }
            }
        }

    if(MarV == 'v'){ // skaiciuojamas vidurkis
        for(int i = 0; i < nrStud; i++){
            float sumND = 0;
            size[i] = sizeof(stud[i].nd)/sizeof(stud[i].nd[0]);

            for(int j = 0; j < nrNd || j < size[i]; j++){
                sumND = sumND + stud[i].nd[j];
            }
            if(arND == 'z'){
                stud[i].galut = 0.4 * sumND/nrNd + 0.6 * stud[i].egz;
            }
                else if(arND == 'n'){
                    stud[i].galut = 0.4 * sumND/size[i] + 0.6 * stud[i].egz;
                }
        }
    } 
        else if (MarV == 'm'){ // skaiciuojama mediana
            for(int i = 0; i < nrStud; i++){
                
                if(size[i] % 2 == 0){
                    stud[i].galut = 0.4 * (stud[i].nd[size[i]/2-1]+stud[i].nd[size[i]/2])/2 + 0.6 * stud[i].egz;
                    cout << (stud[i].nd[size[i]/2-1]+stud[i].nd[size[i]/2])/2 << endl;
                }
                    else {
                        double dydis2 = size[i]/2;
                        int dydis3 = round(dydis2-1);
                        cout << size[i] << endl;
                        stud[i].galut = 0.4 * stud[i].nd[dydis3] + 0.6 * stud[i].egz;
                    }
            }
        }

    cout << "Pavarde                     Vardas                     Galutinis" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for(int i = 0; i < nrStud; i++){ // isvedamas rezultatas
        cout << stud[i].Var << "                     " << stud[i].pVar << "                     " << setprecision(3) << stud[i].galut << endl;
    }
    return 0;
}
