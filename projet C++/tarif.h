#ifndef TARIF_H_INCLUDED
#define TARIF_H_INCLUDED
#include<iostream>
using namespace std;
class tarif
{ private :
    int code ;
    float montant ;

public:
    //constructeur
    tarif(int code =0000 , float montant =0.0);
   //constructeur par recopie
    tarif(const tarif&);
     //destructeur
    virtual ~tarif(){}
    //getters
    int get_code(){return code;}
    float get_montant(){ return montant;}
    //setters
    void set_code(int c){code=c;}
    void set_montant(float p){montant=p;}

    virtual void modifier();
    virtual void saisir();
    virtual void afficher();
    //surchage des operateurs << et >>
    friend ostream& operator<<(ostream&, tarif&t);
    friend istream& operator>>(istream&,tarif &t);

};



#endif // TARIF_H_INCLUDED
