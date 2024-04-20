#ifndef TARIFBOISSON_H_INCLUDED
#define TARIFBOISSON_H_INCLUDED
#include "tarif.h";
#include"boisson.h"
#include<string>
#include<list>

class tarifboisson:public tarif
{
private:

    list <boisson> l;
public:
    tarifboisson(int code =0000, float montant =0.0 ):tarif(code,montant){}
    virtual ~tarifboisson(){l.clear();}
    virtual void ajouter(boisson *b);
    virtual void supprimer(int id );
    virtual void afficher();//probleme: n'affiche pas tarif
    void rechercher_boisson(string nom);
    float boisson_plus_cher();
    double calculer_prix();
    virtual void modifier_prix(int id);
    virtual void modifier_stock(int id);
    friend ostream& operator<<(ostream&, tarifboisson&tarb);
    friend istream& operator>>(istream&,tarifboisson &tarb);


};



#endif // TARIFBOISSON_H_INCLUDED
