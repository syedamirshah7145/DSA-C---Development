#include <iostream>

using namespace std;

int count = 1;

struct Node {
    int data;
    Node *left;
    Node *right;
};

// Completed using recursion
Node* insert(Node *root,int data){
    if(root == nullptr){
        Node* newBST = new Node;
        newBST->left = newBST->right = nullptr;
        newBST->data = data;
        root = newBST;
    }
    else if(data <= root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

// Completed using iterative approach
void insert(Node **root,int data){
    Node *current = new Node;
    current->left = current->right = nullptr;
    current->data = data;
    if((*root) == nullptr){
        (*root) = current;
    }
    else{
        Node *p1 = (*root);
        Node *p2 = nullptr;
        while(p1 != nullptr){
            p2 = p1;
            if(current->data > p2->data){
                p1 = p1->right;
            }
            else{
                p1 = p1->left;
            }
        }
        if(current->data > p2->data){
            p2->right = current;
        }
        else{
            p2->left = current;
        }
    }
}

Node* search(Node *root,int key){
    Node *p = root;
    while(p != nullptr && p->data != key){
        if(key > p->data){
            p = p->right;
        }
        else{
            p = p->left;
        }
    }
    return p;
}

void printPreorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<endl;
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root){
    if(root == nullptr){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<endl;
    printInorder(root->right);
}

void printPostorder(Node *root){
    if(root == nullptr){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<endl;
}

// Finding minimum
Node* min(Node *root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

// Finding Maximum
Node *max(Node *root){
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

// Deletion using recursion
Node *deleteNode(Node *root, int data){
    if(root == nullptr){
        return root;
    }
    else if(data < root->data){
        root->left = deleteNode(root->left,data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right,data);
    }
    //there you go man, time to let you go
    else{
        //Case-1 with no child easiest
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
        }
        //Case-2 with one child
        else if(root->left == nullptr){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        //Case-3 with two child. ha.........., hardest one but i will broke you with my poetry.Coding is Poetry?
        else{
            Node *temp = min(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}

// int countNodes(Node* root){
//     if(root == nullptr){
//         return 0;
//     }
//     return 1 + countNodes(root->left) + countNodes(root->right);
// }

int countNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    if(root->left != nullptr){
        count = count+1;
        countNodes(root->left);
    }
    if(root->right != nullptr){
        count = count+1;
        countNodes(root->right);
    }
    return count;
}

int countRightNodes(Node *root){
    if(root == nullptr){
        return 0;
    }
    if(root->right != nullptr){
        count = count+1;
        countNodes(root->right);
    }
    return count;
}

int height(Node *root){
    int h = 0;
    if(root != nullptr){
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight+1;
    }
    return h;
}

int main(){
    Node* root = nullptr;
    root = insert(root,12);
    root = insert(root,13);
    root = insert(root,10);
    root = insert(root,123);
    cout<<endl<<countNodes(root)<<endl;
}