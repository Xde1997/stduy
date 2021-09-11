#include "stdio.h"
#include "stdlib.h"
#include <stack>
#include <iostream>
using namespace std;
typedef struct BTNode
{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
} BiTNode;

int CreateBiTree(BiTNode **T)
{
    int ch;
    scanf("%d", &ch);
    if (ch == -1)
    {
        *T = NULL;
        return 0;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (T == NULL)
        {
            printf("failed\n");
            return 0;
        }
        else
        {
            (*T)->data = ch;
            printf("输入%d的左子节点：", ch);
            CreateBiTree(&((*T)->lChild));
            printf("输入%d的右子节点：", ch);
            CreateBiTree(&((*T)->rChild));
        }
    }
    return 1;
}

//先序遍历二叉树
void PreOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", T->data);
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}

//前序遍历非递归版
void PreOrderNonRec(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    std::stack<BiTNode *> s;
    cout << T->data << " ";
    s.push(T);
    T = T->lChild;
    while (!s.empty() || T)
    {
        while (T)
        {
            cout << T->data << " ";
            s.push(T);
            T = T->lChild;
        }
        T = s.top()->rChild;
        s.pop();
    }
}

//中序遍历二叉树
void MiddleOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        printf("%d ", T->data);
        MiddleOrderBiTree(T->rChild);
    }
}

//中序遍历二叉树非递归
void InOrderNonRec(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    stack<BiTNode *> s;
    s.push(T);
    T = T->lChild;
    while (!s.empty() || T)
    {
        while (T)
        {
            s.push(T);
            T = T->lChild;
        }
        cout << s.top()->data << " ";
        T = s.top()->rChild;
        s.pop();
    }
}

//后续遍历二叉树
void PostOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        MiddleOrderBiTree(T->rChild);
        printf("%d ", T->data);
    }
}

//后序遍历非递归版
void PostOrderNonRec(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    BiTNode *pre = NULL;
    stack<BiTNode *> s;
    s.push(T);
    while (!s.empty())
    {
        T = s.top();
        if ((!T->lChild && !T->rChild) || (pre && (pre == T->lChild || pre == T->rChild)))
        {
            cout << T->data << " ";
            pre = T;
            s.pop();
        }
        else{
            if(T->rChild)
            {
                s.push(T->rChild);
            }
            if(T->lChild)
            {
                s.push(T->lChild);
            }
        }
    }
}

//二叉树的深度
int TreeDeep(BiTNode *T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
    }
    return deep;
}

//叶子节点个数
int LeafCount(BiTNode *T)
{
    static int count;
    if (T == NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            count++;
        }
        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }
    return count;
}

int main(int argc, const char *argv[])
{
    BiTNode *T;
    int depth, leafCount = 0;
    printf("请输入第一个节点的值，-1表示没有叶节点：\n");
    CreateBiTree(&T);
    printf("先序遍历二叉树：");
    PreOrderBiTree(T);
    printf("\n");
    printf("中序遍历二叉树：");
    MiddleOrderBiTree(T);
    printf("\n");
    printf("后续遍历二叉树：");
    PostOrderBiTree(T);
    printf("\n");
    depth = TreeDeep(T);
    printf("树的深度为：%d\n", depth);
    leafCount = LeafCount(T);
    printf("叶子节点个数:%d\n", leafCount);
    system("pause");
    return 0;
}