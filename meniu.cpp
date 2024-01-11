#include "meniu.h"
#include "templates.h"

Meniu::Meniu() {
    stocMasini.push_back(make_shared<Masina>("Audi", "A4", "Negru", "Benzina", 1.9, 2000.2, 2006, "Sedan"));
    stocMasini.push_back(make_shared<Masina>("BMW", "X5", "Alb", "Motorina", 3.0, 5000.50, 2020, "Decapotabila"));
    stocMasini.push_back(make_shared<Masina>("Ford", "Focus", "Verde", "Benzina", 1.6, 10500.10, 2019, "Sedan"));
    stocMasini.push_back(make_shared<Masina>("Audi", "A3", "Negru", "Benzina", 1.9, 2000.40, 2006, "Decapotabila"));
    
    stocMoto.push_back(make_shared<Moto>("Honda", "Ninja", "Rosie", "Benzina", 252, 3550.2, 2021, 95.5));
    stocMoto.push_back(make_shared<Moto>("Kawasaki", "Y300", "Verde", "Benzina", 500, 40052.28, 2020, 39.0));
    stocMoto.push_back(make_shared<Moto>("Yamaha", "YZF-R1", "Albastru", "Benzina", 1000, 10045.2, 2022, 197.2));
    stocMoto.push_back(make_shared<Moto>("Suzuki", "GSX-R750", "Albastru", "Motorina", 750, 8000.9, 2023, 90.0));
    stocMoto.push_back(make_shared<Moto>("Honda", "Ninja", "Rosie", "Motorina", 252, 6253.8, 2021, 95.5));

    stocCamioane.push_back(make_shared<Camion>("Volvo", "FH16", "Alb", "Motorina", 16.1, 12377.1, 2021, 600));
    stocCamioane.push_back(make_shared<Camion>("Scania", "R 450", "Rosu", "Benzina", 12.7, 70050.8, 2020, 4500));
    stocCamioane.push_back(make_shared<Camion>("MAN", "TGX", "Gri", "Motorina", 13.0, 65257.21, 2022, 510));
    stocCamioane.push_back(make_shared<Camion>("Volvo", "FH14", "Negru", "Benzina", 16.1, 82863.0, 2021, 600));
}

Meniu::~Meniu() = default;