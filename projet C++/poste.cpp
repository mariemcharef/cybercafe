#include"poste.h"
#include"machine.cpp"
poste::poste(int id_pos,string etat_pos){
    string rep;
    list<machine>::iterator l;
    this->id_pos=id_pos;
    this->etat_poste=etat_pos;
    cout<<"voulez-vous ajouter machines?"<<endl;
    cin>>rep;
    if (rep=="oui"){
    cout<<"les machines"<<endl;
    do
    {   machine*l=new machine();
        cin>>*l;
        tab.push_back(*l);
        cout<<"voulez-vous ajouter machine?"<<endl;
        cin>>rep;
    }while (rep=="oui");
}
}
poste::poste(const poste& p){

    id_pos=p.id_pos;
    etat_poste=p.etat_poste;
    for (const machine& m : p.tab) {
            tab.push_back(m); // Copier chaque machine de p.tab dans tab
        }
}
poste&poste::operator=(const poste & other){
        if (this != &other) {
            id_pos = other.id_pos;
            etat_poste = other.etat_poste;
            tab.clear();
            for (const machine& m : other.tab) {
            tab.push_back(m); // Copie chaque machine de p.tab dans tab
        }
        }
        return *this;
    }
ostream& operator<<(ostream& o, poste& c ){
       list<machine>::iterator it=c.tab.begin();
    o<<"la poste d'identite: "<<c.id_pos<<" Letat: "<<c.etat_poste<<endl;
    o<<"les machines: "<<endl;
    for (it=c.tab.begin();it!=c.tab.end();it++) {
        o << "  " << *it << endl;
    }
    return o;
}
istream& operator>>(istream& i, poste& c ){
    list<machine>::iterator it=c.tab.begin();
    cout<<" L'identite de poste: ";
    i>>c.id_pos;
    cout<<" L'etat du poste: ";
    i>>c.etat_poste;
    int nbMachines;
    cout << "Entrez le nombre de machines pour ce poste: ";
    i >> nbMachines;
    for (unsigned j = 0; j < nbMachines; ++j) {
        machine* m = new machine();
        i >> *m;
        c.tab.push_back(*m);
    }

    return i;
}

 void poste::ajouter_machine(machine m){
        machine *p=new machine(m);
        tab.push_back(*p);
}
int poste::recherche(int id){
        list<machine>::iterator i;
        int a=0;
        for (i=tab.begin();i!=tab.end();i++){
            if(i->get_id_m()==id)
                    {return a;}
           ++a;
        }
    return -1;
}
void poste::supprimer_machine(int id){
        int a;
        a=recherche(id);
        list<machine>::iterator i=tab.begin();
        if(a!=-1)
            advance(i,a);
            tab.erase(i);
}
bool poste::verifier_etat_poste(){
        list<machine>::iterator i=tab.begin();
        for (i = tab.begin(); i != tab.end(); ++i) {
            if (!(i->veriferEtat()))
                return (false) ;
        }
        return (true);
}
void poste::compter(string logiciel) {
    int count = count_if(tab.begin(), tab.end(), [logiciel]( machine& m) {
        return m.get_logiciel() == logiciel;
    });

    cout << "Nombre de machines avec le logiciel \"" << logiciel << "\": " << count << endl;
}

poste::~poste() {
    for (list<machine>::iterator i = tab.begin(); i != tab.end(); ++i) {
//        delete *i; // Supprimez chaque objet machine pointé par l'itérateur
    }
    tab.clear(); // Effacez la liste après avoir supprimé tous les éléments
}
