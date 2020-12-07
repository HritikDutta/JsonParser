#pragma once

inline bool IsWhiteSpace(char ch);
inline bool IsDigit(char ch);
inline bool IsAlphabet(char ch);
inline bool IsPartOfANumber(char ch);
inline void EatSpacesAndCountLines(std::string& str, u64& index, u32& lineNumber);

inline void ToLower(char& ch);
inline void ToLower(std::string& str);