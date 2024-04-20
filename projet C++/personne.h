#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include"session.cpp"

#include<fstream>
class personne{
protected:

    int id_p;
    string nom;
    string prenom;
    string adresse;
    vector<session*>tab;//tableau d'objets
    map<int,session> m;//conteneur map
public:
    personne(int id_p=0,string nom="",string prenom="",string adresse="");//constructeur
    personne(const personne&);//constructeur par recopie
    virtual personne&operator=(const personne&);//méthode virtuelle(polymorphisme dynamique)
    //les méthodes get et set pour la modification
    int get_id_p(){return id_p;}
    string get_nom(){return nom;}
    string get_prenom(){return prenom;}
    string get_adresse(){return adresse;}
    void set_id_p(int id){id_p=id;}
    void set_nom(string n){nom=n;}
    void set_prenom(string p){prenom=p;}
    void set_adresse(string a){adresse=a;}
    void ajouter_session(session m);//on peut ajouter session au tableau
    //recherche de session dans le tableau pour la supprimer ou bien afficher
    int recherche(int id);
    void supprimer_session(int id);//supprimer session du vecteur
    void ajout_fin(session*);//ajout des session à la map
    void afficher_map();//affichage des sessions dans le map
    int duree_totale_session();//méthode fait le parcour du tab d'objet et calcule la durée totale des sessions pour faire des statistiques
    friend ostream& operator<<(ostream& os, const personne& p);
    friend istream& operator>>(istream& is, personne& p);
    //pour les fichiers
    static void creer(fstream&);
    static void remplir(fstream&);
    friend ostream& operator<<(ostream& os, const personne* p);
    friend istream& operator>>(istream& is, personne* p);
    virtual~personne();//destructeur
};




#endif // PERSONNE_H_INCLUDED
