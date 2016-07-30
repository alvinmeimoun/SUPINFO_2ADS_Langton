#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "include/Plateau.h"
#include "include/Fourmi.h"
#include "include/Fourmi_Schizo.h"

using namespace std;

int main()
{

    Plateau plateau = Plateau(35, 51);

    int type = 0;

    //espèce

    do{
        cout << "Choisir votre espece : " << endl;
        cout << "1 : Fourmi" << endl;
        cout << "2 : Turmite " << endl;
        cin >> type;
        if(type < 1 || type > 2){
            cout << "Entrez 1 ou 2" << endl;
        }
    } while (type < 1 || type > 2);

    system("cls");

    //Fourmi rapide
    char fourmiRapideChar = 'n';
    bool fourmiRapide = false;
    cout << "Fourmi rapide ? (2 deplacements a la fois) y/n ";
    cin >> fourmiRapideChar;
    if(fourmiRapideChar == 'y'){
        fourmiRapide = true;
    }
    system("cls");

    //nombre de générations

    int nbMoveToDisplay = 0;
    do{
        cout << "Nombre de deplacements a afficher : ";
        cin >> nbMoveToDisplay;
        if(nbMoveToDisplay > 0){
            cout << endl;
        } else {
            cout << "Entrez un nombre > 0" << endl;
        }
    } while (nbMoveToDisplay <= 0);

    system("cls");

    //effacement automatique

    bool clearConsoleAuto = false;
    cout << "Effacer automatiquement la console apres chaque generation ? y/n : " ;
    char autoClearChar;
    cin >> autoClearChar;
    if(autoClearChar == 'y'){
        clearConsoleAuto = true;
    }
    cout << endl;

    system("cls");

    //déplacement rapide de la fourmi


    plateau.efface_fichier();
    if(type == 1){
        Fourmi fourmi = Fourmi(&plateau);
        for(int i = 0; i < nbMoveToDisplay; i++)
        {
            cout << endl << "Generation n" << i+1 << " : " << endl;
            fourmi.deplace();
            if(fourmiRapide){
                fourmi.deplace();
            }
            plateau.affiche();

            system("pause");

            if(clearConsoleAuto){
                system("cls");
            }
        }

        system("cls");
        fourmi.printStats();
    } else if (type == 2) {
        Fourmi_Schizo fourmi = Fourmi_Schizo(&plateau);
        for(int i = 0; i < nbMoveToDisplay; i++)
        {
            cout << endl << "Generation n" << i << " : " << endl;
            fourmi.deplace();
            if(fourmiRapide){
                fourmi.deplace();
            }
            plateau.affiche();

            system("pause");

            if(clearConsoleAuto){
                system("cls");
            }
        }

        system("cls");
        fourmi.printStats();
        system("pause");
    }

    return 0;
}
