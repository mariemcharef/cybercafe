#include"tarif.h"
#include<iostream>
#include<string>
using namespace std ;
tarif::tarif(int code ,float montant)
{
    this->code=code;
    this->montant=montant;
}

void tarif ::saisir()
{
cout<<"donner le code    :    "<<endl;
cin>> code;
cout<<"\n";
cout<<"donnre le montant :    "<<endl;
cin>>montant;
cout<<"\n";
}

void tarif::afficher()
{
    cout<<"code     :"<<code<<endl;
    cout<<"montant  :"<<montant<<endl;

}
ostream& operator<<(ostream&o,tarif&t)
{
    o<<"code    :"<<t.code<<"\n";

    o<<"montant :"<< t.montant<<"\n";
    return o;
}
istream& operator>>(istream&i,tarif&t)
{
    cout<<"donner le code     :";
    i>>t.code;
    cout<<"donner le montant  :";
    i>>t.montant;
    return i;
}
void tarif::modifier()
{
char choix ;
cout<<"voulez vous faire modifier le montant ? oui :'o' non :'n'   \n";
cin>>choix;
if (choix =='o')
{
    cout<<"veuillez ecrire le nouveau montant  pour le  code "<<code<<"  :  ";
    cin>>montant;
}
else {
    cout<<"montant non modifie "<<endl;
}

}

tarif::tarif(const tarif&t)
{
    code=t.code;
    montant=t.montant;

}
