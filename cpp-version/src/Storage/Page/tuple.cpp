#include "Storage/Page/tuple.h"

Tuple::Tuple(vector<Field> fields) {
    for (auto&f : fields) {
        this->fields.push_back(f);
        this->size += f.get_field_size();
    }
}


bool Tuple::get_is_deleted() {
    return this->is_deleted;
};
int Tuple::get_tuble_size() {
    return this->size;
};
vector<Field> Tuple::get_tuple_fields() {
    return this->fields;
};

void Tuple::print_tuple() {
    cout << "----------------------\n";
    cout << (this->get_is_deleted() ? "DELETED" : "FOUND") << '\n';
    for (auto&f : fields) {
        f.print_field(); 
    }
    cout << "\n----------------------\n";
}

void Tuple::mark_as_deleted() {
    this->is_deleted = true;
}


int main() {
    vector<Field> fields{Field(FieldType::TYPE_INT, 10), Field(FieldType::TYPE_DOUBLE, 12.6)};
    Tuple tuple(fields);
    int sz = 0;
    for (auto& f : fields) sz += f.get_field_size();
    assert(sz == tuple.get_tuble_size());
    cout << "t-size: " << tuple.get_tuble_size() << endl;   
    tuple.mark_as_deleted(); 
    tuple.print_tuple();
}