#include "hashtable.h"
#include <iostream>
#include <cmath>

Hashtable::Hashtable(unsigned int _size = 10){
    ratio = 0.6;
    if (_size < 10){
        _size = 10;
    }
    size = _size;
    table = new struct record[size];
    status = new bool[size];
    for (int i = 0; i < size; i++){
        status[i] = false;                                                          // array occupancy status
    }
}

Hashtable::~Hashtable(){
    delete[] table;
    delete[] status;
}

unsigned int Hashtable::hash_function(record new_record){ 
    return new_record.id % size;
}

unsigned int Hashtable::hash_function2(unsigned int key, short int q){
    return int(key + pow(2, q)) % size;                                                          // square hash function
}

void Hashtable::rehash(){
    for (int i = 0; i < size; i++){
        if (status[i] == true){
           unsigned int key = hash_function(table[i]);
           if (key != i){
               if (status[key] == false){
                   table[key].id = table[i].id;
                   table[key].model = table[i].model;
                   table[key].owner = table[i].owner;
                   status[key] = true;
                   status[i] = false;
                   break;
               }
               else{
                   for (int q = 0; q < size; q++){
                       unsigned int key2 = hash_function2(key, q);
                       if (table[key2].id == table[i].id){
                           q = size;
                       }
                       else{
                           if (status[key2] == false){
                               table[key2].id = table[i].id;
                               table[key2].model = table[i].model;
                               table[key2].owner = table[i].owner;
                               status[key2] = true;
                               status[i] = false;
                               break;
                           }
                       }
                   }
               }
           } 
        }
    }
}

bool Hashtable::add(record new_record){
    if (count_ratio(size) > ratio){
        //std::cout<<"Rehash "<<size<<' '<<count_ratio(size)<<' '<<ratio <<std::endl;
        increase_size();
        rehash();
    }
        unsigned int hash_key = hash_function(new_record);
        if (status[hash_key] == false){
            table[hash_key].id = new_record.id;
            table[hash_key].model = new_record.model;
            table[hash_key].owner = new_record.owner;
            status[hash_key] = true;
        }
        else{
             for (int q = 0; q < size; q++){
                unsigned int hash_key2 = hash_function2(hash_key, q);
               // std::cout << "status1:  " << status[hash_key2] << std::endl;
                // std::cout << "hash key2:  " << hash_key2 << " | "<< "q: " << q << std::endl;
                if (status[hash_key2] == false){
                    table[hash_key2].id = new_record.id;
                    table[hash_key2].model = new_record.model;
                    table[hash_key2].owner = new_record.owner;
                    status[hash_key2] = true;
                    return true;
                }
            }
            // block if hash can't add record
            // std:: cout <<"hashcant" << std::endl;
            increase_size();
            rehash();
           // print();
            for (int q = 0; q < size; q++){
                //std::cout << "for cycle" << std::endl;
                unsigned int hash_key2 = hash_function2(hash_key, q);
                // std::cout << "status:  " << status[hash_key2] << std::endl;
                //std::cout << "hash key2:  " << hash_key2 << " | "<< "q: " << q << std::endl;
                if (status[hash_key2] == false){
                    table[hash_key2].id = new_record.id;
                    table[hash_key2].model = new_record.model;
                    table[hash_key2].owner = new_record.owner;
                    status[hash_key2] = true;
                    return true; 
                }
            }

        }
} 

/*            for (int q = 0; q < size; q++){
                unsigned int hash_key2 = hash_function2(hash_key, q);
                if (status[hash_key2] == false){
                    table[hash_key2].id = new_record.id;
                    table[hash_key2].model = new_record.model;
                    table[hash_key2].owner = new_record.owner;
                    status[hash_key2] = true;
                    return true;
*/                    

double Hashtable::count_ratio(int size){
    double record_present = 0;
    for (int i = 0; i < size; i++){
        if (status[i] == true){
            record_present++;
        }
    }
    return (double(record_present / size));
}

bool Hashtable::remove(record new_record){
    int key = search(new_record);
    if (status[key] == false){
        return there_is_no_record;
    }
    status[key] = false;
    if (count_ratio(size) < ratio && size > 10){
        reduce_size();
    }
    else{
        rehash();
    }
}

unsigned int Hashtable::search(record new_record){
    unsigned int key = hash_function(new_record);
    if (status[key] == true){
        if ((table[key].id = new_record.id) && (table[key].model == new_record.model) && (table[key].owner == new_record.owner)){
            return key;
        }
    }
    else{
        for (int q = 0; q < size; q++){
            unsigned int key2 = hash_function2(key, q);
            if (status[key2] == true){
                if (table[key2].id == new_record.id){
                    return key2;
                }
            }
        }

    }
}

void Hashtable::increase_size(){
    struct record *new_table = new struct record[size * 2];
    bool *new_status = new bool[size * 2];
    for (int i = 0; i < size; i++){
        new_table[i] = table[i];
        new_status[i] = status[i];
    }
    delete[] table;
    table = new_table;
    delete[] status;
    status = new_status;
    size = size * 2;
}

void Hashtable::reduce_size(){
    struct record *new_table2 = new struct record[size / 2];
    bool *new_status2 = new bool[size / 2];
    for (int i = 0; i < size / 2; i++){
        new_table2[i] = table[i];
        new_status2[i] = status[i];
    }
    delete[] table;
    table = new_table2;
    delete[] status;
    status = new_status2;
    size = size / 2;
}

void Hashtable::print(){
    std::cout << "Parking places" << std::endl;
    for (int i = 0; i < size; i++){
        if (status[i] == true){
            std::cout << "№ " << i << " | "<< "id: " << table[i].id << " | "<< "owner: " << table[i].owner << " | "<< "model: " << table[i].model << std::endl;
        }
        else{
             std::cout << "№ " << i << " | " << "! There is no car here !" << std::endl;
        }
    }
}