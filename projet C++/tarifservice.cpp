#include "tarifservice.h"
#include"service.h"
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
void tarifservice::ajout_fin(service *s)
{
    map<int,service>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if((it->second.get_IDS())==(s->get_IDS()))
        {
            cout<<"l'element existe deja  dans le map"<<endl;
        }
    }
    m.insert(std::pair<int,service>(s->get_IDS(),*s));
}

void tarifservice::modifier_prix(int ID)
{   char choix ;
    float  nprix;
   cout <<"le changement de tarif service \n";
   cout <<"voulez vous changer  le prix?(o/n)\n";
   cin>>choix;
   if (choix=='o')
   {
        tarif::modifier();
        map<int,service>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        { if(it->second.get_IDS()==ID)
        {
            cout<<"donner le nouveau prix  : "<<endl;
            cin>>nprix;
            it->second.set_prixs(nprix);
        }

        }
}
}
void tarifservice::recherche_service(int id)
{
    map<int ,service>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        { if(it->second.get_IDS()==id)
            {   cout<<"le service existe \n ";
                it->second.afficher_service();
                  break ;
            }
        }
}

void tarifservice::modifier_duree(int ID)
{   char choix ;
    int nduree;
   cout <<"le changement de tarif service \n";
   cout <<"voulez vous changer  la duree ?(o/n)\n";
   cin>>choix;
   if (choix=='o')
   {
        tarif::modifier();
        map<int,service>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        { if(it->second.get_IDS()==ID)
            {
            cout<<"donner la nouvelle duree : "<<endl;
            cin>>nduree;
            it->second.set_duree(nduree);
            }

        }
    }

}

void tarifservice::afficher()
{
tarif::afficher();
map<int,service>::iterator it;
for(it=m.begin();it!=m.end();it++)
{   cout<<"cle  : "<<(*it).first<<"\n";
    it->second.afficher_service();
}

}

ostream& operator<<(ostream& o, tarifservice& tars)
{   int i=1;
    o << static_cast<tarif&>(tars);
    map<int ,service>::iterator it;
    o<<"\n le nombre des paires "<< tars.m.size();
    for(it=tars.m.begin();it!=tars.m.end();it++)
    {
        o<<"\n cle "<<it->first;
        o<<"\n service  "<<i<<"\n"<<it->second ;
        i+=1;
    }
    return o;
}

istream& operator>>(istream& i, tarifservice& tars)
 {

    i >> static_cast<tarif&>(tars);
    pair<int,service>p;
    char rep ;
    do {
        cout<<"saisir cle "<<endl;
        i>>p.first;
        cout<<"saisir un service"<<endl;
        i>>p.second;
        tars.m.insert(p);
        cout<<"voulez vous ajouter un autre paire  ? (o/n)?"<<endl;
        i>>rep;

    } while(rep=='o'||rep=='O');

    return i;
    }
