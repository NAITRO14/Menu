#pragma once
#include "includes.h"

inline wstring UTF8ToWide(const std::string& tmp) {
	if (tmp.empty()) return L"";

	int wlen = MultiByteToWideChar(CP_UTF8, 0,
		tmp.c_str(), -1,
		NULL, 0);
	if (wlen == 0) return L"";

	wstring wpath(wlen, 0);
	MultiByteToWideChar(CP_UTF8, 0,
		tmp.c_str(), -1,
		&wpath[0], wlen);

	wpath.pop_back(); // Убираем завершающий ноль
	return wpath;
}

inline string WideToUTF8(const std::wstring& wide_str) {
    std::cout << "[DEBUG] WideToUTF8 input size: " << wide_str.size() << std::endl;

    if (wide_str.empty()) {
        std::cout << "[DEBUG] Input is empty" << std::endl;
        return "";
    }

    // Безопасное преобразование длины
    int length = static_cast<int>(wide_str.size());
    if (length <= 0) {
        return "";
    }

    // Получаем размер буфера
    int utf8_size = WideCharToMultiByte(CP_UTF8, 0,
        wide_str.c_str(), length,
        nullptr, 0,
        nullptr, nullptr);
    std::cout << "[DEBUG] Required UTF-8 size: " << utf8_size << std::endl;

    if (utf8_size <= 0) {
        DWORD err = GetLastError();
        std::cout << "[ERROR] WideCharToMultiByte failed: " << err << std::endl;
        return "";
    }

    // Создаем строку нужного размера
    std::string result(utf8_size, '\0');

    // Конвертируем
    int converted = WideCharToMultiByte(CP_UTF8, 0,
        wide_str.c_str(), length,
        &result[0], utf8_size,
        nullptr, nullptr);

    std::cout << "[DEBUG] Converted bytes: " << converted << std::endl;

    if (converted <= 0) {
        DWORD err = GetLastError();
        std::cout << "[ERROR] Conversion failed: " << err << std::endl;
        return "";
    }

    // Если размеры не совпадают (маловероятно)
    if (converted != utf8_size) {
        result.resize(converted);
    }

    std::cout << "[DEBUG] Result size: " << result.size() << std::endl;
    return result;
}
