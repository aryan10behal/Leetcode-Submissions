class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
        {
            return "";
        }
        if(mp[key].size() == 0)
        {
            return "";
        }
        if(mp[key].find(timestamp) != mp[key].end())
            return mp[key][timestamp];
        auto it = mp[key].lower_bound(timestamp);  
        if (it == mp[key].begin()) 
           {
            if(it->first > timestamp)
                return "";
            return it->second; 
        }
        it--;
        return it->second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */