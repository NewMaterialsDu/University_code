#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

//typedef char ElemType;

//声明一个结构体（节点），包含数据域和指针域，节点连在一起就是链表
typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//单链表初始化
Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;//返回头节点地址
}

//初始化节点（带节点数据域参数）
Node* initListWithElem(ElemType e) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = e;
	node->next = NULL;
	return node;
}

//单链表头插法：开辟新空间创建一个新节点，这个节点指向next和头节点一样，再把头节点指向新节点（头节点一直是头节点）
void insertHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));//开辟一个新节点空间
	p->data = e;
	p->next = L->next;//新节点下一个指向原来头节点的下一个，现在头节点和p指向同一个next
	L->next = p;//头节点的下一个指向p，现在头节点指p
}

//单链表遍历打印：头节点->20->10（因为头插法是先插10再插20，所以打印出来顺序是20->10）
void listNode(Node *L) {
	Node* p = L->next;
	while (p != NULL) {
        printf("%d\n", p->data);//注意，数据域变的时候，占位符也要变
		p = p->next;
	}
	printf("\n");
}

//遍历获取尾节点地址
Node* get_tail(Node* L) {
	Node* p = L;//因为要返回最后一个节点的信息，所以要创建一个p让L赋值（L传的是地址，用L本身遍历就会把原来的链表改变了)
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}

//尾插法：传入尾节点和插入的数据
Node * insertTail(Node* tail, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;//给p传入数据
	tail->next = p;//尾节点指向p
	p->next = NULL;//p指向空
	return p;//返回新的尾节点
	}

//尾插法（直接传入节点）
Node* insertTailWithNode(Node* tail, Node* node) {
	tail->next = node;
	node->next = NULL;
	return node;
}

//单链表，在指定位置插入数据:需要传入链表L，指定位置pos，数据e
int insertNode(Node* L, int pos, ElemType e) {
	Node* p = L;//指针传入，不能直接使用，会改变原来的值
	//遍历获取pos前的尾节点地址
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			printf("插入位置错误！\n");
			return 0;//p为空时链表已经到头
		}
	}
	//当成一个尾插法
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}

//单链表—删除指定位置的节点:找到删除前的前置节点p，指针q记录要删除的节点（用来释放内存空间),把p指向下下个
int deleteNode(Node* L, int pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			printf("删除位置错误！\n");
			return 0;//p为空时链表已经到头
		}

	}
	if (p->next == NULL) {
		printf("删除位置错误！\n");
		return 0;//此时链表已经到头
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

//单链表-获取链表长度
int listLength(Node* L) {
	int len=0;
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

//单链表-释放链表（把头节点以后的所有节点内存释放）
void freelist(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

//使用双指针找到倒数第K个节点:快指针先走k步，然后一起走，快指针为空时，慢指针到目标位置
int findNodeFS(Node *L,int k) {
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++) {
		fast = fast->next;

	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
    printf("倒数第%d个节点的值为：%d\n", k, slow->data);
	return 1;
}

//查找两个节点共同后缀的起始位置（数据域为char）
Node* findIntersectionNode(Node* headA, Node* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	Node* p = headA;
	int lenA = 0;
	int lenB = 0;

	//遍历链表A，获取A的长度
	while (p != NULL) {
		p = p->next;
		lenA++;
	}
	//获取B的长度
	p = headB;
	while (p != NULL) {
		p = p->next;
		lenB++;
	}

	Node* m;//快指针
	Node* n;//慢指针
	int step;//两个单词之间的差值，可以用于快指针先走的步数
	if (lenA > lenB) {
		step = lenA - lenB;
		m = headA;
		n = headB;
	}
	else {
		step = lenB - lenA;
		m = headB;
		n = headA;
	}
	//让快指针先走step步
	for (int i = 0; i < step; i++) {
		m = m->next;
	}
	//快慢指针同步走，直到指向同一个节点退出循环
	while (m != n) {
		m = m->next;
		n = n->next;
	}
	return m;

}

//删除绝对值相同的节点,留下第一次出现的值，n为链表中最大的绝对值(数据域为int)
void removeNode(Node* L, int n) {
	Node* p = L;
	int index;//作为数组下标使用
	int* q = (int*)malloc(sizeof(int) * (n + 1));//新建一个数组，长度为链表中数的最大绝对值，加一是因为数组下标是从0开始

	//遍历数组,初始化为0，新数组中的每一个值都是0
	for (int i = 0; i < n + 1;i++) {
		*(q + i) = 0;//相当于q[i] = 0;
	}
    //当链表中出现过一次的值，对应数组下表的值就变为1
	while (p->next != NULL) {
		//abs获取绝对值
		index = abs(p->next->data);
		if (*(q + index) == 0) {
			*(q + index) = 1;
			p = p->next;
		}
		//再次出现时，释放链表中的空间
		else {
			Node* temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}
	//最后释放新建的数组
	free(q);
}

//反转链表
Node* reverseList(Node* head) {
    // 如果 head 为 NULL，直接返回 NULL
	if (head == NULL) return NULL;

	// 创建三个指针，一个指向 NULL，一个指向头节点的下一个（第一个节点），一个指向第二个节点
	Node* first = NULL;
	Node* second = head->next;
	Node* third;
	// 三个节点同时移动，反转链表节点指向
	while (second != NULL) {
		third = second->next;// 先保存 next 节点，避免丢失剩余链表
		second->next = first;// 反转指针：让当前节点指向已反转链表的头
		first = second;//相当于两个指针指向同一个节点
		second = third;//同上
	}
	// 复用传入的原 head（哨兵），把它的 next 指向反转后的首节点并返回原 head
	head->next = first;
	return head;
}

//删除链表的中间节点,用快慢指针
int delMiddleNode(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while(fast != NULL&&fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}//fast为空或者fast下一个为空时，slow位于中间节点的前置节点
	Node* q = slow->next;
	slow->next = q->next;
	free(q);
	return 1;
}

//链表重新排序：a1,a2,....,an变成a1,an,a2,a(n-1),a3,a(n-2)
void reorderList(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* first = NULL;
	Node* second = slow->next;
	slow->next = NULL;//前置节点的下一个为空（中间节点），把它断开
	Node* third = NULL;
	//把第二段链表做一个反转
	while (second != NULL) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* p1 = head->next;//头没有变，还是指向第一段链表的第一个节点
	Node* q1 = first;//反转之后，first指向第二段的第一个节点（因为是向头移动的）
	Node* p2, * q2;
    while (p1 != NULL && q1 != NULL) {
		p2 = p1->next;
		q2 = q1->next;
		// 改变指向，将它们交叉相连
		p1->next = q1;
		// 如果第一段后面没有节点了（奇数长度时会出现），
		// 应该把当前第二段的下一个节点接上，保留剩余部分，然后结束
		if (p2 == NULL) {
			//链表长度为奇数时，第二段会多出一个中间节点，把他接上
			q1->next = q2;
			break;
		}
		else {
			//正常运行时：
			q1->next = p2;
		}

		p1 = p2;
		q1 = q2;
	}

}

//判断链表是否有环
int iscycle(Node* head) {
	//快慢指针一起走，在环内总会相遇，相遇时则代表有环
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			return 1;
		}
	}
	return 0;
}

//找到链表环的入口
Node* findBegin(Node* head) {
	//先判断是否有环
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			//新建一个指针，三个指针指向同一个节点，新指针遍历一次，再次相遇时，得出环的节点数，并记录下来
			Node* p = fast;
			int cout = 1;
			while (p->next != slow) {
				cout++;
				p = p->next;
			}
			//让他们回到头节点，fast先走一个环的节点数，此时他们相差刚好一个环数，然后一起走，再次相遇时就是在入口
			fast = head;
			slow = head;
			for (int i = 0; i < cout; i++) {
				fast = fast->next;
			}
			while (fast != slow) {
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}

	}
	return NULL;
}


int main() {
	
	////测试各个函数
	//Node* list = initList();
	//insertHead(list, 10);
	//insertHead(list, 20);
	//listNode(list);//遍历
	//Node* tail = get_tail(list);//获取尾节点
	//tail = insertTail(tail, 50);
	//tail = insertTail(tail, 60);
	//tail = insertTail(tail, 70);//用尾插法插入数据，并更新尾节点
	//listNode(list);//遍历
	//insertNode(list, 3, 25);
	//listNode(list);//遍历
	//deleteNode(list, 3);
	//listNode(list);//遍历
	//int len;
	//len = listLength(list);
	//printf("%d\n",len);
	//listNode(list);//遍历
	////freelist(list);
	////listNode(list);//遍历
	////len = listLength(list);
	////printf("%d\n", len);
	//findNodeFS(list, 3);
	//

	//
	////查找两个节点共同后缀的起始位置
	//Node* listA = initList();
	//Node* listB = initList();
	//Node* tailA = get_tail(listA);
	//Node* tailB = get_tail(listB);
	//tailA = insertTail(tailA, 'l');
	//tailA = insertTail(tailA, 'o');
	//tailA = insertTail(tailA, 'a');
	//tailA = insertTail(tailA, 'd');
	//tailB = insertTail(tailB, 'b');
	//tailB = insertTail(tailB, 'e');
	//Node* nodeI = initListWithElem('i');
	//tailA = insertTailWithNode(tailA,nodeI);
	//tailB = insertTailWithNode(tailB, nodeI);
	//Node* nodeN = initListWithElem('n');
	//tailA = insertTailWithNode(tailA, nodeN);
	//tailB = insertTailWithNode(tailB, nodeN);
	//Node* nodeG = initListWithElem('g');
	//tailA = insertTailWithNode(tailA, nodeG);
	//tailB = insertTailWithNode(tailB, nodeG);
	//listNode(listA);
	//listNode(listB);
	//printf("%c\n", findIntersectionNode(listA, listB)->data);
	//
	
	//
	////测试函数removeNode（）
	//Node* list = initList();
	//Node* tail = get_tail(list);
	//tail = insertTail(tail, 21);
	//tail = insertTail(tail, -15);
	//tail = insertTail(tail, -15);
	//tail = insertTail(tail, 7);
	//tail = insertTail(tail, 15);
	//listNode(list);
	//removeNode(list, 21);
	//listNode(list);

	Node* list = initList();
	Node* tail = get_tail(list);
	tail = insertTail(tail, 1);
	tail = insertTail(tail, 2);
	tail = insertTail(tail, 3);
	//tail = insertTail(tail, 4);
	//tail = insertTail(tail, 5);
	//tail = insertTail(tail, 6);
	//tail = insertTail(tail, 7);
	//tail = insertTail(tail, 8);

	////反转函数测试
	listNode(list);
	Node* reverse = reverseList(list);
	listNode(reverse);
	
	////删除中间节点
	//listNode(list);
	//delMiddleNode(list);
	//listNode(list);

	////链表重新排序
	//listNode(list);
	//reorderList(list);
	//listNode(list);

	////判断是否有环
	//Node* list = initList();
	//Node* tail = get_tail(list);
	//tail = insertTail(tail, 1);
	//tail = insertTail(tail, 2);
	//tail = insertTail(tail, 3);
	//Node* three = tail;
	//tail = insertTail(tail, 4);
	//tail = insertTail(tail, 5);
	//tail = insertTail(tail, 6);
	//tail = insertTail(tail, 7);
	//tail = insertTail(tail, 8);
	//tail->next = three;
	//if (iscycle(list)) {
	//	printf("有环\n");
	//}
	//else {
	//	printf("无环\n");
	//}

	//找到环的入口
	//Node* p = findBegin(list);
	//printf("%d\n", p->data);

	return 0;
}