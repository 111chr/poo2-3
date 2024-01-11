#include <bits/stdc++.h>
#include <memory>
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
protected:
    Meniu() {
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
    
    vector<shared_ptr<Masina>> stocMasini;
    vector<shared_ptr<Moto>> stocMoto;
    vector<shared_ptr<Camion>> stocCamioane;
    
    Meniu(const Meniu &) = delete;
    
    Meniu &operator=(const Meniu &) = delete;
    
    static Meniu *instance;
public:
    
    static Meniu *GetInstance() {
        if (instance == nullptr) {
            instance = new Meniu();
        }
        return instance;
    }
    
    static void DestroyInstance() {
        delete instance;
        instance = nullptr;
    }
    
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
            
            while (!(cin >> optiune)) {
                cout << "Introduceti o optiune valida (un numar)!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora caracterele ramase in buffer
                cout << "Introduceti optiune: ";
            }
            
            switch (optiune) {
                case 1:
                    AdaugaMasina();
                    break;
                case 2:
                    VizualizeazaStoc();
                    break;
                case 3:
                    CautaDupaMarca();
                    break;
                case 4:
                    CalculeazaTva();
                    break;
                case 5:
                    CautaPret();
                    break;
                case 0:
                    exitapp = true;
                    break;
                default:
                    cout << "Optiune invalida. Incercati din nou.\n";
                    break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};


#endif