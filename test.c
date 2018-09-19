#include "BST-Dictionary.h"

int main()
{
	BSTreeNode* pTree = NULL;
	BSTreeNode* node = NULL;
	//��ȡmy.txt
	FILE* in = fopen("my.txt", "r");
	char buf[15] = { 0 };
	int index = 0;
	char ch = 0;
	int flag = 1;
	//�ļ���ʧ��
	if (in == NULL)
	{
		printf("���ļ�ʧ��\n");
		system("pause");
		return -1;
	}
	//���ļ��ַ�����ch,�������ݲ������ļ�������
	while ((ch = getc(in)) != EOF)
	{
		//һ�����ʽ���
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n')
		{
			if (flag == 0)//��ֹ�����ظ�����ĸ�����
				continue;
			flag = 0;
			//���Ҹõ����Ƿ����
			node = BSTreeFind(&pTree, buf);
			//���ڣ����ִ�������
			if (node != NULL)
			{
				node->_value++;
			}
			//���������������Ӹõ���
			else
			{
				BSTreeInsert(&pTree, buf, 1);
			}
			//��ʼ��buf,Ϊ������ѯ��һ������׼��
			memset(buf, 0, 15);
			index = 0;
		}
	    //һ������δ����
		else
		{
			flag = 1;
			//��������,���������ַ�����ch
			buf[index++] = ch;
		}
	}
	BSTreeInOrder(&pTree);
	system("pause");
	return 0;
}