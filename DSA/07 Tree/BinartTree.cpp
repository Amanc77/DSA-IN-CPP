
#include <iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        

        TreeNode(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

TreeNode* createBTree(){
    int data;
    cout << "Enter data for node ";
    cin >> data;

    if (data == -1) return NULL;

    TreeNode* root = new TreeNode(data);

    cout << "Enter left child of " << data << "  ";
    root->left = createBTree();

    cout << "Enter right child of " << data << "  ";
    root->right = createBTree();

    return root;
}

void preOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    cout<<root->data<<" ";
    
    preOrderTraversal(root->left);
    
    preOrderTraversal(root->right);

}


void inOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";

    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
   
    
    postOrderTraversal(root->left);
    
    postOrderTraversal(root->right);
     cout<<root->data<<" ";
}


void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl; // Level finished
            if (!q.empty()) q.push(NULL); // Push marker for next level
        } else {
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
}



int main(){

     TreeNode*  root =  createBTree();
     cout<<endl;


    cout<<"preORder traversal ";
    preOrderTraversal(root);
    cout<<endl;


    cout<<"postORder traversal ";
    postOrderTraversal(root);
    cout<<endl;


    cout<<"inORder traversal ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"level order traversal \n";
    levelOrderTraversal(root);
   cout<<endl;

}