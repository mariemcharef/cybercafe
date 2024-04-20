#include"machine.h"
machine::machine(int id_m,string logiciel,string etat){
    this->id_m=id_m;
    this->logiciel=logiciel;
    this->etat=etat;
}
ostream& operator<<(ostream& o, machine& c )
{
    o<<c.id_m<<" de logiciel: "<<c.logiciel<<" Letat: "<<c.etat;
    return o;
}
istream& operator>>(istream& i, machine& c )
{   cout<<" L'identite: ";
    i>>c.id_m;
    cout<<" L'ogiciel: ";
    i>>c.logiciel;
    cout<<" L'etat: ";
    i>>c.etat;
    return i;
}

