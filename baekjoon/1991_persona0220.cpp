#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct tree_node{
	char name;
	struct tree_node *left;
	struct tree_node *right;
}tree_node;

void preorder(tree_node* root){
	printf("%c", root->name);
	if(root->left)
		preorder(root->left);
	if(root->right)
		preorder(root->right);
}

void inorder(tree_node* root){
	if(root->left)
		inorder(root->left);
	printf("%c", root->name);
	if(root->right)
		inorder(root->right);
}

void postorder(tree_node* root){
	if(root->left)
		postorder(root->left);
	if(root->right)
		postorder(root->right);
	printf("%c", root->name);
}



int main(){
	
	int N;
	cin >> N;

	tree_node tree[N+1];

	for(int i=1; i<=N; i++){
		tree[i].name = 'A' + i -1;
		tree[i].left = NULL;
		tree[i].right = NULL;
	}
	

	for(int i=0; i<N; i++){
		char par, left, right;

		cin >> par >> left >> right;
		
		if(left != '.')
			tree[par-'A'+1].left = &tree[left-'A'+1];
		
		if(right != '.')
			tree[par-'A'+1].right = &tree[right-'A'+1];
	}

	preorder(&tree[1]);
	printf("\n");
	inorder(&tree[1]);
	printf("\n");
	postorder(&tree[1]);

	return 0;
}

