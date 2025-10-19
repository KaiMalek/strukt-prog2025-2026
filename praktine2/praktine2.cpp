#include <iostream>
#include <string>

const int MOKINIAI = 100;
const int PAZYMIAI = 10;

int main() {
    int pasirinkimas;
    int pazymiai[MOKINIAI][PAZYMIAI];
    int pazymiu_kiekis[MOKINIAI];
    int mok_kiekis = 0, index;

    std::string mokiniai[MOKINIAI];
    std::string mok_vardas;

    bool found = false;

	while (true) {
        std::cout << "\n---- MOKINIU PAZYMIU SISTEMA ----\n";
        std::cout << "1. Prideti mokini\n";
        std::cout << "2. Perziureti visu mokiniu pazymius\n";
        std::cout << "3. Perziureti vieno mokinio pazymius\n";
        std::cout << "4. Atnaujinti pazymi\n";
        std::cout << "5. Pasalinti mokini\n";
        std::cout << "0. Iseiti\n";
        std::cout << "Pasirinkite: ";
        std::cin >> pasirinkimas;

        switch (pasirinkimas) {
        case 0: std::cout << "Iki.\n"; return 0; break;
        case 1:
            if (mok_kiekis >= MOKINIAI) {
                std::cout << "Pasiektas mokiniu kiekis.";
                break;
            }

            std::cout << "Mokinio vardas: ";
            std::cin >> mokiniai[mok_kiekis];

            std::cout << "Pazymiu kiekis (iki 10): ";
            std::cin >> pazymiu_kiekis[mok_kiekis];


            if (pazymiu_kiekis[mok_kiekis] > PAZYMIAI)
                pazymiu_kiekis[mok_kiekis] = PAZYMIAI;

            for (int j = 0; j < pazymiu_kiekis[mok_kiekis]; j++) {
                std::cout << "Iveskite " << j + 1 << "-aji pazymi (1-10): ";
                std::cin >> pazymiai[mok_kiekis][j];
            }

            mok_kiekis++;
            std::cout << "Mokinys pridetas sekmingai!\n";
            
            break;
        case 2:
            if (mok_kiekis == 0) {
                std::cout << "Mokiniu nera.\n";
                break;
            }

            for (int i = 0; i < mok_kiekis; i++) {
                std::cout << i + 1 << ". " << mokiniai[i] << ": ";
                for (int j = 0; j < pazymiu_kiekis[i]; j++)
                    std::cout << pazymiai[i][j] << " ";
                std::cout << std::endl;
            }
            break;
        case 3:
            std::cout << "Iveskite mokinio varda: ";
            std::cin >> mok_vardas;

            for (int i = 0; i < mok_kiekis; i++) {
                if (mokiniai[i] == mok_vardas) {
                    std::cout << mokiniai[i] << " pazymiai: ";
                    for (int j = 0; j < pazymiu_kiekis[i]; j++)
                        std::cout << pazymiai[i][j] << " ";
                    std::cout << std::endl;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                std::cout << "Mokinys nerastas.\n";
            }
            break;
        case 4:
            std::cout << "Iveskite mokinio varda: ";
            std::cin >> mok_vardas;

            for (int i = 0; i < mok_kiekis; i++) {
                if (mokiniai[i] == mok_vardas) {
                    found = true;

                    std::cout << mokiniai[i] << " pazymiai: ";
                    for (int j = 0; j < pazymiu_kiekis[i]; j++) {
                        std::cout << j + 1 << ":" << pazymiai[i][j] << " \n";
                    }
                    std::cout << "Kuri pazymi nori pakeisti (1-" << pazymiu_kiekis[i] << ")? ";

                    std::cin >> index;

                    if (index > 0 && index <= pazymiu_kiekis[i]) {
                        std::cout << "Ivesk nauja pazymi: ";
                        std::cin >> pazymiai[i][index - 1];
                        std::cout << "Pazimys atnaujintas.\n";
                    }
                    else {
                        std::cout << "Neteisingas pazymio vietos skaicius.";
                    }
                    break;
                }
            }
            if (!found)
                std::cout << "Mokinys nerastas.\n";

            break;
        case 5:
            std::cout << "Irasyk mokinio varda: ";
            std::cin >> mok_vardas;

            for (int i = 0; i < mok_kiekis; i++) {
                if (mokiniai[i] == mok_vardas) {
                    for (int k = i; k < mok_kiekis - 1; k++) {
                        mokiniai[k] = mokiniai[k + 1];
                        pazymiu_kiekis[k] = pazymiu_kiekis[k + 1];
                        for (int j = 0; j < PAZYMIAI; j++)
                            pazymiai[k][j] = pazymiai[k + 1][j];
                    }

                    mok_kiekis--;
                    found = true;
                    std::cout << "Mokinys pasalintas.\n";
                    break;
                }
            }
            break;
        default: std::cout << "Pasirinkimas neegzistuoja.\n"; break;
        }
	}

    return 0;
}
