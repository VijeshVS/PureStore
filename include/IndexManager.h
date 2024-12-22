#ifndef INDEXMANAGER_H
#define INDEXMANAGER_H

#include <string>
#include <unordered_map>

using namespace std;

class IndexManager {
public:
    void addIndex(int key, size_t offset);
    size_t getOffset(int key);
    void removeIndex(int key);

private:
    unordered_map<int, size_t> indexMap;
};

#endif
