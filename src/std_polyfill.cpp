#include "date/std_polyfill.h"

#include <string>
#include <cstdio>
#include <cwchar>
#include <cstdlib>
#include <cassert>

#ifdef NEED_POLYFILL_TO_STRING
template <typename T>
std::string to_sprintf(const char* format, T t) {
    std::string s;

    int length = snprintf(nullptr, 0, format, t);
    assert(length >= 0 && "snprintf failed unexpectedly");

    s.resize(length);
    int written = snprintf(&s.front(), length, format, t);
    assert(written == length && "snprintf failed unexpectedly");

    return s;
}

namespace std {

std::string to_string(int value) {
    return to_sprintf("%d", value);
}

std::string to_string(long value) {
    return to_sprintf("%ld", value);
}

std::string to_string(long long value) {
    return to_sprintf("%lld", value);
}

std::string to_string(unsigned value) {
    return to_sprintf("%u", value);
}

std::string to_string(unsigned long value) {
    return to_sprintf("%lu", value);
}

std::string to_string(unsigned long long value) {
    return to_sprintf("%llu", value);
}

std::string to_string(float value) {
    return to_sprintf("%f", value);
}

std::string to_string(double value) {
    return to_sprintf("%f", value);
}

std::string to_string(long double value) {
    return to_sprintf("%Lf", value);
}

}
#endif

#ifdef NEED_POLYFILL_TO_WSTRING
template <typename T>
std::wstring to_swprintf(const wchar_t* format, T t) {
    std::wstring s;

    int length = swprintf(nullptr, 0, format, t);
    assert(length >= 0 && "swprintf failed unexpectedly");

    s.resize(length);
    int written = swprintf(&s.front(), length, format, t);
    assert(written == length && "swprintf failed unexpectedly");

    return s;
}

namespace std {

std::wstring to_wstring(int value) {
    return to_swprintf(L"%d", value);
}

std::wstring to_wstring(long value) {
    return to_swprintf(L"%ld", value);
}

std::wstring to_wstring(long long value) {
    return to_swprintf(L"%lld", value);
}

std::wstring to_wstring(unsigned value) {
    return to_swprintf(L"%u", value);
}

std::wstring to_wstring(unsigned long value) {
    return to_swprintf(L"%lu", value);
}

std::wstring to_wstring(unsigned long long value) {
    return to_swprintf(L"%llu", value);
}

std::wstring to_wstring(float value) {
    return to_swprintf(L"%f", value);
}

std::wstring to_wstring(double value) {
    return to_swprintf(L"%f", value);
}

std::wstring to_wstring(long double value) {
    return to_swprintf(L"%Lf", value);
}

}
#endif

#ifdef NEED_POLYFILL_STOLD

long double stold(const std::string& str, std::size_t* pos) {
    const char * startptr = str.c_str();
    char * endptr = nullptr;

    long double value = strtold(startptr, &endptr);

    if (pos != nullptr) {
        *pos = endptr - startptr;
    }

    return value;
}

long double stold(const std::wstring& str, std::size_t* pos) {
    const wchar_t * startptr = str.c_str();
    wchar_t * endptr = nullptr;

    long double value = wcstold(startptr, &endptr);

    if (pos != nullptr) {
        *pos = endptr - startptr;
    }

    return value;
}

#endif
