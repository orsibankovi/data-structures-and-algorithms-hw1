//
// Created by banko on 2022. 09. 24..
//

#ifndef KHF01_ITAL_H
#define KHF01_ITAL_H
#include <string>

using namespace std;


class Ital {
protected:
    double mennyiseg;
    double alkoholtartalom;
    int ertek;
public:
    Ital(){}
    Ital(double menny_, double alktart_, int ertek_): mennyiseg(menny_), alkoholtartalom(alktart_), ertek(ertek_) { };

    double getMennyiseg(){
        return mennyiseg;
    }

    double getAlkoholtartalom(){
        return alkoholtartalom;
    }

    int getErtek(){
        return ertek;
    }
};

class Bor: public Ital{
    string szolofajta;
public:
    Bor(){}
    Bor(double menny, double alktart, int ertek, string szf_): Ital(menny, alktart, ertek), szolofajta(szf_) {};

    string getSzolofajta(){
        return szolofajta;
    }
};

class Sor: public Ital{
    string tipus;
public:
    Sor(){}
    Sor(double menny, double alktart, int ertek, string tipus_): Ital(menny, alktart, ertek), tipus(tipus_) {};

    string getTipus(){
        return tipus;
    }
};

class Palinka: public Ital{
    string gyumolcs;
public:
    Palinka(){}
    Palinka(double menny, double alktart, int ertek, string gyumolcs_): Ital(menny, alktart, ertek), gyumolcs(gyumolcs_) {};

    string getGyumolcs(){
        return gyumolcs;
    }
};

#endif //KHF01_ITAL_H
