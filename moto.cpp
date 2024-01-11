#include "moto.h"
#include "exceptii.h"

Moto::Moto() : Vehicul(), kw(0.0) {}

Moto::Moto(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
           float pret, int an, float kw) : Vehicul(marca, model, culoare, combustibil, cc, pret, an), kw(kw) {
    if (kw > 2000) {
        throw ExceptieKwInvalid("Kw nu poate fi peste 2000.");
    }
}

Moto::~ Moto() {}

Moto::Moto(const Vehicul &other, float kw) : Vehicul(other), kw(kw) {}

Moto &Moto::operator=(const Moto &other) {
    if (this != &other) {
        Vehicul::operator=(other);
        kw = other.kw;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Moto &Moto) {
    out << static_cast<const Vehicul &>( Moto);
    out << "Kw Motocicleta: " << Moto.kw << "\n";
    return out;
}

istream &operator>>(istream &in, Moto &Moto) {
    in >> static_cast<Vehicul &>( Moto);
    cout << "Introduceti kw-ul motocicletei: ";
    in >> Moto.kw;
    return in;
}

const string &Moto::getMarca() const {
    return marca;
}

const string &Moto::getModel() const {
    return model;
}
float Moto::calculCostTotal() const {
    float tva = pret * 0.24; // presupunem tva 24%
    float pretCuTVA = pret + tva;
    return pretCuTVA;
}