#ifndef SIMULATIONPARAMS_H
#define SIMULATIONPARAMS_H

class SimulationParams {
    private:
        double length_x;
        double length_y;
        int num_steps_x;
        int num_steps_y;
        double dx;
        double dy;

    public:
        SimulationParams() : length_x(1.0), length_y(1.0), num_steps_x(100), num_steps_y(100), dx(length_x/(num_steps_x - 1)), dy(length_y/(num_steps_y - 1)) {}
        SimulationParams(const double& Lx, const double& Ly, int num_step_x, int num_step_y) : length_x(Lx), length_y(Ly), num_steps_x(num_step_x), num_steps_y(num_step_y), dx(Lx/(num_step_x - 1)), dy(Ly/(num_step_y - 1)) {}

        double get_x_length() const {return length_x;}
        double get_y_length() const {return length_y;}
        int get_x_steps() const {return num_steps_x;}
        int get_y_steps() const {return num_steps_y;}
        double get_dx() const {return dx;}
        double get_dy() const {return dy;}
};

#endif