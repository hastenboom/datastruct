#include <iostream>
#include <initializer_list>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *lnode, *rnode;
    Node() : val(0), lnode(nullptr), rnode(nullptr) {}
    Node(int x) : val(x), lnode(nullptr), rnode(nullptr) {}
};

class BiTree
{
private:
    //这是存储各个节点地址的数组首地址指针

public:
    Node **tree;
    BiTree(initializer_list<int> initList)
    {
        //建立指针数组，里面存放的是Node*
        tree = new Node *[initList.size()] {};
        int j = 0;
        // initList.begin()+j,j=0,所以取第一个数据的地址
        tree[0] = new Node(*(initList.begin() + j));

        for (auto data : initList)
        {
            //按照跟initList，即输入数据的位置格式来存储节点地址，这里是按照层次从左到右的顺序
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            //确保left不会超过所有节点数，以及确保他不是空的；如果是null的那么就不会建立链接
            if (left < initList.size() && *(initList.begin() + left) != NULL)
            {

                tree[left] = new Node;
                //存入数据
                tree[left]->val = *(initList.begin() + left);
                //建立连接
                tree[j]->lnode = tree[left];
            }

            //同样的逻辑建立右孩子
            if (right < initList.size() && *(initList.begin() + right) != NULL)
            {
                tree[right] = new Node;
                tree[right]->val = *(initList.begin() + right);
                tree[j]->rnode = tree[right];
            }
            //记得j++
            j++;
        }
    }
};

void preOrder(Node *tmp)
{
    if (NULL == tmp)
        return;
    cout << tmp->val << ' ';
    preOrder(tmp->lnode);
    preOrder(tmp->rnode);
}

void preOrder_iter(Node *tmp)
{
    stack<Node *> s;
    //把root先放进来
    s.push(tmp);
    while (!s.empty())
    {
        //在pop元素之前，要记录top元素的位置
        //然后pop
        //记录的位置找right然后left，先后入栈
        //循环更新的是top元素
        auto node = s.top();
        cout << s.top()->val << ' ';
        s.pop();

        if (node->rnode)
        {
            s.push(node->rnode);
        }
        if (node->lnode)
        {
            s.push(node->lnode);
        }
    }
}

void inOrder(Node *tmp)
{
    if (NULL == tmp)
        return;
    inOrder(tmp->lnode);
    cout << tmp->val << ' ';
    inOrder(tmp->rnode);
}

void inOrder_iter(Node *tmp)
{
    stack<Node *> s;
    auto pointer = tmp;

    //循环搜索，如果有左节点有去左，如果没有就去右
    //
    while (pointer || !s.empty())
    {
        //搜索一直搜到5处
        while (pointer)
        {
            s.push(pointer);
            pointer = pointer->lnode;
        }
        //此时栈的top是5，输出
        cout << s.top()->val << ' ';
        //检查5那边是不是有右节点，但是5已经出栈了，所以需要另一个东西来保存这个数据
        pointer = s.top();
        //保存好5后，让5出栈,[1,2,6]
        s.pop();
        //搜索5的右孩子，结合上面的第二个while，因为没有右孩子，所以此时输出6，保存6的位置，让6出栈剩下[1,2]
        //然后搜索6的右孩子
        pointer = pointer->rnode;
    }
}

void rearOrder(Node *tmp)
{
    if (NULL == tmp)
        return;
    rearOrder(tmp->lnode);
    rearOrder(tmp->rnode);
    cout << tmp->val << ' ';
}

void rearOrder_iter(Node *tmp)
{
    stack<Node *> s;
    auto pointer = tmp;
    auto follow = tmp;
    while (pointer || !s.empty())
    {
        //这个循环是管理所有左右节点的入栈的
        while (pointer)
        {
            s.push(pointer);
            pointer = pointer->lnode;
        }
        //[1,2,6]
        //此时还不能进行输出，因为如果6存在右子节点，
        //则根据后序应该先输出这个右子节点，然后再输出父节点6
        // p指向6
        //因为11没有左孩子，所以没有更新pointer，所以p->11
        pointer = s.top();

        //如果6有右子节点，则入栈，并更新pointer
        if (pointer->rnode && pointer->rnode != follow)
        {
            // p指向11，在第二次循环时会被入栈[1,2,6,11]
            // p->11
            pointer = pointer->rnode;
        }
        //没有就输出
        else
        {
            // out: 11
            cout << pointer->val << ' ';
            follow = pointer;
            //[1,2,6]
            s.pop();
            pointer = NULL;
        }
    }
}

void level(Node *tmp)
{
    queue<Node *> q;
    auto pointer = tmp;
    //【1】
    q.push(tmp);
    while (!q.empty())
    {
        //【1，2】
        if (q.front()->lnode)
        {
            q.push(pointer->lnode);
        }
        //【1，2，3】
        if (q.front()->rnode)
        {
            q.push(pointer->rnode);
        }
        // out:1
        cout << q.front()->val << ' ';
        //【2，3】
        q.pop();
        pointer = q.front();
    }
}

int main()
{
    BiTree bt{1,
              2, 6,
              6, 4, 99, 10,
              5, 3, NULL, 7, NULL, NULL, NULL, NULL};

    BiTree bt2{1,
               2, 3,
               NULL, 4, 9, NULL,
               NULL, NULL, 5, 6, NULL, 10, NULL, NULL,
               NULL, NULL, NULL, NULL, 7, 8, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    BiTree bt3{1, 2, 3, 6, 7, NULL, 5, NULL, 11};

    BiTree bt4{1, 2, 3};
    // preOrder(bt.tree[0]);
    // cout << endl;
    // preOrder_iter(bt.tree[0]);
    // inOrder_iter(bt.tree[0]);
    // cout << endl;
    // inOrder(bt.tree[0]);
    // cout << endl;
    // rearOrder(bt3.tree[0]);
    // cout << endl;
    // rearOrder_iter(bt3.tree[0]);
    // cout << endl;
    level(bt3.tree[0]);
    system("pause");
    return 0;
}
