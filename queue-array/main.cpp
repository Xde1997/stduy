#include "stdlib.h"
#include "stdio.h"

#define QUEUE_SIZE 5

static int queue[QUEUE_SIZE];
static int head = 0;
static int tail = 0;

void EnQueue(int value)
{
    //先判断队满
    if ((tail + 1) % QUEUE_SIZE == head)
    {
        printf("%s", "队列已满，无法从队尾插入元素\n");
    }
    else
    {
        queue[tail] = value;
        tail = (tail + 1) % QUEUE_SIZE;
    }
}

int DeQueue()
{
    int temp;
    if (tail == head)
    {
        printf("%s", "队列为空，元素无法出队列\n");
    }
    else
    {
        printf("弹出前head:%d\n", head);
        temp = queue[head];
        head = (head + 1) % QUEUE_SIZE;
    }
    printf("%d\n", temp);
    printf("弹出后head:%d\n", head);
    return temp;
}

int IsEmpty()
{
    if (head == tail)
    {
        printf("%s", "队列为空");
        return 1;
    }
    printf("%s", "队列不为空\n");
    return 0;
}

int IsFull()
{
    if ((tail + 1) % QUEUE_SIZE == head)
    {
        printf("%s", "队列已满\n");
        return 1;
    }
    printf("%s", "队列未满\n");
    return 0;
}

void PrintQueue()
{
    for (int i = head; (i + 1) % QUEUE_SIZE == tail; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{

    EnQueue(4);
    EnQueue(1);
    EnQueue(2);
    EnQueue(9);
    EnQueue(8);
    PrintQueue();

    DeQueue();
    DeQueue();
    EnQueue(8);
    EnQueue(7);
    PrintQueue();

    system("pause");
    return 0;
}