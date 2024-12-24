#include "Database.h"
#include <sstream>

Database::Database(const string &filename, const Schema &schema) : fileManager(filename), schema(schema) {}

void Database::insert(int id, const string &name, int age)
{
    ostringstream recordStream;
    recordStream << id << "|" << name << "|" << age;
    string record = recordStream.str();

    ifstream file(fileManager.getFilename(), ios::ate); // Open in append mode
    size_t offset = file.tellg();
    file.close();

    fileManager.appendRecord(record);
    indexManager.addIndex(id, offset);
}

string Database::retrieve(int id)
{
    size_t offset = indexManager.getOffset(id);
    if (offset == (size_t)-1)
    {
        return "Record not found";
    }
    return fileManager.getRecordAt(offset);
}

void Database::deleteRecord(int id)
{
    size_t offset = indexManager.getOffset(id);
    if (offset == (size_t)-1)
    {
        return; // Record not found
    }
    indexManager.removeIndex(id);
}
