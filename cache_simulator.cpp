#include <iostream>
#include <vector>

class CacheSimulator {
    int cacheSize;
    std::vector<int> cache;

public:
    CacheSimulator(int size) : cacheSize(size), cache(size, -1) {}

    bool access(int address) {
        int index = address % cacheSize;
        if (cache[index] == address) {
            return true; // Hit
        } else {
            cache[index] = address; // Miss, load into cache
            return false;
        }
    }
};

int main() {
    CacheSimulator cache(4); // 4-line cache for simplicity

    int addresses[] = {0, 4, 1, 4, 2, 4, 3, 4, 0};

    for (int addr : addresses) {
        if (cache.access(addr)) {
            std::cout << "Address " << addr << " is a hit." << std::endl;
        } else {
            std::cout << "Address " << addr << " is a miss." << std::endl;
        }
    }

    return 0;
}

