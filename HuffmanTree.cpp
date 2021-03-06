//
// Created by antonio on 17-11-28.
//

#include "HuffmanTree.h"

void Haffman(int weight[], int n, HaffNode haffTree[]){
    //建立叶结点个数n，权值数组为weight的哈夫曼树
    int m1, m2, x1, x2 ;
    int x, y ;
    //哈夫曼树的初始化n个叶结点的二叉树共有2n-1个结点
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (i < n) haffTree[i].weight = weight[i] ;//先给叶子结点初始化
        else       haffTree[i].weight = 0 ;//非叶子结点全部为0

        haffTree[i].parent = -1 ;
        haffTree[i].flag = 0 ;
        haffTree[i].leftChild = -1 ;
        haffTree[i].rightChild = -1;

    }

    int i = 0;
    //构造哈夫曼树的n-1个非叶结点
    for (; i < n - 1; ++i) {
        m1 = m2 = MaxValue ;
        x1 = x2 = 0 ;
        for (int j = 0; j < n + i; ++j) {//好极了：（j = 0; j < n+i; ++j）
            // 从已经初始化的结点中包括非叶子结点找出权值最小和次小的子树

            //就这里不是很理解，怎么找到两个最小的权值的。
            //经过验证，这里的m1， m2, x1, x2是真的牛逼，能够同时得到最小和次小weight
            if (haffTree[j].weight < m1 && haffTree[j].parent == -1){
                m2 = m1 ;
                x2 = x1 ;
                m1 = haffTree[j].weight ;
                x1 = j ;
            }
            else if (haffTree[j].weight < m2 && haffTree[j].parent == -1){
                m2 = haffTree[j].weight ;
                x2 = j ;
            }
        }



        //*将找出来的两颗权值最小和次小的子树合并为一颗子树
        haffTree[x1].parent = n + i ;
        haffTree[x2].parent = n + i ;
        haffTree[x1].flag = 1 ;
        haffTree[x2].flag = 1 ;
        haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight ;
        haffTree[n + i].leftChild = x1 ;
        haffTree[n + i].rightChild = x2 ;
    }

}

void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[]){//n = 4
    //由n个结点的哈夫曼树构造哈夫曼编码
    Code *code = (Code *)malloc(sizeof(Code)) ;//一个起始下标， bit数组，和一个int权值

    int i, j, child, parent ;
    //求n个叶结点的哈夫曼编码
    for (i = 0; i < n; i++){
        code->start = n - 1 ;//不等长编码的最后一位为n-1
        code->weight = haffTree[i].weight ;//取得编码对应的权值
        child = i ;
        parent = haffTree[child].parent ;
        //由叶结点向上直到根
        while (parent != -1){//-1为初始标记
            if (haffTree[parent].leftChild == child)//判定当前结点是不是它父亲的左孩子
                code->bit[code->start] = 0 ;//左孩子分支编码0
                //注意这里的code->start ！= 0,也就是说，这里是倒序赋值
            else
                code->bit[code->start] = 1 ;//右孩子分支编码1
            code->start-- ;//如果前面是倒序，那么这里就必须要-1啦
            child = parent ;//自下而上的
            parent = haffTree[child].parent ;

        }

        for (j = code->start+1; j < n; j++)
            haffCode[i].bit[j] = code->bit[j] ;//保存每个叶结点的编码
        //?
        haffCode[i].start = code->start + 1 ;//保存叶结点编码的起始位
        haffCode[i].weight = code->weight ;//保存编码对应的权值
    }
}