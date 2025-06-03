#ifndef GASCANISTER_H
#define GASCANISTER_H

class GasCanister {
    private:
        double x_loc;
        double y_loc;
        double concentration_val;
        double radius;

    public:
        GasCanister() : x_loc(0.0), y_loc(0.0), concentration_val(0.0), radius(0.0) {}
        GasCanister(const double& x, const double& y, const double& conc, const double& rad) : x_loc(x), y_loc(y), concentration_val(conc), radius(rad){}

        double get_x_loc() const {return x_loc;}
        double get_y_loc() const {return y_loc;}
        double get_radius() const {return radius;}
        double get_concentration() const  {return concentration_val;}

};

#endif