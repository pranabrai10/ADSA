#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

/* ----------- Utility ----------- */
Node* newNode(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

/* ----------- SPLAY OPERATION ----------- */
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key) {
        if (root->left == NULL)
            return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }

    else {
        if (root->right == NULL)
            return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

/* ----------- SEARCH ----------- */
Node* search(Node* root, int key) {
    return splay(root, key);
}

/* ----------- INSERT ----------- */
Node* insert(Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    root = splay(root, key);

    if (root->key == key)
        return root;

    Node* n = newNode(key);

    if (key < root->key) {
        n->right = root;
        n->left = root->left;
        root->left = NULL;
    } else {
        n->left = root;
        n->right = root->right;
        root->right = NULL;
    }

    return n;
}

/* ----------- DELETE ----------- */
Node* delete(Node* root, int key) {
    if (root == NULL)
        return NULL;

    root = splay(root, key);

    if (root->key != key)
        return root;  // key not found

    Node* temp;
    if (root->left == NULL) {
        temp = root->right;
    } else {
        temp = splay(root->left, key);  // max of left subtree
        temp->right = root->right;
    }

    free(root);
    return temp;
}

/* ----------- TRAVERSALS ----------- */
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

/* ----------- MAIN MENU ----------- */
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n===== SPLAY TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted and splayed.\n");
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                root = search(root, key);
                if (root && root->key == key)
                    printf("Found %d (now at root).\n", key);
                else
                    printf("Not found.\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                printf("Delete operation done.\n");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
