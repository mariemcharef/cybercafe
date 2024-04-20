#ifndef ADMIN_SYS_H_INCLUDED
#define ADMIN_SYS_H_INCLUDED
#indlude"admin.cpp"

class admin_sys:public admin{//classe hérité du classe abstraite admin
    string domaine;
public:
    admin_sys(int id_p=0,string nom="",string prenom="",string adresse="",float salaire=0.0,string poste="",string domaine="d"):admin(id_p,nom,prenom,adresse,salaire,poste){
    this->domaine=domaine;
    }
    string get_domaine(){return domaine;}
    void set_domaine(string d){domaine=d;}
    friend ostream& operator<<(ostream& os, const admin_sys& a);
    friend istream& operator>>(istream& is, admin_sys& a);
    friend ostream& operator<<(ostream& os, const admin_sys* a);
    friend istream& operator>>(istream& is, admin_sys* a);
    ~admin_sys(){};
};

#endif // ADMIN_SYS_H_INCLUDED
