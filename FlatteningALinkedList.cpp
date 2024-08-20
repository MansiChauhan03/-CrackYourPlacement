Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL; // Since we're flattening, there should be no `next` pointers
    return result;
}

Node *flatten(Node *root) {
    if (!root || !root->next)
        return root;

    // Recursively flatten the next linked list
    root->next = flatten(root->next);

    // Merge the current list with the flattened next list
    root = merge(root, root->next);

    return root;
}
