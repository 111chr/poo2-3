#include "exceptii.h"

ExceptieKwInvalid::ExceptieKwInvalid(const string &message) : message_(message) {}

const char *ExceptieKwInvalid::what() const noexcept {
    return message_.c_str();
}

ExceptieMotorizareInvalida::ExceptieMotorizareInvalida(const string &message) : message_(message) {}

const char *ExceptieMotorizareInvalida::what() const noexcept {
    return message_.c_str();
}
