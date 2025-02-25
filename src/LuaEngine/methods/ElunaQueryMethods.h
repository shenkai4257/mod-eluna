/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef QUERYMETHODS_H
#define QUERYMETHODS_H

#define RESULT  (*result)

/***
 * The result of a database query.
 *
 * E.g. the return value of [Global:WorldDBQuery].
 *
 * Inherits all methods from: none
 */
namespace LuaQuery
{
    static void CheckFields(lua_State* L, ElunaQuery* result)
    {
        uint32 field = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 count = RESULT->GetFieldCount();
        if (field >= count)
        {
            char arr[256];
            snprintf(arr, sizeof(arr), "trying to access invalid field index %u. There are %u fields available and the indexes start from 0", field, count);
            luaL_argerror(L, 2, arr);
        }
    }

    /**
     * Returns `true` if the specified column of the current row is `NULL`, otherwise `false`.
     *
     * @param uint32 column
     * @return bool isNull
     */
    int IsNull(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);

        Eluna::Push(L, RESULT->Fetch()[col].IsNull());
        return 1;
    }

    /**
     * Returns the number of columns in the result set.
     *
     * @return uint32 columnCount
     */
    int GetColumnCount(lua_State* L, ElunaQuery* result)
    {
        Eluna::Push(L, RESULT->GetFieldCount());
        return 1;
    }

    /**
     * Returns the number of rows in the result set.
     *
     * @return uint32 rowCount
     */
    int GetRowCount(lua_State* L, ElunaQuery* result)
    {
        if (RESULT->GetRowCount() > (uint32)-1)
            Eluna::Push(L, (uint32)-1);
        else
            Eluna::Push(L, (uint32)(RESULT->GetRowCount()));
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a boolean.
     *
     * @param uint32 column
     * @return bool data
     */
    int GetBool(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<bool>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 8-bit integer.
     *
     * @param uint32 column
     * @return uint8 data
     */
    int GetUInt8(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<uint8>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 16-bit integer.
     *
     * @param uint32 column
     * @return uint16 data
     */
    int GetUInt16(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<uint16>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 32-bit integer.
     *
     * @param uint32 column
     * @return uint32 data
     */
    int GetUInt32(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<uint32>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to an unsigned 64-bit integer.
     *
     * @param uint32 column
     * @return uint64 data
     */
    int GetUInt64(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<uint64>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 8-bit integer.
     *
     * @param uint32 column
     * @return int8 data
     */
    int GetInt8(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<int8>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 16-bit integer.
     *
     * @param uint32 column
     * @return int16 data
     */
    int GetInt16(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<int16>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 32-bit integer.
     *
     * @param uint32 column
     * @return int32 data
     */
    int GetInt32(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<int32>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a signed 64-bit integer.
     *
     * @param uint32 column
     * @return int64 data
     */
    int GetInt64(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<int64>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a 32-bit floating point value.
     *
     * @param uint32 column
     * @return float data
     */
    int GetFloat(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<float>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a 64-bit floating point value.
     *
     * @param uint32 column
     * @return double data
     */
    int GetDouble(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<double>());
        return 1;
    }

    /**
     * Returns the data in the specified column of the current row, casted to a string.
     *
     * @param uint32 column
     * @return string data
     */
    int GetString(lua_State* L, ElunaQuery* result)
    {
        uint32 col = Eluna::CHECKVAL<uint32>(L, 2);
        CheckFields(L, result);
        Eluna::Push(L, RESULT->Fetch()[col].Get<std::string>());
        return 1;
    }

    /**
     * Advances the [ElunaQuery] to the next row in the result set.
     *
     * *Do not* call this immediately after a query, or you'll skip the first row.
     *
     * Returns `false` if there was no new row, otherwise `true`.
     *
     * @return bool hadNextRow
     */
    int NextRow(lua_State* L, ElunaQuery* result)
    {
        Eluna::Push(L, RESULT->NextRow());
        return 1;
    }

    /**
     * Returns a table from the current row where keys are field names and values are the row's values.
     *
     * All numerical values will be numbers and everything else is returned as a string.
     *
     * **For example,** the query:
     *
     *     SELECT entry, name FROM creature_template
     *
     * would result in a table like:
     *
     *     { entry = 123, name = "some creature name" }
     *
     * To move to next row use [ElunaQuery:NextRow].
     *
     * @return table rowData : table filled with row columns and data where `T[column] = data`
     */
    int GetRow(lua_State* L, ElunaQuery* result)
    {
        uint32 col = RESULT->GetFieldCount();
        Field* row = RESULT->Fetch();

        lua_createtable(L, 0, col);
        int tbl = lua_gettop(L);

        for (uint32 i = 0; i < col; ++i)
        {
            Eluna::Push(L, RESULT->GetFieldName(i));

            std::string _str = row[i].Get<std::string>();
            const char* str = _str.c_str();
            if (row[i].IsNull() || !str)
                Eluna::Push(L);
            else
            {
                // MYSQL_TYPE_LONGLONG Interpreted as string for lua
                switch (row[i].GetType())
                {
                    case DatabaseFieldTypes::Int8:
                    case DatabaseFieldTypes::Int16:
                    case DatabaseFieldTypes::Int32:
                    case DatabaseFieldTypes::Int64:
                    case DatabaseFieldTypes::Float:
                    case DatabaseFieldTypes::Double:
                        Eluna::Push(L, strtod(str, NULL));
                        break;
                    default:
                        Eluna::Push(L, str);
                        break;
                }
            }
            lua_rawset(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }
};
#undef RESULT

#endif
