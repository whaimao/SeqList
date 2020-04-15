#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"

typedef struct _tag_SeqList{
	int length; //链表长度
	int capacity; // 链表容量
	unsigned int *node; // 存放一个地址
	
}TSeqList;

SeqList *SeqList_Create(int capacity){
	int ret = 0;
	TSeqList *tmp = NULL;
	tmp = (TSeqList*)malloc(sizeof(TSeqList)); //开辟一段内存
	if(tmp == NULL){
		ret = -1;
		printf("func SeqList_Create() err:%d", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList)); // 初始化内存为0
	
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*) * capacity); // 存capacity个这样的地址
	if(tmp-node == NULL){
		ret = -2;
		printf("func SeqList_Create() malloc err:%d", ret);
		if(tmp != NULL){
			free(tmp);
		}
		return NULL;
	}
	memset(tmp, 0, sizeof(unsigned int*) * capacity); // 初始化内存为0
	tmp->length = 0;
	tmp->capacity = capacity;
	return NULL;
}

void SeqList_Destroy(SeqList * list){
	TSeqList* tlist = NULL;
	if(list == NULL){
		return NULL;
	}
	tlist = (TSeqList*)list;
	if(tlist-node != NULL){
		free(tlist->node);
	}
	free(tlist);
}

void SeqList_Clear(SeqList *list){
	TSeqList* tlist = NULL;
	if(list == NULL){
		return NULL;
	}
	tlist = (TSeqList*)list;
	tlist->length = 0;
}
int SeqList_Length(SeqList * list){
	TSeqList* tlist = NULL;
	if(list == NULL){
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList * list){
	TSeqList* tlist = NULL;
	if(list == NULL){
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	TSeqList* tlist = NULL;
	int i = 0, ret = 0;
	if(list == NULL || node == NULL || pos < 0){
		ret = -1;
		printf("func SeqList_Insert() err:%d", ret);
		return ret;
	}
	// 容错
	if(pos >= tlist->length){
		pos = tlist->length;
	}
	tlist = (TSeqList*) list;
	// 向后移动
	for(i = tlist->length; i > pos; i--){
		tlist->node[i + 1] = tlist->node[i]
	}
	tlist->node[pos] = node;
	tlist->length ++;
	return ret;
}

SeqListNode *SeqList_Delete(SeqList* list, int pos){
	TSeqList* tlist = NULL;
	SeqListNode* tmp = NULL;
	int i = 0, ret = 0;
	if(list == NULL || pos < 0){
		ret = -1;
		printf("func SeqList_Insert() err:%d", ret);
		return ret;
	}
	// 容错
	if(pos >= tlist->length){
		pos = tlist->length;
	}
	tlist = (TSeqList*) list;
	// 向前移动
	 tmp = (SeqListNode*)tlist->node[pos];
	 
	for(i = pos; i < tlist->length - 1; i++){
		tlist->node[i] = tlist->node[i + 1];
	}
	return tmp;
}

SeqListNode *SeqList_Get(SeqList* list, int pos){
	TSeqList* tlist = NULL;
	SeqListNode* tmp = NULL;
	int i = 0, ret = 0;
	if(list == NULL || pos < 0){
		ret = -1;
		printf("func SeqList_Insert() err:%d", ret);
		return ret;
	}
	// 容错
	if(pos >= tlist->length){
		pos = tlist->length;
	}
	tlist = (TSeqList*) list;
	return tlist->node[pos];
}  