#include "numbers.hpp"

int neg_modulo(int a, int b) {
    return (b + (a % b)) % b;
}
