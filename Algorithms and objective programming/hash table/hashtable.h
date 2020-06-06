#include <string>

enum errors{
    invalid_key, cant_add, record_exists, there_is_no_record
};

struct record{
    unsigned int id;
    std::string model;
    std::string owner;
};

class Hashtable{
    private:
        unsigned int size;                                                      // size of table
        unsigned int volume;                                                    // current size of table
        double ratio;                                                           // ratio of table filling
        struct record *table;                                                   // vector of records
        bool *status;                                                           // status of record
        unsigned int hash_function(record);                                     // hash function 1
        unsigned int hash_function2(unsigned int key, short int q);             // hash function 2
        double count_ratio(int);                                                // count ratio of filling out
        void increase_size();                                                   // increase size of hash table
        void reduce_size();                                                     // reduce size of hash table
        void rehash();                                                          // used to get new hashtable
    public:
        Hashtable(unsigned int);
        ~Hashtable();
        bool add(record);
        bool remove(record);
        unsigned int search(record);
        void print();
};