#include "BST-Dictionary.h"

static BSTreeNode* BuyNode(BSTKeyType key, BSTValueType value)
{
	BSTreeNode* newNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (newNode == NULL)
		perror("BuyNode::malloc()");
	newNode->_key = (BSTKeyType)malloc(strlen(key) + 1);
	strcpy(newNode->_key, key);
	newNode->_value = value;
	newNode->_left = NULL;
	newNode->_right = NULL;

	return newNode;
}
int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
{
	BSTreeNode *cur = *ppTree;
	BSTreeNode *parent = NULL;
	if (*ppTree == NULL)
	{
		*ppTree = BuyNode(key, value);
		return 1;
	}
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			//cur->_value++;
			return 0;
		}
	}
	if (strcmp(parent->_key, key) < 0)
		parent->_right = BuyNode(key, value);
	else
		parent->_left = BuyNode(key, value);
	return 1;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
{
	BSTreeNode* cur = *ppTree;
	assert(ppTree);
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			cur = cur->_right;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	BSTreeNode* root = *ppTree;
	if (*ppTree == NULL)
		return;

	BSTreeInOrder(&root->_left);
	printf("%s:%d\n", root->_key, root->_value);
	BSTreeInOrder(&root->_right);
}

//void TestBSTree2()
//{
//	char str[10] = { '0' };
//	BSTreeNode* pTree = NULL;
//	while (1)
//	{
//		BSTreeNode* node;
//		scanf("%s", str);
//		if (strcmp(str, "exit") == 0)
//		{
//			break;
//		}
//
//		node = BSTreeFind(&pTree, str);
//		if (node)
//		{
//			node->_value++;
//		}
//		else
//		{
//			BSTreeInsert(&pTree, str, 1);
//		}
//	}
//	BSTreeInOrder(&pTree);
//}