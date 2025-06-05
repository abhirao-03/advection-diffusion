#include <iostream>
#include <vector>
#include <iomanip>
#include "Simulation.h"
#include "SimulationParams.h"
#include "GasCanister.h"

int main() {
    int num_points_x = 10;
    int num_points_y = 10;
    double length_x = 1.0;
    double length_y = 1.0;

    double dc_x = 1.0;
    double dc_y = 1.0;
    double av_x = 1.0;
    double av_y = 1.0;
    double dt = 0.001;

    SimulationParams params(length_x, length_y, num_points_x, num_points_y);

    Simulation sim(params,
                   dc_x,
                   dc_y,
                   av_x,
                   av_y,
                   dt);

    GasCanister canister1(0.25, 0.25, 100.0, 0.1);
    GasCanister canister2(0.5, 0.5, 10.0, 0.1);

    sim.add_canister(canister1);
    sim.add_canister(canister2);

    sim.initialize_concentration_field();

    const auto& grid = sim.get_concentration_grid();

    // Print the grid
    std::cout << "Concentration Grid (iy from 0 at top to Ny-1 at bottom):" << std::endl;
    for (int iy = 0; iy < params.get_y_steps(); ++iy) {
        for (int ix = 0; ix < params.get_x_steps(); ++ix) {
            // std::fixed and std::setprecision ensure consistent decimal formatting
            std::cout << std::fixed << std::setprecision(2) << grid[iy][ix] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // For debugging, print dx and dy
    std::cout << "dx = " << params.get_dx() << std::endl;
    std::cout << "dy = " << params.get_dy() << std::endl;


    return 0;
}