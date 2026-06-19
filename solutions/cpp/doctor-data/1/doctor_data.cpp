#include "doctor_data.h"

    


    heaven::Vessel::Vessel(std::string name, int generation) {
        this->name = name;
        this->generation = generation;
        this->current_system = star_map::System::Sol; // default
    }    

// Constructor - with a starting system
    heaven::Vessel::Vessel(std::string name, int generation, star_map::System star) {
        this->name = name;
        this->generation = generation;
        this->current_system = star;
    }

    
    heaven::Vessel heaven::Vessel::replicate(std::string name) {
        return Vessel(name, this->generation + 1, this->current_system);
    }
    // Adds a buster charge
    void heaven::Vessel::make_buster() {
        this->busters++;
    }
    
    // Fires a buster if available, returns true if it fired
    bool heaven::Vessel::shoot_buster() {
        if (this->busters > 0) {
            this->busters--;
            return true;
        }
        return false;
    }
    bool heaven::in_the_same_system(heaven::Vessel a, heaven::Vessel b) {
        return a.current_system == b.current_system;
    }

    std::string heaven::get_older_bob(heaven::Vessel a, heaven::Vessel b) {
        if (a.generation < b.generation) {
            return a.name;
        }
        return b.name;
    }