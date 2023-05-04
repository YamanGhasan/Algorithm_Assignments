 
#include <iostream>
#include <cassert>
using namespace std;
struct binaryTreeNode {
    int info;
    binaryTreeNode* llink;
    binaryTreeNode* rlink;
};
class BinaryTree {
public :
    void inorderTraversal()const;
    BinaryTree();
protected:
    binaryTreeNode* root;
private:
    void inorder(binaryTreeNode* p) const;
};
void BinaryTree::inorderTraversal() const {
    inorder(root);
}
void BinaryTree::inorder(binaryTreeNode* p) const {
    if (p != 0) {
        inorder(p->llink);
        cout<< p->info;
        inorder(p->rlink);
    }
}
BinaryTree::BinaryTree()
{
    root = NULL;
}
class binarysearchtree :public BinaryTree {
public:
    bool search(const int& searchitem) const;
    void insert(const int& insertitem);
    void deleteNode(const int& deleteitem);
private:
    void deletefromTree(binaryTreeNode*& p);

};
void binarysearchtree::insert(const int& insertitem) {
    binaryTreeNode* curr;
    binaryTreeNode* trailCurrent=NULL;
    binaryTreeNode* newnode;
    newnode = new binaryTreeNode;
    assert(newnode != NULL);
    newnode->info = insertitem;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    if (root == NULL)
        root = newnode;
    else {
        curr = root;

        while (curr != NULL)
        {
            trailCurrent = curr;
            if (curr->info == insertitem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed."
                    << insertitem << endl;
                return;
            }
            else if (curr->info > insertitem)
                curr = curr->llink;
            else
                curr = curr->rlink;
        }//end while
        if (trailCurrent->info > insertitem) {
            trailCurrent->llink = newnode;
        }
        else {
            trailCurrent->rlink = newnode;
        }
    }
}//end insert

bool binarysearchtree::search(const int& searchitem) const {
    binaryTreeNode* current;
    bool found = false;
    if (root == NULL)
        cerr << "Cannot search the empty tree." << endl;
    else
    {
        current = root;
        while (current != NULL && !found)
        {
            if (current->info == searchitem)
                found = true;
            else if (current->info > searchitem)
                current = current->llink;
            else
                current = current->rlink;
        }//end while
    }//end else
    return found;
}//end search

void binarysearchtree::deleteNode(const int& deleteitem) {
    binaryTreeNode* current;
    binaryTreeNode* trailcurrent;
    bool found = false;
    if (root == NULL)
        cout << "can not delete from empty tree";
    else {
        current = root;
        trailcurrent = root;
        while (current != NULL && !found) {
            if (current->info == deleteitem)
                found = true;
            else
                trailcurrent = current;
            if (current->info > deleteitem)
                current = current->llink;
            else
                current = current->rlink;
        }
        if (current == NULL) cerr << "The delete item is not in the tree";
        else if (found) {
            if (current == root)
                deletefromTree(root);

            else if (trailcurrent->info > deleteitem)
                deletefromTree(trailcurrent->llink);
            else
                deletefromTree(trailcurrent->rlink);
        }
    }
}


void binarysearchtree::deletefromTree(binaryTreeNode * &p){
        binaryTreeNode* current;
        binaryTreeNode* trailcurrent;
        binaryTreeNode* temp;
        if (p == NULL) cerr << "Error: The node to de deleted is NULL" << endl;
        else if (p->llink == NULL && p->rlink == NULL) {
            temp = p;
            p = NULL;
            delete temp;

        }
        else if (p->llink == NULL) {
            temp = p;
            p = temp->rlink;
            delete temp;
        }
        else if (p->rlink == NULL) {
            temp = p;
            p = temp->llink;
            delete temp;
        }
        else {
            current = p->llink;
            trailcurrent = NULL;
            while (current->rlink != NULL) {
                trailcurrent = current;
                current = current->rlink;

            }
            p->info = current->info;
            if (trailcurrent == NULL)
                p->llink = current->llink;
            else
                trailcurrent->rlink = current->llink;
            delete current;
        }
        }

     
int main() {

    binarysearchtree myTree;
   
    myTree.insert(80);
    myTree.insert(10);
    myTree.insert(40);
    myTree.insert(20);
    myTree.insert(90);
    myTree.insert(30);

 cout << "Tree in inorder Traversal :" << endl;
  myTree.inorderTraversal();
  cout <<endl<< "delete node 100 from tree :" << endl;
  myTree.deleteNode(100);
  cout << endl << "Srearch node 88 in tree :" << endl;
  cout << myTree.search(88) << endl;
      cout<< "0= not found and 1=found";
}


 
























 