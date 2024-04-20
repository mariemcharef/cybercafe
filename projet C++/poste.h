#ifndef POSTE_H_INCLUDED
#define POSTE_H_INCLUDED
#include"machine.h"
#include<list>
#include<iterator>
#include<algorithm>
#include<map>
class poste{
    int id_pos;
    list<machine>tab;//conteneur liste
    string etat_poste;//avtivé si tous les machines sont avtivées et disactivée sinon
public:
    poste(int id_pos,string etat_poste);//constructeur pour l'allocation des paties dynamiques
    poste(const poste&);//constructeur par recopie
    ~poste();//destructeur
    poste&operator=(const poste&);//affectation
    //les méthodes get et set
    int get_id_p(){return id_pos;}
    string get_etat_poste(){return etat_poste;}
    void set_idp(int i){id_pos=i;}
    void set_etat_pos(string e){etat_poste=e;}
    void ajouter_machine(machine m);//ajouter machine à la liste
    int recherche(int id);//recherche d'une machine dans tab
    void supprimer_machine(int id);
    void activer(){etat_poste="activee";}
    void desactiver(){etat_poste="desactivee";}
    bool verifier_etat_poste();//vrai lorsque tous les machines sont activés
 //pour lire et écrire à l'écran
    friend ostream& operator<<(ostream& , poste& );
    friend istream& operator>>(istream&, poste& );
    void compter(string);//compter les nbr des machines qui ont le meme logiciel

};

#endif // POSTE_H_INCLUDED
