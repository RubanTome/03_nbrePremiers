/*
------------------------------------------------------------------------------
  Fichier     : nbre_1er.cpp
  Auteur(s)   : Ruben Tomé
  Date        : 07.10.2026

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

int main () {
    const int borneInf = 2;
    const int borneSup = 1000;
    bool recommencer = 1; // Initialisation à True
    char choixRecommencerUtilisateur = 'N';
    do {

        int limite = 2;

        do {
            cout << "Entrer une valeur [2-1000] : ";
            cin >> limite;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }while (limite < borneInf || borneSup > 1000);

        cout << "Voici la liste des nombres premiers" << endl;

        // Parcours des nombres de 2 à la limite
        for (int i = borneInf; i <= limite; i++) {

            bool premier = true;

            // On cherche un diviseur de i
            for (int j = borneInf; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    premier = false;
                    break;
                }
            }

            // Si aucun diviseur n'a été trouvé
            if (premier) {
                cout << setw(5) << i;
            }
        }

        cout << endl;

        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> choixRecommencerUtilisateur;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }while (choixRecommencerUtilisateur != 'O'&& choixRecommencerUtilisateur != 'N');

        if (choixRecommencerUtilisateur == 'N') {
            recommencer = 0;
        }

    }while (recommencer);

    return EXIT_SUCCESS;
}


