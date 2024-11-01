#include "StarterCode.hpp"

/*
 * Given a vector of Paintings, return the count of how many paintings
 * qualify with the given style and its year is between the given start
 * and end (inclusive).
 */
int Painting::countPaintings(const vector<Painting *> &collection, Style style, int start, int end) {
    int res = 0;
    for(Painting* p : collection){
        if(p->getStyle().equals(style) && p->getYear()>=start && p->getYear() < end){
            res++;
        }
    }
    return res;
}
