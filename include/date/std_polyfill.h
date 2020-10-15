#ifndef STD_POLYFILL_H
#define STD_POLYFILL_H

#include <string>

#ifdef ESP32
#define NEED_POLYFILL_TO_STRING
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

#endif
