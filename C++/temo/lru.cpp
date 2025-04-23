#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    deque<pair<int, int>> de;
    unordered_map<int, int> hash;
    int maxi;
    LRUCache(int capacity)
    {

        // Chill.
        maxi = capacity;
    }

    int get(int key) { return hash.find(key) != hash.end()? hash[key] : -1; }

    void put(int key, int value)
    {

        // If already exists then sihashly update.
        if (hash.find(key) != hash.end())
        {
            hash[key] = value;
            cout << key << " " << value;
            return;
        }

        // If it is not there, then check for size, if limit is reached then
        // remove lru.
        if (size(de) == maxi)
        {
            // Setting the first element as -1 ;
            hash[de.front().first] = -1;

            hash[key] = value;
            de.push_back({key, value});
            de.pop_front();
        }
        else
        {
            // Then we add the key.
            de.push_back({key, value});
            hash[key] = value;
        }
    }
};
int main(){
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    cout << l.get(1) << " ";
    l.put(3, 3);
    cout << l.get(2) << " ";
    l.put(4, 4);
    cout << l.get(1) << " ";
    cout << l.get(3) << " ";
    cout << l.get(4) << " ";
}