
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct BST {
    Node* root = nullptr;
    int size = 0;

    // TODO: Cài đặt hàm chèn phần tử x
    void insert(int x) {
        if (root==NULL) {
            root=new Node(x);
            size++;
            return;
        }

        Node* p = root;
        Node* pre= NULL;
        while(p) {
            if (x < p->data) {
                pre=p;
                p=p->left;
            }
            else if (x>p->data) {
                pre=p;
                p=p->right;
            }
            else {
                return ;
            }
        }
        if (x < pre->data) {
            pre->left = new Node(x);
        }
        else pre->right = new Node(x);
        size++;
    }

    // TODO: Cài đặt hàm tìm kiếm x, trả về true/false
    bool search(int x) {
       if (root == NULL) return false;
       Node*p = root;
       while(p) {
        if (x < p->data) {
            p=p->left;
        }
        else if (x > p->data) p=p->right;
        else return true;
       }
        return false;
    }
    Node* remove_tree(Node* node , int x , bool &removed) {
        if (node==NULL) return NULL;
        if (x<node->data) node->left = remove_tree(node->left,x,removed);
        else if (x > node->data) node->right = remove_tree(node->right,x,removed);
        else {
            removed=true;
            if (node->left!=NULL && node->right!=NULL) {
                Node*p=node->right;
                while(p->left) p = p->left;
                node->data=p->data;
                node->right = remove_tree(node->right,p->data,removed);

                return node;
            }
            else if (node->left) {
                Node* temp = node->left;
                delete node;
                node=NULL;
                return temp;
            }
            else if (node->right ) {
                Node* temp = node->right;
                delete node;
                node=NULL;
                return temp;
            }
            else {
                delete node;
                node=NULL;
                return NULL;
            }
        }
        return node;
    }

    // TODO: Cài đặt hàm xóa phần tử x
    void remove(int x) {
        bool removed = false;
        root=remove_tree(root,x,removed);
        if (removed) size--;
    }

    // TODO: Tính chiều cao của cây
    int getHeight(Node* node) {
        if (node==NULL) return -1 ;
        return max(getHeight(node->left),getHeight(node->right))+1;

    }

    // TODO: Duyệt In-order
    void inOrder(Node* node, vector<int>& res) {
        if (node==NULL) return;
        inOrder(node->left,res);
        res.push_back(node->data);
        inOrder(node->right,res);
        
    }

    // TODO: Duyệt Pre-order
    void preOrder(Node* node, vector<int>& res) {
        if (node==NULL) return;
        res.push_back(node->data);
        preOrder(node->left,res);
        preOrder(node->right,res);
    }

    // TODO: Duyệt Post-order
    void postOrder(Node* node, vector<int>& res) {
         if (node==NULL) return;
        postOrder(node->left,res);
        postOrder(node->right,res);
        res.push_back(node->data);
    }

    // TODO: Tìm giá trị trong cây gần x nhất
    int findClosest(int x) {
        if (root == NULL) return 0;

        int ans = root->data;
       Node*p = root;
       while(p) {

        if (abs(p->data-x) < abs(ans-x) || (abs(p->data-x) == abs(ans-x) && p->data > ans)) ans =p->data;
        if (x < p->data) {
            p=p->left;
        }
        else if (x > p->data) p=p->right;
        else return ans;
       }
        return ans;
    }

    // Helper function để gọi từ main
    void printOrder(int type) {
        vector<int> res;
        if (type == 5) inOrder(root, res);
        else if (type == 6) preOrder(root, res);
        else if (type == 7) postOrder(root, res);
        
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    BST tree;

    while (Q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            tree.insert(x);
        } else if (type == 2) {
            cin >> x;
            cout << (tree.search(x) ? "Yes" : "No") << "\n";
        } else if (type == 3) {
            cin >> x;
            tree.remove(x);
        } else if (type == 4) {
            cout << tree.getHeight(tree.root) << "\n";
        } else if (type >= 5 && type <= 7) {
            tree.printOrder(type);
        } else if (type == 8) {
            cin >> x;
            if (tree.root) cout << tree.findClosest(x) << "\n";
        } else if (type == 9) {
            cout << tree.size << "\n";
        }
    }
    return 0;
}
