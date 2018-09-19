#include "BST-Dictionary.h"

int main()
{
	BSTreeNode* pTree = NULL;
	BSTreeNode* node = NULL;
	//读取my.txt
	FILE* in = fopen("my.txt", "r");
	char buf[15] = { 0 };
	int index = 0;
	char ch = 0;
	int flag = 1;
	//文件打开失败
	if (in == NULL)
	{
		printf("打开文件失败\n");
		system("pause");
		return -1;
	}
	//将文件字符读入ch,读入内容不等于文件结束符
	while ((ch = getc(in)) != EOF)
	{
		//一个单词结束
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n')
		{
			if (flag == 0)//防止遇到重复非字母的情况
				continue;
			flag = 0;
			//查找该单词是否存在
			node = BSTreeFind(&pTree, buf);
			//存在，出现次数增加
			if (node != NULL)
			{
				node->_value++;
			}
			//不存在在树里增加该单词
			else
			{
				BSTreeInsert(&pTree, buf, 1);
			}
			//初始化buf,为继续查询下一个单词准备
			memset(buf, 0, 15);
			index = 0;
		}
	    //一个单词未读完
		else
		{
			flag = 1;
			//索引后移,将读到的字符存入ch
			buf[index++] = ch;
		}
	}
	BSTreeInOrder(&pTree);
	system("pause");
	return 0;
}