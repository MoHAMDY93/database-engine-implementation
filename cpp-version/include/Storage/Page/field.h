#pragma once

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

/*
    here we need:
    1) field type: {int, double, bool, string}
    2) field value: {}
    3) metadata
*/

enum class FieldType {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_BOOL,
    TYPE_STRING
};

class Field {
private:
    // field type
    FieldType field_type;
    
    // field value
    union {
        int VALUE_INT;
        bool VALUE_BOOL;
        double VALUE_DOUBLE;
        const char* VALUE_STRING;
    };

    // metadata
    bool is_null{false};
    int size{0};
 
public:
    Field(FieldType type, int vlaue);
    Field(FieldType type, double vlaue);
    Field(FieldType type, bool vlaue);
    Field(FieldType type, const char* vlaue);

    Field(FieldType type);

    FieldType get_field_type();
    int get_field_size();
    bool get_is_null();


    int get_value_int();
    double get_value_double();
    bool get_vlaue_bool();
    string get_value_string();

    void print_field();

};