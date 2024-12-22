#include "Database.h"
#include <sstream>

Database::Database(const std::string& filename) : fileManager(filename) {}

void Database::insert(int id, const string& name, int age) {
    std::ostringstream recordStream;
    recordStream << id << "|" << name << "|" << age;
    std::string record = recordStream.str();

    std::ifstream file(fileManager.getFilename(), std::ios::ate); // Open in append mode
    size_t offset = file.tellg();
    file.close();

    fileManager.appendRecord(record);
    indexManager.addIndex(id, offset);
}

std::string Database::retrieve(int id) {
    size_t offset = indexManager.getOffset(id);
    if (offset == (size_t)-1) {
        return "Record not found";
    }
    return fileManager.getRecordAt(offset);
}

void Database::deleteRecord(int id) {
    size_t offset = indexManager.getOffset(id);
    if (offset == (size_t)-1) {
        return; // Record not found
    }
    indexManager.removeIndex(id);
}
