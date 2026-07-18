#include <unordered_map>
using namespace std;

struct Node {
    int key, value, cnt;
    Node* prev;
    Node* next;
    
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        prev = nullptr;
        next = nullptr;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void removeNode(Node* delnode) {
        Node* prevNode = delnode->prev;
        Node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    
    ~List() {
        delete head;
        delete tail;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSize;
    int minFreq;
    int cursize;

    void update(Node* node) {
        freqListMap[node->cnt]->removeNode(node);
        
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }
        
        List* nextHigherFreq;
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreq = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreq = new List();
            freqListMap[node->cnt + 1] = nextHigherFreq;
        }
        
        node->cnt += 1;
        nextHigherFreq->addFront(node);
    }

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        cursize = 0;
    }
    
    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            update(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSize == 0) return;
        
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            update(node);
        } else {
            if (cursize == maxSize) {
                List* list = freqListMap[minFreq];
                Node* nodeToDelete = list->tail->prev;
                
                keyNode.erase(nodeToDelete->key);
                list->removeNode(nodeToDelete);
                delete nodeToDelete;
                cursize--;
            }
            
            cursize++;
            minFreq = 1;
            
            List* listFreq;
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }
            
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */