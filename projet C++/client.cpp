#include"client.h"

client::client(const client& other) : personne(other) {
    this->points = other.points;
    // Copie des factures
    for (unsigned int i = 0; i < other.tabb.size(); i++) {
        this->tabb.push_back(new facture(*other.tabb[i]));
    }
}
client&client::operator=(const client & other){
    if (this != &other) {
            personne::operator=(other);
            points=other.points;
            for (auto& facture_ptr : tabb) {
                delete facture_ptr;
            }
            tabb.clear();
            for (size_t i = 0; i < tabb.size(); ++i) {
                // Effectuer une copie en profondeur si nécessaire
                 tabb[i] = new facture(*(other.tabb[i]));
            }
        }
        return *this;
}

void client::ajouter_facture(facture m){
        facture *p=new facture(m);
        tabb.push_back(p);
}
client::~client() {

    for (unsigned int i = 0; i < tabb.size(); i++) {
        delete tabb[i];
    }
}
ostream& operator<<(ostream& os, const client& c) {
    os <<static_cast<const personne&>(c);//completer la méthode cout hérité du personne
    os << "Points: " << c.points << endl;
     os<<"factures"<<endl;
    for (int i=0;i<c.tabb.size();i++) {
        os << "  " << *c.tabb[i] << endl;
    }
    return os;
}
ostream& operator<<(ostream& o, const client* c) {
    o <<static_cast<const personne&>(*c);//completer la méthode cout hérité du personne
    o << "Points: " << c->points << endl;
    o<<"factures"<<endl;
    for (int i=0;i<c->tabb.size();i++) {
        o << "  " << *c->tabb[i] << endl;
    }
    return o;
}
istream& operator>>(istream& is, client& c) {
    is >> static_cast<personne&>(c);//completer la méthode cin hérité du personne
    cout << "Points: ";
    is >> c.points;
    int nbr_factures;
    cout << "Entrez le nombre de factures pour cet personne: ";
    is >> nbr_factures;
    for (unsigned j = 0; j < nbr_factures; ++j) {
        facture* m = new facture();
        is >> *m;
        c.tabb.push_back(m);
    }
    return is;
}
istream& operator>>(istream& is, client* c) {
    is.seekg(0);
    is >> static_cast<personne&>(*c);//completer la méthode cin hérité du personne
    cout << "Points: ";
    is >> c->points;
    int nbr_factures;
    cout << "Entrez le nombre de factures pour cet personne: ";
    is >> nbr_factures;
    for (unsigned j = 0; j < nbr_factures; ++j) {
        facture* m = new facture();
        is >> *m;
        c->tabb.push_back(m);
    }
    return is;
}
void client::gagner_points(){
    if ((240<=duree_totale_session())&&(duree_totale_session()<540))
    {points+=10;}
    else if ((540<=duree_totale_session())&&(duree_totale_session()<740))
    {points+=100;}
    else if (740<=duree_totale_session())
    {points+=1000;}
}

void client::remplir(fstream&f){
    client p(0," "," "," ",0);
    int n;
    cout<<"saisir le nbre de client"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir un client"<<endl;
        cin>>p;
        f<<"le client n° :"<<i+1<<endl;
        f<<&p<<endl;
    }
}
