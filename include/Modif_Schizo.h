#ifndef MODIF_SCHIZO_H
#define MODIF_SCHIZO_H

#include "Modif.h"

class Modif_Schizo : public Modif
{
    public:
        Modif_Schizo();
        Modif_Schizo(int c, int d, int e);
        ~Modif_Schizo();
        int modif_etat;
    protected:
    private:
};

#endif // MODIF_SCHIZO_H
