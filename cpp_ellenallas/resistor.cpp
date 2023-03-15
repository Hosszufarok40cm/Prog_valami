/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

void Resistor::setDef(double r){
    defR = r;
}
Resistor Resistor::operator+(const Resistor& r) const{
    Resistor uj;
    uj.R = R+r.R;
    return uj;
}
Resistor Resistor::operator%(const Resistor& r) const{
    Resistor uj;
    uj.R = 1/((1/R)+(1/r.R));
    return uj;
}
Resistor operator*(int n, const Resistor& r){
    if(n <= 0){
        throw "UG050E";
    }else{
        Resistor uj(n * r.getR());
        return uj;
    }
}