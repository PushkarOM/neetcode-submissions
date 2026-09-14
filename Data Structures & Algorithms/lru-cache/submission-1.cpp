struct ListNodeDouble {
    int key;
    int val;

    ListNodeDouble* next;
    ListNodeDouble* prev;

    ListNodeDouble(int k, int v)
        : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    
    int capacity;
    int currCapacity;

    unordered_map<int, ListNodeDouble*> mp;

    ListNodeDouble* head;
    ListNodeDouble* tail;

    LRUCache(int capacity) {
        
        this->capacity = capacity;
        currCapacity = 0;
        head = new ListNodeDouble(-1,-1);
        tail = new ListNodeDouble(-1,-1);

        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        
        ListNodeDouble* temp = mp[key];

        remove(temp);
        insertAtTail(temp);

        return temp->val;
    }
    
    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            ListNodeDouble* temp = mp[key];

            temp->val = value;

            remove(temp);
            insertAtTail(temp);

            return;
        }

        // Cache is full
        if (currCapacity == capacity) {
            ListNodeDouble* lru = head->next;

            mp.erase(lru->key);
            remove(lru);
            delete lru;

            currCapacity--;
        }

        // Add new node
        ListNodeDouble* temp = new ListNodeDouble(key, value);

        mp[key] = temp;
        insertAtTail(temp);

        currCapacity++;
    }

    void remove(ListNodeDouble* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtTail(ListNodeDouble* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
    

};
