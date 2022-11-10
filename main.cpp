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

    // ------------------------------------------------------------------------------------------------------------------------------

    sum = 0;
    laikas = 0;

    chrono::steady_clock::time_point g1 = std::chrono::steady_clock::now();

    ifstream in1("StudentaiRandom.txt"); // failo nuskaitymas LIST

    for(int i = 0; i < stSk; i++){
        in >> Vardas >> pVardas >> galutinis;

        LVar.push_back(Vardas);
        LpVar.push_back(pVardas);
        Lgalut.push_back(galutinis);
    }

    in.close();

    std::chrono::steady_clock::time_point h1 = std::chrono::steady_clock::now();

    double laikas1 = (chrono::duration_cast<std::chrono::nanoseconds>(h1 - g1).count())/1000000000.0;

    double sum1 = sum1 + laikas1;

    cout << "Failo nuskaitymas list uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point j2 = std::chrono::steady_clock::now();

    ofstream out3("GalvociaiL.txt"); // studentu isskirstymas LIST
    ofstream out4("VargsiukaiL.txt");

    string A[1000000];
    string B[1000000];
    float C[1000000];

    int i = 0;

    for(string x : LVar){
        A[i] = x;
        i++;
    }

    for(string x : LpVar){
        B[i] = x;
        i++;
    }

    for(float x : Lgalut){
        C[i] = x;
        i++;
    }

    for(int i = 0; i < stSk; i++){
        if(C[i] < 5){
            out4 << A[i] << " " << B[i] << " " << C[i] << endl;
        }
            else if (C[i] >= 5){
                out3 << A[i] << " " << B[i] << " " << C[i] << endl;
            }
    }

    out1.close();
    out2.close();

    chrono::steady_clock::time_point k2 = std::chrono::steady_clock::now();

    laikas = (chrono::duration_cast<std::chrono::nanoseconds>(k2 - j2).count())/1000000000.0;

    sum1 = sum1 + laikas1;

    cout << "Failo isrusiavimas list ir ivedimas i naujus du failus uztruko: " << laikas << " sekundziu." << endl;
    cout << "Visi veiksmai sudejus uztruko: " << sum << " sekundziu." << endl;

    return 0;
}
