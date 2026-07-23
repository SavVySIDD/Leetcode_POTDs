class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {

    int capacity;

    unordered_map<int, Node*> mp;

    Node *head, *tail;

    // Remove a node from DLL
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head
    void insertAfterHead(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if(mp.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insertAfterHead(node);

        mp[key] = node;
    }
};