#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <chrono>
#include <unistd.h>

using namespace std;

struct Studentai{
    string Var[10000];
    string pVar[10000];
    float galut[10000];
};

int main(){

    Studentai stud;

    int stSk;
    
    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> stSk;

    chrono::steady_clock::time_point b0 = std::chrono::steady_clock::now();

    ofstream out("StudentaiRandom.txt"); // failo sukurimas

    for(int i = 0; i < stSk; i++){
        out << "Vardenis" << i+1 << " Pavardenis" << i+1 << " " << rand() % 10 + 1 << endl;
    }

    out.close();

    std::chrono::steady_clock::time_point e0 = std::chrono::steady_clock::now();

    double laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e0 - b0).count())/1000000000.0;
    double sum = laikas;

    cout << "Failo sukurimas uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    ifstream in("StudentaiRandom.txt"); // failo nuskaitymas

    for(int i = 0; i < stSk; i++){
        in >> stud.Var[i] >> stud.pVar[i] >> stud.galut[i];
    }

    in.close();

    std::chrono::steady_clock::time_point e1 = std::chrono::steady_clock::now();

    laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count())/1000000000.0;

    sum = sum + laikas;

    cout << "Failo nuskaitymas uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point b2 = std::chrono::steady_clock::now();

    ofstream out1("Galvociai.txt"); // studentu isskirstymas
    ofstream out2("Vargsiukai.txt");

    for(int i = 0; i < stSk; i++){
        if(stud.galut[i] < 5){
            out2 << stud.Var[i] << " " << stud.pVar[i] << " " << stud.galut[i] << endl;
        }
            else if (stud.galut[i] >= 5){
                out1 << stud.Var[i] << " " << stud.pVar[i] << " " << stud.galut[i] << endl;
            }
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
