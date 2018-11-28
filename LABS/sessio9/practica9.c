#include <stdio.h>
#include <unistd.h>


double doblePrec (double x, double y) {
    return x*x*x*x - 4*y*y*y*y - 4*y*y;
}

float simplePrec (float x, float y) {
    return x*x*x*x - 4*y*y*y*y - 4*y*y;
}

long long longIntPrec (long long x, long long y) {
    return x*x*x*x - 4*y*y*y*y - 4*y*y;
}


int main() {

    printf("doble precisió: %f\n",doblePrec(665857,470832));
    printf("simple precisió: %f\n",simplePrec(665857,470832));
    printf("long integer precisió: %lld\n",longIntPrec(665857,470832));

    return 0;
}
