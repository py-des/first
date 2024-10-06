#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <iostream>
using namespace std;

class aaa
{
public:
    void func();
    int aa = 10;
    int bbb = 200;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aaa x,y;
//    pointer_cast<void*>(&x::func);
//    asm_cast(p4,x::func);
    auto *p = aaa::func;
    qDebug() << "x: " << &x.aa
             << &x.bbb;
    qDebug() << "y: " << &y.aa
             << &y.bbb;
    int aaa = 10;
//    ReverceString("I am a student!");
//    ListNode *pTmp1 = new ListNode(2);
//    pTmp1->next = new ListNode(4);
//    pTmp1->next->next = new ListNode(3);
//    ListNode *pTmp2 = new ListNode(5);
//    pTmp2->next = new ListNode(6);
//    pTmp2->next->next = new ListNode(4);
//    ListNode *l3 = addTwoNumbers(pTmp1, pTmp2);
//    while (l3 != nullptr)
//    {
//        qDebug() << l3->val;
//        l3 = l3->next;
//    }
//    char* ptr = new char;
//    qDebug() << "111111ptr: " << ptr;
//    int* ptr2 = (int*)ptr;
//    qDebug() << "2222222ptr: " << ptr;
//    qDebug() << "33333333ptr2: " << ptr2;
//    *ptr2 = 10;
//    qDebug() << "44444444444ptr: " << ptr;
//    qDebug() << "5555555555555ptr2: " << ptr2;
//    delete []ptr;
//    ptr = nullptr;
//    qDebug() << "6666666666666ptr: " << ptr;
//    qDebug() << "77777777777ptr2: " << ptr2;
//    int aa = 1;

}

QString MainWindow::ReverceString(QString strSrc)
{
    qDebug() << "strSrc: " << strSrc;
    QString strTmp = "";
    for (int i = strSrc.size() - 1; i >= 0; i--)
    {
        qDebug() << "i: " << i
                 << "strSrc[i]: " << strSrc[i];
        strTmp += strSrc[i];
    }
    qDebug() << "strTmp: " << strTmp;
    return strTmp;
}

ListNode *MainWindow::addTwoNumbers(ListNode *pListNode1, ListNode *pListNode2)
{
    ListNode* pHead = new ListNode(-1);//存放结果的链表
    ListNode* pTmp = pHead;//移动指针
    int iSum = 0;//每个位的加和结果
    bool bFlag = false;//进位标志
    while (pListNode1 != nullptr || pListNode2 != nullptr)
    {
        if (pListNode1 != nullptr)
        {
            iSum += pListNode1->val;
            pListNode1 = pListNode1->next;
        }
        if (pListNode2 != nullptr)
        {
            iSum += pListNode2->val;
            pListNode2 = pListNode2->next;
        }
        if (bFlag)
        {
            iSum++;
        }
        pTmp->next = new ListNode(iSum%10);
        pTmp = pTmp->next;
        bFlag = iSum >= 10 ? true : false;
        iSum = 0;
    }
    if (bFlag)
    {
        pTmp->next = new ListNode(1);
    }
    return pHead;
}

MainWindow::~MainWindow()
{
    delete ui;
}
