#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    for (unsigned int i = 0; i < K; i++) {
        unsigned int hash = hash_functions[i](s);
        count[i][hash % M]++;
    }
}

unsigned int CountMinSketch::find(const string & s) {
    unsigned int y;
    for (unsigned int i = 0; i < K; i++) {
        unsigned int hash = hash_functions[i](s);
        unsigned int x = count[i][hash % M];
        y = min(y, x);
    }
    return y;
}
