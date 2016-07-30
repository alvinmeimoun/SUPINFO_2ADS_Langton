#ifndef FOURMI_H
#define FOURMI_H

#include "Modif.h"
#include "Plateau.h"

#define NORD 1
#define OUEST 2
#define SUD 3
#define EST 4

class Fourmi
{
    public:
        Fourmi(Plateau* plat);
        Fourmi(Plateau* plat, int c1, int d1, int c2, int d2);
        ~Fourmi();
        Fourmi & operator++();
        void change_direction(int c);
        void agrandir();
        virtual Plateau* deplace();
        void printStats();
    protected:
        Modif regles[2];
        Plateau* plateau;
    private:
        int i;
        int j;
        int direction;
        void init();
        int countNORD;
        int countSUD;
        int countEST;
        int countOUEST;
};

#endif // FOURMI_H
