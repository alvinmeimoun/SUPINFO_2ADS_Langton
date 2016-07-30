#ifndef PLATEAU_H
#define PLATEAU_H

#include "Etat.h"

class Plateau
{
    public:
        Plateau();
        Plateau(int h, int l);
        Plateau(const Plateau &p);
        Plateau & operator=(const Plateau &p);
        Plateau & operator++();
        ~Plateau();

        void affiche();
        void affiche_fichier();
        void agrandir();
        bool efface_fichier();
        int getHeight();
        int getWidth();
        Etat* getCase(int x, int y);
        int schizo_state;
    protected:
    private:
        void init();
        void clean();
        Etat** tab;
        int haut;
        int larg;
};

#endif // PLATEAU_H
