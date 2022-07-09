int height(node *root){
	if(!root) return;
	int l = height(root->left);
	int r = height(root->right);
	return 1+max(l,r);
}
