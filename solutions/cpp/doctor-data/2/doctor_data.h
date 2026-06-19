#pragma once
#include <string>

namespace star_map{
    enum class System{
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}


namespace heaven{
    
    class Vessel{
        public:
            std::string name;
            int generation;
            star_map::System current_system;
            int busters{0};
            Vessel(std::string name, int generation );
            Vessel(std::string name, int generation , star_map::System star);

            
            Vessel replicate(std::string name) const;
            void make_buster();
            bool shoot_buster();
            
    };
        bool in_the_same_system(const Vessel& a, const Vessel& b);
        std::string get_older_bob(const Vessel& a, const Vessel& b);

}
