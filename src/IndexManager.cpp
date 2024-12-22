#include "IndexManager.h"

void IndexManager::addIndex(int key, size_t offset) {
    indexMap[key] = offset;
}

size_t IndexManager::getOffset(int key) {
    return indexMap.count(key) ? indexMap[key] : -1;
}

void IndexManager::removeIndex(int key) {
    indexMap.erase(key);
}
