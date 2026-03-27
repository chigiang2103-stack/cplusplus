#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

struct AVLTree {
    Node* root = nullptr;

    // Lay chieu cao cua nut
    int height(Node *N) {
        if (N == nullptr) return 0;
        return N->height;
    }
    void update_height(Node* node) {
        if (!node) return;
        node->height = max(height(node->left),height(node->right))+1;
    }
    // TODO: Thuc hien xoay phai cay con goc y
    Node* rightRotate(Node* y) {
        if (y->left ==NULL) return y;
   Node* L =y->left;
   Node* R = y->right;
    Node* rL = L->right;
    L->right=y;
    y->left = rL;
    update_height(y);
    update_height(L);
    return L;
    }

    // TODO: Thuc hien xoay trai cay con goc x
    Node* leftRotate(Node* x) {
       if (x->right == NULL) return x;
 
    Node* L = x->left;
    Node* R = x->right;
    Node* lR = R->left;
 
    R->left=x;
    x->right = lR;
    update_height(x);
    update_height(R);
    return R;
    }


    // Lay he so can bang (Balance Factor)
    int getBalance(Node *N) {
        if (!N) return 0;
        return height(N->left) - height(N->right);
    }
    void fix_node(Node* & node) {
        if (getBalance(node) > 1) {
            if (getBalance(node->left) >= 0) node=rightRotate(node);
            else {
                node->left=leftRotate(node->left);
                node = rightRotate(node);
            }
        }

        if (getBalance(node) < -1) {
            if(getBalance(node->right) <=0) node= leftRotate(node);
            else {
                node->right=rightRotate(node->right);
                node= leftRotate(node);
            }
        }





    }

    // TODO: Ham chen nut vao cay AVL (Recursive)
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    update_height(node);
    fix_node(node);

    return node;
}

    // TODO: Ham xoa nut khoi cay AVL (Recursive)
      Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;
 
        if (key < node->key) node->left = deleteNode(node->left, key);
        else if (key > node->key) node->right = deleteNode(node->right, key);
        else {

            if (node->left && node->right) {
                Node *p = node->right;
                while (p->left) p = p->left;
                node->key = p->key;
                node->right = deleteNode(node->right, p->key);

                update_height(node);
                fix_node(node);
                                                                            
                return node;
            } else if (node->left) {
                Node *tmp = node->left;
                delete node;
                node = nullptr;
                return tmp;
            } else if (node->right) {
                Node *tmp = node->right;
                delete node;
                node = nullptr;
                return tmp;
            } else {
                delete node;
                node = nullptr;
                return nullptr;
            }
        }
           update_height(node);
        fix_node(node);
 
        return node;
      }


    // Duyet tien thu tu
    void preOrder(Node *node, bool &first) {
        if (node != nullptr) {
            if (!first) cout << " ";
            cout << node->key;
            first = false;
            preOrder(node->left, first);
            preOrder(node->right, first);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;
    
    AVLTree tree;
    while (Q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) tree.root = tree.insert(tree.root, v);
        else tree.root = tree.deleteNode(tree.root, v);
    }

    bool first = true;
    tree.preOrder(tree.root, first);
    cout << endl;

    return 0;
}