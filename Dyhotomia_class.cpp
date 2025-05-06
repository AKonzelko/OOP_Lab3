#include "Dyhotomia_class.h"
#include <cmath>
#include <limits>

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::f(double x) {
    double tg = tan(x);
    return tg - (pow(tg, 3) + 1) / 3.0 + 0.2 * pow(tg, 5);
}

double Dyhotomia_class::df(double x) {
    double tg = tan(x);
    double sec2 = 1.0 / (cos(x) * cos(x));
    return (
        sec2 - sec2 * tg * tg + 0.2 * 5 * pow(tg, 4) * sec2
    );
}

int Dyhotomia_class::count(double &x) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) return 1;

    double c;
    while ((b - a) >= eps) {
        c = (a + b) / 2.0;
        double fc = f(c);

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    x = (a + b) / 2.0;
    return 0;
}

int Dyhotomia_class::count_newton(double &x) {
    x = (a + b) / 2.0;
    int max_iter = 100;

    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) return 2;

        double x_new = x - fx / dfx;
        if (fabs(x_new - x) < eps) {
            x = x_new;
            return 0;
        }
        x = x_new;
    }

    return 1;
}