#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this ->data  = d;
            this ->left = NULL;
            this -> right = NULL;
        }
};


//create mapping
//return target node
node* createParentMapping(node* root,int target,map<node*,node*>& nodeToParent){

    node* result = NULL;

    queue<node*>q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){

        node* front = q.front();
        q.pop();

        if(front->data == target){
            result = front;
        }

        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
            }
    }
    return result;
}

int burnTree(node* root,map<node*,node*>& nodeToParent){

    map<node*,bool>visited;
    queue<node*>q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){

        bool flag = 0;
        
        int size = q.size();
        for(int i = 0;i<size;i++){
            //process neighbouring node
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }

        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;
}

int minTime(node* root,int target){

    //algo
    //step1 : create nodeToParent mapping
    //step 2 :find target node
    //step 3 : burn the tree in min time
   
    map<node*,node*>nodeToParent;
    node* targetNode = createParentMapping(root,target,nodeToParent);

    int ans = burnTree(targetNode,nodeToParent);
    return ans;

}


int main() {
  
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int target = 4;
    cout << "Minimum time to burn the tree from target " << target << " is: " << minTime(root, target) << endl;

    return 0;
}