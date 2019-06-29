/** @file
 *  @author Губанова О.А.
 *  @version 1.0
 *  @date 25.06.2019
 *  @brief заголовочный файл класса modAlphaCipher
 */
 
#pragma once

#include <vector>
#include <string>
#include <map>

/** @brief Шифрование методом Гронсфельда
 *  @details Ключ устанавливается в конструкторе.
 *  Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 *  @warning Реализация  для русского языка
 */
class modAlphaCipher {
	
private:
	std::wstring numAlpha = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";//алфавит по порядку
	std::map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
	std::vector <int> key; //ключ
	std::vector <int> convert(const std::wstring& s); //преобразование строка-вектор
	std::wstring convert(const std::vector<int>& v); //преобразование вектор-строка
	std::wstring getValidKey(const std::wstring & in); //Проверка правильный ли ключ задали
	std::wstring getValidOpenText(const std::wstring & in); //Проверка на правильность открытого текста
	std::wstring getValidCipherText(const std::wstring & in); //Проверка на правильность зашифрованного текста

public:
	modAlphaCipher()=delete; //запретим конструктор без параметров
    modAlphaCipher(const std::wstring& skey); //конструктор для установки ключа
	std::wstring encrypt(const std::wstring& open_text);  //зашифрование
	std::wstring decrypt(const std::wstring& cipher_text);//расшифрование
};

class cipher_error: public std::invalid_argument {
	
public:
    explicit cipher_error (const std::string& what_arg): //explicit запрещает компилятору приравнивать "Object a = 5" и "Object a(5)".
														//Делает доступным только второе
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};