#include <iostream>

using namespace std;

#define SPACE 10

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        this->val = 0;
        left = right = nullptr;
    }

    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

class AVLTree
{
public:
    TreeNode *root;

    AVLTree()
    {
        root = nullptr;
    }

    bool isTreeEmpty()
    {
        if (root == nullptr)
        {
            return true;
        }
        return false;
    }

    int height(TreeNode *r)
    {
        if (r == nullptr)
        {
            return -1;
        }
        else
        {
            int lHeight = height(r->left);
            int rHeight = height(r->right);

            if (lHeight > rHeight)
            {
                return (lHeight + 1);
            }
            else
            {
                return (rHeight + 1);
            }
        }
    }

    int getBalancingFactor(TreeNode *r)
    {
        if (r == nullptr)
        {
            return -1;
        }
        else
        {
            return height(r->left) - height(r->right);
        }
    }

    TreeNode *rightRotate(TreeNode *x)
    {
        TreeNode *y = x->left;
        TreeNode *z = y->right;

        y->right = x;
        x->left = z;
        return y;
    }

    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *z = y->left;

        y->left = x;
        x->right = z;
        return y;
    }

    TreeNode *insertion(TreeNode *r, TreeNode *newNode)
    {
        if (r == nullptr)
        {
            r = newNode;
            return r;
        }
        if (newNode->val < r->val)
        {
            r->left = insertion(r->left, newNode);
        }
        else if (newNode->val > r->val)
        {
            r->right = insertion(r->right, newNode);
        }
        else
        {
            cout << "No Duplicate Value Allow!" << endl;
            return r;
        }

        // now checking for balancing factor and balancing the tree
        int bf = getBalancingFactor(r);

        // left-left case
        if (bf > 1 && newNode->val < r->left->val)
        {
            return rightRotate(r);
        }

        // right-right case
        if (bf < -1 && newNode->val > r->right->val)
        {
            return leftRotate(r);
        }

        // left-right case
        if (bf > 1 && newNode->val > r->left->val)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // right-left case
        if (bf < -1 && newNode->val < r->left->val)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == nullptr)
        {
            return;
        }
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << r->val << "\n";
        print2D(r->left, space);
    }

    void printInorder(TreeNode *r)
    {
        if (r == nullptr)
        {
            return;
        }
        printInorder(r->left);
        cout << r->val << endl;
        printInorder(r->right);
    }

    TreeNode *minValueNode(TreeNode *r){
        TreeNode *current = r;
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode *r, int val)
    {
        if (r == nullptr)
        {
            return nullptr;
        }
        else if (val < r->val)
        {
            r->left = deleteNode(r->left, val);
        }
        else if (val > r->val)
        {
            r->right = deleteNode(r->right,val);
        }
        else
        {
            //Node with only one child at right
            if(r->left == nullptr){
                TreeNode *temp = r->right;
                delete r;
                return temp; 
            }
            //Node With only one child at left
            else if(r->right == nullptr){
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            //Node with two child
            else{
                TreeNode *temp = minValueNode(r->right);
                r->val = temp->val;
                r->right = deleteNode(r->right,temp->val);
            }
        }

        int bf = getBalancingFactor(r);

        // case 1-ll imbalance,Right rotation
        if (bf == 2 && getBalancingFactor(r->left) >= 0)
        {
            return rightRotate(r);
        }

        // case 2-LR imbalance,LR Rotation required
        else if (bf == 2 && getBalancingFactor(r->left) == -1)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // case 3-RR imbalance,LL rotation
        else if (bf == -2 && getBalancingFactor(r->right) <= 0)
        {
            return leftRotate(r);
        }

        // case 4-RL imabalance.RL rotation needed
        else if (bf == -2 && getBalancingFactor(r->right) == 1)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }
};

int main()
{
    AVLTree obj;
    TreeNode *newNode = new TreeNode(12);
    TreeNode *newNode1 = new TreeNode(13);
    TreeNode *newNode2 = new TreeNode(15);
    TreeNode *newNode3 = new TreeNode(123);
    TreeNode *newNode4 = new TreeNode(163);
    TreeNode *newNode5 = new TreeNode(167);

    obj.root = obj.insertion(obj.root, newNode);
    obj.root = obj.insertion(obj.root, newNode1);
    obj.root = obj.insertion(obj.root, newNode2);
    obj.root = obj.insertion(obj.root, newNode3);
    obj.root = obj.insertion(obj.root, newNode4);
    obj.root = obj.insertion(obj.root, newNode5);
    // obj.root = obj.deleteNode(obj.root,167);
    // obj.root = obj.deleteNode(obj.root,15);
    // obj.root = obj.deleteNode(obj.root,163);
    // obj.root = obj.deleteNode(obj.root,123);
    // obj.root = obj.deleteNode(obj.root,13);
    // obj.root = obj.deleteNode(obj.root,12);
    // obj.root = obj.deleteNode(obj.root,167);
    // obj.root = obj.deleteNode(obj.root,167);
    // obj.print2D(obj.root,4);
    obj.print2D(obj.root, 5);
}