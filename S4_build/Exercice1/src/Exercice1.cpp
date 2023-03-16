/*
Nom : VAUDRY
Prenom : Pierre
Classse : AERO 3PSA-1
Groupe : A1
Exercice :EXERXICE 1
Version : v1
Date : 16/03/2023 | seance 4 (cours-TP)
Description :

*/

//------------------------------------
//             En-tete
//------------------------------------
#include<iostream>
#include<cmath>

using namespace std;

//------------------------------------
//           Classe
//------------------------------------
class point{

protected:
    //attributs
       double x;
       double y;


public:
    //methodes
    point(double,double);
    void   afficher(string);
   double ladistance(const point &);

};
//----------------------------------
class point_3D:public point{

protected :
    //attributs
       double z;

public:
    //methodes
    point_3D(double,double,double);
    void   afficher(string);
    double ladistance(const point_3D &);

};
//----------------------------------
class couleur{

protected:
    //attributs
       string coul;

public:
    //methodes
    couleur(string);
    void afficher();

};
//----------------------------------
class point_couleur:public point,public couleur{

public:
    //methodes
    point_couleur(double,double,string);
    void afficher(string);
    double ladistance(const point_couleur &);

};

//----------------------------------
class point_3D_couleur:public point_3D,public couleur{

public:
    //methodes
    point_3D_couleur(double,double,double,string);
    void afficher(string);
    double ladistance(const point_3D_couleur &);

};

//----------------------------------
// Definition des methodes de la classe point
//----------------------------------

point:: point(double a =0, double b=0):x(a),y(b){} // constructeur


void point::afficher(string s ){cout << "------------- point " << s <<" ---------<<"<<endl;
                                cout<<"x= "<<x<<endl;
                                cout<<"y= "<<y<<endl;
}


double point::ladistance(const point & p){return(sqrt(pow(x-p.x,2)+pow(y-p.y,2)));}

//----------------------------------
// definition des methodes de la classe point_3D
//----------------------------------

point_3D:: point_3D(double a =0, double b=0, double c=0):point(a,b),z(c){} // constructeur


void point_3D::afficher(string s ){point::afficher(s); cout<<"z= "<<z<<endl;}


double point_3D::ladistance(const point_3D & p){return(   sqrt(pow(point::ladistance(p) ,2) + pow(z-p.z,2)  )   );}

//----------------------------------
// Definition des methodes de la classe couleur
//----------------------------------

couleur:: couleur(string s="no_color"):coul(s){} // constructeur
void couleur::afficher(){
                                cout<<"couleur= "<<coul<<endl;

}

//----------------------------------
// Definition des methodes de la classe point_couleur
//----------------------------------

     point_couleur:: point_couleur(double a =0, double b=0, string s="no_color"):point(a,b),couleur(s){} // constructeur


void point_couleur::afficher(string s ){point::afficher(s);couleur::afficher();

                            }
double point_couleur::ladistance(const point_couleur & p){return(point::ladistance(p));}

//----------------------------------
// Definition des methodes de la classe point_3D_couleur
//----------------------------------

point_3D_couleur:: point_3D_couleur(double a =0, double b=0,double c=0, string s="no_color"):point_3D(a,b,c),couleur(s){} // constructeur


void point_3D_couleur::afficher(string s ){point_3D::afficher(s);couleur::afficher();}
double point_3D_couleur::ladistance(const point_3D_couleur & p){return(point_3D::ladistance(p));}


//------------------------------------
//        Programme Principal
//------------------------------------

main()
{

    /*cout<<"--------------------------------------"<<endl;
    cout<< " Test de la classe point " <<endl;
    cout<<"--------------------------------------"<<endl;
    point p1(1,2),p2(2,3); //po est un objet de la classe point
    double d;

    p1.afficher("p1");
    p2.afficher("p2");
    d=p1.ladistance(p2);
    cout<<"--------------------------------------"<<endl;
    cout<< "la distance entre p1 et p2 : " << d <<endl;
    cout<<"--------------------------------------"<<endl;*/


    /*cout<<"--------------------------------------"<<endl;
    cout<< " Test de la classe point_3D " <<endl;
    cout<<"--------------------------------------"<<endl;
    point_3D pp1(1,2,3),pp2(2,3,3);
    double d;

    pp1.afficher("pp1");
    pp2.afficher("pp2");
    d=pp1.ladistance(pp2);
    cout<<"--------------------------------------"<<endl;
    cout<< "la distance entre pp1 et pp2 : " << d <<endl;
    cout<<"--------------------------------------"<<endl;*/

    /*cout<<"--------------------------------------"<<endl;
    cout<< " Test de la classe couleur " <<endl;
    cout<<"--------------------------------------"<<endl;
    couleur c1,c2("red");

    c1.afficher();
    c2.afficher();

    cout<<"--------------------------------------"<<endl;*/
    /*cout<<"--------------------------------------"<<endl;
    cout<< " Test de la classe point_couleur " <<endl;
    cout<<"--------------------------------------"<<endl;
    point_couleur pc1(1,2,"red"),pc2(2,3,"blue");

    pc1.afficher("1");
    pc2.afficher("2");

    double d = pc1.ladistance(pc2);
    cout<<"--------------------------------------"<<endl;
    cout<< "la distance entre pc1 et pc2 : " << d <<endl;
    cout<<"--------------------------------------"<<endl;*/

    cout<<"--------------------------------------"<<endl;
    cout<< " Test de la classe point_3D_couleur " <<endl;
    cout<<"--------------------------------------"<<endl;
    point_3D_couleur pc1(1,2,2,"red"),pc2(2,3,5,"blue");

    pc1.afficher("1");
    pc2.afficher("2");

    double d = pc1.ladistance(pc2);
    cout<<"--------------------------------------"<<endl;
    cout<< "la distance entre pc1 et pc2 : " << d <<endl;
    cout<<"--------------------------------------"<<endl;

}


