#include "vehicul.h"

Vehicul::Vehicul() : marca(""), model(""), culoare(""), combustibil(""), cc(0.0), pret(0.0), an(0) {}

Vehicul::Vehicul(const string &marca, const string &model, const string &culoare,
                 const string &combustibil, float cc, float pret, int an)
        : marca(marca), model(model), culoare(culoare), combustibil(combustibil), cc(cc), pret(pret), an(an) {}

Vehicul::~Vehicul() {
    if (!marca.empty()) marca.clear();
    if (!model.empty()) model.clear();
    if (!culoare.empty()) culoare.clear();
    if (!combustibil.empty()) combustibil.clear();
}

Vehicul::Vehicul(const Vehicul &other)
        : marca(other.marca), model(other.model), culoare(other.culoare),
          combustibil(other.combustibil), cc(other.cc), pret(other.pret), an(other.an) {}

Vehicul &Vehicul::operator=(const Vehicul &other) {
    if (this != &other) {
        marca = other.marca;
        model = other.model;
        culoare = other.culoare;
        combustibil = other.combustibil;
        cc = other.cc;
        an = other.an;
        pret = other.pret;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Vehicul &vehicul) {
    out << "Marca: " << vehicul.marca << "\n";
    out << "Model: " << vehicul.model << "\n";
    out << "Culoare: " << vehicul.culoare << "\n";
    out << "Combustibil: " << vehicul.combustibil << "\n";
    out << "CC: " << vehicul.cc << "\n";
    out << "An: " << vehicul.an << "\n";
    out << "Pret: " << vehicul.pret << "\n";
    return out;
}

istream &operator>>(istream &in, Vehicul &vehicul) {
    cout << "Introduceti marca: ";
    in >> vehicul.marca;
    cout << "Introduceti modelul: ";
    in >> vehicul.model;
    cout << "Introduceti culoarea: ";
    in >> vehicul.culoare;
    cout << "Introduceti combustibilul: ";
    in >> vehicul.combustibil;
    cout << "Introduceti capacitatea cilindrica: ";
    in >> vehicul.cc;
    cout << "Introduceti anul: ";
    in >> vehicul.an;
    cout << "Introduceti pretul: ";
    in >> vehicul.pret;
    return in;
}

const string &Vehicul::getMarca() const {
    return marca;
}

const string &Vehicul::getModel() const {
    return model;
}

const float &Vehicul::getPret() const {
    return pret;
}

float Vehicul::calculCostTotal() const {
    float pretCuTVA = pret * 1.19;
    return pretCuTVA;
}