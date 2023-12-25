#ifndef MAP_H
#define MAP_H

#include <iostream>

template <typename Key, typename Value>
class Map {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const Key& key, const Value& value) {
        if (node == nullptr) {
            return new Node(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;
        }

        return node;
    }

    Node* findNode(Node* node, const Key& key) const {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return findNode(node->left, key);
        } else {
            return findNode(node->right, key);
        }
    }

    void inOrderTraversal(Node* node, std::ostream& os) const {
        if (node != nullptr) {
            inOrderTraversal(node->left, os);
            os << node->key << ": " << node->value << std::endl;
            inOrderTraversal(node->right, os);
        }
    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    Node* copyTree(const Node* otherNode) {
        if (otherNode == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(otherNode->key, otherNode->value);
        newNode->left = copyTree(otherNode->left);
        newNode->right = copyTree(otherNode->right);

        return newNode;
    }

public:
    Map() : root(nullptr) {}

    ~Map() {
        deleteTree(root);
    }

    void add(const Key& key, const Value& value) {
        root = insert(root, key, value);
    }

    Value* find(const Key& key) {
        Node* foundNode = findNode(root, key);
        if (foundNode != nullptr) {
            return &foundNode->value;
        }
        return nullptr;
    }

    Map(const Map& other) : root(nullptr) {
        root = copyTree(other.root);
    }

    Map& operator=(const Map& other) {
        if (this != &other) {
            deleteTree(root);
            root = copyTree(other.root);
        }
        return *this;
    }

    bool remove(const Key& key) {
        root = removeNode(root, key);
        return true;
    }

    bool contains(const Key& key) const {
        return findNode(root, key) != nullptr;
    }

    size_t size() const {
        return countNodes(root);
    }

    friend std::ostream& operator<<(std::ostream& os, const Map<Key, Value>& map) {
        map.inOrderTraversal(map.root, os);
        return os;
    }
};


#endif
