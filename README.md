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
