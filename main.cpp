#include "mylib.h"
#include "strukturos.h"

int main(){

    vector <Studentai> stud;

    int studSkaic;
    int nrStud = 0;
    int nrNd = 0;
    char iras;
    char arND;
    char MarV;
    char atsit;
    char skait;
    vector <int> size;
    
    cout << "Jei noresite skaityti is failo, irasykite t, jei noresite patys vesti duomenis, irasykite n" << endl;
    
    try{
        cin  >> skait;

        if(skait != 't' && skait != 'n'){
            throw 0;

            return -1;
        }
    }
        catch(int x){
            cout << "Ivesta raide neatitinka kriteriju ! ERROR NR. " << x << endl;
        }

    if (skait == 'n'){ // skaitomi duomenys is console 
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
    }
        else if (skait == 't'){ // skaitomi duomenys is failo
            try{
                ifstream in("studentai10000.txt");

                if(in.eof()){
                    throw 1;
                }
            } 
                catch (int x){
                    cout << "Duomenu failas yra tuscias ! ERROR NR. " << x << endl;
                    
                    return -1;
                }

            ifstream in ("studentai10000.txt");

            studSkaic = 0;

            while(true){
                if(in.eof()){
                    break;
                }

                studSkaic = studSkaic + 1;

                stud.resize(studSkaic);

                in >> stud.at(studSkaic - 1).Var;
                in >> stud.at(studSkaic - 1).pVar;

                for(int j = 0; j < 15; j++){
                    stud.at(studSkaic - 1).nd.resize(j+1);
                    in >> stud.at(studSkaic - 1).nd.at(j);
                }

                in >> stud.at(studSkaic - 1).egz;
            }

            in.close();

            cout << "Jei noresite viska pateikta mediana, irasykite m, o jei vidurkiu, irasykite v" << endl;

            try{
                cin  >> MarV;
                
                if(MarV != 'm' && MarV != 'v'){
                    throw 2;
                }
            }
                catch(int x) {
                    cout << "Ivesta raide neatitinka kriteriju ! ERROR NR. " << x << endl;
                }

            if(MarV == 'v'){ // skaiciuojamas vidurkis
                for(int i = 0; i < stud.size(); i++){
                    float sumND = 0;
                    
                    size.resize(stud.size());
                    size.at(i) = stud.at(i).nd.size();
                   
                    for(int j = 0; j < nrNd || j < size.at(i); j++){
                        sumND = sumND + stud.at(i).nd.at(j);
                    }
                    
                    stud.at(i).galut = 0.4 * sumND/size.at(i) + 0.6 * stud.at(i).egz;
                    
                }
            } 
            else if (MarV == 'm'){ // skaiciuojama mediana
                for(int i = 0; i < stud.size(); i++){
                    size.resize(stud.size());
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
            
            cout << "Jei noresite rodyti duomenis faile, rasykite f, o jei console, rasykite c" << endl;
            cin  >> iras;

        }
    if(iras == 'c'){ // isvedamas rezultatas
        cout << "Pavarde                     Vardas                     Galutinis" << endl;
        cout << "----------------------------------------------------------------" << endl;

        for(int i = 0; i < nrStud || i < stud.size(); i++){ 
            cout << stud.at(i).Var << "                     " << stud.at(i).pVar << "                     " << setprecision(3) << stud.at(i).galut << endl;
        }
    }
        else if(iras == 'f'){
            ofstream out("rezultatai.txt");

            out << "Pavarde                     Vardas                     Galutinis" << endl;
            out << "----------------------------------------------------------------" << endl;

            for(int i = 0; i < stud.size(); i++){ 
                out << stud.at(i).Var << "                     " << stud.at(i).pVar << "                     " << setprecision(3) << stud.at(i).galut << endl;
            }

            out.close();
        }

    return 0;
}
