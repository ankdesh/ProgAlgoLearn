// This file implements a search tree which can return the number of nodes smaller than
// a given number. 

#include <iostream>

int countSmall = 0;

class AugBSTNode {

public:
AugBSTNode(int val_){
  left = NULL;
  right = NULL;
  val = val_;
  size = 1; // Keeps track of number of children including itself
}

AugBSTNode* left;
AugBSTNode* right;
int val;  // Value of the node
int size; // Size of the subtree rooted at this node

}; 

AugBSTNode* insert(int key, AugBSTNode* root){ // Returs number of nodes smaller than this 
  if (root == NULL){
    return new AugBSTNode(key);
  }
  else {
    // Either moving left or right, the size of root node will increase.
    root->size ++;
  }

  if (key <= root-> val){
    root->left = insert(key, root->left);
  }
  else {
    if(root->left != NULL){
      // Counts the numebr of values smaller than key. 
      // Keep dding size of left subtree and root, when moving right 
      countSmall += root->left->size; 
      countSmall ++;
    }
    root->right = insert(key, root->right);
  }
}

void printInOrder (AugBSTNode* currNode){
  if (currNode != NULL){
    std::cout << currNode->val << " " << currNode->size << std::endl;
    printInOrder(currNode->left);
    printInOrder(currNode->right);
  }
}

int main(){
  AugBSTNode *root = NULL;
  root = insert(5,root);

  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(3,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(2,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(4,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(7,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(6,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 
  insert(8,root);  
  std::cout << ">>" << countSmall << std::endl;
  countSmall = 0; 

  printInOrder(root);

}
