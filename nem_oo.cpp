#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */



int sajat::atoi(const char *p, int base){
    int ret = 0;
    for(int i = 0; p[i] != '\0' && p[i] != ' ';i++ ){
        if(isdigit(p[i]) && base >= 0 && base <= 10 && p[i] != base){
            ret *= base;
            ret += p[i] - '0';
        }else{
            throw "UG050E";
        }
    }
    return ret;
}
char *sajat::strcat(const char *p1, const char *p2){
    unsigned int hossz = strlen(p1) + strlen(p2);
    char * ret = new char[hossz +1];
    for(unsigned int i = 0; i != hossz; i++){
        if(i < strlen(p1)){
            ret[i] = p1[i];
        }else{
            ret[i] = p2[i-strlen(p1)];
        }
    }
    ret[hossz] = '\0';
    return ret; 
}
char *sajat::unique(char *first, char *last){
    for(int i = 0; first+i != last-1;i++){
        if(first[i] == first[i+1]){
            for(int k = i+1; first+k != last-1 ;k++){
                first[k] = first[k+1];
            }
            last -= 1;
            if(first[i] == first[i+1]){
                i--;
            }
        }
    }
    return last;
}
