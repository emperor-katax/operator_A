#include "Helper.h"

Helper::Helper() {};
Helper::~Helper() {};



/*

///////////////////////// part 1 - global overload

class Unit_Base {
public:
    //con/des
    Unit_Base() {
        Unit_Damage = 5;
    }
    ~Unit_Base() {}

    // properties
    string Unit_Name = "##";
    int Unit_Count = 0;
    int Unit_Damage = 0;
    int Unit_Shield = 0;
    // functions/methods
    void dbug(string txt) {
        if (Unit_Shield < 0)  cout << " xx " << txt << " is destroyed xx " << endl;
        if (Unit_Shield >= 0) cout << " " << txt << " shield: " << Unit_Shield << endl;
    }
};

class Catapult : public Unit_Base {
public:
    Catapult() {
        Unit_Name = "Rising Hell";
        // Unit_Shield = .. ; //  <-- will use base class value if not changed
    }
    Catapult(int damage) { Unit_Damage = damage; }  // con overloaded
    ~Catapult() {} //des
};


class CivHouse : public Unit_Base {
public:
    CivHouse() {
        Unit_Name = "House level 2";
        Unit_Shield = 12000; // <-- will replace base class value from 0 to 12000
    }
    CivHouse(string houseName) { Unit_Name = houseName; }
    ~CivHouse() {} // des

    void GetDamage(Catapult ct) { Unit_Shield -= ct.Unit_Damage; }
};

// overload - global

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

//CivHouse& operator += (CivHouse& leftVar, Catapult& RghtVar) {
//    leftVar.Unit_Shield -= RghtVar.Unit_Damage;
//    cout << " global H += C -------operator  += overload  " << endl;
//    return leftVar;
//}

int main() {

    CivHouse* House = new CivHouse();
    Catapult* Catapult_01 = new Catapult(1000);


    House->dbug(" <- start - House ");
    cout << "\n";

    *House = *House + *Catapult_01; // <-- same as *House += *Catapult_01
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

    cout << "\n\n";

    // make new instance
    Catapult* Catapult_02 = new Catapult(2000);
    *House = *House + *Catapult_02; // <-- same as *House += *Catapult_02;
    House->dbug(" <-F--- House ");

    cout << "\n";

    //*House = *House + *Catapult_01 + *Catapult_01 + *House; // <-- problem  *House + *House
    //*House = (*House + *Catapult_01) + (*Catapult_01 + *House); // <-- problem  *House + *House
    //*House = *House + *Catapult_01 + *Catapult_01 + *Catapult_02; // no problem
    //House->dbug(" <-G--- House ");

    delete House;
    House = nullptr;
    delete Catapult_01;
    Catapult_01 = nullptr;
    delete Catapult_02;
    Catapult_02 = nullptr;


    cout << " ---  end of code --- ";

}


*/


/*

///////////////////////// part 2 - overload in class

class Unit_Base {
public:
    //con/des
    Unit_Base() {
        Unit_Damage = 5;
    }
    ~Unit_Base() {}

    // properties
    string Unit_Name = "##";
    int Unit_Count = 0;
    int Unit_Damage = 0;
    int Unit_Shield = 0;
    // functions/methods
    void dbug(string txt) {
        if (Unit_Shield < 0)  cout << " xx " << txt << " is destroyed xx " << endl;
        if (Unit_Shield >= 0) cout << " " << txt << " shield: " << Unit_Shield << endl;
    }
};

class Catapult : public Unit_Base {
public:
    Catapult() {
        Unit_Name = "Rising Hell";
        // Unit_Shield = .. ; //  <-- will use base class value if not changed
    }
    Catapult(int damage) { Unit_Damage = damage; }  // con overloaded
    ~Catapult() {} //des
};


class CivHouse : public Unit_Base {
public:
    CivHouse() {
        Unit_Name = "House level 2";
        Unit_Shield = 12000; // <-- will replace base class value from 0 to 12000
    }
    CivHouse(string houseName) { Unit_Name = houseName; }
    ~CivHouse() {} // des

    void GetDamage(Catapult ct) { Unit_Shield -= ct.Unit_Damage; }

    //// overload - in-class
    void operator += (Catapult& ct) { //  += overload
        this->Unit_Shield -= ct.Unit_Damage;
        cout << " CivHouse class -------operator  += overload  " << endl;
    }

    CivHouse operator + (int RghtVar) { // + int overload
        this->Unit_Shield += RghtVar;
        return *this;
    }

    bool operator == (const CivHouse& civ) const { //  == overload
        cout << " CivHouse class -------operator  == overload  " << endl;
        //cout << this->Unit_Name << " == " << civ.Unit_Name <<endl;
        return (this->Unit_Name == civ.Unit_Name);
    }
    //// const at the end -> this wont modify any class properties
    // https://www.youtube.com/watch?v=ehJKvbbe9hk
};

// overload - global

CivHouse operator + (const CivHouse& leftVar, const Catapult& RghtVar) {
    CivHouse* C = new CivHouse();
    C->Unit_Shield = leftVar.Unit_Shield;
    C->Unit_Shield -= RghtVar.Unit_Damage;
    cout << " global H + C -------operator + overload  " << endl;
    return *C;
}

CivHouse operator + (const Catapult& leftVar, const CivHouse& RghtVar) {
    CivHouse* C = new CivHouse();
    C->Unit_Shield = RghtVar.Unit_Shield;
    C->Unit_Shield -= leftVar.Unit_Damage;
    cout << " global C + H -------operator + overload  " << endl;
    return *C;
}



int main() {

    CivHouse* House = new CivHouse();
    Catapult* Catapult_01 = new Catapult(1000);

    House->dbug(" <-str- House ");
    cout << "\n";

    *House = *House + *Catapult_01; // <-- same as *House += *Catapult_01
    House->dbug(" <-A--- House ");

    *House = *House + 85; // <--- use int value
    House->dbug(" <-B--- House ");

    cout << "\n";

    *House = *House + *Catapult_01;
    House->dbug(" <-C--- House ");

    *House = *Catapult_01 + *House;
    House->dbug(" <-D--- House ");

    cout << "\n";

    *House = *House + *Catapult_01 + *Catapult_01;
    House->dbug(" <-E--- House ");

    cout << "\n\n";

    // make new instance
    Catapult* Catapult_02 = new Catapult(2000);
    *House = *House + *Catapult_02; // <-- same as *House += *Catapult_01;
    House->dbug(" <-F--- House ");

    cout << "\n";

    //*House = *House + *Catapult_01 + *Catapult_01 + *House; // <-- problem  *House + *House
    //*House = (*House + *Catapult_01) + (*Catapult_01 + *House); // <-- problem  *House + *House
    //*House = *House + *Catapult_01 + *Catapult_01 + *Catapult_02; // no problem
    //House->dbug(" <-G--- House ");

    //cout << "\n\n\n";
    //

    CivHouse* House_01 = new CivHouse("=========== City unit");
    CivHouse* House_02 = new CivHouse("=========== City unit");
    CivHouse* House_03 = new CivHouse("=========== Village unit");

    cout << House_01->Unit_Name << endl;
    cout << House_02->Unit_Name << endl;
    cout << House_03->Unit_Name << endl;


    //if (House_02 == House_01) cout << "-- same name --" << endl; // <-- not working
    if (*House_02 == *House_01) cout << "-- same name --" << endl;
    else cout << "-]- not same name -[-" << endl;


    delete House;
    House = nullptr;
    delete Catapult_01;
    Catapult_01 = nullptr;
    delete Catapult_02;
    Catapult_02 = nullptr;

    delete House_01;
    delete House_02;
    delete House_03;
    House_01 = nullptr;
    House_02 = nullptr;
    House_03 = nullptr;

    cout << " ---  end of code --- ";
}

// C++ operator overloading
// https://www.programiz.com/cpp-programming/operator-overloading
// https://en.cppreference.com/w/cpp/language/operators
// https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c


*/

