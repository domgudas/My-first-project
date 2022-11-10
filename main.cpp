#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <chrono>
#include <unistd.h>

using namespace std;

int main(){

    vector <string> Var;
    vector <string> pVar;
    vector <float> galut;
    list <string> LVar;
    list <string> LpVar;
    list <float> Lgalut;

    string Vardas, pVardas;
    float galutinis;

    int stSk;
    
    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> stSk;

    ofstream out("StudentaiRandom.txt"); // failo sukurimas

    for(int i = 0; i < stSk; i++){
        out << "Vardenis" << i+1 << " Pavardenis" << i+1 << " " << rand() % 10 + 1 << endl;
    }

    out.close();

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    ifstream in("StudentaiRandom.txt"); // failo nuskaitymas VECTOR

    for(int i = 0; i < stSk; i++){
        in >> Vardas >> pVardas >> galutinis;

        Var.push_back(Vardas);
        pVar.push_back(pVardas);
        galut.push_back(galutinis);
    }

    in.close();

    std::chrono::steady_clock::time_point e1 = std::chrono::steady_clock::now();

    double laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count())/1000000000.0;

    double sum = sum + laikas;

    cout << "Failo nuskaitymas vektoriais uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point b2 = std::chrono::steady_clock::now();

    ofstream out1("GalvociaiV.txt"); // studentu isskirstymas VECTOR
    ofstream out2("VargsiukaiV.txt");

    for(int i = 0; i < stSk; i++){
        if(galut[i] < 5){
            out2 << Var[i] << " " << pVar[i] << " " << galut[i] << endl;
        }
            else if (galut[i] >= 5){
                out1 << Var[i] << " " << pVar[i] << " " << galut[i] << endl;
            }
    }

    out1.close();
    out2.close();

    chrono::steady_clock::time_point e2 = std::chrono::steady_clock::now();

    laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e2 - b2).count())/1000000000.0;

    sum = sum + laikas;

    cout << "Failo isrusiavimas vektoriais ir ivedimas i naujus du failus uztruko: " << laikas << " sekundziu." << endl;
    cout << "Visi veiksmai sudejus uztruko: " << sum << " sekundziu." << endl;

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    // ------------------------------------------------------------------------------------------------------------------------------

    sum = 0;
    laikas = 0;

    ifstream in("StudentaiRandom.txt"); // failo nuskaitymas LIST

    for(int i = 0; i < stSk; i++){
        in >> Vardas >> pVardas >> galutinis;

        LVar.push_back(Vardas);
        LpVar.push_back(pVardas);
        Lgalut.push_back(galutinis);
    }

    in.close();

    std::chrono::steady_clock::time_point e1 = std::chrono::steady_clock::now();

    double laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count())/1000000000.0;

    double sum = sum + laikas;

    cout << "Failo nuskaitymas list uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point b2 = std::chrono::steady_clock::now();

    ofstream out1("GalvociaiL.txt"); // studentu isskirstymas LIST
    ofstream out2("VargsiukaiL.txt");

    for(float i = 0; i < stSk; i++){
        if(Lgalut[i] < 5){
            out2 << LVar[i] << " " << LpVar[i] << " " << Lgalut[i] << endl;
        }
            else if (galut[i] >= 5){
                out1 << LVar[i] << " " << LpVar[i] << " " << Lgalut[i] << endl;
            }
    }

    out1.close();
    out2.close();

    chrono::steady_clock::time_point e2 = std::chrono::steady_clock::now();

    laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e2 - b2).count())/1000000000.0;

    sum = sum + laikas;

    cout << "Failo isrusiavimas list ir ivedimas i naujus du failus uztruko: " << laikas << " sekundziu." << endl;
    cout << "Visi veiksmai sudejus uztruko: " << sum << " sekundziu." << endl;

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    return 0;
}
