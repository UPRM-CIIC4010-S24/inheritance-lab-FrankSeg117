#include "StarterCode.hpp"

/* Exercise 5
 * Given a vector of Art pieces, return a vector containing only the
 * Sculptures in the original vector. You must use dynamic casting to
 * determine whether an Art piece is a Sculpture or not .
 */
    vector<Sculpture *> Sculpture::segregateSculptures(const vector<Art *> &collection) {
        vector<Sculpture*> result;
        for(int i = 0; i < collection.size(); i++){
            Sculpture* sculpture = dynamic_cast<Sculpture*>(collection[i]);
            if(sculpture != nullptr){
                result.push_back(sculpture);
            }
        }
        return result;
    }
