#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class machine{
    int id_m;
    string logiciel;
    string etat;
public:
    machine(int id_m =1,string logiciel="",string etat="");
    ~machine(){}
    void activer(){etat="active";}
    void eteindre(){etat="desactive";}
    bool veriferEtat(){return (etat=="active");}//vrai lorsque une machine est activée
    int get_id_m(){return id_m;}
    void set_id_m(int id){id_m=id;}
    string get_logiciel(){return logiciel;}
    void set_logiciel(string l){logiciel=l;}
    string get_etat(){return etat;}
    void set_etat(string e){etat=e;}
    friend ostream& operator<<(ostream&, machine& );
    friend istream& operator>>(istream&, machine& );


};
#endif // MACHINE_H_INCLUDED
