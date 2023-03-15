/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

/// Előre elkészített tagfüggvények

/// 0, 1 és 2 paraméteres konstruktor
/// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
/// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const { return sqrt(re*re + im*im); }

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}
#endif

// ------------------------ Eddig elkészítettük -------------------------
// TODO: A hiányzó tag- és globális függvények itt következnek

double Komplex::getRe() const {
    return re;
}
double Komplex::getIm() const {
    return im;
}

void Komplex::setRe(double re) {
    this->re = re;
}
void Komplex::setIm(double im) {
    this->im = im;
}

bool Komplex::operator==(const Komplex& rhs_k) const {
    if (re == rhs_k.re && im == rhs_k.im) {
        return true;
    }
    else {
        return false;
    }
}

Komplex Komplex::operator+(const Komplex& rhs_k) const {
    Komplex uj;
    uj.re = this->re + rhs_k.re;
    uj.im = this->im + rhs_k.im;
    return uj;
}
Komplex Komplex::operator+(double rhs_d) const {
    Komplex uj;
    uj.re = this->re + rhs_d;
    uj.im = this->im;
    return uj;
}

Komplex operator+(double lhs_d, const Komplex& rhs_k) {
    Komplex uj;
    uj.setRe(lhs_d+rhs_k.getRe());
    uj.setIm(rhs_k.getIm());
    return uj;
}

Komplex& Komplex::operator+=(const Komplex& rhs_k) {
    this->re = this->re + rhs_k.re;
    this->im = this->im + rhs_k.im;
    return *this;
}

/*még nem a legjobb*/
std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k) {
    if (rhs_k.getIm() >= 0) {
        os << rhs_k.getRe() << "+" << rhs_k.getIm() << "j";
    }
    else {
        os << rhs_k.getRe() << rhs_k.getIm() << "j";
    }    
    return os ;
}
std::istream& operator>>(std::istream& is, Komplex& rhs_k) {
    double r = 0, i = 2;
    is >> r >> i;
    rhs_k.setRe(r);
    rhs_k.setIm(i);
    return is;
}

Komplex Komplex::operator~() const {
    Komplex uj;
    uj.re = re;
    uj.im = (im * -1);
    return uj;
}

Komplex Komplex::operator*(const Komplex& rhs_k) const {
    Komplex uj;
    uj.re = (re * rhs_k.re - im * rhs_k.im);
    uj.im = (re * rhs_k.im + im * rhs_k.re);
    return uj;
}
Komplex Komplex::operator*(double rhs_d) const {
    Komplex uj;
    uj.re = re * rhs_d;
    uj.im = im * rhs_d;
    return uj;
}
Komplex& Komplex::operator*=(const Komplex& rhs_k) {
    double r = (re * rhs_k.re - im * rhs_k.im);
    double i = (re * rhs_k.im + im * rhs_k.re);
    re = r;
    im = i;
    return *this;
}
Komplex& Komplex::operator*=(double rhs_d) {
    re = re * rhs_d;
    im = im * rhs_d;
    return *this;
}