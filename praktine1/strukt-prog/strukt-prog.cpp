#include <iostream>
#include <string>
#include <iomanip>

// 2025 09 24 Praktine uzduotis

int main() {
    // pirkti valiuta 
    float eur_kaina = 1.f;
    float gbp_pirkti = 0.8600f;
    float usd_pirkti = 1.1460f;
    float inr_pirkti = 101.3862f;

    // palyginti valiuta
    float gbp_bendras = 0.8729f;
    float usd_bendras = 1.1793f;
    float inr_bendras = 104.6918f;

    // parduoti valiuta (is valiutos i eurus)
    float gbp_parduoti = 0.9220f;
    float usd_parduoti = 1.2340f;
    float inr_parduoti = 107.8546f;

    int pasirinkimas;

    std::string valiuta;
    float kiekis, rez;

    std::cout << "Pagrindine valiuta: Eur\n";

    std::cout << "1. Valiutos kurso palyginimas su kita valiuta.\n2. Galimybe isigyti valiutos.\n3. Galimybe parduoti valiuta.\n Pasirinkimas: ";
    std::cin >> pasirinkimas;

    // valiutos pasirinkimas
    std::cout << "Pasirinkite valiuta (EUR, GBP, USD, INR): ";
    std::cin >> valiuta;

    switch (pasirinkimas) {
    case 1:
        if (valiuta == "EUR" || valiuta == "eur") {
            rez = eur_kaina;
        }
        else if (valiuta == "GBP" || valiuta == "gbp") {
            rez = gbp_bendras;
        }
        else if (valiuta == "USD" || valiuta == "usd") {
            rez = usd_bendras;
        }
        else if (valiuta == "INR" || valiuta == "inr") {
            rez = inr_bendras;
        }
        else {
            std::cout << "Valiuta nerasta.\n";
            return 0;
        }
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "1 Eur: " << rez << " " << valiuta << std::endl;
        break;
    case 2:
        std::cout << "Iveskite kiek Eur norite issikeisti: ";
        std::cin >> kiekis;

        if (valiuta == "GBP" || valiuta == "gbp")
            rez = kiekis * gbp_pirkti;
        else if (valiuta == "USD" || valiuta == "usd")
            rez = kiekis * usd_pirkti;
        else if (valiuta == "INR" || valiuta == "inr")
            rez = kiekis * inr_pirkti;
        else {
            std::cout << "Valiuta nerasta.\n";
            return 0;
        }

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Uz " << kiekis << " Eur gausite " << rez << " " << valiuta << std::endl;

        break;
    case 3:
        std::cout << "Iveskite kiek " << valiuta << " norite parduoti: ";
        std::cin >> kiekis;

        if (valiuta == "GBP" || valiuta == "gbp")
            rez = kiekis * gbp_parduoti;
        else if (valiuta == "USD" || valiuta == "usd")
            rez = kiekis * usd_parduoti;
        else if (valiuta == "INR" || valiuta == "inr")
            rez = kiekis * inr_parduoti;
        else {
            std::cout << "Valiuta nerasta.\n";
            return 0;
        }

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Uz " << kiekis << " " << valiuta << " gausite " << rez << " Eur" << std::endl;
        break;
    default:
        std::cout << "Pasirinkimas neegzistuoja" << std::endl;
        break;
    }

    return 0;
}