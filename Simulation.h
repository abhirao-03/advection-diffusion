#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "SimulationParams.h"
#include "GasCanister.h"

class Simulation{
    private:
        SimulationParams params;
        std::vector<GasCanister> canisters;
        std::vector<std::vector<double>> concentration_grid;
        double diffusion_coeff_x;
        double diffusion_coeff_y;
        double advection_velocity_x;
        double advection_velocity_y;
        double time_step_dt;

    public:
        explicit Simulation(const SimulationParams& initial_params,
                            double pde_Dx, double pde_Dy,
                            double pde_ux, double pde_uy,
                            double pde_dt):
            params(initial_params),
            concentration_grid(initial_params.get_y_steps(), std::vector<double>(initial_params.get_x_steps(), 0.0)),
            diffusion_coeff_x(pde_Dx), diffusion_coeff_y(pde_Dy),
            advection_velocity_x(pde_ux), advection_velocity_y(pde_uy),
            time_step_dt(pde_dt)
            {};
            
        void initialize_concentration_field();
        void add_canister(const GasCanister& canister);
        const std::vector<std::vector<double>>& get_concentration_grid() const {return concentration_grid;}
};

#endif