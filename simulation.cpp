#include "Simulation.h"
#include <algorithm>

void Simulation::add_canister(const GasCanister& canister){
    canisters.push_back(canister);
}

void Simulation::initialize_concentration_field(){
    double dx = params.get_dx();
    double dy = params.get_dy();
    int Nx = params.get_x_steps();
    int Ny = params.get_y_steps();

    for (const GasCanister& current_canister : this->canisters) {
        double gc_x = current_canister.get_x_loc();
        double gc_y = current_canister.get_y_loc();
        double gc_conc = current_canister.get_concentration();
        double gc_rad = current_canister.get_radius();

        int ix_low  = static_cast<int>((gc_x - gc_rad) / dx);
        int ix_high = static_cast<int>((gc_x + gc_rad) / dx);
        int iy_low  = static_cast<int>((gc_y - gc_rad) / dy);
        int iy_high = static_cast<int>((gc_y + gc_rad) / dy);

        for (int iy_cell = std::max(0, iy_low); iy_cell <= std::min(Ny - 1, iy_high); ++iy_cell) {
            for (int ix_cell = std::max(0, ix_low); ix_cell <= std::min(Nx - 1, ix_high); ++ix_cell){
                double cell_center_x = (ix_cell + 0.5) * dx;
                double cell_center_y = (iy_cell + 0.5) * dy;
                
                double delta_x = cell_center_x - gc_x;
                double delta_y = cell_center_y - gc_y;
                double dist_sq = delta_x * delta_x + delta_y * delta_y;

                if (dist_sq <= (gc_rad*gc_rad)) {
                    concentration_grid[iy_cell][ix_cell] = gc_conc;
                }
            }
        }
    }
}

void Simulation::perform_time_step(){
    int Nx = params.get_x_steps();
    int Ny = params.get_y_steps();
    double dx = params.get_dx();
    double dy = params.get_dy();

    std::vector<std::vector<double>> next_concentration_grid(Ny, std::vector<double>(Nx, 0.0));

    for (int iy = 1; iy < Ny - 1; ++iy){
        for (int ix = 1; ix < Nx - 1; ++ix){
            
        }
    }
    this->concentration_grid = next_concentration_grid;
}