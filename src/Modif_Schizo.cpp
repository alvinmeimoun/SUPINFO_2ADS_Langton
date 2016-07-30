#include "Modif_Schizo.h"

Modif_Schizo::Modif_Schizo() : Modif()
{
   modif_etat = 1;
}

Modif_Schizo::Modif_Schizo(int c, int d, int e) : Modif(c, d)
{
    modif_etat = e;
}

Modif_Schizo::~Modif_Schizo()
{

}
