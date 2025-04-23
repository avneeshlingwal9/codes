#include <bits/stdc++.h>
#include <deque>
using namespace std;
typedef pair<int, int> P;
typedef list<P> DLL;
class LFUCache
{
public:
    DLL dl;
    unordered_map<int, pair<DLL::iterator, int>> keymap;
    map<int, deque<DLL::iterator>> freqmap;
    int n;
    LFUCache(int capacity)
    {

        n = capacity;
    }
    void update(int key)
    {

        auto it = keymap[key].first;
        // Updating the frequency
        int currfreq = it->second;

        if (freqmap[currfreq].size() == 1)
        {
            freqmap.erase(currfreq);
        }
        else
        {
            auto toer = remove(freqmap[currfreq].begin(), freqmap[currfreq].end(), it);
            
            freqmap[currfreq].erase(toer);
        }

        it->second = currfreq + 1;
        freqmap[it->second].push_back(it);
    }

    int get(int key)
    {

        if (keymap.find(key) == keymap.end())
        {
            return -1;
        }

        update(key);
        return keymap[key].second;
    }

    void put(int key, int value)
    {

        // If already exist just update frequency and value.
        if (keymap.find(key) != keymap.end())
        {
            keymap[key].second = value;
            update(key);
            return;
        }
        // Insert the new key.
        else if(n == 0)
        {
            
            

                auto it = freqmap.begin()->second;
                auto todelete = it.front();

                it.pop_front();
                int value = todelete->first;
                keymap.erase(value);
                dl.erase(todelete);
                if (it.size() == 0)
                {
                    freqmap.erase(freqmap.begin());
                }
                n++;
            
        }

        

            dl.push_front({key, 1});
            keymap[key] = {dl.begin(), value};
            freqmap[1].push_back(dl.begin());
            n--;
        
        // After insertion of new key, then delete LFU, if tie, then LRU.

    }
};
int main(){

    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache lfu(2);
    lfu.put(1, 1); // cache=[1,_], cnt(1)=1
    lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);    // return 1
                   // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3); // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                   // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);    // return -1 (not found)
    lfu.get(3);    // return 3
                   // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4); // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                   // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);    // return -1 (not found)
    lfu.get(3);    // return 3
                   // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);    // return 4
                   // cache=[4,3], cnt(4)=2, cnt(3)=3
}