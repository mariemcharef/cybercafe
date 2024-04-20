#include"facture.h"
ostream& operator<<(ostream& o, facture& c ){
    o<<c.id_f<<endl;

    return o;
}
istream& operator>>(istream& i,facture& c ){
    cout<<" L'identite: ";
    i>>c.id_f;
    int choix;string rep;
    do
    {
        cout<<"\n taper 1:tarif, 2:tarif boisson ,3:tarif service"<<endl;
        i>>choix;
        if(choix==1)
        {
            tarif* p=new tarif();
            i>>*p;
            c.ta.push_back(p);
        }
       /* else if (choix==2)
        {
            tarif boisson*p=new tarifboisson();
            i>>*p;
            c.ta.push_back(p);
        }
        else if(choix==3)
        {
            tarifservice*p=new tarifservice();
            i>>*p;
            stat.ta.push_back(p);
        }*/
        cout<<"\n ajouter?"<<endl;
        i>>rep;
    }while(rep=="oui");
    return i;
}
