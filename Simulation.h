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

    public:
        explicit Simulation(const SimulationParams& initial_params):
            params(initial_params),
            concentration_grid(initial_params.get_y_steps(), std::vector<double>(initial_params.get_x_steps(), 0.0))
            {};
            
        void initialize_concentration_field();
        void add_canister(const GasCanister& canister);
        const std::vector<std::vector<double>>& get_concentration_grid() const {return concentration_grid;}
};

#endif