#include "../include/Fourmi.h"

#include <iostream>
#include <iomanip>

using namespace std;

Fourmi::Fourmi(Plateau* plat)
{
    plateau = plat;
    regles[0] = Modif(2, 1);
    regles[1] = Modif(1, 2);

    init();
}

Fourmi::Fourmi(Plateau* plat, int c1, int d1, int c2, int d2)
{
    plateau = plat;
    regles[0] = Modif(c1, d1);
    regles[1] = Modif(c2, d2);

    init();
}

Fourmi& Fourmi::operator++()
{
    agrandir();

    return *this;
}

void Fourmi::agrandir(){
    plateau->agrandir();

    i++;
    j++;
}

void Fourmi::init()
{
    //initialise la fourmi au milieu du plateau
    int hauteur = plateau->getHeight();
    int largeur = plateau->getWidth();
    i = (int)largeur/2;
    j = (int)hauteur/2;

    direction = NORD;
    countNORD = 1;
    countEST = 0;
    countOUEST = 0;
    countSUD = 0;

    Etat* curposState = plateau->getCase(i, j);
    curposState->inverser_libre();
}

Fourmi::~Fourmi()
{
    delete regles;
}

void Fourmi::change_direction(int c)
{
    switch(direction){
    case NORD:
        if(c == 1){
            direction = OUEST;
            countOUEST++;
        } else if (c == 2){
            direction = EST;
            countEST++;
        }
        break;
    case OUEST:
        if(c == 1){
            direction = SUD;
            countSUD++;
        } else if (c == 2){
            direction = NORD;
            countNORD++;
        }
        break;
    case EST:
        if(c == 1){
            direction = NORD;
            countNORD++;
        } else if (c == 2){
            direction = SUD;
            countSUD++;
        }
        break;
    case SUD:
        if(c == 1){
            direction = EST;
            countEST++;
        } else if (c == 2){
            direction = OUEST;
            countOUEST++;
        }
        break;
    }
}

Plateau* Fourmi::deplace()
{
    //change de direction
    Etat* curposState = plateau->getCase(i, j);
    if(curposState->getColor() == 1){
        change_direction(1);
    } else {
        change_direction(2);
    }

    //inverse la couleur
    curposState->inverser_couleur();

    //effectuele déplacement
    switch(direction){
    case NORD:
        j--;
        break;
    case SUD:
        j++;
        break;
    case OUEST:
        i--;
        break;
    case EST:
        i++;
        break;
    }
    curposState->inverser_libre();
    Etat* newposState = plateau->getCase(i, j);
    newposState->inverser_libre();

    if(i < 2 || j < 2 || i > plateau->getWidth()-2 || j > plateau->getHeight()-2){
        agrandir();
    }

    return plateau;
}

void Fourmi::printStats()
{
    double totalDeplacements = countEST + countNORD + countOUEST + countSUD;
    double percentEST = (countEST/totalDeplacements)*100;
    double percentOUEST = (countOUEST/totalDeplacements)*100;
    double percentSUD = (countSUD/totalDeplacements)*100;
    double percentNORD = (countNORD/totalDeplacements)*100;

    cout << totalDeplacements-1 << " deplacements :" << endl << endl;
    cout << "EST : " << countEST << " - " << setprecision(3) << percentEST << "%" << endl;
    cout << "OUEST : " << countOUEST << " - " << setprecision(3) << percentOUEST << "%" << endl;
    cout << "NORD : " << countNORD << " - " << setprecision(3) << percentNORD << "%" << endl;
    cout << "SUD : " << countSUD << " - " << setprecision(3) << percentSUD << "%" << endl;
    cout << endl;
}
