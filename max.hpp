#ifndef _MAX_HPP
#define _MAX_HPP
/**
 * file max.hpp
 * (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * A C++ nem OO bővítéseinek gyakorlásához.
 *
 *
 * FELADATOK:
 *  2. Valósítson meg EBBEN a fájlban, a Sajat névtéren belül egy olyan sablont, ami
 *     alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 *  3. Specializálja a sablont a nem_oo.h állományban deklarált Komplex típusra
 *     úgy hogy a nagyobb abszolút értékû Komplex számot adja vissza!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

#include "nem_oo.h"

namespace sajat{
    template <typename T > T max(T t1, T t2){
        return (t1 > t2) ? t1 : t2;
    }
    Komplex max (Komplex k1, Komplex k2){
        return (absKomplex(k1) > absKomplex(k2) ? k1 : k2);
    }
}





#endif // _MAX_HPP

