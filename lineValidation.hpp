/**
 * @file lineValidation.hpp
 * @brief Definicja funkcji `lineValidation` sprawdzającej poprawność danych wiersza.
 */

#ifndef LINEVALIDATION_HPP
#define LINEVALIDATION_HPP

#include <string>
#include <cctype>
#include <algorithm>

#include "logger.hpp"

/**
 * @brief Waliduje pojedynczy wiersz danych wejściowych.
 *
 * Funkcja sprawdza poprawność wiersza danych wejściowych pod kątem kilku kryteriów:
 * - Wiersz nie może być pusty.
 * - Wiersz nie może zawierać nagłówka ("Time").
 * - Wiersz nie może zawierać znaków alfabetycznych (poza formatem danych liczbowych).
 * - Wiersz musi zawierać dokładnie 5 przecinków.
 *
 * Jeśli wiersz jest niepoprawny, odpowiedni komunikat błędu zostaje zapisany do loggera.
 *
 * @param line Ciąg znaków reprezentujący wiersz danych wejściowych.
 * @return `true`, jeśli wiersz jest poprawny; w przeciwnym razie `false`.
 */
bool lineValidation(const std::string& line);

#endif
