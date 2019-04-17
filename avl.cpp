#include <iostream>
#include "avltree.h"
using namespace std;

static int arr[]= {3,2,1,4,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen;
    AVLTree<int>* tree=new AVLTree<int>();

    cout << "== ��������: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i],i);
    }

    cout << "\n== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: "<<endl;;
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== �߶�: " << tree->height() << endl;
    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->print();

    i = 6;
    cout << "\n== ɾ���ڵ�: " << i;
    tree->remove(i);

    cout << "\n== �߶�: " << tree->height() ;
    cout << "\n== �������: " ;
    tree->inOrder();
    cout << "\n== ������ϸ��Ϣ: " << endl;
    tree->print();

    // ���ٶ�����
    tree->destroy();
    return 0;
}