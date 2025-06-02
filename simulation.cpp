#include "Simulation.h"

void Simulation::add_canister(const GasCanister& canister){
    canisters.push_back(canister);
}

void Simulation::initialize_concentration_field(){
    for (const GasCanister& current_canister : this->canisters) {
        double gc_x = current_canister.get_x_loc();
        double gc_y = current_canister.get_y_loc();
        double gc_conc = current_canister.get_concentration();

        
    }
}