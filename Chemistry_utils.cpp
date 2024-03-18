#include "Chemistry_utils.h"

namespace Ionen {
    // Negatief
    Chemistry::Ion fluorideion = {"fluoride-ion", "F", "-"};
    Chemistry::Ion chlorideion = {"chloride-ion", "Cl", "-"};
    Chemistry::Ion bromideion = {"bromide-ion", "Br", "-"};
    Chemistry::Ion jodideion = {"jodide-ion", "I", "-"};
    Chemistry::Ion oxideion = {"oxide-ion", "O", "2-"};
    Chemistry::Ion sulfideion = {"sulfide-ion", "S", "2-"};

    // Positief
    Chemistry::Ion aliminiumion = {"aliminiumion", "Al", "3+"};
    Chemistry::Ion bariumion = {"bariumion", "Ba", "2+"};
    Chemistry::Ion calciumion = {"calciumion", "Ca", "2+"};
    Chemistry::Ion goudIion = {"goud(I)ion", "Au", "+"};
    Chemistry::Ion goudIIIion = {"goud(III)ion", "Au", "3+"};
    Chemistry::Ion ijzerIIion = {"ijzer(II)ion", "Fe", "2+"};
    Chemistry::Ion ijzerIIIion = {"ijzer(III)ion", "Fe", "3+"};
    Chemistry::Ion kaliumion = {"kalium", "K", "+"};
    Chemistry::Ion koperion = {"koperion", "Cu", "2+"};
    Chemistry::Ion kwikIion = {"kwik(I)ion", "Hg", "+"};
    Chemistry::Ion kwikIIion = {"kwik(II)ion", "Hg", "2+"};
    Chemistry::Ion lithiumion = {"lithiumion", "Li", "+"};
    Chemistry::Ion loodIIion = {"lood(II)ion", "Pb", "2+"};
    Chemistry::Ion loodIVion = {"lood(IV)ion", "Pb", "4+"};
    Chemistry::Ion magnesiumion = {"magnesiumion", "Mg", "2+"};
    Chemistry::Ion mangaanIIion = {"mangaan(II)ion", "Mn", "2+"};
    Chemistry::Ion mangaanIVion = {"mangaan(IV)ion", "Mn", "4+"};
    Chemistry::Ion natriumion = {"natriumion", "Na", "+"};
    Chemistry::Ion tinIIion = {"tin(II)ion", "Sn", "2+"};
    Chemistry::Ion tinIVion = {"tin(IV)ion", "Sn", "4+"};
    Chemistry::Ion uraanIIIion = {"uraan(III)ion", "U", "3+"};
    Chemistry::Ion uraanVIion = {"uraan(VI)ion", "U", "6+"};
    Chemistry::Ion zilverion = {"zilverion", "Ag", "+"};
    Chemistry::Ion zinkion = {"zinkion", "Zn", "2+"};

    // Samengesteld Negatief
    Chemistry::Ion acetaation = {"acetaation", "CH3COO", "-"};
    Chemistry::Ion carbonaation = {"carbonaation", "CO3", "2-"};
    Chemistry::Ion fosfaation = {"fosfaation", "PO4", "3-"};
    Chemistry::Ion hydroxideion = {"hydroxide-ion", "OH", "-"};
    Chemistry::Ion nitraation = {"nitraation", "NO3", "-"};
    Chemistry::Ion nitrietion = {"nitrietion", "NO2", "-"};
    Chemistry::Ion sulfaation = {"sulfaation", "SO4", "2-"};
    Chemistry::Ion sulfietion = {"sulfietion", "SO3", "2-"};
    Chemistry::Ion waterstofcarbonaation = {"waterstofcarbonaation", "HCO3", "-"};

    // Samengesteld Postief
    Chemistry::Ion ammoniumion = {"ammoniumion", "NH4", "+"};

    std::vector<Chemistry::Ion> Ions = {
        fluorideion, chlorideion, bromideion, jodideion, oxideion, sulfideion,
        
        aliminiumion, bariumion, calciumion, goudIion, goudIIIion, ijzerIIion, 
        ijzerIIIion, kaliumion, koperion, kwikIion, kwikIIion, lithiumion, 
        loodIIion, loodIVion, magnesiumion, mangaanIIion, mangaanIVion, natriumion,
        tinIIion, tinIVion, uraanIIIion, uraanVIion, zilverion, zinkion,

        acetaation, carbonaation, fosfaation, hydroxideion, nitraation, nitrietion,
        sulfaation, sulfietion, waterstofcarbonaation,

        ammoniumion,
    };
}

namespace Chemistry {
    Ion GetRandomIon() {
        srand(time(0));
        int index = rand() % Ionen::Ions.size();
        return Ionen::Ions[index];
    }

    bool operator == (Ion A, Ion B) {
        if (A.Naam != B.Naam) {
            return false;
        }

        if (A.Formule != B.Formule) {
            return false;
        }

        if (A.Lading != B.Lading) {
            return false;
        }

        return true;
    };
}
