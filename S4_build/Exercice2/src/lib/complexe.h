/*
Nom : VAUDRY
Prenom : Pierre
Classse : AERO 3PSA-1
Groupe : A1
Exercice :EXERXICE 2
Version : v2
Date : 16/03/2023 | seance  (cours-TP)
Description :
	Bibliotheque de l'exercice 2
*/

//------------------------------------
//             En-tete
//------------------------------------
#include <tgmath.h>
#include<iostream> // bibliotheques des flux entrants et sortant

using namespace std ;

//------------------------------------
//           Classe
//------------------------------------
class complexe {

private :
    double x ;
    double y ; // X la valeur réelle et Y la valeur imaginaire pure
    static int nb ; // Le nombre de complexe dans l'exo

public :
    // constructeur
    complexe() ;
    complexe(double) ;
    complexe(double ,double);
    complexe(const complexe &);
    ~complexe() ;

    //getters
    double get_x();
    double get_y();

    //setters
    void set_x(double);
    void set_y(double);

    //operators
    complexe operator + (const complexe &) ;
    complexe operator - (const complexe &) ;
    complexe operator * (const complexe &) ;
    complexe operator / (const complexe &) ;

    void operator += (const complexe &) ;
    void operator -= (const complexe &) ;
    void operator *= (const complexe &) ;
    void operator /= (const complexe &) ;

    bool operator == (const complexe &) ;
    bool operator != (const complexe &) ;

    complexe operator + (double) ;
    complexe operator - (double) ;
    complexe operator * (double) ;
    complexe operator / (double) ;

    void operator += (double) ;
    void operator -= (double) ;
    void operator *= (double) ;
    void operator /= (double) ;

    //autres methodes
    double distance(const complexe &) ;
    void afficher(string) ;
    complexe conjugue() ;
    double module() ;
    double argument() ;

    //methodes friend
    friend ostream & operator<<(ostream &, const complexe &);
    friend istream & operator>>(istream &, complexe &);
};
//------------------------------------

//----------------------------------
// Definition des methodes de la classe complexe
//----------------------------------
// Définition du constructeur par défaut
complexe::complexe() : x(0.0), y(0.0) {
    nb++;
}

// Définition du constructeur à un paramètre
complexe::complexe(double reel) : x(reel), y(0.0) {
    nb++;
}

// Définition du constructeur à deux paramètres
complexe::complexe(double reel, double imag) : x(reel), y(imag) {
    nb++;
}

// Définition du constructeur par recopie
complexe::complexe(const complexe& c) : x(c.x), y(c.y) {
    nb++;
}

// Définition du destructeur
complexe::~complexe() {
    nb--;
}

// Définition des getters et setters
void complexe::set_x(double reel) {
    x = reel;
}

void complexe::set_y(double imag) {
    y = imag;
}

double complexe::get_x() {
    return x;
}

double complexe::get_y() {
    return y;
}

// Définition des opérateurs arithmétiques
complexe complexe::operator+(const complexe& c) {
    return complexe(x + c.x, y + c.y);
}

complexe complexe::operator-(const complexe& c) {
    return complexe(x - c.x, y - c.y);
}

complexe complexe::operator*(const complexe& c) {
    return complexe(x * c.x - y * c.y, x * c.y + y * c.x);
}

complexe complexe::operator/(const complexe& c) {
    double denom = c.x * c.x + c.y * c.y;
    return complexe((x * c.x + y * c.y) / denom, (y * c.x - x * c.y) / denom);
}

// Définition des opérateurs combinés
void complexe::operator+=(const complexe& c) {
    x += c.x;
    y += c.y;
}

void complexe::operator-=(const complexe& c) {
    x -= c.x;
    y -= c.y;
}

void complexe::operator*=(const complexe& c) {
    double a = x;
    double b = y;
    x = a * c.x - b * c.y;
    y = a * c.y + b * c.x;
}

void complexe::operator/=(const complexe& c) {
    double a = x;
    double b = y;
    double denom = c.x * c.x + c.y * c.y;
    x = (a * c.x + b * c.y) / denom;
    y = (b * c.x - a * c.y) / denom;
}

// Définition des opérateurs de comparaison
bool complexe::operator==(const complexe& c) {
    return x == c.x && y == c.y;
}

bool complexe::operator!=(const complexe& c) {
    return !(*this == c);
}

// Définition des opérateurs arithmétiques avec un double
complexe complexe::operator+(double reel) {
    return complexe(x + reel, y);
}

complexe complexe::operator-(double reel) {
    return complexe(x - reel, y);
}

complexe complexe::operator*(double a)
{
    complexe res;
    res.x = x * a;
    res.y = y * a;
    return res;
}

complexe complexe::operator/(double a) {
    return complexe(x / a, y / a);
}

void complexe::operator+=(double a) {
    x += a;
}

void complexe::operator-=(double a) {
    x -= a;
}

void complexe::operator*=(double a) {
    x *= a;
    y *= a;
}

void complexe::operator/=(double d) {
    x /= d;
    y /= d;
}

ostream & operator<<(ostream & out, const complexe & c){
    return out << "Partie reel : " << c.x << endl << "Partie imaginaire : " << c.y << endl ;
}
istream & operator >> (istream & out,complexe & c){
    double a,b ;
    cout << "Rentrez la valeur réel pour le nombre voulu : " ;
    cin >> a ;
    cout << "Rentrez la valeur imaginaire pour le nombre voulu : " ;
    cin >> b ;
    c = complexe (a,b);
}

void complexe :: afficher(string str = ""){
    cout << endl <<"-----------------" << endl;
    cout << "point " << str << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

double complexe::distance(const complexe &c) {
return sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
}

complexe complexe::conjugue() {
return complexe(x, -y);
}

double complexe::module() {
return sqrt(pow(x, 2) + pow(y, 2));
}

double complexe::argument() {
    double arg = atan(abs(y) / x);
    if (x > 0 && y > 0) {
        // cas 1
        return arg;
    } else if (x < 0 && y > 0) {
        // cas 2
        return M_PI - arg;
    } else if (x < 0 && y < 0) {
        // cas 3
        return arg - M_PI;
    } else if (x > 0 && y < 0) {
        // cas 4
        return -arg;
    } else if (x == 0 && y > 0) {
        // cas 5
        return M_PI_2;
    } else if (x == 0 && y < 0) {
        // cas 6
        return -M_PI_2;
    } else {
        // cas 7 : x == 0 && y == 0
        return 0;
    }

};
// fin de la classe complexe
