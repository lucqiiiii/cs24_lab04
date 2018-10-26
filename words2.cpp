// words2.cpp - implements class Words
// (dynamic array version)
// Qi Guo 10/25/2018

#include <cassert>
#include <string>
#include "words2.h"

using std::string;
namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
        capacity = initial_capacity;
        data = new string [initial_capacity];
    }
    
    Words::Words(const Words &source){
        data = new string [source.capacity];
        used = source.used;
        capacity = source.capacity;
        copy(source.data, source.data + used, data);
    }

    Words::~Words() {
    delete [] data;
    }

    void Words::append(string word) {
        if(used < capacity){
            data[used] = word;
            ++used;
        }
        else{
            string *new_data;
            new_data = new string [used*2];
            copy(data, data + used, new_data);
            delete[] data;
            data = new_data;
            capacity = used*2;
            data[used] = word;
            ++used;
       }
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    Words& Words::operator = (const Words &source){
        string  *new_data;
        if(this == &source){
            return *this;
        }
        if(capacity != source.capacity){
            new_data = new string[source.capacity];
            delete []data;
            data = new_data;
            capacity = source.capacity;
        }
        used = source.used;
        copy(source.data, source.data + used, data);
    }

    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }
    
}

