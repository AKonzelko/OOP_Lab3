#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
public:
    Dyhotomia_class(void);
    ~Dyhotomia_class(void);
    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    int count(double &x);
    int count_newton(double &x);

private:
    double a;
    double b;
    double eps;
    double f(double x);
    double df(double x);
};

#endif