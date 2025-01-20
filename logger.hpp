/**
 * @file logger.hpp
 * @brief Deklaracja klasy Logger do obsługi logowania zdarzeń w aplikacji.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

/**
 * @class Logger
 * @brief Klasa do zarządzania logowaniem zdarzeń w aplikacji.
 * 
 * Klasa ta pozwala na zapis wiadomości do pliku logów z dołączonym znacznikiem czasowym. 
 * Istnieją dwa rodzaje loggerów: jeden do logowania standardowych wiadomości i drugi do logowania błędów.
 */
class Logger {
public:
    /**
     * @brief Konstruktor klasy Logger.
     * 
     * Tworzy logger z unikalną nazwą pliku zawierającą datę i czas utworzenia.
     * 
     * @param filename Nazwa pliku bazowego do generowania nazw plików logów.
     */
    Logger(const std::string& filename);

    /**
     * @brief Destruktor klasy Logger.
     * 
     * Zamyka plik logów, jeśli jest otwarty.
     */
    ~Logger();

    /**
     * @brief Zapisuje wiadomość do pliku logów.
     * 
     * Zawiera znaczniki czasowe, które są dodawane przed każdą wiadomością. Jeśli logger jest używany do zapisu błędów, 
     * to zwiększa licznik błędów.
     * 
     * @param message Wiadomość do zapisania w pliku logów.
     */
    void log(const std::string& message);

private:
    std::ofstream logFile; /**< Strumień do zapisu w pliku logów. */
};

/** Instancja loggera do standardowych logów. */
extern Logger logger;

/** Instancja loggera do logowania błędów. */
extern Logger loggerError;

/** Licznik błędów zapisanych w loggerze błędów. */
extern int loggerErrorCount;

#endif
