#include "mylib.h"

int main(){
    
    list <string> Var, pVar, VargsiukaiVar, GalvociaiVar, VargsiukaipVar, GalvociaipVar;
    list <string>::iterator it1;
    list <string>::iterator it2;
    list <float> galut, Vargsiukaigalut, Galvociaigalut;
    list <float>::iterator it3;

    int stSk, Galutinis;
    string Vardas, Pavarde;
    
    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> stSk;

    ofstream out("StudentaiRandom.txt"); // failo sukurimas

    for(int i = 0; i < stSk; i++){
        out << "Vardenis" << i+1 << " Pavardenis" << i+1 << " " << rand() % 10 + 1 << endl;
    }

    out.close();

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    ifstream in("StudentaiRandom.txt"); // failo nuskaitymas

    for(int i = 0; i < stSk; i++){
        in >> Vardas >> Pavarde >> Galutinis;

        Var.push_back(Vardas);
        pVar.push_back(Pavarde);
        galut.push_back(Galutinis);
    }

    in.close();

    std::chrono::steady_clock::time_point e1 = std::chrono::steady_clock::now();

    double laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count())/1000000000.0;

    double sum = sum + laikas;

    cout << "Failo nuskaitymas uztruko: " << laikas << " sekundziu." << endl;

    it1 = Var.begin();
    it2 = pVar.begin();

    chrono::steady_clock::time_point b2 = std::chrono::steady_clock::now();

    ofstream out1("Galvociai.txt"); // studentu isskirstymas
    ofstream out2("Vargsiukai.txt");

    for(it3 = galut.begin(); it3 != galut.end(); ++it3){
        if(*it3 < 5){
            out2 << *it1 << " " << *it2 << " " << *it3 << endl;

            VargsiukaiVar.push_back(*it1);
            VargsiukaipVar.push_back(*it2);
            Vargsiukaigalut.push_back(*it3);
        }
            else if (*it3 >= 5){
                out1 << *it1 << " " << *it2 << " " << *it3 << endl;

                GalvociaiVar.push_back(*it1);
                GalvociaipVar.push_back(*it2);
                Galvociaigalut.push_back(*it3);
            }
        ++it1;
        ++it2;
    }

    out1.close();
    out2.close();

    chrono::steady_clock::time_point e2 = std::chrono::steady_clock::now();

    laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e2 - b2).count())/1000000000.0;

    sum = sum + laikas;

    cout << "Failo isrusiavimas ir ivedimas i naujus du failus uztruko: " << laikas << " sekundziu." << endl;
    cout << "Visi veiksmai sudejus uztruko: " << sum << " sekundziu." << endl;

    return 0;
}
