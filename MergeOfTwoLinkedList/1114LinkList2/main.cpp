//
//  main.cpp
//  1114LinkList2
//
//  Created by liuzhu on 15/11/14.
//  Copyright © 2015年 liuzhu. All rights reserved.
//

#include <iostream>
using namespace std;

/// 定义一个单链表
typedef struct LZLNode{
    
    /// 数据部分
    int data;
    
    /// 头指针
    struct LZLNode *next;
    
} LZLNode;

#pragma mark - 函数定义
void mergeLinkList( LZLNode *&nodeA, LZLNode *&nodeB, LZLNode *&nodeC);
void prepareForNode( LZLNode *&nodeA, LZLNode *&nodeB );
void logLinkList( LZLNode *node );



#pragma mark - 主函数,需求如下:
//A 和 B 是两个单链表(带头结点),其中元素递增有序.设计一个算法,
//将 A 和 B 归并成一个按元素值非递减有序的链表 C.
//C 由 A 和 B 中的结点组成.
int main(int argc, const char * argv[]) {
    
    //定义结点
    LZLNode *nodeA,*nodeB,*nodeC;
    
    //准备链表
    prepareForNode(nodeA,nodeB);
    
    //打印链表
    printf("\nA链表的内容\n");
    logLinkList(nodeA);
    printf("\nB链表的内容\n");
    logLinkList(nodeB);

    //排序
    mergeLinkList(nodeA,nodeB,nodeC);
    
    //打印排序后的链表
    printf("\n排序后的链表的内容\n");
    logLinkList(nodeC);
    
    return 0;
}


#pragma mark - 以下是功能函数
#pragma mark  归并有序单链表且含有表头的 A 和 B.
/// 归并有序单链表且含有表头的 A 和 B.
/// @param nodeA    输入  A 的表头(&表示别名,可以直接改指针的值)
/// @param nodeB    输入  B 的表头
/// @param nodeC    输出  C 的表头
void mergeLinkList( LZLNode *&nodeA, LZLNode *&nodeB, LZLNode *&nodeC){

    //判断链表是否为空
    if (nodeA == NULL &&
        nodeB == NULL ) {
        
        printf("链表不能为空");
        return;
    }
    
    //定义两个指针,分别指向 A 和 B 的开始元素
    LZLNode *p = nodeA -> next;
    LZLNode *q = nodeB -> next;
    
    //确立归并后的链表的表头C指向 A,并定义一个表尾指针
    nodeC = nodeA;
//    LZLNode *r = NULL;//错误写法
//    nodeC -> next = r;
    LZLNode *r = nodeC;
    r -> next = NULL;
    
    //释放 B 链表的表头
    free(nodeB);
    
    //若链表 A 或 B 有一个为空,便将 C 的结尾指针指向不为空的链表
    while ( p != NULL && q!= NULL) {
        
        if (p -> data >= q -> data ) {
            
            //C 的结尾指向最小的
            r -> next = q;
            //最小的向右移动一位
            q = q -> next;
        }else{
        
            //C 的结尾指向最小的
            r -> next = p;
            //最小的向右移动一位
            p = p -> next;
        }
        //很关键的一步,将 C 的尾端指针移动到最新的尾端
        r = r -> next;
    }
    
    //若 A 链表不为空,就将 C 的尾端指针移动到
    if(p != NULL) r -> next = p;
    if(q != NULL) r -> next = q;
    
}

#pragma mark  给两个链表分配内存空间
/// 给两个链表分配内存空间
/// @param nodeA 要分配内存空间(表头默认是-1,不参与排序)
/// @param nodeB 要分配内存空间
void prepareForNode( LZLNode *&nodeA1, LZLNode *&nodeB1 ){
    
    //开辟链表 A 的内存空间,并赋值
    LZLNode *nodeA5 = (LZLNode *)malloc(sizeof(LZLNode));
    LZLNode *nodeA4 = (LZLNode *)malloc(sizeof(LZLNode));
    LZLNode *nodeA3 = (LZLNode *)malloc(sizeof(LZLNode));
    LZLNode *nodeA2 = (LZLNode *)malloc(sizeof(LZLNode));
    nodeA1          = (LZLNode *)malloc(sizeof(LZLNode));
    
    *nodeA5 = {33,NULL};
    *nodeA4 = {15,nodeA5};
    *nodeA3 = {9,nodeA4};
    *nodeA2 = {5,nodeA3};
    *nodeA1  = {-1,nodeA2};
    
    //开辟链表 B 的内存空间,并赋值
    LZLNode *nodeB3 = (LZLNode *)malloc(sizeof(LZLNode));
    LZLNode *nodeB2 = (LZLNode *)malloc(sizeof(LZLNode));
    nodeB1          = (LZLNode *)malloc(sizeof(LZLNode));
    
    *nodeB3 = {20,NULL};
    *nodeB2 = {4,nodeB3};
    *nodeB1 = {-1,nodeB2};
    
}

#pragma mark  遍历链表的内容并打印
/// 遍历链表的内容并打印
/// @param node 要打印的目的链表
void logLinkList( LZLNode *node ){

    if(node -> next == NULL){
    
        printf("表头指向的内容为空,意味着链表为空");
        return;
    }
    
    node = node -> next;
    
    while (node != NULL) {
        
        //打印当前结点的数据
        printf("%d..",node -> data);
        
        //跳到下一个结点,若下一结点内容不存在,就结束打印
        node = node -> next;
    }
}

