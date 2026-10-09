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

    const int n_col = 5;
    const int borneInf = 2;
    const int borneSup = 1000;
    int compteurNbCln = 0; // Compteur pour suivre l'affichage des nombres premiers
    bool continuerProgramme = 1; // Initialisation à True par défault
    char choixRecommencer = 'N';

    do {

        int limite = 2;

        // Vérifie l'entré utilisateur pour la limite
        do {

            cout << "Entrer une valeur [2-1000] : ";
            cin >> limite;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }while (limite < borneInf || limite > borneSup);

        cout << "Voici la liste des nombres premiers" << endl;

        // Parcours des nombres de 2 à la limite
        for (int i = borneInf; i <= limite; i++) {

            bool estPremier = true;

            // On cherche un diviseur de i
            for (int j = borneInf; j < i; j++) {
                if (i % j == 0) {
                    estPremier = false;
                    break; // Si on trouve un seul diviseur il est pas premier on arrête la boucle là pas besoin de continuer
                }
            }

            // Si aucun diviseur n'a été trouvé
            if (estPremier) {
                cout << setw(5) << i;
                compteurNbCln++;
            }

            // Si déjà 5 nombres ont été afficher sur une ligne on fait un retour à la ligne et on remet le compteur à 0
            if (compteurNbCln == n_col) {
                cout << endl;
                compteurNbCln = 0;
            }
        }

        cout << endl;

        // Vérifie l'entré utilisateur pour recommencer ou pas le programme
        do {

            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> choixRecommencer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }while (choixRecommencer != 'O' && choixRecommencer != 'N');

        // Si le choix est non on établit choixRecommencer à false pour ne pas continuer
        if (choixRecommencer == 'N') {
             continuerProgramme = 0;
        }

    }while (continuerProgramme);

    cout << "Fin de programme";

    return EXIT_SUCCESS;
}


