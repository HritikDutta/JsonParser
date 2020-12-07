#include "helpers.h"

#include <string>

#include "types.h"

inline bool
IsWhiteSpace(char ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0';
}

inline bool
IsDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

inline bool
IsAlphabet(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

inline bool
IsPartOfANumber(char ch)
{
    return IsDigit(ch) || ch == '.' || ch == '-' || ch == 'e' || ch == 'E';
}

inline void
EatSpacesAndCountLines(std::string& str, u64& index, u32& lineNumber)
{
    while (index < str.length() && IsWhiteSpace(str[index]))
    {
        if (str[index] == '\n') lineNumber++;
        index++;
    }
}

inline void
ToLower(char& ch)
{
    if (ch >= 'A' && ch <= 'Z')
        ch += ('a' - 'A');
}

inline void
ToLower(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
        ToLower(str[i]);
}