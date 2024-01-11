#include <typeinfo>
#include <iostream>
#include <set>
#include <cstring>
#include "masina.h"
#include "vehicul.h"
#include "moto.h"
#include "camion.h"
#include "exceptii.h"

using namespace std;

#ifndef POO_TEMPLATES_H
#define POO_TEMPLATES_H

template<typename T>
vector<shared_ptr<Masina>> filterCarsByPrice(const vector<shared_ptr<Masina>> &cars, T maxPrice) {
    vector<shared_ptr<Masina>> auxMasini;
    for (const auto &car: cars) {
        if (car && car->getPret() < maxPrice) {
            auxMasini.push_back(car);
        }
    }
    return auxMasini;
}

template<typename T>
vector<shared_ptr<Moto>> filterMotoByPrice(const vector<shared_ptr<Moto>> &cars, T maxPrice) {
    vector<shared_ptr<Moto>> auxMoto;
    for (const auto &car: cars) {
        if (car && car->getPret() < maxPrice) {
            auxMoto.push_back(car);
        }
    }
    return auxMoto;
}

template<typename T>
vector<shared_ptr<Camion>> filterCamionByPrice(const vector<shared_ptr<Camion>> &cars, T maxPrice) {
    vector<shared_ptr<Camion>> auxCamion;
    for (const auto &car: cars) {
        if (car && car->getPret() < maxPrice) {
            auxCamion.push_back(car);
        }
    }
    return auxCamion;
}

template<typename T>
class GestiuneVehicule {
private:
    std::vector<std::shared_ptr<T>> vehicule;
public:
    void AdaugaVehicul(std::shared_ptr<T> vehicul) {
        vehicule.push_back(vehicul);
    }
    
    void AfiseazaVehicule() const {
        for (const auto &vehicul: vehicule) {
            vehicul->AfiseazaDetalii();
            cout << "--------------------\n";
        }
    }
};

#endif
