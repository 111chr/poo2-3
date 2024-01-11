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

//template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
//void AdaugaMasina( vector<Masina *> &stocMasini, const T1 &marca, const T2 &model, const T3 &culoare,
//                  const T4 &combustibil, const T5 &cc, const T6 &pret, const T7 &an, const T8 &tip) {
//    try {
//        Masina *masinaNoua = new Masina(marca, model, culoare, combustibil, cc, pret, an, tip);
//        stocMasini.push_back(masinaNoua);
//         cout << "Masina a fost adaugata in stocMasini.\n";
//    } catch (const ExceptieMotorizareInvalida &ex) {
//         cerr << "Eroare: " << ex.what() <<  endl;
//    } catch (const ExceptieKwInvalid &ex) {
//         cerr << "Eroare: " << ex.what() <<  endl;
//    } catch (const  exception &ex) {
//         cerr << "Eroare necunoscuta: " << ex.what() <<  endl;
//    }
//}

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


#endif
