#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform Breadth-First Search (BFS) on a binary tree
void bfs(struct Node* root) {
    if (root == NULL) return;

    // Create a queue for BFS
    struct Node* queue[100];
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node from the queue
        struct Node* currentNode = queue[front++];

        // Print the data of the current node
        printf("%d ", currentNode->data);

        // Enqueue the left child if it exists
        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }

        // Enqueue the right child if it exists
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform BFS on the binary tree
    printf("Breadth-First Search (BFS) traversal: ");
    bfs(root);
    printf("\n");

    return 0;
}