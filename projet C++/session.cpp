#include"session.h"
session::session(int id,int d){
        duree=d;
        idS=id;
    }
ostream& operator<<(ostream& os, const session& s) {
    os << "Session " << s.idS << " dure : " << s.duree/60 << " heures et " << s.duree%60 << " minutes"<<endl;
    return os;
}

// Implémentation de l'opérateur d'entrée pour la classe session
istream& operator>>(istream& is,const session& s) {
    cout << " Entrez l'identifiant de la session : ";
    is >> s.idS;
    cout << "Entrez la durée de la session (en minute minutes) : ";
    is >> s.duree;
    return is;
}
session& operator+(const session& s1, const session& s2){
    int new_id = s1.idS + s2.idS;
    int totalduree = s1.duree + s2.duree;
    return *new session(new_id, totalduree);
}
