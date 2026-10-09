#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;

    // 从前到后：最久未使用 -> 最近使用
    list<pair<int, int>> cache;

    // key -> 该元素在链表中的位置
    unordered_map<int, list<pair<int, int>>::iterator> positions;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = positions.find(key);
        if (it == positions.end()) {
            return -1;
        }

        // 找到了：移到末尾，表示刚刚使用过
        cache.splice(cache.end(), cache, it->second);
        return it->second->second;  // pair 的 second 是 value
    }

    void put(int key, int value) {
        auto it = positions.find(key);

        if (it != positions.end()) {
            // 已存在：更新值，并移到末尾
            it->second->second = value;
            cache.splice(cache.end(), cache, it->second);
            return;
        }

        if (static_cast<int>(cache.size()) == capacity) {
            // 链表开头就是最久未使用的元素
            int oldKey = cache.front().first;
            positions.erase(oldKey);
            cache.pop_front();
        }

        cache.emplace_back(key, value);
        positions[key] = prev(cache.end());
    }
};