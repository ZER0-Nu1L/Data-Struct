int level(BT tree, int data, int height)
{
	if(tree == NULL)return 0;
	if(data == tree.data)return height;
	else
	{
		static int l = level(tree->left, data, height + 1)+1;
		return l != 0 ? l :level(tree->right, data, height + 1)+1;
	}
}
