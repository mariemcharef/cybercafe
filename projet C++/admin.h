#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include"personne.cpp"
class admin:public personne{//classe abstraite héritée du personne
protected:
    float salaire;
    string poste;
public:
    admin(int id_p=0,string nom="",string prenom="",string adresse="",float salaire=0.0,string poste=""):personne(id_p,nom,prenom,adresse){
    this->salaire=salaire;
    this->poste=poste;
    }
    float get_salaire(){return salaire;}
     // Méthode virtuelle pure, rendant la classe admin abstraite
    virtual void calcule_augmentation_salaire(int pourcentage,float augmentation)=0;
    friend ostream& operator<<(ostream& os, const admin& a);
    friend istream& operator>>(istream& is, admin& a);
    friend ostream& operator<<(ostream& os, const admin* a);
    friend istream& operator>>(istream& is, admin* a);

    virtual~admin(){};
};

#endif // ADMIN_H_INCLUDED
