#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using Letter = std::pair<char, std::string>;

struct Node {
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

    char symbol = 0;

    void addLetter(Letter& letter) {
        std::string& temp = letter.second;
        if (temp == "") {
            symbol = letter.first;
            return;
        }
        Node* node;
        if (temp[0] == '0') {
            if (!left) {
                node = new Node();
                node->parent = this;
                left = node;
            }
            node = left;
        }
        else if (temp[0] == '1') {
            if (!right) {
                node = new Node();
                node->parent = this;
                right = node;
            }
            node = right;
        }
        temp.erase(0, 1);
        node->addLetter(letter);
    }

    char getSymbol(std::string code) {
        if (code == "") {
            return symbol;
        }

        char num = code[0];
        Node* node;
        if (num == '0') {
            node = left;
        }
        else if (num == '1') {
            node = right;
        }
        code.erase(0, 1);
        return node->getSymbol(code);
    }

    ~Node() {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
    }
};

int main(void) {
    int numLetters;
    int lengthString;
    std::cin >> numLetters >> lengthString;

    std::vector<Letter> letters;

    for (int i = 0; i < numLetters; i++) {
        std::string symbol;
        std::string code;
        std::cin >> symbol >> code;
        letters.push_back(std::make_pair(symbol[0], code));
    }

    Node root;
    for (auto &letter : letters) {
        root.addLetter(letter);
    }

    std::string codedString;
    std::cin >> codedString;

    std::string code;
    for (int i = 0; i < lengthString; i++) {
        code += codedString[0];
        codedString.erase(0, 1);
        char s = root.getSymbol(code);
        if (s != 0) {
            std::cout << s;
            code = "";
        }
    }

    std::cout << std::endl;

    return 0;
}
