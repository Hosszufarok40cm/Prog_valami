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

double Resistor::defR = 98;

Resistor::Resistor(){
    this->R = defR;
}
Resistor::Resistor(double r){
    this->R = r;
}
Resistor Resistor::operator+(const Resistor& r) const{
    Resistor uj((this->R)+r.R);
    return uj;
}
Resistor Resistor::operator%(const Resistor& r) const{
    Resistor uj(1/((1/this->R)+(1/r.R)));
    return uj;
}
Resistor operator*(int n, const Resistor& r){
    if(n <= 0){
        throw "UG050E";
    }
    Resistor uj(n*r.getR());
    return uj;
}
void Resistor::setDef(double r){
    defR = r;
}
