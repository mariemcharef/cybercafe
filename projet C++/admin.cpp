#include"admin.h"
void admin::calcule_augmentation_salaire(int pourcentage,float augmentation){
    augmentation=salaire*pourcentage/100;

}
ostream& operator<<(ostream& os, const admin& a) {
    os << static_cast<const personne&>(a);
    os << "Salaire: " << a.salaire << endl;
    os << "Poste: " << a.poste << endl;
    return os;
}
ostream& operator<<(ostream& os, const admin* a) {
    os << static_cast<const personne&>(*a);
    os << "Salaire: " << a->salaire << endl;
    os << "Poste: " << a->poste << endl;
    return os;
}
istream& operator>>(istream& is, admin& a) {
    is >> static_cast<personne&>(a);
    cout << "Salaire: ";
    is >> a.salaire;
    cout << "Poste: ";
    is >> a.poste;
    return is;
}
istream& operator>>(istream& is, admin* a) {
    is >> static_cast<personne&>(*a);
    cout << "Salaire: ";
    is >> a->salaire;
    cout << "Poste: ";
    is >> a->poste;
    return is;
}
