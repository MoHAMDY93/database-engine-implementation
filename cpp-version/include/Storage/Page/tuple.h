#pragma once
#include "field.h"
#include <vector>

class Tuple {
    // tuple is simply a vector of fields
private:
    vector<Field> fields;

    // metadata
    bool is_deleted{false};
    int size{0};

public:
    Tuple(vector<Field> fields);

    bool get_is_deleted();
    int get_tuble_size();
    vector<Field> get_tuple_fields();

    void print_tuple();

    void mark_as_deleted();

};