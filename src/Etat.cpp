#include "../include/Etat.h"

Etat::Etat()
{
    couleur = 1;
    libre = true;
}

Etat::Etat(int c, bool l)
{
    couleur = c;
    libre = l;
}

Etat::~Etat()
{

}

void Etat::inverser_libre()
{
    libre = !libre;
    if(couleur == 1) {
        couleur = 2;
    } else {
        couleur = 1;
    }
}

void Etat::inverser_couleur()
{
    if(couleur == 1){
        couleur = 2;
    } else if (couleur == 2){
        couleur = 1;
    }
}

bool Etat::isLibre()
{
    return libre;
}

int Etat::getColor()
{
    return couleur;
}
