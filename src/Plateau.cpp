#include "../include/Plateau.h"

#include <iostream>
#include <stdio.h>

using namespace std;

Plateau::Plateau()
{
    larg = 21;
    haut = 51;

    init();
}

Plateau::Plateau(int h, int l)
{
    if(h > 0 && h%2 > 0){
        larg = h;
    } else {
        larg = h++;
    }

    if(l > 0 && l%2 > 0){
        haut = l;
    } else {
        haut = l++;
    }

    init();
}

Plateau::Plateau(const Plateau &p)
{
    larg = p.larg;
    haut = p.haut;

    init();
}

Plateau& Plateau::operator=(const Plateau &p)
{
    if(this != &p){
        clean();

        larg = p.larg;
        haut = p.haut;

        init();
    }

    return *this;
}

Plateau& Plateau::operator++()
{
    agrandir();
    return *this;
}

void Plateau::init()
{
    //création du tableau
    tab = new Etat*[haut];
    for(int i = 0; i < haut; i++){
        tab[i] = new Etat[larg];
    }

    //initialisation des valeurs du tableau
    for(int i = 0; i < haut; i++){
        for(int j = 0; j < larg; j++){
            tab[i][j] = Etat();
        }
    }

    schizo_state = 1;
}

void Plateau::clean()
{
    for(int i = 0; i < haut; i++){
        delete tab[i];
    }
    delete tab;
}

void Plateau::agrandir()
{
    haut+=2;
    larg+=2;
    Etat** newTab;

    //création du nouveau tableau
    newTab = new Etat*[haut];
    for(int i = 0; i < haut; i++){
        newTab[i] = new Etat[larg];
    }

    //création des nouvelles cases pour les lignes du haut et du bas
    for(int i = 0; i < haut; i++){
        newTab[i][0] = Etat(1, true);
        newTab[i][larg-1] = Etat(1, true);
    }
    //création des nouvelles cases pour les colonnes de gauche et de droite
    for(int i = 1; i < larg-1; i++){
        newTab[0][i] = Etat(1, true);
        newTab[haut-1][i] = Etat(1, true);
    }
    //copie du tableau existant
    for(int i = 0; i < haut-2; i++){
        for(int j = 0; j < larg-2; j++){
            newTab[i+1][j+1] = tab[i][j];
        }
    }

    //nettoyage de l'ancien tableau
    for(int i = 0; i < haut; i++){
        delete tab[i];
    }
    delete tab;

    //affectation de l'adresse du nouveau tableau
    tab = newTab;
}

Plateau::~Plateau()
{
    clean();
}

void Plateau::affiche()
{
    cout << endl;
    for(int i = 0; i < haut; i++){
        for(int j = 0; j < larg; j++){
            if(tab[i][j].isLibre()){
                if(tab[i][j].getColor() == 1){
                    cout << " ";
                } else {
                    cout << ".";
                }
            } else {
                if(schizo_state == 1){
                    cout << "x";
                } else if (schizo_state == 2){
                    cout << "o";
                }
            }
        }
        cout << endl;
    }
}

bool Plateau::efface_fichier(){
    FILE* file = NULL;
    file = fopen("fourmi.txt", "w");

    if(file != NULL){
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void Plateau::affiche_fichier()
{
    FILE* file = NULL;
    file = fopen("fourmi.txt", "a");
    if(file != NULL){
        fputc('\n', file);
        for(int i = 0; i < haut; i++){
            for(int j = 0; j < larg; j++){
                if(tab[i][j].isLibre()){
                    if(tab[i][j].getColor() == 1){
                        fputc(' ', file);
                    } else {
                        fputc('.', file);
                    }
                } else {
                    if(schizo_state == 1){
                        fputc('x', file);
                    } else if (schizo_state == 2){
                        fputc('o', file);
                    }
                }
            }

            if(i < larg -1){
                fputc('\n', file);
            }
        }
        fputc('\n', file);
        fclose(file);
    }

}

int Plateau::getHeight()
{
    return haut;
}

int Plateau::getWidth()
{
    return larg;
}

Etat* Plateau::getCase(int x, int y)
{
    return &tab[x][y];
}
