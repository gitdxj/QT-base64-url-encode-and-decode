

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <string>

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);
std::string URLEncode(const std::string &str_source);
std::string URLDecode(const std::string &str_source);
int _htoi(char *s);

#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */
