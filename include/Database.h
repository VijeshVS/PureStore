#ifndef DATABASE_H
#define DATABASE_H

#include "FileManager.h"
#include "IndexManager.h"
#include <string>

using namespace std;

struct Field {
    string type; // int,number,string
    string name;
};

using Schema = vector<Field>;

class Database {
public:
    Database(const string& filename,const Schema& schema);
    void insert(int id, const string& name, int age);
    string retrieve(int id);
    void deleteRecord(int id);
    Schema getSchema() const { return schema; } // similar to view in solidity
private:
    FileManager fileManager;
    IndexManager indexManager;
    Schema schema;
};

#endif
