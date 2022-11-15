#include "mylib.h"
#include "strukturos.h"

int main(){

    vector <Studentai> stud;

    int stSk;
    
    cout << "Iveskite studentu skaiciu" << endl;
    cin  >> stSk;

    stud.resize(stSk);

    ofstream out("StudentaiRandom.txt"); // failo sukurimas

    for(int i = 0; i < stSk; i++){
        out << "Vardenis" << i+1 << " Pavardenis" << i+1 << " " << rand() % 10 + 1 << endl;
    }

    out.close();

    chrono::steady_clock::time_point b1 = std::chrono::steady_clock::now();

    ifstream in("StudentaiRandom.txt"); // failo nuskaitymas

    for(int i = 0; i < stSk; i++){
        in >> stud.at(i).Var >> stud.at(i).pVar >> stud.at(i).galut;
    }

    in.close();

    std::chrono::steady_clock::time_point e1 = std::chrono::steady_clock::now();

    double laikas = (chrono::duration_cast<std::chrono::nanoseconds>(e1 - b1).count())/1000000000.0;

    double sum = sum + laikas;

    cout << "Failo nuskaitymas uztruko: " << laikas << " sekundziu." << endl;

    chrono::steady_clock::time_point b2 = std::chrono::steady_clock::now();

    ofstream out1("Galvociai.txt"); // studentu isskirstymas
    ofstream out2("Vargsiukai.txt");

    for(int i = 0; i < stSk; i++){
        if(stud.at(i).galut < 5){
            out2 << stud.at(i).Var << " " << stud.at(i).pVar << " " << stud.at(i).galut << endl;
        }
            else if (stud.at(i).galut >= 5){
                out1 << stud.at(i).Var << " " << stud.at(i).pVar << " " << stud.at(i).galut << endl;
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
