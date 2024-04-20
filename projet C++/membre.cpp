#include"membre.h"
membre&membre::operator=(const membre & other){
    if (this != &other) {
            client::operator=(other);
            type_abonnement=other.type_abonnement;
            idfidelite=other.idfidelite;
        }
        return *this;
}
void client::convertir_en_membre() {
    if (points >= 1000) {
        string type_abonnement;
        int idfidelite;
        // Demandez à l'utilisateur de saisir les détails spécifiques du membre
        cout << "Saisissez le type d'abonnement du membre : ";
        cin >> type_abonnement;

        cout << "Saisissez l'identifiant de fidélité du membre : ";
        cin >> idfidelite;
        // Convertir en membre en utilisant le constructeur de la classe membre
        membre m(id_p, nom, prenom, adresse, points, type_abonnement, idfidelite);
        // Copier les factures du client vers le membre
        for (auto& facture_ptr : tabb) {
                m.tabb.push_back(new facture(*facture_ptr));
            }
        // Copier les sessions du client vers le membre
        for (auto& session_ptr : tab) {
                m.tab.push_back(new session(*session_ptr));
            }
        // Informez l'utilisateur que le client est devenu membre
        cout << "Le client est devenu membre avec succès !" << endl;
    } else {
        cout << "Le nombre de points du client est inférieur à 1000. Impossible de le convertir en membre." << endl;
    }
}
membre::membre(const membre& other) : client(other) {
    this->type_abonnement = other.type_abonnement;
    this->idfidelite=other.idfidelite;
}


void membre::remplir(fstream&f){
    membre p(0," "," "," ",0," ",0);
    int n;
    cout<<"saisir le nbre de membres"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir un membre"<<endl;
        cin>>p;
        f<<"le membre n° :"<<i+1<<endl;
        f<<&p<<endl;
    }
}
ostream& operator<<(ostream& o, const membre& m) {
    o << static_cast<const client&>(m);//completer la méthode cout hérité du client
    o << "Type d'abonnement: " << m.type_abonnement << endl;
    o << "ID de fidélité: " << m.idfidelite << endl;
    return o;
}
ostream& operator<<(ostream& o, const membre* m) {
    o << static_cast<const client&>(*m);//completer la méthode cout hérité du client
    o << "Type d'abonnement: " << m->type_abonnement << endl;
    o << "ID de fidélité: " << m->idfidelite << endl;
    return o;
}
istream& operator>>(istream& i, membre& m) {
    i >> static_cast<client&>(m);
    cout << "Type d'abonnement: ";
    i >> m.type_abonnement;
    cout << "ID de fidélité: ";
    i >> m.idfidelite;
    return i;
}
istream& operator>>(istream& i, membre* m) {
    i >> static_cast<client&>(*m);
    cout << "Type d'abonnement: ";
    i >> m->type_abonnement;
    cout << "ID de fidélité: ";
    i >> m->idfidelite;
    return i;
}
