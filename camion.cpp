#include "camion.h"

Camion::Camion() : Vehicul(), gabarit(0.0) {}

Camion::Camion(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
               float pret, int an, float gabarit) : Vehicul(marca, model, culoare, combustibil, cc, pret, an),
                                                    gabarit(gabarit) {}

Camion::Camion(const Vehicul &other, float gabarit) : Vehicul(other), gabarit(gabarit) {}

Camion::~ Camion() {}

Camion &Camion::operator=(const Camion &other) {
    if (this != &other) {
        Vehicul::operator=(other);
        gabarit = other.gabarit;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Camion &Camion) {
    out << static_cast<const Vehicul &>( Camion);
    out << "Gabarit camion: " << Camion.gabarit << "\n";
    return out;
}

istream &operator>>(istream &in, Camion &Camion) {
    in >> static_cast<Vehicul &>( Camion);
    cout << "Introduceti gabaritul camionului: ";
    in >> Camion.gabarit;
    return in;
}
const string &Camion::getMarca() const {
    return marca;
}

const string &Camion::getModel() const {
    return model;
}
float Camion::calculCostTotal() const {
    float tva = pret * 0.35; // presupunem tva 35%
    float pretCuTVA = pret + tva;
    return pretCuTVA;
}