#include "date/std_polyfill.h"

#include <string>
#include <cstdio>
#include <cassert>

#ifdef NEED_POLYFILL_TO_STRING
template <typename T>
std::string to_sprintf(const char* format, T t) {
    std::string s;

    int length = snprintf(nullptr, 0, format, t);
    assert(length >= 0 && "snprintf failed unexpectedly");

    s.resize(length);
    int written = snprintf(&s.front(), length + 1, format, t);
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
