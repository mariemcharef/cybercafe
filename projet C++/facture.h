#ifndef FACTURE_H_INCLUDED
#define FACTURE_H_INCLUDED
#include"tarif.cpp"
class facture{
    int id_f;
    vector<tarif*>ta;
public:
    facture(int id =1,double m=0.0){
        id_f=id;
    }
    ~facture(){}
    int get_id_f(){return id_f;}
    void set_id_f(int id){id_f=id;}
    friend ostream& operator<<(ostream&, facture&);
    friend istream& operator>>(istream&, facture&);

};


#endif // FACTURE_H_INCLUDED
