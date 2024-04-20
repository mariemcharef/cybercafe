#include"personne.h"
#include<string>
personne::personne(int id_p,string nom,string prenom,string adresse){
    this->id_p=id_p;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    string re;
    cout<<"voulez-vous ajouter sessions?"<<endl;
    cin>>re;
    if (re=="oui"){
    cout<<"les sessions"<<endl;
    do
    {   int id;
            int d;
            cout << "Entrez l'ID de la session : ";
            cin >> id;
            cout << "Entrez la durée de la session (en minutes) : ";
            cin >> d;
            session* s = new session(id, d);
            tab.push_back(s);
            cout << "Voulez-vous ajouter une autre session ? (oui/non)" << endl;
            cin >> re;
    }while (re=="oui");
}
}
personne::personne(const personne& p){
    id_p=p.id_p;
    nom=p.nom;
    prenom=p.prenom;
    adresse=p.adresse;
    for(int i=0;i<p.tab.size();i++){
        session*l=new session(*p.tab[i]);
        tab.push_back(l);
    }
}
personne&personne::operator=(const personne & other){
        if (this != &other) {
            id_p = other.id_p;
            nom = other.nom;
            prenom=other.prenom;
            adresse=other.adresse;
            for (auto& session_ptr : tab) {
                delete session_ptr;
            }
            tab.clear();
            for (auto& session_ptr : other.tab) {
                tab.push_back(new session(*session_ptr));
            }
        }
        return *this;
    }

void personne::ajouter_session(session m){
        session *p=new session(m);
        tab.push_back(p);
}
int personne::recherche(int id){
        int a=-1;
        for (unsigned i=0;i<tab.size();i++){
            if(tab[i]->get_id_s()==id)
                    {return i;}
        }
    return a;
}
void personne::supprimer_session(int id){
    int index = recherche(id);
    if (index != -1) {
        tab.erase(tab.begin() + index);
    }
}
//pour les fichiers
void personne::creer(fstream&f){
    f.open("fichierPersonne.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit (-1);
}
void personne::remplir(fstream&f){
    personne p(0," "," "," ");
    int n;
    cout<<"saisir le nbre de personnes"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir la personne"<<endl;
        cin>>p;
        f<<"la personne n° :"<<i+1<<endl;
        f<<&p<<endl;
    }
}
int personne::duree_totale_session() {
    int duree_totale = 0;
    for (unsigned i = 0; i < tab.size(); ++i) {
        if (tab[i] != nullptr) {
            duree_totale += tab[i]->get_duree();
        }
    }

    return duree_totale;
}
void personne::ajout_fin(session*s){
    map<int,session>::iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
        if((it->second.get_id_s())==(s->get_id_s()))
        {
            cout<<"l'élement existe deja"<<endl;
        }
    }
    m.insert(std::pair<int,session>(s->get_id_s(),*s));
}
void personne::afficher_map(){
    map<int,session>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        cout<<(*it).first;
        cout<<it->second;
    }
}
personne::~personne(){
        for (unsigned int i=0;i<tab.size();i++)
 { delete tab[i]; }
}
ostream& operator<<(ostream& o, const personne& p) {
    o << "ID: " << p.id_p << endl;
    o << "Nom: " << p.nom << endl;
    o << "Prenom: " << p.prenom << endl;
    o << "Adresse: " << p.adresse << endl;
    o<<"sessions"<<endl;
    for (int i=0;i<p.tab.size();i++) {
        o << "  " << *p.tab[i] << endl;
    }
    map<int,session> m;
    map<int,session>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        o<<(*it).first;
        o<<it->second;
    }
    return o;
}
ostream& operator<<(ostream& o, const personne* p) {
    o << "ID: " << p->id_p << endl;
    o << "Nom: " << p->nom << endl;
    o << "Prenom: " << p->prenom << endl;
    o << "Adresse: " << p->adresse << endl;
    o<<"sessions"<<endl;
    for (int i=0;i<p->tab.size();i++) {
        o << "  " << *p->tab[i] << endl;
    }
    return o;
}
istream& operator>>(istream& i, personne& p) {
    cout << "ID: ";
    i >> p.id_p;
    cout << "Nom: ";
    i >> p.nom;
    cout << "Prenom: ";
    i >> p.prenom;
    cout << "Adresse: ";
    i >> p.adresse;
    string re;
    do
    {   int id;
            int d;
            cout << "Entrez l'ID de la session : ";
            i >> id;
            cout << "Entrez la durée de la session (en minutes) : ";
            i >> d;
            session* nouvelleSession = new session(id, d);
            p.tab.push_back(nouvelleSession);

            cout << "Voulez-vous ajouter une autre session ? (oui/non)" << endl;
            i >> re;
    }while (re=="oui");
    return i;
}
istream& operator>>(istream& i, personne* p) {
    i.seekg(0);
    cout << "ID: ";
    i >> p->id_p;
    cout << "Nom: ";
    i >> p->nom;
    cout << "Prenom: ";
    i >> p->prenom;
    cout << "Adresse: ";
    i >> p->adresse;
        string re;
    do
    {   int id;
            int d;
            cout << "Entrez l'ID de la session : ";
            i >> id;
            cout << "Entrez la durée de la session (en minutes) : ";
            i >> d;
            session* nouvelleSession = new session(id, d);
            p->tab.push_back(nouvelleSession);
            cout << "Voulez-vous ajouter une autre session ? (oui/non)" << endl;
            i >> re;
    }while (re=="oui");
    return i;
}
