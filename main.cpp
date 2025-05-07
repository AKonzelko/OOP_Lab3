#include <iostream>
#include "Dyhotomia_class.h"

int main() {
    Dyhotomia_class* dyh = new Dyhotomia_class();
    dyh->setVolumes(0.0, 0.8);
    dyh->setTolerance(1e-6);

    double x;

    if (dyh->count(x) == 0) {
        std::cout << "Метод дихотомії: корінь x = " << x << std::endl;
    } else {
        std::cout << "Метод дихотомії: не вдалося знайти корінь." << std::endl;
    }

    Newton_class* newton = new Newton_class();
    newton->setVolumes(0.0, 0.8);
    newton->setTolerance(1e-6);

    if (newton->count_newton(x) == 0) {
        std::cout << "Метод Ньютона: корінь x = " << x << std::endl;
    } else {
        std::cout << "Метод Ньютона: не вдалося знайти корінь." << std::endl;
    }

    delete dyh;
    delete newton;

    return 0;
}