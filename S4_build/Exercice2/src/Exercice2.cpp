/*
Nom : VAUDRY
Prenom : Pierre
Classse : AERO 3PSA-1
Groupe : A1
Exercice :EXERXICE 2
Version : v2
Date : 16/03/2023 | seance 4 (cours-TP)
Description :

*/

//------------------------------------
//             En-tete
//------------------------------------
#include"lib/complexe.h"

int complexe::nb = 0 ;

//------------------------------------
//        Programme Principal
//------------------------------------
int main() {

    complexe c1(2.0, 3.0);
    complexe c2(1.0, -1.0);
    complexe c3;

    c1.afficher("c1");
    c2.afficher("c2");

    cout << "c3 = c1 + c2 : ";
    c3 = c1 + c2;
    c3.afficher("c3");

    cout << "c3 = c1 - c2 : ";
    c3 = c1 - c2;
    c3.afficher("c3");

    cout << "c3 = c1 * c2 : ";
    c3 = c1 * c2;
    c3.afficher("c3");

    cout << "c3 = c1 / c2 : ";
    c3 = c1 / c2;
    c3.afficher("c3");

    cout << "c3 += c2 : ";
    c3 += c2;
    c3.afficher("c3");

    cout << "c3 -= c2 : ";
    c3 -= c2;
    c3.afficher("c3");

    cout << "c3 *= c2 : ";
    c3 *= c2;
    c3.afficher("c3");

    cout << "c3 /= c2 : ";
    c3 /= c2;
    c3.afficher("c3");

    cout << "c1 == c2 : " << (c1 == c2) << endl;
    cout << "c1 != c2 : " << (c1 != c2) << endl;

    cout << "c3 = c1 + 2.0 : ";
    c3 = c1 + 2.0;
    c3.afficher("c3");

    cout << "c3 = c1 - 2.0 : ";
    c3 = c1 - 2.0;
    c3.afficher("c3");

    cout << "c3 = c1 * 2.0 : ";
    c3 = c1 * 2.0;
    c3.afficher("c3");

    cout << "c3 = c1 / 2.0 : ";
    c3 = c1 / 2.0;
    c3.afficher("c3");

    cout << "c3 += 2.0 : ";
    c3 += 2.0;
    c3.afficher("c3");

    cout << "c3 -= 2.0 : ";
    c3 -= 2.0;
    c3.afficher("c3");

    cout << "c3 *= 2.0 : ";
    c3 *= 2.0;
    c3.afficher("c3");

    cout << "c3 /= 2.0 : ";
    c3 /= 2.0;
    c3.afficher("c3");

    cout << "Conjugué de c1 : ";
    c1.conjugue().afficher("c1");

    cout << "Conjugué de c2 : ";
    c2.conjugue().afficher("c2");

    cout << "Module de c1 : " << c1.module() << endl;
    cout << "Module de c2 : " << c2.module() << endl;
    cout << "Module de c3 : " << c3.module() << endl;


    cout << "Distance entre c1 et c2 : " << c1.distance(c2) << endl;

    return 0;
}



