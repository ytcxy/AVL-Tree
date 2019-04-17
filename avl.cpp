#include <iostream>
#include "avltree.h"
using namespace std;

static int arr[]= {3,2,1,4,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen,op;
    AVLTree<int>* tree=new AVLTree<int>();

    cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i],i);
    }
    tree -> push();
    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";;
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;
    // 查找某个点。
    op = 6;
    if (tree->search(op) != NULL)    
        cout<<tree->search(i)->value<<endl;
    else cout<<"不存在这个点"<<endl;

    //index 查找某个点
    i = 10;
    if (tree -> indexsearch(i) != NULL) 
        cout<<tree->indexsearch(i) -> value<<endl;
    else cout<<"不存在这个点"<<endl;

    // index 删除某个点。
    if (tree -> indexsearch(i) != NULL){
        op = tree->indexsearch(i) -> key;
        tree -> remove(op);
    } else{
        cout<<"不存在这个点"<<endl;
    }
    tree->push();

    cout << "== 高度: " << tree->height() << endl;
    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    i = 6;
    cout << "\n== 删除节点: " << i;
    tree->remove(i);
    tree -> push();
    cout << "\n== 高度: " << tree->height() ;
    cout << "\n== 中序遍历: " ;
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    tree->print();
    // 销毁二叉树
    tree->destroy();
    // 合并两个avl树。
    AVLTree<int>* treea=new AVLTree<int>();
    AVLTree<int>* treeb=new AVLTree<int>();
    for (i = 0; i < 5; ++i)
        treea -> insert(arr[i],i);
    for (i = 5; i < 10; ++i)
        treeb -> insert(arr[i],i);
    treea -> merge(treeb);
    treea -> print();
    printf("----------------\n");
    // 分裂两个avl树。
    AVLTree<int>* treec=new AVLTree<int>();
    AVLTree<int>* treed=new AVLTree<int>();
    for (i = 0; i < 10; ++i)
        treec -> insert(arr[i],i);
    op = 5;
    treec -> split(treed,op);
    treec -> print();
    printf("------------------\n");
    treed -> print();


    return 0;
}