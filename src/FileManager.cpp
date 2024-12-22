#include "FileManager.h"

FileManager::FileManager(const string& filename) : filename(filename) {}

void FileManager::appendRecord(const std::string& record) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << record << "\n";
    }
    file.close();
}

string FileManager::getRecordAt(size_t offset) {
   ifstream file(filename);

   // if the file is open
    if (file.is_open()) {
        file.seekg(offset);
        string record;
        getline(file, record);
        file.close();
        return record;
    }

    // if the file is closed !!
    return "";
}

void FileManager::rewriteFile(const vector<string>& allRecords) {
    ofstream file(filename, ios::trunc);
    if (file.is_open()) {
        for (const auto& record : allRecords) {
            file << record << "\n";
        }
    }
    file.close();
}