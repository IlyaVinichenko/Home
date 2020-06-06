#include <iostream>
#include "hashtable.h"
#include <string>

using namespace std;

int main(){
    Hashtable table(10);
    record new_record;

    new_record.id=1000;
    new_record.model ="Toyota";
    new_record.owner= "Vasya";

    int S =

    for (int i = 1; i < S; i++){
        cout <<"ADD | "<< new_record.id << endl;
        table.add(new_record);
        new_record.id += 10;
        new_record.model[0] += 1;
        new_record.owner[0] += 1;
    }
    
    cout << endl;
    table.print();

    for (int i = 0; i < S; i++){
        table.remove(new_record);
        new_record.id -= 10;
        new_record.model[0] -= 1;
        new_record.owner[0] -= 1;

    }
    
    cout << endl;
    table.print();
}