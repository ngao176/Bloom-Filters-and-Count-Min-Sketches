#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    for (int i = 0; i < K; i++) {
        int h = hash<string>{}(s + to_string(i));
        int index = h % M;
        bits[index]= true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    for (int i = 0; i < K; i++) {
        int h = hash<string>{}(s + to_string(i));
        int index = h % M;
        if (!bits[index]) {
                return false;
        }
    }
    return true;
}
