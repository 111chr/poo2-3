#include <exception>
#include <string>

using namespace std;

#ifndef POO_EXCEPTII_H
#define POO_EXCEPTII_H

class ExceptieMotorizareInvalida : public exception {
private:
    string message_;
public:
    ExceptieMotorizareInvalida(const string &message);
    const char *what() const noexcept override;
};

class ExceptieKwInvalid : public exception {
private:
    string message_;
public:
    ExceptieKwInvalid(const string &message);
    const char *what() const noexcept override;
};

#endif
