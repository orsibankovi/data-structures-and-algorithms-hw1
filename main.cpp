#include <iostream>
#include "Ital.h"
#include "Raktar.h"
#include "woodpecker.hpp"

using namespace std;

TEST("ItalRaktar teszt", 1) {
    {
        Raktar *raktar = new Raktar();

        for (int i = 0; i < 10; i++) {
            Bor* bor = new Bor(0.75, 10 + (i * 0.5), 2000 + (i * 500), "Merlot");
            raktar->bortarto->betesz(bor);
        }

        CHECK_EQ(2,raktar->bortarto->tarolo_db_szam());
        CHECK_EQ(18,raktar->bortarto->ossz_kapacitas());
        CHECK_EQ(12.25,raktar->bortarto->atl_alkoholtartalom());
        CHECK_EQ(42500,raktar->bortarto->osszertek());

        for (int i = 0; i < 10; i++) {
            Ital &ital = (*(raktar->bortarto))[i];
            CHECK_EQ(0.75,ital.getMennyiseg());
            CHECK_EQ(10+(i*0.5),ital.getAlkoholtartalom());
            CHECK_EQ(2000+(i*500),ital.getErtek());
        }

        for (int i=0; i<21; i++){
            Sor* sor = new Sor(0.5,4+(i*0.1),500+(i*10), "IPA");
            raktar->rekesz->betesz(sor);
        }

        CHECK_EQ(2,raktar->rekesz->tarolo_db_szam());
        CHECK_EQ(40,raktar->rekesz->ossz_kapacitas());
        CHECK_EQ(600,raktar->rekesz->atl_ertek());
        CHECK_EQ(10.5,raktar->rekesz->ossz_mennyiseg());

        for (int i=0; i<11; i++){
            Palinka* palinka = new Palinka(0.7,35+i,5000+(i*100), "Barack");
            raktar->polc->betesz(palinka);
        }

        CHECK_EQ(2,raktar->polc->tarolo_db_szam());
        CHECK_EQ(20,raktar->polc->ossz_kapacitas());

        CHECK_EQ(2752,raktar->atl_ertek());
        CHECK_EQ(115600,raktar->osszertek());

        delete raktar;
    }
}

WOODPECKER_TEST_MAIN(-1, -1)
