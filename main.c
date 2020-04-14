#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"

typedef struct Teacher{
	int age;
	char name[64];
}Teacher;

void main(){
	
	int ret = 0, i = 0;
	SeqList *list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;
	list = SeqList_Create(10);
	if(list == NULL){
		ret = -1;
		printf("func SeqList_Create() err:%d", ret);
	}
	
	SeqList_Insert(list, (SeqListNode*)&t1, 0);
	SeqList_Insert(list, (SeqListNode*)&t2, 0);
	SeqList_Insert(list, (SeqListNode*)&t3, 0);
	SeqList_Insert(list, (SeqListNode*)&t4, 0);
	SeqList_Insert(list, (SeqListNode*)&t5, 0);
	
	//遍历
	for(i = 0; i < SeqList_Length(list); i++){
		Teacher* tmp = (Teacher*)SeqList_Get(list, i);
		printf("tmp->age：%d", tmp->age);
	}
	// 删除头结点
	while(SeqList_Length(list) > 0){
		SeqList_Delete(list, 0);
	}
	
	SeqList_Destroy(list);
	
}