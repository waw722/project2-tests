#include <stdio.h>
#include <math.h>

/**
 * global statistics
 */
long double diff_abs_sum;
int testfn_calls;

/**
 * call specified math function and ouput difference from expected
 */
void testfn_caller(double (* fn)(double), char *fname, double x, double ex) {
    double diff, res;
    res = fn(x);
    diff = fabs(ex - res);
    printf("fn: %s\tin: %12E\tres: %20.16E\tdiff: %20.16E\n", fname, x, res, diff);
    if (!isnan(diff) && !isinf(diff)) {
        testfn_calls++;
        diff_abs_sum += diff;
    }
}

/**
 * entrypoint
 */
int main() {
    diff_abs_sum = 0;
    testfn_calls = 0;
    printf("%s\n", "Trig functions called on 0");
    testfn_caller(&sin, "sin()",    0, 0);
    testfn_caller(&cos, "cos()",    0, 1);
    testfn_caller(&tan, "tan()",    0, 0);
    testfn_caller(&asin, "asin()",  0, 0);
    testfn_caller(&acos, "acos()",  0, M_PI_2);
    testfn_caller(&atan, "atan()",  0, 0);
    printf("%s\n", "Trig functions called on 1");
    testfn_caller(&sin, "sin()",    1, 0.841470984807896506652502321630298999);
    testfn_caller(&cos, "cos()",    1, 0.540302305868139717400936607442976603);
    testfn_caller(&tan, "tan()",    1, 1.557407724654902230506974807458360173);
    testfn_caller(&asin, "asin()",  1, M_PI_2);
    testfn_caller(&acos, "acos()",  1, 0);
    testfn_caller(&atan, "atan()",  1, M_PI_4);
    printf("%s\n", "Trig functions called on 1/2");
    testfn_caller(&sin, "sin()",    0.5, 0.4794255386042030002732879352155713);
    testfn_caller(&cos, "cos()",    0.5, 0.8775825618903727161162815826038296);
    testfn_caller(&tan, "tan()",    0.5, 0.5463024898437905132551794657802853);
    testfn_caller(&asin, "asin()",  0.5, 0.5235987755982988730771072305465838);
    testfn_caller(&acos, "acos()",  0.5, 1.0471975511965977461542144610931676);
    testfn_caller(&atan, "atan()",  0.5, 0.4636476090008061162142562314612144);
    printf("%s\n", "Trig functions called on sqrt(2)");
    testfn_caller(&sin, "sin()",    M_SQRT2, 0.987765945992735527069134072078);
    testfn_caller(&cos, "cos()",    M_SQRT2, 0.155943694765374473454647978908);
    testfn_caller(&tan, "tan()",    M_SQRT2, 6.334119167042191554056833264227);
    testfn_caller(&asin, "asin()",  M_SQRT2, NAN);
    testfn_caller(&acos, "acos()",  M_SQRT2, NAN);
    testfn_caller(&atan, "atan()",  M_SQRT2, 0.955316618124509278163857102515);
    printf("%s\n", "Trig functions called on pi");
    testfn_caller(&sin, "sin()",    M_PI, 0);
    testfn_caller(&cos, "cos()",    M_PI, -1);
    testfn_caller(&tan, "tan()",    M_PI, 0);
    testfn_caller(&asin, "asin()",  M_PI, NAN);
    testfn_caller(&acos, "acos()",  M_PI, NAN);
    testfn_caller(&atan, "atan()",  M_PI, 1.262627255678911683444322083605698);
    printf("%s\n", "Trig functions called on pi/2");
    testfn_caller(&sin, "sin()",    M_PI_2, 1);
    testfn_caller(&cos, "cos()",    M_PI_2, 0);
    testfn_caller(&tan, "tan()",    M_PI_2, NAN);
    testfn_caller(&asin, "asin()",  M_PI_2, NAN);
    testfn_caller(&acos, "acos()",  M_PI_2, NAN);
    testfn_caller(&atan, "atan()",  M_PI_2, 1.0038848218538872141484239449171);
    printf("Average error: %20.16LE\n", diff_abs_sum / testfn_calls);
    testfn_calls = 0;
    diff_abs_sum = 0;
    printf("%s\n", "Hyperbolic Trig functions called on 0");
    testfn_caller(&sinh, "sinh()",    0, 0);
    testfn_caller(&cosh, "cosh()",    0, 1);
    testfn_caller(&tanh, "tanh()",    0, 0);
    testfn_caller(&asinh, "asinh()",  0, 0);
    testfn_caller(&acosh, "acosh()",  0, M_PI_2);
    testfn_caller(&atanh, "atanh()",  0, 0);
    printf("%s\n", "Hyperbolic Trig functions called on 1");
    testfn_caller(&sinh, "sinh()",    1, 0.841470984807896506652502321630298999);
    testfn_caller(&cosh, "cosh()",    1, 0.540302305868139717400936607442976603);
    testfn_caller(&tanh, "tanh()",    1, 1.557407724654902230506974807458360173);
    testfn_caller(&asinh, "asinh()",  1, M_PI_2);
    testfn_caller(&acosh, "acosh()",  1, 0);
    testfn_caller(&atanh, "atanh()",  1, M_PI_4);
    printf("%s\n", "Hyperbolic Trig functions called on 1/2");
    testfn_caller(&sinh, "sinh()",    0.5, 0.4794255386042030002732879352155713);
    testfn_caller(&cosh, "cosh()",    0.5, 0.8775825618903727161162815826038296);
    testfn_caller(&tanh, "tanh()",    0.5, 0.5463024898437905132551794657802853);
    testfn_caller(&asinh, "asinh()",  0.5, 0.5235987755982988730771072305465838);
    testfn_caller(&acosh, "acosh()",  0.5, 1.0471975511965977461542144610931676);
    testfn_caller(&atanh, "atanh()",  0.5, 0.4636476090008061162142562314612144);
    printf("%s\n", "Hyperbolic Trig functions called on sqrt(2)");
    testfn_caller(&sinh, "sinh()",    M_SQRT2, 0.987765945992735527069134072078);
    testfn_caller(&cosh, "cosh()",    M_SQRT2, 0.155943694765374473454647978908);
    testfn_caller(&tanh, "tanh()",    M_SQRT2, 6.334119167042191554056833264227);
    testfn_caller(&asinh, "asinh()",  M_SQRT2, NAN);
    testfn_caller(&acosh, "acosh()",  M_SQRT2, NAN);
    testfn_caller(&atanh, "atanh()",  M_SQRT2, 0.955316618124509278163857102515);
    printf("%s\n", "Hyperbolic Trig functions called on pi");
    testfn_caller(&sinh, "sinh()",    M_PI, 0);
    testfn_caller(&cosh, "cosh()",    M_PI, -1);
    testfn_caller(&tanh, "tanh()",    M_PI, 0);
    testfn_caller(&asinh, "asinh()",  M_PI, NAN);
    testfn_caller(&acosh, "acosh()",  M_PI, NAN);
    testfn_caller(&atanh, "atanh()",  M_PI, 1.262627255678911683444322083605698);
    printf("%s\n", "Hyperbolic Trig functions called on pi/2");
    testfn_caller(&sinh, "sinh()",    M_PI_2, 1);
    testfn_caller(&cosh, "cosh()",    M_PI_2, 0);
    testfn_caller(&tanh, "tanh()",    M_PI_2, NAN);
    testfn_caller(&asinh, "asinh()",  M_PI_2, NAN);
    testfn_caller(&acosh, "acosh()",  M_PI_2, NAN);
    testfn_caller(&atanh, "atanh()",  M_PI_2, 1.0038848218538872141484239449171);
    printf("Hyperbolic trig avg err: %20.16LE\n", diff_abs_sum / testfn_calls);
}
