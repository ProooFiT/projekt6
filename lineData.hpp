/**
 * @file lineData.hpp
 * @brief Definicja klasy `LineData` reprezentującej pojedynczy rekord danych energetycznych.
 */

#ifndef LINEDATA_HPP
#define LINEDATA_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @class LineData
 * @brief Klasa reprezentująca pojedynczy rekord danych energetycznych.
 *
 * Klasa `LineData` przechowuje dane dotyczące daty, autokonsumpcji, eksportu, importu,
 * poboru i produkcji energii. Zapewnia metody do odczytu, zapisu, serializacji i
 * deserializacji danych.
 */
class LineData {
public:
    /**
     * @brief Konstruktor tworzący obiekt `LineData` na podstawie ciągu znaków.
     * @param line Ciąg znaków reprezentujący pojedynczy rekord danych w formacie CSV.
     */
    explicit LineData(const string& line);

    /**
     * @brief Konstruktor tworzący obiekt `LineData` na podstawie strumienia wejściowego.
     * @param in Strumień wejściowy używany do deserializacji obiektu.
     */
    LineData(ifstream& in);

    /**
     * @brief Wyświetla dane na standardowe wyjście w pełnej postaci.
     */
    void print() const;

    /**
     * @brief Wyświetla dane w sformatowanej postaci, z wcięciem.
     */
    void printData() const;

    /**
     * @brief Zwraca dane w postaci ciągu znaków.
     * @return Dane w formie tekstowej.
     */
    string printString();

    /**
     * @brief Serializuje dane do strumienia wyjściowego.
     * @param out Strumień wyjściowy, do którego dane będą zapisane.
     */
    void serialize(ofstream& out) const;

    /**
     * @brief Deserializuje dane ze strumienia wejściowego.
     * @param in Strumień wejściowy, z którego dane będą odczytane.
     */
    void deserialize(ifstream& in);

    /**
     * @brief Zwraca datę rekordu.
     * @return Data w formie tekstowej.
     */
    string getDate() const { return date; }

    /**
     * @brief Zwraca wartość autokonsumpcji.
     * @return Wartość autokonsumpcji.
     */
    float getAutokonsumpcja() const { return autokonsumpcja; }

    /**
     * @brief Zwraca wartość eksportu.
     * @return Wartość eksportu.
     */
    float getEksport() const { return eksport; }

    /**
     * @brief Zwraca wartość importu.
     * @return Wartość importu.
     */
    float getImport() const { return import; }

    /**
     * @brief Zwraca wartość poboru.
     * @return Wartość poboru.
     */
    float getPobor() const { return pobor; }

    /**
     * @brief Zwraca wartość produkcji.
     * @return Wartość produkcji.
     */
    float getProdukcja() const { return produkcja; }

private:
    string date; ///< Data rekordu w formacie tekstowym.
    float autokonsumpcja; ///< Wartość autokonsumpcji.
    float eksport; ///< Wartość eksportu.
    float import; ///< Wartość importu.
    float pobor; ///< Wartość poboru.
    float produkcja; ///< Wartość produkcji.
};

#endif
