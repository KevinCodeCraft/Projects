#ifndef CHEMISTRY_UTILS_H
#define CHEMISTRY_UTILS_H

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>
#include <limits>

namespace Chemistry {
    struct Ion {
        std::string Naam;
        std::string Formule;
        std::string Lading;
    };

    Ion GetRandomIon();

    bool operator == (Ion A, Ion B);
}

namespace Ionen {
    // Negatief
    extern Chemistry::Ion fluorideion;
    extern Chemistry::Ion chlorideion;
    extern Chemistry::Ion bromideion;
    extern Chemistry::Ion jodideion;
    extern Chemistry::Ion oxideion;
    extern Chemistry::Ion sulfideion;

    // Positief
    extern Chemistry::Ion aliminiumion;
    extern Chemistry::Ion bariumion;
    extern Chemistry::Ion calciumion;
    extern Chemistry::Ion goudIion;
    extern Chemistry::Ion goudIIIion;
    extern Chemistry::Ion ijzerIIion;
    extern Chemistry::Ion ijzerIIIion;
    extern Chemistry::Ion kaliumion;
    extern Chemistry::Ion koperion;
    extern Chemistry::Ion kwikIion;
    extern Chemistry::Ion kwikIIion;
    extern Chemistry::Ion lithiumion;
    extern Chemistry::Ion loodIIion;
    extern Chemistry::Ion loodIVion;
    extern Chemistry::Ion magnesiumion;
    extern Chemistry::Ion mangaanIIion;
    extern Chemistry::Ion mangaanIVion;
    extern Chemistry::Ion natriumion;
    extern Chemistry::Ion tinIIion;
    extern Chemistry::Ion tinIVion;
    extern Chemistry::Ion uraanIIIion;
    extern Chemistry::Ion uraanVIion;
    extern Chemistry::Ion zilverion;
    extern Chemistry::Ion zinkion;

    // Samengesteld Negatief
    extern Chemistry::Ion acetaation;
    extern Chemistry::Ion carbonaation;
    extern Chemistry::Ion fosfaation;
    extern Chemistry::Ion hydroxideion;
    extern Chemistry::Ion nitraation;
    extern Chemistry::Ion nitrietion;
    extern Chemistry::Ion sulfaation;
    extern Chemistry::Ion sulfietion;
    extern Chemistry::Ion waterstofcarbonaation;

    // Samengesteld Postief
    extern Chemistry::Ion ammoniumion;

    // Array of ions
    extern std::vector<Chemistry::Ion> Ions;
}

#endif