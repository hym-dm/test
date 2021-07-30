#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
#include"list.h"
int main()
{
	//SeqList mylist;
	//SList mylist;
	DCList mylist;
	//SeqListInit(&mylist);
	//SListInit(&mylist);
	DCListInit(&mylist);

	ElemType item, key;
	int pos;
	//SListNode *p;
	DCListNode* p;

	int select = 1;
	while (select)
	{
		printf("***************************************\n");
		printf("* [1] push_back       [2] push_front  *\n");
		printf("* [3] show_list       [0] quit_system *\n");
		printf("* [4] pop_back        [5] pop_front   *\n");
		printf("* [6] length          [7] capacity    *\n");
		printf("* [8] insert_val      [9] insert_pos  *\n");
		printf("* [10] delete_val     [11] delete_pos *\n");
		printf("* [12] find           [13] sort       *\n");
		printf("* [14] reverse        [15] remove all *\n");
		printf("* [16] clear          [*17] destory   *\n");
		printf("* [18] find_binary                    *\n");
		printf("***************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
				//SeqListPushBack(&mylist, item);
				//SListPushBack(&mylist, item);
				DCListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据（以-1结束:>");
			while (scanf("%d", &item), item != -1)
				//SeqListPushFront(&mylist, item);
				//SListPushFront(&mylist, item);
				DCListPushFront(&mylist, item);
			break;
		case 3:
			//SeqListShow(&mylist);
			//SListShow(&mylist);
			DCListShow(&mylist);
			break;
		case 4:
			//SeqListPopBack(&mylist);
			//SListPopBack(&mylist);
			DCListPopBack(&mylist);
			break;
		case 5:
			//SeqListPopFront(&mylist);
			//SListPopFront(&mylist);
			DCListPopFront(&mylist);
			break;
		case 6:
			//printf("表的表长为>%d\n", SeqListCapacity(&mylist));
			printf("表长为%d\n", SListLength(&mylist));
			break;
		case 7:
			//printf("容量为:>%d\n", SeqListLength(&mylist));
			break;
		case 8:
			printf("请输入要插入的值\n");
			scanf("%d", &item);
			//SeqListInsertByVal(&mylist, item);
			//SListInsertByVal(&mylist, item);
			DCListInsertByval(&mylist, item);
			break;
		case 9:
			//printf("请输入要插入的位置和要插入的值:>");
			//scanf("%d %d", &pos, &key);
			//SeqListInsertByPos(&mylist, pos, key);
			
			//SListInsertAfter(&mylist, pos,  key);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListDeleteByVal(&mylist, key);
		//	SListDeleteByVal(&mylist, key);
			DCListDeleteByVal(&mylist,key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			//pos = SeqListFind(&mylist, key);
			//pos = SListFind(&mylist, key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
			printf("要查找的值存在\n");
			break;
		case 13:
			//SeqListSort(&mylist);
			//SListSort(&mylist);
			break;
		case 14:
			//SeqListReverse(&mylist);
			//SListReverse(&mylist);
			DCListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的值\n");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			//SListRemoveAll(&mylist, key);
			break;
		case 16:
			//SeqListClear(&mylist);
			//SListClear(&mylist);
			DCListClear(&mylist);
			break;

		case 18:
			printf("请输入要二分查找的值:>\n");
			scanf("%d", &key);
			//pos = SeqListFindByBinary(&mylist, key);
			//if (pos == -1)
			//	printf("要查找的值不存在\n");
			//else
			//	printf("要查找的值%d在下标为%d的位置.\n", key, pos);
			//break;
		}
		system("pause");
		system("cls");
	}
	//SeqListDestroy(&mylist);
	//SListDestroy(&mylist);
	DCListDestroy(&mylist);
	return 0;
}
