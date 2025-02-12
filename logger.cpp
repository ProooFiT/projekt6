/**
 * @file logger.cpp
 * @brief Implementacja klasy Logger do obsługi logowania zdarzeń w aplikacji.
 */

#include <iomanip>
#include <ctime>
#include <cstdio>
#include <sstream>

#include "logger.hpp"

// Globalne instancje loggerów
Logger logger("log"); /**< Logger dla standardowych wiadomości. */
Logger loggerError("log_error"); /**< Logger dla wiadomości o błędach. */
int loggerErrorCount = 0; /**< Licznik błędów zapisanych w loggerze błędów. */

/**
 * @brief Konstruktor klasy Logger.
 * 
 * Tworzy logger z unikalną nazwą pliku zawierającą datę i czas utworzenia.
 * 
 * @param filename Nazwa pliku bazowego do generowania nazw plików logów.
 * @throws std::runtime_error Jeśli nie można otworzyć pliku logów.
 */
Logger::Logger(const std::string& filename) {
    auto t = std::time(nullptr);
    std::tm tm;

#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << filename << "_" << std::put_time(&tm, "%d%m%Y_%H%M%S") << ".txt";
    std::string datedFilename = oss.str();

    if (std::remove(datedFilename.c_str()) != 0) {
        // Jeśli plik istnieje, nie trzeba go usuwać.
    }

    logFile.open(datedFilename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku log");
    }
}

/**
 * @brief Destruktor klasy Logger.
 * 
 * Zamyka plik logów, jeśli jest otwarty.
 */
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

/**
 * @brief Zapisuje wiadomość do pliku logów z dołączonym znacznikiem czasowym.
 * 
 * Jeśli loggerem jest `loggerError`, zwiększa licznik błędów `loggerErrorCount`.
 * 
 * @param message Wiadomość do zapisania w pliku logów.
 */
void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        auto t = std::time(nullptr);
        std::tm tm;

#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&tm, &t);
#else
        localtime_r(&t, &tm);
#endif

        logFile << std::put_time(&tm, "%d.%m.%Y %H:%M:%S") << " " << message << std::endl;
    }

    if (this == &loggerError) {
        ++loggerErrorCount;
    }
}
