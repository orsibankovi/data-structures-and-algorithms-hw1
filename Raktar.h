//
// Created by banko on 2022. 09. 24..
//

#ifndef KHF01_RAKTAR_H
#define KHF01_RAKTAR_H

#include "Ital.h"
#include <vector>
#include <string>

using namespace std;

class Tarolo{
public:
    Tarolo(){}
    virtual ~Tarolo(){}

    virtual double atl_alkoholtartalom()=0;

    virtual double atl_ertek()=0;

    virtual int osszertek()=0;

    virtual int ossz_kapacitas()=0;

    virtual double ossz_mennyiseg()=0;

    virtual int tarolo_db_szam()=0;
};

class ItalTarolo: public Tarolo{
protected:
    vector<vector<Ital>> taroloTarolo;
    size_t maxKapacitas;
public:
    ItalTarolo(size_t maxKapacitas_): maxKapacitas(maxKapacitas_){
    taroloTarolo = {};
    }

    Ital& operator[](int);

    int tarolo_db_szam() override{
        return taroloTarolo.size();
    }

    int ossz_kapacitas() override{
        return taroloTarolo.size() * maxKapacitas;
    }

    int osszertek() override{
        int osszeg = 0;
        for (size_t i=0; i<taroloTarolo.size(); i++){
            for (size_t j=0; j<taroloTarolo[i].size(); j++){
                osszeg += taroloTarolo[i][j].getErtek();
            }
        }
        return osszeg;
    }

    double ossz_mennyiseg() override{
        double menny = 0;
        for (size_t i=0; i<taroloTarolo.size(); i++){
            for (size_t j=0; j<taroloTarolo[i].size(); j++){
                menny += taroloTarolo[i][j].getMennyiseg();
            }
        }
        return menny;
    }
    int darab(){
        int db = 0;
        for (size_t i=0; i<taroloTarolo.size(); i++){
            for (size_t j=0; j<taroloTarolo[i].size(); j++){
                db += 1;
            }
        }
        return db;
    }

    double atl_ertek() override{
        return osszertek()/darab();
    }

    double atl_alkoholtartalom() override{
        double alk = 0;
        for (size_t i=0; i<taroloTarolo.size(); i++){
            for (size_t j=0; j<taroloTarolo[i].size(); j++){
                alk += taroloTarolo[i][j].getAlkoholtartalom()*taroloTarolo[i][j].getMennyiseg();
            }
        }
        return alk /ossz_mennyiseg();
    }
};

Ital& ItalTarolo::operator[](int index) {
    int sor = index / maxKapacitas;
    int db = index % maxKapacitas;
    return taroloTarolo[sor][db];
}


class Bortarto: public ItalTarolo{
public:
    Bortarto(): ItalTarolo(9){
        taroloTarolo = vector<vector<Ital>>();
    }

    void betesz(Bor *bor){
        if (taroloTarolo.empty()){
            taroloTarolo = {{*bor}};
        }
        else{
            if (taroloTarolo[taroloTarolo.size()-1].size() == 9){
                taroloTarolo.push_back({*bor});
            } else{
                taroloTarolo[taroloTarolo.size()-1].push_back(*bor);
            }
        }

        delete bor;
    }

};

class Rekesz: public ItalTarolo{
public:
    Rekesz(): ItalTarolo(20){
        taroloTarolo = vector<vector<Ital>>();
    }
    void betesz(Sor *sor){
        if (taroloTarolo.empty()){
            taroloTarolo = {{*sor}};
        }
        else{
            if (taroloTarolo[taroloTarolo.size()-1].size() == 20){
                taroloTarolo.push_back({*sor});
            } else{
                taroloTarolo[taroloTarolo.size()-1].push_back(*sor);
            }
        }
        delete sor;
    }
};

class Polc: public ItalTarolo{
public:
    Polc(): ItalTarolo(10){
        taroloTarolo = vector<vector<Ital>>();
    }
    void betesz(Palinka *palinka){
        if (taroloTarolo.empty()){
            taroloTarolo = {{*palinka}};
        }
        else{
            if (taroloTarolo[taroloTarolo.size()-1].size() == 10){
                taroloTarolo.push_back({*palinka});
            } else{
                taroloTarolo[taroloTarolo.size()-1].push_back(*palinka);
            }
        }
        delete palinka;
    }
};

class Raktar: public Tarolo{
public:
    Bortarto *bortarto;
    Rekesz *rekesz;
    Polc *polc;

    Raktar(){
        bortarto = new Bortarto();
        rekesz = new Rekesz();
        polc = new Polc();
    }
    ~Raktar(){
        delete bortarto;
        delete rekesz;
        delete polc;
    }

    int tarolo_db_szam(){
        int db = 0;
        db = bortarto->tarolo_db_szam() + rekesz->tarolo_db_szam() + polc->tarolo_db_szam();
        return db;
    }

    int ossz_kapacitas(){
        int ossz = 0;
        ossz = bortarto->ossz_kapacitas() + rekesz->ossz_kapacitas() + polc->ossz_kapacitas();
        return ossz;
    }

    double ossz_mennyiseg(){
        double ossz = 0;
        ossz = bortarto->ossz_mennyiseg() + rekesz->ossz_mennyiseg() + polc->ossz_mennyiseg();
        return ossz;
    }

    int osszertek(){
        int ossz = 0;
        ossz = bortarto->osszertek() + rekesz->osszertek() + polc->osszertek();
        return ossz;
    }

    double atl_alkoholtartalom(){
        double osszalk_ = 0;
        osszalk_ = bortarto->atl_alkoholtartalom() + rekesz->atl_alkoholtartalom() + polc->atl_alkoholtartalom();
        return osszalk_ / ossz_mennyiseg();
    }

    double atl_ertek(){
        int osszdb = 0;
        osszdb = bortarto->darab() + rekesz->darab() + polc->darab();
        return osszertek() / osszdb;
    }
};

#endif //KHF01_RAKTAR_H
