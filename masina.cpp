#include "masina.h"
#include "exceptii.h"

Masina::Masina() : Vehicul(), tip("") {}

Masina::Masina(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
               float pret, int an, const string &tip) : Vehicul(marca, model, culoare, combustibil, cc, pret, an),
                                                        tip(tip) {
    if (combustibil != "Motorina" && combustibil != "Benzina") {
        throw ExceptieMotorizareInvalida("Combustibil invalid. Va rog introduceti Motorina/Benzina.");
    }
}

Masina::~Masina() {
    if (!tip.empty()) tip.clear();
}

Masina::Masina(const Masina &other) : Vehicul(other), tip(other.tip) {}

Masina &Masina::operator=(const Masina &other) {
    if (this != &other) {
        Vehicul::operator=(other);
        tip = other.tip;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Masina &masina) {
    out << static_cast<const Vehicul &>(masina);
    out << "Tip masina: " << masina.tip << "\n";
    return out;
}

istream &operator>>(istream &in, Masina &masina) {
    in >> static_cast<Vehicul &>(masina);
    cout << "Introduceti tipul masinii: ";
    in >> masina.tip;
    return in;
}


const string &Masina::getMarca() const {
    return marca;
}

const string &Masina::getModel() const {
    return model;
}

const float &Masina::getPret() const {
    return pret;
}

float Masina::calculCostTotal() const {
    float tva = pret * 0.19; // presupunem tva 19%
    float pretCuTVA = pret + tva;
    return pretCuTVA;
}