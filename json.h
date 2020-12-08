#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "types.h"

namespace JSON
{

    struct Value;
    typedef std::unordered_map<std::string, Value> JSONObject;
    typedef std::vector<Value> JSONArray;

    struct Value
    {
        enum struct Type
        {
            Null,
            Bool,
            Int,
            Float,
            String,
            Object,
            Array,
            Error
        };

        Type type;
        
        union
        {
            bool         Bool;
            i64          Int;
            f64          Float;
            std::string* String;
            JSONObject*  Object;
            JSONArray*   Array;
        };

        Value();
        Value(bool b);
        Value(int i);
        Value(i64 i);
        Value(f64 f);
        Value(std::string* s);
        Value(char* s);
        Value(const std::string& s);
        Value(JSONObject* o);
        Value(JSONArray* a);
        Value(Type forceType);
        Value(Value&& other);
        ~Value();

        inline Value& operator=(Value&& rhs);
        inline Value& operator[](u64 idx);
        inline Value& operator[](const std::string& key);

        inline bool&        GetBool();
        inline i64&         GetInt();
        inline f64&         GetFloat();
        inline std::string& GetString();
        inline u64          GetArraySize() const;

        std::string Value::GetTypeName() const;
    };

    struct Token
    {
        enum struct Type
        {
            Value,
            Int,
            Float,
            String,

            Comma = ',',
            Colon = ':',
            
            SquareBracket_Open  = '[',
            SquareBracket_Close = ']',
            CurlyBracket_Open   = '{',
            CurlyBracket_Close  = '}',

            Error   // @TODO: Use this later to implement proper error checking.
        };

        Type type;
        std::string value;

        Token();
        Token(const Token& other);
        Token(Token&& other);

        inline Token& operator=(Token&& rhs);
    };

    inline Value LoadFile(const std::string& filepath);
    Value ParseNext(std::string& data, u64& index, const std::string& filepath, u32& lineNumber);

} // namespace JSON

typedef JSON::Value Json;