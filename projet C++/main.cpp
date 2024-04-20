#pragma once
#include <iostream>
#include<string>
#include"poste.cpp"
#include<fstream>
#include<iomanip>
#include"statistics.cpp"

using namespace std;
void afficher(fstream&f){
    char ch[101];
    f.seekg(0);
while(1){
        f.getline(ch,100);
        if(f.eof())break;
        cout<<ch<<endl;
     }
f.close();
system("pause");

}
int main()

{
vector<statistics*>table;
vector<poste*>t;
int choix;
do {
    // Afficher le menu principal
    cout << "========== Menu Principal ==========" << endl;
    cout << "1. Gérer statistiques" << endl;
    cout << "2. Gérer postes" << endl;
    cout << "3. Quitter" << endl;
    cout << "Choix: ";
    cin >> choix;
    switch (choix) {
        case 1: {
            // Menu de gestion des statistiques
            int choixS;
            // Afficher le menu de gestion de statistiques
            cout << "===== Menu Gestion Statistiques =====" << endl;
            cout << "1. Création " << endl;
            cout << "2. Afficher " << endl;
            cout << "3. Supprimer " << endl;
            cout << "4. Ajouter personnes " << endl;
            cout << "5. Retour au menu principal" << endl;
            cout << "Choix: ";
            cin >> choixS;
            // Effectuer des actions basées sur le choix de l'utilisateur
            switch (choixS) {
               case 1: {
                   int mois, annee;
                    double dureeMoyenne;
                    cout << "Entrez le mois et l'année : ";
                    cin >> mois >> annee;
                    statistics *p = new statistics(mois, annee, 0, 0);
                    table.push_back(p);
                   break;
               }
               case 2:{
                    int mois, annee;
                   cout << "Entrez le mois et l'année pour afficher les statistiques : ";
                   cin >> mois >> annee;
                   bool found = false;
                   for (size_t i = 0; i < table.size(); i++) {
                        if (table[i]->get_mois() == mois && table[i]->get_annee() == annee) {
                            cout << *(table[i]);
                            cout<<"la durée totole est : "<<endl;
                            cout<<(table[i]->total_session());
                            cout<<endl;
                            found = true;
                            break;
                        }
                    }
                   if (!found)
                       cout << "Aucune statistique pour le mois " << mois << " et l'année " << annee << " n'a été trouvée." << endl;
                break;
               }
               case 3:{
                   int mois, annee;
                   cout << "Entrez le mois et l'année pour supprimer les statistiques : ";
                   cin >> mois >> annee;
                   bool found = false;
                   for (size_t i = 0; i < table.size(); i++) {
                        if (table[i]->get_mois() == mois && table[i]->get_annee() == annee) {
                            cout << *(table[i]);
                            delete table[i];
                            table.erase(table.begin() + i);
                            found = true;
                            break;
                        }
                    }
                   if (!found)
                       cout << "Aucune statistique pour le mois " << mois << " et l'année " << annee << " n'a été trouvée." << endl;
                break;
               }
               case 4:{
                    int mois, annee;
                   cout << "Entrez le mois et l'année pour ajouter des personnes : ";
                   cin >> mois >> annee;
                   bool found = false;
                   for (size_t i = 0; i < table.size(); i++) {
                        if (table[i]->get_mois() == mois && table[i]->get_annee() == annee) {
                             int choixAjouter;
                             // Afficher le menu de gestion de personne
                             cout << "===== Menu Ajout =====" << endl;
                             cout << "1. Ajouter personne " << endl;
                             cout << "2. Ajouter client " << endl;
                             cout << "3. Ajouter membre " << endl;
                             cout << "4. Retour au menu principal" << endl;
                             cout << "Choix: ";
                             cin >> choixAjouter;
                             // Effectuer des actions basées sur le choix de l'utilisateur
                             switch (choixAjouter) {
                                case 1: {
                                    personne p(0, " ", " ", " ");
                                    cin >> p;
                                    table[i]->ajouterPersonne(p);
                                    break;
                                }
                                case 2: {
                                    client c(0, " ", " ", " ", 0);
                                    cin >> c;
                                    c.gagner_points();
                                    c.convertir_en_membre();
                                    table[i]->ajouterPersonne(c);
                                    break;
                                }
                                case 3: {
                                    membre m(0, " ", " ", " ", 1000, " ", 0);
                                    cin >> m;
                                    table[i]->ajouterPersonne(m);
                                    break;
                                }
                                case 4: {
                                    // Retourner au menu principal
                                    break;
                                }
                                default:
                                    cout << "Choix invalide !" << endl;
                                    break;
                            }
                            found = true;
                            table[i]->calculerDureeMoyenneSession();
                        }
                    }
                    if (!found)
                        cout << "Aucune statistique pour le mois " << mois << " et l'année " << annee << " n'a été trouvée." << endl;
                    break;
               }
            }
               case 5:
                  // Retourner au menu principal
                  break;
               default:
                   cout << "Choix invalide !" << endl;
                break;
            }
            break;

    case 2: {
            // Menu de gestion des postes
            int choixposte;
            // Afficher le menu de gestion de postes
            cout << "===== Menu Gestion postess =====" << endl;
            cout << "1. Création " << endl;
            cout << "2. Afficher " << endl;
            cout << "3. Supprimer " << endl;
            cout << "4. modifier machines " << endl;
            cout << "5. Retour au menu principal" << endl;
            cout << "Choix: ";
            cin >> choixposte;
            // Effectuer des actions basées sur le choix de l'utilisateur
            switch (choixposte) {
               case 1: {
                   int id_pos;
                    cout << "Entrez l'identités : ";
                    cin >> id_pos;
                    poste *p = new poste(id_pos," ");
                    t.push_back(p);
                   break;
               }
               case 2:{
                    int id_pos;string l;
                   cout << "Entrez l'identitée pour afficher la poste : ";
                   cin >> id_pos;
                   bool found = false;
                   for (size_t i = 0; i < t.size(); i++) {
                        if (t[i]->get_id_p() == id_pos ) {
                            cout << *(t[i]);
                            if(t[i]->verifier_etat_poste())
                            {
                                cout<<"La poste est active"<<endl;
                            }
                            cout<<"entrer un logiciel pour compter les machines:  "<<endl;
                            cin>>l;
                            t[i]->compter(l);
                            cout<<endl;
                            found = true;
                            break;
                        }
                    }
                   if (!found)
                       cout << "Aucune poste pour l'identitée " << id_pos << endl;
                break;
               }
               case 3:{
                  int id_pos;
                   cout << "Entrez l'identitée pour supprimer2 la poste : ";
                   cin >> id_pos;
                   bool found = false;
                   for (size_t i = 0; i < t.size(); i++) {
                        if (t[i]->get_id_p() == id_pos) {
                            cout << *(table[i]);
                            delete t[i];
                            t.erase(t.begin() + i);
                            found = true;
                        }
                    }
                   if (!found)
                       cout << "Aucune poste pour le mois " << id_pos<< " n'a été trouvée." << endl;
                break;
               }
               case 4:{
                   int id_pos;
                   cout << "Entrez l'identitée pour afficher la poste : ";
                   cin >> id_pos;
                   bool found = false;
                   for (size_t i = 0; i < t.size(); i++) {
                        if (t[i]->get_id_p() == id_pos) {
                             int choixm;
                             // Afficher le menu de gestion de personne
                             cout << "===== Menu Modifier =====" << endl;
                             cout << "1. Ajouter machine " << endl;
                             cout << "2. supprimer machine " << endl;
                             cout << "3. Retour au menu principal" << endl;
                             cout << "Choix: ";
                             cin >> choixm;
                             // Effectuer des actions basées sur le choix de l'utilisateur
                             switch (choixm) {
                                case 1: {
                                    machine p(0, " ", " ");
                                    cin >> p;
                                    t[i]->ajouter_machine(p);
                                    break;
                                }
                                case 2: {
                                   int id_m;
                                   cout << "Entrez l'identitée du machine : ";
                                   cin >> id_m;
                                   t[i]->supprimer_machine(t[i]->recherche(id_m));
                                    break;
                                }
                                case 3: {
                                    // Retourner au menu principal
                                    break;
                                }
                                default:
                                    cout << "Choix invalide !" << endl;
                                    break;
                            }
                            found = true;
                            table[i]->calculerDureeMoyenneSession();
                        }
                    }
                    if (!found)
                        cout << "Aucune poste pour l'identitée " << id_pos << " n'a été trouvée." << endl;
                    break;
               }

               case 5:
                  // Retourner au menu principal
                  break;
               default:
                   cout << "Choix invalide !" << endl;
                break;
            }
    }
               case 3:{
                   break;
               }

}

}while (choix != 4);

}
