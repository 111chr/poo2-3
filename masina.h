#include <string>
#include "vehicul.h"

using namespace std;

#ifndef POO_MASINA_H
#define POO_MASINA_H

class Masina : public Vehicul {
protected:
    string tip; //decapotabila sau sedane
public:
    
    Masina();
    
    Masina(const Vehicul &other, const string &tip);
    
    Masina(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
           float pret, int an, const string &tip);
    
    ~Masina();
    
    Masina(const Masina &other);
    
    Masina &operator=(const Masina &other);
    
    friend ostream &operator<<(ostream &out, const Masina &masina);
    
    friend istream &operator>>(istream &in, Masina &masina);
    
    const string &getMarca() const override;
    
    const string &getModel() const override;
    
    const float &getPret() const override;
    
    float calculCostTotal() const override;
};


#endif
