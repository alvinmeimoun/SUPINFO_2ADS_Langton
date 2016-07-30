#include "Fourmi_Schizo.h"

Fourmi_Schizo::Fourmi_Schizo(Plateau* plat, int c11,
            int d11, int e11, int c12, int d12, int e12,
            int c21, int d21, int e21, int c22, int d22, int e22)
            : Fourmi(plat)
{
    regles[0][0] = Modif_Schizo(c11, d11, e11);
    regles[0][1] = Modif_Schizo(c12, d12, e12);
    regles[1][0] = Modif_Schizo(c21, d21, e21);
    regles[1][1] = Modif_Schizo(c22, d22, e22);
    etat_fourmi = e11;
    last_etat = 0;
}

Fourmi_Schizo::Fourmi_Schizo(Plateau* plat) : Fourmi(plat)
{
    regles[0][0] = Modif_Schizo(2, 1, 2);
    regles[0][1] = Modif_Schizo(1, 1, 2);
    regles[1][0] = Modif_Schizo(2, 2, 2);
    regles[1][1] = Modif_Schizo(1, 1, 1);
    etat_fourmi = 2;
    last_etat = 0;
}

Fourmi_Schizo::~Fourmi_Schizo()
{
    delete regles;
}

Plateau* Fourmi_Schizo::deplace()
{
    switch(last_etat){
    case 0:
        etat_fourmi = regles[0][1].modif_etat;
        last_etat = 1;
        break;
    case 1:
        etat_fourmi = regles[1][0].modif_etat;
        last_etat = 2;
        break;
    case 2:
        etat_fourmi = regles[1][1].modif_etat;
        last_etat = 3;
        break;
    case 3:
        etat_fourmi = regles[0][0].modif_etat;
        last_etat = 0;
        break;
    }
    plateau->schizo_state = etat_fourmi;
    return Fourmi::deplace();
}
