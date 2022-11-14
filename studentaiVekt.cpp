#include "mylib.h"

struct Studentai{
    string Var;
    string pVar;
    vector <float> nd;
    float egz;
    float galut;
};

int main(){

    vector <Studentai> stud;

    int nrStud;
    int nrNd = 0;
    char arND;
    char MarV;
    char atsit;
    vector <int> size;

    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> nrStud;
    stud.resize(nrStud);
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
                cin  >> stud.at(i).Var;
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud.at(i).pVar;
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud.at(i).egz;
    
                for(int j = 0; j < nrNd; j++){
                    cout << "Iveskite " << i+1 << " studento " << j+1 << "namu darbu bala" << endl;
                    stud.at(i).nd.resize(j+1);
                    cin  >> stud.at(i).nd.at(j);
                }
            }
        }
            else if (atsit == 't'){ // atsitiktinai generuojami skaiciai
                for(int i = 0; i < nrStud; i++){
                    cout << "Iveskite " << i+1 << " studento varda" << endl;
                    cin  >> stud.at(i).Var;
                    cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                    cin  >> stud.at(i).pVar;
                    
                    stud.at(i).egz = rand() % 10 + 1;
                    for(int j = 0; j < nrNd; j++){
                        stud.at(i).nd.resize(j+1);
                        stud.at(i).nd.at(j) = rand() % 10 + 1;
                    }
                }
            }
    }
        else if(arND == 'n'){ // namu darbu kiekis vedant pasakomas
            for(int i = 0; i < nrStud; i++){
                cout << "Iveskite " << i+1 << " studento varda" << endl;
                cin  >> stud.at(i).Var;
                cout << "Iveskite " << i+1 << " studento pavarde" << endl;
                cin  >> stud.at(i).pVar;
                cout << "Iveskite " << i+1 << " studento egzamino bala" << endl;
                cin  >> stud.at(i).egz;

                for(int j = 0; j < 10000; j++){
                    cout << "Iveskite " << i+1 << "-o studento, " << j+1 << "-o namu darbu bala. Kai noresite baigti, irasykite -1" << endl;
                    stud.at(i).nd.resize(j+1);
                    cin  >> stud.at(i).nd.at(j);
                    
                    if(stud.at(i).nd.at(j) == -1){
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
            
            size.resize(stud.at(i).nd.size());
            size.at(i) = stud.at(i).nd.size() - 1;
            
            for(int j = 0; j < nrNd || j < size.at(i); j++){
                sumND = sumND + stud.at(i).nd.at(j);
            }
            if(arND == 'z'){
                stud.at(i).galut = 0.4 * sumND/nrNd + 0.6 * stud.at(i).egz;
            }
                else if(arND == 'n'){
                    stud.at(i).galut = 0.4 * sumND/size.at(i) + 0.6 * stud.at(i).egz;
                }
        }
    } 
        else if (MarV == 'm'){ // skaiciuojama mediana
            for(int i = 0; i < nrStud; i++){
                size.resize(stud.at(i).nd.size());
                size.at(i) = stud.at(i).nd.size() - 1;
                
                if(size.at(i) % 2 == 0){
                    stud.at(i).galut = 0.4 * (stud.at(i).nd.at(size.at(i)/2-1)+stud.at(i).nd.at(size.at(i)/2))/2 + 0.6 * stud.at(i).egz;
                }
                    else {
                        double dydis2 = size.at(i)/2.0;
                        cout << dydis2 << " = dydis2" << endl;
                        int dydis3 = round(dydis2-1);
                        cout << dydis3 << " = dydis3" << endl;
                        stud.at(i).galut = 0.4 * stud.at(i).nd.at(dydis3) + 0.6 * stud.at(i).egz;
                    }
            }
        }

    cout << "Pavarde                     Vardas                     Galutinis" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for(int i = 0; i < nrStud; i++){ // isvedamas rezultatas
        cout << stud.at(i).Var << "                     " << stud.at(i).pVar << "                     " << setprecision(3) << stud.at(i).galut << endl;
    }
    return 0;
}
