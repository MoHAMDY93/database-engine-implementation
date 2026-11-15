#include "Storage/Page/field.h"
#include <iomanip>

Field::Field(FieldType type, int value) {
    this->field_type = type;
    this->VALUE_INT = value;
    this->size = sizeof(value);
};

Field::Field(FieldType type, double value) {
    this->field_type = type;
    this->VALUE_DOUBLE = value;
    this->size = sizeof(value);
};

Field::Field(FieldType type, bool value) {
    this->field_type = type;
    this->VALUE_BOOL = value;
    this->size = sizeof(value);
};

Field::Field(FieldType type, const char* value) {
    this->field_type = type;
    this->size = strlen(value);
    this->VALUE_STRING = new char(size + 1);
    strcpy((char*)this->VALUE_STRING, value);
};

Field::Field(FieldType type) {
    this->is_null = true;
    this->field_type = type;   

    this->VALUE_BOOL = false;
    this->VALUE_INT = 0;
    this->VALUE_DOUBLE = 0.0;
    this->VALUE_STRING = "";
}


FieldType Field::get_field_type() {
    return this->field_type;
}
int Field::get_field_size() {
    return this->size;
}
bool Field::get_is_null() {
    return this->is_null;
}


int Field::get_value_int() {
    return this->VALUE_INT;
}
double Field::get_value_double() {
    return this->VALUE_DOUBLE;
}
bool Field::get_vlaue_bool() {
    return this->VALUE_BOOL;
}
string Field::get_value_string() {
    return string(this->VALUE_STRING);
}

void Field::print_field() {
    switch (this->field_type)
    {
    case FieldType::TYPE_INT:
        cout << left << setw(15) << this->VALUE_INT;
        break;
    case FieldType::TYPE_DOUBLE:
        cout << left << setw(15) << this->VALUE_DOUBLE;
        break;
    case FieldType::TYPE_BOOL:
        cout << left << setw(15) << this->VALUE_BOOL;
        break;
    case FieldType::TYPE_STRING:
        cout << left << setw(15) << this->VALUE_STRING;
        break;
    default:
        cout << "NULL" << endl;
        break;
    }
}

// int main() {
//     // test
//     {   
//         FieldType type = FieldType::TYPE_STRING;
//         const char* value = "mohamed";
//         Field f(type, value);
//         f.print_field();
//     }
// }