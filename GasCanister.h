#ifndef GASCANISTER_H
#define GASCANISTER_H

class GasCanister {
    private:
    double x_loc;
    double y_loc;
    double concentration_val;

    public:
        GasCanister() : x_loc(0.0), y_loc(0.0), concentration_val(0.0) {}
        GasCanister(const double& x, const double& y, const double& conc) : x_loc(x), y_loc(y), concentration_val(conc){}

        double get_x_loc() const {return x_loc;}
        double get_y_loc() const {return y_loc;}
        double get_concentration() const  {return concentration_val;}

};

#endif