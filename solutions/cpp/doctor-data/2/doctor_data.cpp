#include "doctor_data.h"

    heaven::Vessel::Vessel(std::string name, int generation) 
        : name{std::move(name)}
        , generation{generation}
        , current_system{star_map::System::Sol}{}    

// Constructor - with a starting system
    heaven::Vessel::Vessel(std::string name, int generation, star_map::System star)
        : name{std::move(name)}
        , generation{generation}
        , current_system{star}{}

    
    heaven::Vessel heaven::Vessel::replicate(std::string name) const {
        return Vessel{std::move(name), generation + 1, current_system};
    }
    // Adds a buster charge
    void heaven::Vessel::make_buster() {
        ++busters;
    }
    
    // Fires a buster if available, returns true if it fired
    bool heaven::Vessel::shoot_buster() {
        if (busters > 0) {
            --busters;
            return true;
        }
        return false;
    }
    bool heaven::in_the_same_system(const Vessel& a, const Vessel& b) {
        return a.current_system == b.current_system;
    }

    std::string heaven::get_older_bob(const Vessel& a, const Vessel& b) {
        if (a.generation < b.generation) {
            return a.name;
        }
        return b.name;
    }