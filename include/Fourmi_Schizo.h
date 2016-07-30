#ifndef FOURMI_SCHIZO_H
#define FOURMI_SCHIZO_H

#include "Fourmi.h"
#include "Modif_Schizo.h"

class Fourmi_Schizo : public Fourmi
{
    public:
        Fourmi_Schizo(Plateau* plat, int c11,
            int d11, int e11, int c12, int d12, int e12,
            int c21, int d21, int e21, int c22, int d22, int e22);

        Fourmi_Schizo(Plateau* plat);
        ~Fourmi_Schizo();
        Plateau* deplace();
    protected:
        Modif_Schizo regles[2][2];
    private:
        int etat_fourmi;
        int last_etat;
};

#endif // FOURMI_SCHIZO_H
