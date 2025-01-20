/**
 * @file treeData.hpp
 * @brief Deklaracja klasy TreeData, która przechowuje i przetwarza dane związane z energią w hierarchicznej strukturze.
 */

#ifndef TREEDATA_H
#define TREEDATA_H

#include <map>
#include <string>
#include <vector>
#include "lineData.hpp"

/**
 * @class TreeData
 * @brief Klasa do zarządzania danymi dotyczącymi energii w strukturze hierarchicznej.
 * 
 * Klasa ta przechowuje dane w strukturze hierarchicznej (Rok -> Miesiąc -> Dzień -> Kwartał), 
 * umożliwiając dodawanie, przetwarzanie i analizowanie danych dotyczących energii w różnych okresach.
 */
class TreeData {
public:

    /**
     * @struct QuarterNode
     * @brief Struktura przechowująca dane o kwartale w ciągu godziny.
     * 
     * Zawiera informacje o kwartale, godzinie, minucie oraz dane związane z energią w tym czasie.
     */
    struct QuarterNode {
        int quarter; /**< Numer kwartału (1-4). */
        int hour; /**< Godzina. */
        int minute; /**< Minuta. */
        std::vector<LineData> data; /**< Dane dotyczące energii w tym kwartale. */
    };

    /**
     * @struct DayNode
     * @brief Struktura przechowująca dane o dniu.
     * 
     * Zawiera mapę, która odwzorowuje kwartalną strukturę danych.
     */
    struct DayNode {
        int day; /**< Numer dnia. */
        std::map<int, QuarterNode> quarters; /**< Mapa kwartali w danym dniu. */
    };

    /**
     * @struct MonthNode
     * @brief Struktura przechowująca dane o miesiącu.
     * 
     * Zawiera mapę dni w danym miesiącu.
     */
    struct MonthNode {
        int month; /**< Numer miesiąca. */
        std::map<int, DayNode> days; /**< Mapa dni w danym miesiącu. */
    };

    /**
     * @struct YearNode
     * @brief Struktura przechowująca dane o roku.
     * 
     * Zawiera mapę miesięcy w danym roku.
     */
    struct YearNode {
        int year; /**< Numer roku. */
        std::map<int, MonthNode> months; /**< Mapa miesięcy w danym roku. */
    };

    /**
     * @brief Dodaje dane do struktury TreeData.
     * 
     * Przetwarza dane i przypisuje je do odpowiednich kwartali, dni, miesięcy oraz lat.
     * 
     * @param lineData Dane do dodania.
     */
    void addData(const LineData& lineData);

    /**
     * @brief Drukuje dane w strukturze TreeData.
     * 
     * Wypisuje całą hierarchię danych w TreeData, wyświetlając wartości dla każdego kwartału, dnia, miesiąca oraz roku.
     */
    void print() const;

    /**
     * @brief Pobiera dane w zadanym przedziale dat.
     * 
     * Zwraca dane dotyczące energii w zadanym przedziale dat, uwzględniając kwartały, dni i miesiące.
     * 
     * @param startDate Data początkowa (w formacie "YYYY-MM-DD").
     * @param endDate Data końcowa (w formacie "YYYY-MM-DD").
     * @return Lista danych zawierających energię w zadanym okresie.
     */
    std::vector<LineData> getDataBetweenDates(const std::string& startDate, const std::string& endDate) const;

    /**
     * @brief Oblicza sumy wartości dla różnych typów danych w zadanym przedziale dat.
     * 
     * Oblicza sumy dla autokonsumpcji, eksportu, importu, poboru oraz produkcji w zadanym okresie.
     * 
     * @param startDate Data początkowa (w formacie "YYYY-MM-DD").
     * @param endDate Data końcowa (w formacie "YYYY-MM-DD").
     * @param autokonsumpcjaSum Suma autokonsumpcji w zadanym okresie.
     * @param eksportSum Suma eksportu w zadanym okresie.
     * @param importSum Suma importu w zadanym okresie.
     * @param poborSum Suma poboru w zadanym okresie.
     * @param produkcjaSum Suma produkcji w zadanym okresie.
     */
    void calculateSumsBetweenDates(const std::string& startDate, const std::string& endDate, 
        float& autokonsumpcjaSum, float& eksportSum, float& importSum, float& poborSum, float& produkcjaSum) const;

    /**
     * @brief Oblicza średnie wartości dla różnych typów danych w zadanym przedziale dat.
     * 
     * Oblicza średnie wartości dla autokonsumpcji, eksportu, importu, poboru oraz produkcji w zadanym okresie.
     * 
     * @param startDate Data początkowa (w formacie "YYYY-MM-DD").
     * @param endDate Data końcowa (w formacie "YYYY-MM-DD").
     * @param autokonsumpcjaAvg Średnia autokonsumpcji w zadanym okresie.
     * @param eksportAvg Średnia eksportu w zadanym okresie.
     * @param importAvg Średnia importu w zadanym okresie.
     * @param poborAvg Średnia poboru w zadanym okresie.
     * @param produkcjaAvg Średnia produkcji w zadanym okresie.
     */
    void calculateAveragesBetweenDates(const std::string& startDate, const std::string& endDate, 
        float& autokonsumpcjaAvg, float& eksportAvg, float& importAvg, float& poborAvg, float& produkcjaAvg) const;

    /**
     * @brief Porównuje dane pomiędzy dwoma przedziałami dat.
     * 
     * Porównuje wartości autokonsumpcji, eksportu, importu, poboru i produkcji pomiędzy dwoma przedziałami dat.
     * 
     * @param startDate1 Data początkowa pierwszego przedziału.
     * @param endDate1 Data końcowa pierwszego przedziału.
     * @param startDate2 Data początkowa drugiego przedziału.
     * @param endDate2 Data końcowa drugiego przedziału.
     * @param autokonsumpcjaDiff Różnica autokonsumpcji między okresami.
     * @param eksportDiff Różnica eksportu między okresami.
     * @param importDiff Różnica importu między okresami.
     * @param poborDiff Różnica poboru między okresami.
     * @param produkcjaDiff Różnica produkcji między okresami.
     */
    void compareDataBetweenDates(const std::string& startDate1, const std::string& endDate1, 
        const std::string& startDate2, const std::string& endDate2, 
        float& autokonsumpcjaDiff, float& eksportDiff, float& importDiff, 
        float& poborDiff, float& produkcjaDiff) const;

    /**
     * @brief Serializuje dane TreeData do pliku.
     * 
     * Zapisuje całą strukturę TreeData do pliku binarnego.
     * 
     * @param out Strumień wyjściowy do zapisu danych.
     */
    void serialize(std::ofstream& out) const;

    /**
     * @brief Wyszukuje rekordy z tolerancją dla wartości w zadanym przedziale dat.
     * 
     * Wyszukuje dane w zadanym przedziale dat, gdzie różnice między wartościami są mniejsze niż zadana tolerancja.
     * 
     * @param startDate Data początkowa (w formacie "YYYY-MM-DD").
     * @param endDate Data końcowa (w formacie "YYYY-MM-DD").
     * @param value Wartość do porównania.
     * @param tolerance Tolerancja dla wartości.
     * @return Lista rekordów, które pasują do kryteriów wyszukiwania.
     */
    std::vector<LineData> searchRecordsWithTolerance(const std::string& startDate, const std::string& endDate, 
        float value, float tolerance) const;

private:
    std::map<int, YearNode> years; /**< Mapa lat przechowująca całą strukturę danych. */
};

#endif
