#include <bits/stdc++.h>
#include "templates.h"
#include "vehicul.h"
#include "masina.h"
#include "moto.h"
#include "camion.h"
#include "exceptii.h"

using namespace std;

#ifndef POO_MENIU_H
#define POO_MENIU_H

class Meniu {
private:
    vector<shared_ptr<Masina>> stocMasini;
    vector<shared_ptr<Moto>> stocMoto;
    vector<shared_ptr<Camion>> stocCamioane;
public:
    Meniu();
    
    ~Meniu();
    
    void Instructiuni() {
        cout << "Instructiuni de utilizare\n\n";
        cout << "1 -> Adauga vehicul in stoc\n";
        cout << "2 -> Vizualizeaza stocul vehiculelor\n";
        cout << "3 -> Cauta vehicul dupa marca\n";
        cout << "4 -> Calculeaza TVA-ul pentru anumite vehicule.\n";
        cout << "5 -> Cauta dupa pret.\n";
        cout << "0 -> Iesi din program\n\n";
    }
    
    void AdaugaMasina() {
        int x;
        cout << "\t -> Ce tip de vehicul adaugi? (Masina - 1, Motor - 2, Camion - 3)\n";
        cin >> x;
        
        try {
            if (x == 1) {
                auto masinaNoua = make_shared<Masina>();
                cin >> *masinaNoua;
                stocMasini.push_back(masinaNoua);
                cout << "Masina a fost adaugata in stocMasini.\n";
            } else if (x == 2) {
                auto motoNou = make_shared<Moto>();
                cin >> *motoNou;
                stocMoto.push_back(motoNou);
                cout << "Motorul a fost adaugat in stocMoto.\n";
            } else if (x == 3) {
                auto camionNou = make_shared<Camion>();
                cin >> *camionNou;
                stocCamioane.push_back(camionNou);
                cout << "Camionul a fost adaugat in stocCamioane.\n";
            } else {
                cout << "Introduceti o valoare valida.\n";
            }
        } catch (const ExceptieMotorizareInvalida &ex) {
            cerr << "Eroare: " << ex.what() << endl;
        } catch (const ExceptieKwInvalid &ex) {
            cerr << "Eroare: " << ex.what() << endl;
        } catch (const exception &ex) {
            cerr << "Eroare necunoscuta: " << ex.what() << endl;
        }
    }
    
    void VizualizeazaStoc() {
        int x;
        cout << "\t -> Vehiculul este.. Masina - 1 / Motor - 2 / Camion - 3\n";
        cin >> x;
        if (x == 1) {
            cout << "Numarul de masini in stoc: " << stocMasini.size() << "\n";
        }
        if (x == 2) {
            cout << "Numarul de motoare in stoc: " << stocMoto.size() << "\n";
        }
        if (x == 3) {
            cout << "Numarul de camioane in stoc: " << stocCamioane.size() << "\n";
        }
    }
    
    void CautaDupaMarca() {
        cout << "Introduceti marca vehiculului pentru cautare: ";
        string marcaCautata;
        cin >> marcaCautata;
        int x;
        cout << "\t -> Vehiculul este o .. Masina - 1 / Motor - 2 / Camion - 3\n";
        cin >> x;
        if (x == 1) {
            bool gasit = false;
            for (const auto &iterator: stocMasini) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Masina cu marca " << marcaCautata << " a fost gasita:\n";
                    cout << *iterator << endl;
                    gasit = true;
                }
            }
            if (!gasit) {
                cout << "Nu am gasit nicio masina cu marca " << marcaCautata << ".\n";
            }
        }
        if (x == 2) {
            bool gasit = false;
            for (const auto &iterator: stocMoto) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Masina cu marca " << marcaCautata << " a fost gasita:\n";
                    cout << *iterator << endl;
                    gasit = true;
                }
            }
            if (!gasit) {
                cout << "Nu am gasit nicio masina cu marca " << marcaCautata << ".\n";
            }
            
        }
        if (x == 3) {
            bool gasit = false;
            for (const auto &iterator: stocCamioane) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Masina cu marca " << marcaCautata << " a fost gasita:\n";
                    cout << *iterator << endl;
                    gasit = true;
                }
            }
            if (!gasit) {
                cout << "Nu am gasit nicio masina cu marca " << marcaCautata << ".\n";
            }
            
        }
    }
    
    void CalculeazaTva() {
        cout << "Introduceti marca vehiculului pentru cautare: ";
        string marcaCautata;
        cin >> marcaCautata;
        
        int x;
        cout << "\t -> Vehiculul este o .. Masina - 1 / Motor - 2 / Camion - 3\n";
        cin >> x;
        
        bool gasit = false;
        vector<string> modeleGasite;
        
        if (x == 1) {
            for (const auto &iterator: stocMasini) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Masina cu marca " << marcaCautata << " a fost gasita:\n";
                    cout << *iterator << endl;
                    gasit = true;
                    modeleGasite.push_back(iterator->getModel());
                }
            }
        } else if (x == 2) {
            for (const auto &iterator: stocMoto) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Motor cu marca " << marcaCautata << " a fost gasit:\n";
                    cout << *iterator << endl;
                    gasit = true;
                    modeleGasite.push_back(iterator->getModel());
                }
            }
        } else if (x == 3) {
            for (const auto &iterator: stocCamioane) {
                if (iterator->getMarca() == marcaCautata) {
                    cout << "Camion cu marca " << marcaCautata << " a fost gasit:\n";
                    cout << *iterator << endl;
                    gasit = true;
                    modeleGasite.push_back(iterator->getModel());
                }
            }
        } else {
            cout << "Optiune invalida. Va rugam sa introduceti 1, 2 sau 3.\n";
        }
        
        if (gasit) {
            if (!modeleGasite.empty()) {
                cout << "Modele gasite pentru " << marcaCautata << ":\n";
                for (const auto &model: modeleGasite) {
                    cout << "Pret cu TVA pentru modelul " << model << ": ";
                    
                    for (const auto &masina: stocMasini) {
                        if (masina->getMarca() == marcaCautata && masina->getModel() == model) {
                            float pretCuTVA = masina->calculCostTotal();
                            cout << pretCuTVA << endl;
                            break;
                        }
                    }
                    
                    for (const auto &moto: stocMoto) {
                        if (moto->getMarca() == marcaCautata && moto->getModel() == model) {
                            float pretCuTVA = moto->calculCostTotal();
                            cout << pretCuTVA << endl;
                            break;
                        }
                    }
                    
                    for (const auto &camion: stocCamioane) {
                        if (camion->getMarca() == marcaCautata && camion->getModel() == model) {
                            float pretCuTVA = camion->calculCostTotal();
                            cout << pretCuTVA << endl;
                            break;
                        }
                    }
                }
            } else {
                cout << "Nu am gasit nicio masina/motor/camion cu marca " << marcaCautata << ".\n";
            }
        }
        
    }
    
    void CautaPret() {
        float pretMax;
        cout << "Adauga pretul maxim: ";
        cin >> pretMax;
        
        int x;
        cout << "\t -> Categoria.. Masina - 1 / Motor - 2 / Camion - 3\n";
        cin >> x;
        
        if (x == 1) {
            auto CautaPretMasini = filterCarsByPrice(stocMasini, pretMax);
            
            if (CautaPretMasini.empty()) {
                cout << "Nu exista masini sub pretul " << pretMax << endl;
            } else {
                cout << "Masini gasite sub pretul de " << pretMax << ":" << endl;
                for (auto car: CautaPretMasini) {
                    cout << "Marca: " << car->getMarca()
                         << ", Model: " << car->getModel()
                         << ", Pret: " << car->getPret() << endl;
                }
            }
        } else if (x == 2) {
            auto CautaPretMoto = filterMotoByPrice(stocMoto, pretMax);
            
            if (CautaPretMoto.empty()) {
                cout << "Nu exista motoare sub pretul " << pretMax << endl;
            } else {
                cout << "Motoare gasite sub pretul de " << pretMax << ":" << endl;
                for (auto car: CautaPretMoto) {
                    cout << "Marca: " << car->getMarca()
                         << ", Model: " << car->getModel()
                         << ", Pret: " << car->getPret() << endl;
                }
            }
        } else if (x == 3) {
            auto CautaPretCamion = filterCamionByPrice(stocCamioane, pretMax);
            
            if (CautaPretCamion.empty()) {
                cout << "Nu exista camioane sub pretul " << pretMax << endl;
            } else {
                cout << "Camioane gasite sub pretul de " << pretMax << ":" << endl;
                for (auto car: CautaPretCamion) {
                    cout << "Marca: " << car->getMarca()
                         << ", Model: " << car->getModel()
                         << ", Pret: " << car->getPret() << endl;
                }
            }
        }
    }
    
    
    void Run() {
        Instructiuni();
        int optiune;
        bool exitapp = false;
        
        while (!exitapp) {
            cout << "Introduceti optiune: ";
            if (!(cin >> optiune)) {
                cout << "Introduceti o optiune valida!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            switch (optiune) {
                case 1: {
                    AdaugaMasina(); //done
                    break;
                }
                case 2: {
                    VizualizeazaStoc(); //done
                    break;
                }
                case 3: {
                    CautaDupaMarca(); //done
                    break;
                }
                case 4: {
                    CalculeazaTva(); //done
                    break;
                }
                case 5: {
                    CautaPret(); //done
                    break;
                }
                case 0: {
                    exitapp = true;
                    break;
                }
                default: {
                    cout << "optiune invalida. Incercati din nou.\n";
                    break;
                }
            }
        }
    }
};

#endif //POO_3_MENIU_H
