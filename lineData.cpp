/**
 * @file lineData.cpp
 * @brief Implementacja klasy `LineData`, która reprezentuje pojedynczy rekord danych energetycznych.
 *
 * Klasa `LineData` przechowuje dane dotyczące energii i zapewnia metody do serializacji,
 * deserializacji oraz ich prezentacji w postaci tekstowej.
 */

#include <algorithm>
#include <iostream>
#include <sstream>

#include "lineData.hpp"
#include "logger.hpp"

using namespace std;

/**
 * @brief Konstruktor tworzący obiekt `LineData` na podstawie ciągu znaków.
 * @param line Ciąg znaków reprezentujący pojedynczy rekord danych (CSV).
 */
LineData::LineData(const string& line) {
    vector<string> values;
    stringstream ss(line);
    string value;

    while (getline(ss, value, ',')) {
        value.erase(remove(value.begin(), value.end(), '\"'), value.end());
        values.push_back(value);
    }

    this->date = values[0];
    this->autokonsumpcja = stof(values[1]);
    this->eksport = stof(values[2]);
    this->import = stof(values[3]);
    this->pobor = stof(values[4]);
    this->produkcja = stof(values[5]);

    logger.log("Wczytano linie: " + this->printString());
}

/**
 * @brief Konstruktor tworzący obiekt `LineData` na podstawie strumienia wejściowego.
 * @param in Strumień wejściowy do deserializacji obiektu.
 */
LineData::LineData(ifstream& in) {
    deserialize(in);
}

/**
 * @brief Wyświetla dane na standardowe wyjście.
 */
void LineData::print() const {
    cout << date << " " << autokonsumpcja << " " << eksport << " " 
         << import << " " << pobor << " " << produkcja << endl;
}

/**
 * @brief Wyświetla dane w sformatowanej postaci, z wcięciem.
 */
void LineData::printData() const {
    cout << "\t\t\t\t" << autokonsumpcja << " " << eksport << " " 
         << import << " " << pobor << " " << produkcja << endl;
}

/**
 * @brief Zwraca dane w postaci ciągu znaków.
 * @return Dane w formie tekstowej.
 */
string LineData::printString() {
    return date + " " + to_string(autokonsumpcja) + " " + to_string(eksport) + " " 
           + to_string(import) + " " + to_string(pobor) + " " + to_string(produkcja);
}

/**
 * @brief Serializuje dane do strumienia wyjściowego.
 * @param out Strumień wyjściowy, do którego dane będą zapisane.
 */
void LineData::serialize(ofstream& out) const {
    size_t dateSize = date.size();
    out.write(reinterpret_cast<const char*>(&dateSize), sizeof(dateSize));
    out.write(date.c_str(), dateSize);
    out.write(reinterpret_cast<const char*>(&autokonsumpcja), sizeof(autokonsumpcja));
    out.write(reinterpret_cast<const char*>(&eksport), sizeof(eksport));
    out.write(reinterpret_cast<const char*>(&import), sizeof(import));
    out.write(reinterpret_cast<const char*>(&pobor), sizeof(pobor));
    out.write(reinterpret_cast<const char*>(&produkcja), sizeof(produkcja));
}

/**
 * @brief Deserializuje dane ze strumienia wejściowego.
 * @param in Strumień wejściowy, z którego dane będą odczytane.
 */
void LineData::deserialize(ifstream& in) {
    size_t dateSize;
    in.read(reinterpret_cast<char*>(&dateSize), sizeof(dateSize));
    date.resize(dateSize);
    in.read(&date[0], dateSize);
    in.read(reinterpret_cast<char*>(&autokonsumpcja), sizeof(autokonsumpcja));
    in.read(reinterpret_cast<char*>(&eksport), sizeof(eksport));
    in.read(reinterpret_cast<char*>(&import), sizeof(import));
    in.read(reinterpret_cast<char*>(&pobor), sizeof(pobor));
    in.read(reinterpret_cast<char*>(&produkcja), sizeof(produkcja));
}
