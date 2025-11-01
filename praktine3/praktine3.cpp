#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void bilietai() {
    std::string failo_pav = "bilietai.txt";
    std::ifstream failas(failo_pav);
    std::ofstream rezultatas("rez_bilietai.txt");

    double kaina;
    int kiekis;
    int visi_bilietai = 0;
    double pajamos = 0.0;

    while (failas >> kaina >> kiekis) {
        visi_bilietai += kiekis;
        pajamos += kaina * kiekis;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Parduota bilietu: " << visi_bilietai << std::endl;
    std::cout << "Bendros vietu pajamos: " << pajamos << " EUR" << std::endl;

    rezultatas << std::fixed << std::setprecision(2);
    rezultatas << "Parduota bilietu: " << visi_bilietai << std::endl;
    rezultatas << "Bendros vietu pajamos: " << pajamos << " EUR" << std::endl;

    std::cout << "Rezultatas issaugotas rez_bilietai.txt" << std::endl;

    failas.close();
    rezultatas.close();
}

void atlyginimai() {
    std::string failo_pav = "atlyginimas.txt";
    std::ifstream failas(failo_pav);
    std::ofstream rezultatas("rez_atlyginimas.txt");

    std::string vardas, pavarde;
    double atlyginimas, procentas;

    std::cout << std::fixed << std::setprecision(2);
    rezultatas << std::fixed << std::setprecision(2);

    std::cout << "Atnaujinti atlyginimai:" << std::endl;

    while (failas >> pavarde >> vardas >> atlyginimas >> procentas) {
        double naujasAtlyginimas = atlyginimas + (atlyginimas * procentas / 100.0);
        std::cout << pavarde << " " << vardas << " " << naujasAtlyginimas << std::endl;
        rezultatas << pavarde << " " << vardas << " " << naujasAtlyginimas << std::endl;
    }

    std::cout << "Rezultatas issaugotas rez_atlyginimas.txt" << std::endl;

    failas.close();
    rezultatas.close();
}

int main() {
    int pasirinkimas;

    while(true) {
        std::cout << "== Duomenu apdorojimo sistema ==" << std::endl;
        std::cout << "1. Apskaiciuoti bilietu pardavimus" << std::endl;
        std::cout << "2. Atnaujinti darbuotoju atlyginimus" << std::endl;
        std::cout << "Pasirinkite: ";
        std::cin >> pasirinkimas;

        switch(pasirinkimas) {
        case 1:
            bilietai();
            break;
        case 2:
            atlyginimai();
            break;
        default:
            std::cout << "Pasirinkimas neegzistuoja" << std::endl;
        }
    }

    return 0;
}
