#ifndef DATABASE_H
#define DATABASE_H

#include "FileManager.h"
#include "IndexManager.h"
#include <string>

using namespace std;

class Database {
public:
    Database(const string& filename);
    void insert(int id, const string& name, int age);
    string retrieve(int id);
    void deleteRecord(int id);

private:
    FileManager fileManager;
    IndexManager indexManager;
};

#endif
