/**
 * @file app.hpp
 * @brief Definicja klasy `App` oraz enumeracji `MenuOption` używanych w programie.
 *
 * Klasa `App` jest klasą narzędziową, zarządzającą główną logiką programu, 
 * w tym obsługą menu i interakcją z danymi energetycznymi.
 *
 * ## Funkcjonalności:
 * - Obsługa głównego menu programu
 * - Ładowanie danych z plików CSV
 * - Wyświetlanie danych w formie drzewa
 * - Przetwarzanie i analizowanie danych w różnych przedziałach czasowych
 * - Zapis i odczyt danych z plików binarnych
 *
 * ### Enumeracja `MenuOption`:
 * Wyliczenie definiuje dostępne opcje menu, takie jak:
 * - `LOAD_DATA_FROM_FILE`: Załaduj dane z pliku CSV.
 * - `DISPLAY_TREE_STRUCTURE`: Wyświetl strukturę drzewa.
 * - `GET_DATA_BETWEEN_DATES`: Pobierz dane w określonym przedziale czasowym.
 * - `CALCULATE_SUMS_BETWEEN_DATES`: Oblicz sumy w przedziale czasowym.
 * - `CALCULATE_AVERAGES_BETWEEN_DATES`: Oblicz średnie wartości w przedziale czasowym.
 * - `COMPARE_DATA_BETWEEN_DATES`: Porównaj dane pomiędzy zakresami czasowymi.
 * - `SEARCH_RECORDS_WITH_TOLERANCE`: Wyszukaj dane w przedziale czasowym z tolerancją.
 * - `SAVE_DATA_TO_BINARY_FILE`: Zapisz dane do pliku binarnego.
 * - `LOAD_DATA_FROM_BINARY_FILE`: Wczytaj dane z pliku binarnego.
 * - `EXIT`: Wyjdź z programu.
 *
 * ### Klasa `App`:
 * Wszystkie metody klasy są statyczne i obsługują różne funkcje programu.
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <vector>

#include "treeData.hpp"

/**
 * @enum MenuOption
 * @brief Enumeracja definiująca opcje dostępne w menu.
 */
enum MenuOption {
  LOAD_DATA_FROM_FILE = 1,            ///< Załaduj dane z pliku CSV
  DISPLAY_TREE_STRUCTURE,             ///< Wyświetl strukturę drzewa
  GET_DATA_BETWEEN_DATES,             ///< Pobierz dane w określonym przedziale czasowym
  CALCULATE_SUMS_BETWEEN_DATES,       ///< Oblicz sumy w przedziale czasowym
  CALCULATE_AVERAGES_BETWEEN_DATES,   ///< Oblicz średnie wartości w przedziale czasowym
  COMPARE_DATA_BETWEEN_DATES,         ///< Porównaj dane pomiędzy zakresami czasowymi
  SEARCH_RECORDS_WITH_TOLERANCE,      ///< Wyszukaj dane w przedziale czasowym z tolerancją
  SAVE_DATA_TO_BINARY_FILE,           ///< Zapisz dane do pliku binarnego
  LOAD_DATA_FROM_BINARY_FILE,         ///< Wczytaj dane z pliku binarnego
  EXIT                                ///< Wyjdź z programu
};

/**
 * @brief Operator strumieniowy umożliwiający odczyt wartości `MenuOption` z wejścia.
 * @param iStream Strumień wejściowy
 * @param menuOption Referencja do obiektu `MenuOption`, gdzie zapisana będzie wartość
 * @return Referencja do strumienia wejściowego
 */
std::istream& operator>>(std::istream& iStream, MenuOption& menuOption);

/**
 * @class App
 * @brief Klasa zarządzająca główną logiką programu.
 *
 * Klasa `App` implementuje funkcje obsługi danych energetycznych oraz interakcję użytkownika.
 * Wszystkie metody są statyczne, co pozwala na wywoływanie ich bez konieczności tworzenia instancji klasy.
 */
class App {
private:
  static TreeData treeData; ///< Statyczna instancja klasy `TreeData` przechowująca dane.

  /**
   * @brief Konstruktor prywatny, aby uniemożliwić tworzenie instancji klasy `App`.
   */
  App() = delete;

  /**
   * @brief Prywatny konstruktor kopiujący (zablokowany).
   */
  App(const App&) = delete;

  /**
   * @brief Prywatny operator przypisania (zablokowany).
   */
  App& operator=(const App&) = delete;

  // Deklaracje metod obsługi różnych funkcji programu
  static int mainMenu();                             ///< Obsługuje główne menu programu
  static int handleLoadDataFromFile();               ///< Ładuje dane z pliku CSV
  static int handleDisplayTreeStructure();           ///< Wyświetla strukturę drzewa
  static int handleGetDataBetweenDates();            ///< Pobiera dane w przedziale czasowym
  static int handleCalculateSumsBetweenDates();      ///< Oblicza sumy w przedziale czasowym
  static int handleCalculateAveragesBetweenDates();  ///< Oblicza średnie wartości w przedziale czasowym
  static int handleCompareDataBetweenDates();        ///< Porównuje dane między przedziałami czasowymi
  static int handleSearchRecordsWithTolerance();     ///< Wyszukuje dane z tolerancją
  static int handleSaveDataToBinaryFile();           ///< Zapisuje dane do pliku binarnego
  static int handleLoadDataFromBinaryFile();         ///< Wczytuje dane z pliku binarnego
  static int handleExit();                           ///< Obsługuje wyjście z programu

public:
  /**
   * @brief Uruchamia główną pętlę programu.
   * @return Kod zakończenia programu
   */
  static int run();
};

#endif // APP_HPP
