#include <bits/stdc++.h>
#include "meniu.h"
using namespace std;
int main() {
    Meniu* meniu = Meniu::GetInstance();
    meniu->Run();
    Meniu::DestroyInstance();
    return 0;
}