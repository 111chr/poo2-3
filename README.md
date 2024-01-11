# Sistem de Management al Vehiculelor dintr-o Reprezentanta Auto

Acest proiect este dezvoltat pentru gestionarea unui inventar de vehicule dintr-o reprezentanta auto. El include diferite tipuri de vehicule, cum ar fi mașini, motociclete și camioane, fiecare cu propriile caracteristici și atribute specifice.

# Structura proiectului

1. Clase de Vehicule:

Vehicul: Clasa de bază care definește atributele comune tuturor vehiculelor, cum ar fi marca, modelul, culoarea, tipul de combustibil, capacitatea cilindrică, prețul și anul fabricației.
Masina: Subclasă a Vehicul, care adaugă atribute și funcționalități specifice mașinilor.
Moto: Subclasă a Vehicul, destinată motocicletelor, cu atribute și funcționalități specifice.
Camioane: Subclasă a Vehicul, destinată camioanelor, cu atribute și funcționalități specifice.

2. Meniu și Interacțiunea cu Utilizatorul:

Meniu: Clasa care gestionează interfața cu utilizatorul, permițându-le să interacționeze cu sistemul prin diferite opțiuni.
Include funcționalități pentru afișarea instrucțiunilor, gestionarea stocului de vehicule și realizarea diferitelor operațiuni legate de vehicule.

3. Template-uri și Excepții:

templates.h: Conține funcții template.
Implementare de excepții personalizate pentru a gestiona cazuri specifice de eroare.

 # Cerinte
-- Tema 2
-Separarea codului din clase în .h (sau .hpp) și .cpp

-Minim o clasă de bază și 3 clase derivate (cu bază proprie, cele cu bază predifinită pot fi în plus)

-Minim o funcție virtuală va fi specifică temei (e.g. nu simple citiri/afișări)

-Minim un exemplu de polimorfism

-Apelarea constructorului clasei de bază din constructori ai clasei derivate

-Smart pointers

-Conversii de tipuri pentru pointeri către clase

-Suprascris metode (e.g. operatorul= pentru copieri/atribuiri corecte)

-Excepții (clase derivate din std::exception; minim 2 clase pentru erori specifice)

-Utilizare cu sens: de exemplu, throw în constructor, try/catch în main

-Funcții și atribute static

-Cât mai multe const

-Utilizare STL

-- Tema 3
-Minim 2 șabloane de proiectare (design patterns)

-Minim o clasă template cu sens; minim 2 instanțieri

-Minim o funcție template cu sens; minim 2 instanțieri

-De preferat și un exemplu template specialization (dacă are sens)
