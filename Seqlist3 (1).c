
#include"Seqlist.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item, key;
	int pos;
	


	int select = 1;
	while (select)
	{
		printf("***************************************\n");
		printf("* [1] push_back       [2] push_front  *\n");
		printf("* [3] show_list       [0] quit_system *\n");
		printf("* [4] pop_back        [5] pop_front   *\n");
		printf("* [6] length          [7] capacity    *\n");
		printf("* [8] insert_val      [9] insert_pos  *\n");
		printf("* [10] delect_val     [11] delect_pos *\n");
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
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据（以-1结束:>");
			while (scanf("%d", &item), item != -1)
				SeqListPushFront(&mylist, item);
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("表的容量为>%d\n", SeqListCapacity(&mylist));
			break;
		case 7:
			printf("表长为:>%d\n", SeqListLength(&mylist));
			break;
		case 9:
			printf("请输入要插入的位置和要插入的值:>");
			scanf("%d %d", &pos, &key);
			SeqListInsertByPos(&mylist, pos, key);
			break;
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d的位置为%d\n", key, pos);
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestory(&mylist);
	return 0;
}