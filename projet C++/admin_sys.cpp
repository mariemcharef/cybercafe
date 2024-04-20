#include"admin_sys.h"
ostream& operator<<(ostream& os, const admin_sys& a) {
    os << static_cast<const admin&>(a);
    os << "domaine: " << a.domaine << endl;
    return os;
}
ostream& operator<<(ostream& os, const admin_sys* a) {
    os << static_cast<const admin&>(*a);
    os << "domaine: " << a->domaine << endl;
    return os;
}
istream& operator>>(istream& is, admin_sys& a) {
    is >> static_cast<personne&>(a);
    cout << "domaine: ";
    is >> a.domaine;
    return is;
}
istream& operator>>(istream& is, admin_sys* a) {
    is >> static_cast<personne&>(*a);
    cout << "domaine: ";
    is >> a->domaine;
    return is;
}
