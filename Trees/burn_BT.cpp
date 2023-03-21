/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* findnode(TreeNode* root, int B){
    
    if(!root) return NULL;
    
    auto l = findnode(root->left,B);
    auto r = findnode(root->right,B);
    
    if(root->val == B) return root;
    else if(l==NULL and r==NULL) return NULL;
    else if(l!=NULL) return l;
    else return r;
    
}

void connectpartochild(TreeNode* root, map<TreeNode*,TreeNode*>&par){
    
    
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        
        auto node = q.front();
        q.pop();
        
        if(node->left!=NULL){
            par[node->left]=node;
            q.push(node->left);
        }
        
        
        if(node->right!=NULL){
            par[node->right]=node;
            q.push(node->right);
        }
    }
    
    
}


int Solution::solve(TreeNode* A, int B) {
    
    if(!A) return 0;
    
    TreeNode* target = findnode(A,B);
    map<TreeNode*,TreeNode*>par;
    
    connectpartochild(A,par);
    
    map<TreeNode*,bool>vis;
    vis[target]=1;
    int time=-1;
    
    queue<TreeNode*>q;
    q.push(target);
    
    while(!q.empty()){
        
    
        int sz = q.size();
        time++;
        for(int i=0;i<sz;++i){
            
            auto node = q.front();
            q.pop();
            
            if(node->left!=NULL and !vis[node->left]){
                vis[node->left]=1;
                q.push(node->left);
            }
            
            if(node->right!=NULL and !vis[node->right]){
                vis[node->right]=1;
                q.push(node->right);
            }
            
            if(par[node] and !vis[par[node]]){
                vis[par[node]]=1;
                q.push(par[node]);
            }
        }    
    }
    
    return time;
}