/**
 * Original testcase for bug
 * https://bugs.launchpad.net/qemu/+bug/645662
 */

#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    x = -2.1073424255447017e-08;
    y = asinh(x);
    printf("y = %20.16e\n",y);
    printf("should be -2.1073424255447017e-08\n");
}
