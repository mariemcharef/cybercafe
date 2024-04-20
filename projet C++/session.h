#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED

class session{
    int idS;
    int duree;//en minute
public:
    session(int id=0,int d=0);
    ~session(){}
    int get_id_s(){return idS;}
    int get_duree(){return duree;}
    friend session&operator+(const session&,const session&);//retourne la somme du sessions
    friend ostream& operator<<(ostream& ,const session& );
    friend istream& operator>>(istream&,const session& );
 };

#endif // SESSION_H_INCLUDED
