#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


struct Node {
    Node(char letter, int weight) : letter(letter), weight(weight) {}
    Node(Node* node1, Node* node2) {
        node1->parent = this;
        node2->parent = this;
        leftChild = node1;
        rightChild = node2;
        weight = node1->weight + node2->weight;
        letter = 0;
    }

    Node* parent = nullptr;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    int weight;
    char letter;
    std::string code;
};

class PriorityQueue {
    std::vector<Node*> _queue;
public:
    Node* getMinNode() {
        Node* ret = _queue.back();
        _queue.pop_back();
        return ret;
    }

    void addNode(Node* node) {
        _queue.push_back(node);
        for (int i = _queue.size()-1; i >= 0; i--) {
            if (i == 0) {
                _queue[0] = node;
                break;
            }
            if (_queue[i-1]->weight < node->weight) {
                _queue[i] = _queue[i-1];
            }
            else {
                _queue[i] = node;
                break;
            }
        }
    }

    size_t size() { return _queue.size(); }
};

int main(void) {
    PriorityQueue queue;
    std::string s;
    std::cin >> s;

    std::map<const char, int> mLetters;
    for (char c : s) {
        mLetters[c]++;
    }

    std::map<const char, Node*> leaves;
    for (auto &pair : mLetters) {
        Node* n = new Node(pair.first, pair.second);
        leaves[pair.first] = n;
        queue.addNode(n);
    }

    while (queue.size() > 1) {
        Node* node1 = queue.getMinNode();
        Node* node2 = queue.getMinNode();
        Node* newNode = new Node(node1, node2);
        queue.addNode(newNode);
    }

    int length = 0;
    for (auto pair : leaves) {
        Node* node = pair.second;
        Node* temp = node;
        while (temp->parent) {
            Node* parent = temp->parent;
            if (parent->leftChild == temp) {
                node->code += "1";
            }
            else if (parent->rightChild == temp) {
                node->code += "0";
            }
            temp = parent;
        }
        std::reverse(node->code.begin(), node->code.end());
        length += node->code.size() * mLetters[node->letter];
    }

    if (leaves.size() == 1) {
      leaves[s[0]]->code = "0";
      length = s.size();
    }

    std::cout << leaves.size() << " " << length << " ";
    for (auto pair : leaves) {
      std::cout << pair.first << ": " << pair.second->code << " ";
    }

    for (char c : s) {
        std::cout << leaves[c]->code;
    }

    std::cout << std::endl;

    return 0;
}
