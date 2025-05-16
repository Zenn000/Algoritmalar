#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return current->isEndOfWord;
}

int main() {
    TrieNode *root = createNode();
    insert(root, "apple");
    insert(root, "app");
    
    printf("'app' var mı? %s\n", search(root, "app") ? "Evet" : "Hayır");
    printf("'orange' var mı? %s\n", search(root, "orange") ? "Evet" : "Hayır");
    return 0;
}
