/*
 * @Author: Code
 * @Date: 2019-12-30 14:59:39
 * @LastEditTime : 2020-01-22 17:00:04
 * @LastEditors  : Please set LastEditors
 * @Description: 牛客华科复试机试题：《二叉排序树》
 * @FilePath: /牛客 华科/二叉排序树.cpp
 */
#include <stdio.h>
#include <stdlib.h>

// 结点的结构：值 + 左右指针
typedef struct node{
    int val;
    struct node *lchild, *rchild;
}Node, *BiTree;

// 指向根结点
BiTree biTree;
/**
 * @description: 新建一个结点 
 * @param {int}结点的值  
 * @return: 新建的结点的地址
 */
Node* NewNode(int tmp){
    Node *one = (Node *)malloc(sizeof(Node));
    one->val = tmp;    one->lchild = one->rchild = NULL;
    return one;
}
/**
 * @description: 遍历二叉排序树，寻找某个结点其父节点的值
 * @param {int}待寻找结点的值
 * @return: 待寻找结点其父节点的值
 */
int Find(int tmp){
    BiTree now = biTree;
    while(now){
        if(tmp < now->val){
            if(now->lchild == NULL){
                now->lchild = NewNode(tmp);
                return now->val;
            }else{
                now = now->lchild;
            }
        }else if(tmp > now->val){
            if(now->rchild == NULL){
                now->rchild = NewNode(tmp);
                return now->val;
            }else{
                now = now->rchild;
            }
        }
    }
}

int main(){
    biTree = (Node*)malloc(sizeof(Node));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        if(i == 0){
            biTree->val = tmp;
            printf("-1\n");
        }else{
            printf("%d\n", Find(tmp));
        }
    }
    return 0;
}