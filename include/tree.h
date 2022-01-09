#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree {
public:
    struct Node {
        T value;
        Node *parent;
        Node *left;
        Node *right;
        Node(const T &value): value(value), parent(nullptr), left(nullptr), right(nullptr) {}
    };
    Tree(): root(nullptr) {}

    void insert(T value) {
        insert(value, &root);
    }
    void remove(Node *node) {
        // Room for balancing in this step
        // For now, choosing the new child arbitrarily
    }
    void traverse(void (*func)(Node *n)) {
        traverse(func, root);
    }

    template <typename State>
    State accumulate(State (*func)(Node *n, State state), State initial) {
        return accumulate<State>(func, root, initial);
    }

    Node *root;
private:
    void insert(T value, Node **parent) {
        if (!(*parent)) {
            *parent = new Node(value);
        } else {
            if ((*parent)->value >= value) {
                insert(value, &(*parent)->left);
            } else {
                insert(value, &(*parent)->right);
            }
        }
    };

    void traverse(void (*func)(Node *n), Node *parent) {
        if (parent) {
            traverse(func, parent->left);
            func(parent);
            traverse(func, parent->right);
        }
    }

    template <typename State>
    State accumulate(State (*func)(Node *n, State state), Node *parent, State state) {
        if (parent) {
            state = accumulate<State>(func, parent->left, state);
            state = func(parent, state);
            state = accumulate<State>(func, parent->right, state);
        }
        return state;
    }
};

#endif
