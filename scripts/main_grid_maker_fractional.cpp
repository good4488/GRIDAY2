#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "../Griday.hpp"

int
main(int argc, char* argv[])
try {
    using namespace std;

    if (argc < 5)
        {
        cerr << "./grid_maker_fractional nA nB nC atom_type "
                "force_field input_cssr egrid_stem"
             << endl;
        return 1;
        }

    GIndex maxNx = static_cast<GIndex>(stoi(argv[1]));
    GIndex maxNy = static_cast<GIndex>(stoi(argv[2]));
    GIndex maxNz = static_cast<GIndex>(stoi(argv[3]));
    //GReal  spacing = static_cast<GReal>(stof(argv[1]));
    string atomTypeName {argv[2]};
    string forceFieldName {argv[3]};
    string cssrName {argv[4]};
    string outputStem {argv[5]};

    cout << setw(80) << setfill('=') << "" << setfill(' ') << endl;
    cout << "GRIDAY STARTS" << endl;
    cout << setw(80) << setfill('=') << "" << setfill(' ') << endl;
    cout << endl;

    AtomTypeMap typeMap;
    typeMap.read(atomTypeName);

    cout << "1. Atom type information" << endl;
    typeMap.print();
    cout << endl;

    ForceField forceField {typeMap};
    forceField.read(forceFieldName);

    cout << "2. Force Feild Information" << endl;
    forceField.print();
    cout << endl;

    Framework framework {typeMap};

    cout << "3. Generating Energy Grid" << endl;
    GridMaker maker {typeMap, framework, forceField};

    framework.read(cssrName);
    framework.print();
    cout << endl;

    maker.setFramework(framework);
    //maker.make("CH4", spacing, outputStem);
	maker.make("CH4", maxNx, maxNy, maxNz, outputStem);

    return 0;
    }
catch (GridayException& e)
    {
    std::cerr << e.what() << std::endl;
    }
catch (std::exception& e)
    {
    std::cerr << e.what() << std::endl;
    }
