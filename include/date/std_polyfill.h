#ifndef STD_POLYFILL_H
#define STD_POLYFILL_H

#include <string>

#ifdef ESP32
#define NEED_POLYFILL_TO_STRING
#define NEED_POLYFILL_TO_WSTRING
#define NEED_POLYFILL_STOLD
#endif

#ifdef NEED_POLYFILL_TO_STRING
namespace std {

std::string to_string(int value);
std::string to_string(long value);
std::string to_string(long long value);
std::string to_string(unsigned value);
std::string to_string(long unsigned value);
std::string to_string(long long unsigned value);
std::string to_string(float value);
std::string to_string(double value);
std::string to_string(long double value);

}
#endif

#ifdef NEED_POLYFILL_TO_WSTRING
namespace std {

std::wstring to_wstring(int value);
std::wstring to_wstring(long value);
std::wstring to_wstring(long long value);
std::wstring to_wstring(unsigned value);
std::wstring to_wstring(long unsigned value);
std::wstring to_wstring(long long unsigned value);
std::wstring to_wstring(float value);
std::wstring to_wstring(double value);
std::wstring to_wstring(long double value);

}
#endif

#ifdef NEED_POLYFILL_STOLD
namespace std {

long double stold(const std::string& str, std::size_t* pos = nullptr);
long double stold(const std::wstring& str, std::size_t* pos = nullptr);

}
#endif

#endif
