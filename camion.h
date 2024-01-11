#include <string>
#include "vehicul.h"

using namespace std;

#ifndef POO_CAMION_H
#define POO_CAMION_H

class Camion : public Vehicul {
private:
    float gabarit;
public:
    
    Camion();
    
    Camion(const string &marca, const string &model, const string &culoare, const string &combustibil, float cc,
           float pret, int an, float gabarit);
    
    Camion(const Vehicul &other, float gabarit);
    
    ~ Camion();
    
    Camion &operator=(const Camion &other);
    
    friend ostream &operator<<(ostream &out, const Camion &Camion);
    
    friend istream &operator>>(istream &in, Camion &Camion);
    
    const string &getMarca() const override;
    
    const string &getModel() const override;
    
    float calculCostTotal() const override;
};

#endif
