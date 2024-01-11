#include <bits/stdc++.h>
#include "meniu.h"
#include "vehicul.h"
#include "masina.h"
#include "moto.h"
#include "camion.h"
#include "templates.h"

using namespace std;

int main() {
    GestiuneVehicule<Masina> gestiuneMasini;
    gestiuneMasini.AdaugaVehicul(make_shared<Masina>("Audi", "A4", "Negru", "Benzina", 1.9, 2000.2, 2006, "Sedan"));
    gestiuneMasini.AdaugaVehicul(make_shared<Masina>("BMW", "X5", "Alb", "Motorina", 3.0, 5000.50, 2020, "Decapotabila"));
    gestiuneMasini.AdaugaVehicul(make_shared<Masina>("Ford", "Focus", "Verde", "Benzina", 1.6, 10500.10, 2019, "Sedan"));
    gestiuneMasini.AdaugaVehicul(make_shared<Masina>("Audi", "A3", "Negru", "Benzina", 1.9, 2000.40, 2006, "Decapotabila"));
    
    GestiuneVehicule<Moto> gestiuneMoto;
    gestiuneMoto.AdaugaVehicul(make_shared<Moto>("Honda", "Ninja", "Rosie", "Benzina", 252, 4580.2, 2021, 95.5));
    gestiuneMoto.AdaugaVehicul(make_shared<Moto>("Kawasaki", "Y300", "Verde", "Benzina", 500, 40052.28, 2020, 39.0));
    gestiuneMoto.AdaugaVehicul(make_shared<Moto>("Yamaha", "YZF-R1", "Albastru", "Benzina", 1000, 10045.2, 2022, 197.2));
    gestiuneMoto.AdaugaVehicul(make_shared<Moto>("Suzuki", "GSX-R750", "Albastru", "Motorina", 750, 8000.9, 2023, 90.0));
    gestiuneMoto.AdaugaVehicul(make_shared<Moto>("Honda", "Ninja", "Rosie", "Motorina", 252, 6253.8, 2021, 95.5));
    
    GestiuneVehicule<Camion> gestiuneCamioane;
    gestiuneCamioane.AdaugaVehicul(make_shared<Camion>("Volvo", "FH16", "Alb", "Motorina", 16.1, 12377.1, 2021, 600));
    gestiuneCamioane.AdaugaVehicul(make_shared<Camion>("Scania", "R 450", "Rosu", "Benzina", 12.7, 70050.8, 2020, 4500));
    gestiuneCamioane.AdaugaVehicul(make_shared<Camion>("MAN", "TGX", "Gri", "Motorina", 13.0, 65257.21, 2022, 510));
    gestiuneCamioane.AdaugaVehicul(make_shared<Camion>("Volvo", "FH14", "Negru", "Benzina", 16.1, 82863.0, 2021, 600));
    

    cout << "----------------------------\n";
    cout << "Masini in gestiune:" << endl;
    gestiuneMasini.AfiseazaVehicule();
    cout << "----------------------------\n";
    cout << "Moto in gestiune:" << endl;
    gestiuneMoto.AfiseazaVehicule();
    cout << "----------------------------\n";
    cout << "Camioane in gestiune:" << endl;
    gestiuneCamioane.AfiseazaVehicule();
    cout << "----------------------------\n";
    
    Meniu *meniu = Meniu::GetInstance();
    meniu->Run();
    Meniu::DestroyInstance();
    
    return 0;
}