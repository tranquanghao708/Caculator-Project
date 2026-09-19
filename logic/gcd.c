#include <stdio.h>
#include "../header/Argorithm_Cal.h"

unsigned long long gcd(unsigned long long a,unsigned long long b){ //Euclid algorithm GDD(a,b) = GDC(a, a mod b)
    while (b != 0) {
        unsigned long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}