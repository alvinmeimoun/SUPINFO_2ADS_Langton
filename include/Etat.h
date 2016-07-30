#ifndef ETAT_H
#define ETAT_H


class Etat
{
    public:
        Etat();
        Etat(int c, bool l);
        ~Etat();
        void inverser_libre();
        void inverser_couleur();
        bool isLibre();
        int getColor();
    protected:
    private:
        int couleur;
        bool libre;
};

#endif // ETAT_H
