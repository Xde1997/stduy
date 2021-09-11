#include "stdlib.h"
#include "stdio.h"

#define QUEUE_SIZE 5

static int queue[QUEUE_SIZE];
static int head = 0;
static int tail = 0;

void EnQueue(int value)
{
    //���ж϶���
    if ((tail + 1) % QUEUE_SIZE == head)
    {
        printf("%s", "�����������޷��Ӷ�β����Ԫ��\n");
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
        printf("%s", "����Ϊ�գ�Ԫ���޷�������\n");
    }
    else
    {
        printf("����ǰhead:%d\n", head);
        temp = queue[head];
        head = (head + 1) % QUEUE_SIZE;
    }
    printf("%d\n", temp);
    printf("������head:%d\n", head);
    return temp;
}

int IsEmpty()
{
    if (head == tail)
    {
        printf("%s", "����Ϊ��");
        return 1;
    }
    printf("%s", "���в�Ϊ��\n");
    return 0;
}

int IsFull()
{
    if ((tail + 1) % QUEUE_SIZE == head)
    {
        printf("%s", "��������\n");
        return 1;
    }
    printf("%s", "����δ��\n");
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