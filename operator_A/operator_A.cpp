#include <iostream>
#include <string>
#include <list>

using namespace std;

enum CivilianType {
    City,
    Farm,
    Industry,
    def
};

struct Catapult {
    //con/des
    Catapult() {
        cout << " - cons def -  Catapult "  << endl;
        Unit_Name = "Rising Hell";
    }
    Catapult(int damage) { 
        Unit_Damage = damage; 
        // code
    }  // con overloaded
    Catapult(string name) { 
        Unit_Name = name; 
    }  // con overloaded
    ~Catapult() { 
        cout << " - free memory ++  Catapult " << Unit_Name <<endl;
    }  

    // properties
    string Unit_Name = "##";
    int Unit_Count = 0;
    int Unit_Damage = 500;
    int Unit_Shield = 0;
    
    // functions/methods
    void dbug(string txt) {
        if (Unit_Shield < 0)  cout << " xx " << txt << " is destroyed xx " << endl;
        if (Unit_Shield >= 0) cout << " " << txt << " shield: " << Unit_Shield << endl;
    }
};

struct CivHouse {
    //con/des
    CivHouse() {
        Unit_Name = "House level 2";
        Unit_Shield = 12000; // <-- will replace base class value from 0 to 12000
    }
    CivHouse(CivilianType houseType) {
        CivType_01 = houseType;
    }
    ~CivHouse() {
        cout << " - free memory |  CivHouse" << endl;
    } 
    // properties
    string Unit_Name = "##";
    int Unit_Count = 0;
    int Unit_Damage = 0;
    int Unit_Shield = 10000;
    CivilianType CivType_01 = CivilianType::def;
    
    // functions/methods
    void GetDamage(Catapult ct) { 
        Unit_Shield -= ct.Unit_Damage; 
    }

    void dbug(string txt) {
        if (Unit_Shield < 0)  cout << " xx " << txt << " is destroyed xx " << endl;
        if (Unit_Shield >= 0) cout << " " << txt << " shield: " << Unit_Shield << endl;
    }
};

// on overloading operator, you need develop code for these questions:
// 1- what is on the left side of operator ?
// 2- what is on the right side of operator ?
// 3- what operator returns ?

///////////////////////// operator overloading - global
CivHouse operator + (const CivHouse& leftVar, const Catapult& RghtVar) {
    CivHouse* C = new CivHouse();
    C->Unit_Shield = leftVar.Unit_Shield;
    C->Unit_Shield -= RghtVar.Unit_Damage; // damage
    cout << " global H + C -------operator + overload  " << endl;
    return *C;
}

CivHouse operator + (const CivHouse& leftVar, const int& RghtVar) {
    CivHouse* C = new CivHouse();
    C->Unit_Shield = leftVar.Unit_Shield;
    C->Unit_Shield += RghtVar; // repair
    cout << " global H + int -------operator + overload  " << endl;
    return *C;
}

CivHouse operator + (const Catapult& leftVar, const CivHouse& RghtVar) {
    CivHouse* C = new CivHouse();
    C->Unit_Shield = RghtVar.Unit_Shield;
    C->Unit_Shield -= leftVar.Unit_Damage;
    cout << " global C + H -------operator + overload  " << endl;
    return *C;
}

CivHouse& operator += (CivHouse& leftVar, Catapult& RghtVar) {
    leftVar.Unit_Shield -= RghtVar.Unit_Damage;
    cout << " global H += C -------operator  += overload  " << endl;
    return leftVar;
}

int main() {

    CivilianType House_CivType = CivilianType::Industry;
    
    // save in stack
    CivHouse AHouse =  CivHouse(House_CivType);
    //Catapult ACatapult_01 = Catapult();
    Catapult ACatapult_01 = Catapult(1000); // <-- default constructor not executed
    
    //AHouse.dbug(" <- start - AHouse ");
    //cout << "\n";

    ////AHouse = AHouse + ACatapult_01; // <-- same as 
    //AHouse += ACatapult_01;
    //AHouse.dbug(" <-A ++++++++ AHouse ");

    //AHouse = AHouse + 85; // <-- use int number 
    //AHouse.dbug(" <-B ++++++++ AHouse ");

    ////cout << "\n";

    //AHouse = AHouse + ACatapult_01;
    //AHouse.dbug(" <-C ++++++++ AHouse ");

    //AHouse = ACatapult_01 + AHouse;
    //AHouse.dbug(" <-D ++++++++ AHouse ");

    ////cout << "\n";

    //AHouse = AHouse + ACatapult_01 + ACatapult_01;
    //AHouse.dbug(" <-E ++++++++ AHouse ");

    //cout << "\n\n";

    //// save in heap 
    CivHouse* House = new CivHouse();
    Catapult* Catapult_01 = new Catapult("Stormrider");


    House->dbug(" <- start - House ");
    cout << "\n";

    *House = *House + *Catapult_01; // <-- same as 
    *House += *Catapult_01;
    House->dbug(" <-A--- House ");

    *House = *House + 85; // <-- use int number
    House->dbug(" <-B--- House ");

    cout << "\n";

    *House = *House + *Catapult_01;
    House->dbug(" <-C--- House ");

    *House = *Catapult_01 + *House;
    House->dbug(" <-D--- House ");

    cout << "\n";

    *House = *House + *Catapult_01 + *Catapult_01;
    House->dbug(" <-E--- House ");

    //cout << "\n\n";

    //// make new instance
    Catapult* Catapult_02 = new Catapult("The Hammer");
    *House = *House + *Catapult_02; // <-- same as *House += *Catapult_02;
    *House += *Catapult_02;
    House->dbug(" <-F--- House ");

    cout << "\n";

    //*House = *House + *House; // <-- problem  *House + *House
    //*House = (*House ) + ( *House); // <-- problem  *House + *House
    //*House = *House   ; // no problem
    //House->dbug(" <-G--- House ");


    //// IMPORTANT --  delete pointers at the end of your code !! - MEMORY must be clean 
    delete House;
    House = nullptr;
    delete Catapult_01;
    Catapult_01 = nullptr;
    delete Catapult_02;
    Catapult_02 = nullptr;


    cout << " ---  end of code --- \n\n";

}

// link
// https://www.youtube.com/watch?v=BnMnozsSPmw


