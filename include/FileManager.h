// Simple file based storage system

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileManager {
    public: 
        FileManager(const string& filename);
        void appendRecord(const string& record);
        string getRecordAt(size_t offset);
        void rewriteFile(const vector<string>& allRecords);
        string getFilename() const;
        
    private:
        string filename;
};

#endif