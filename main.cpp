#include <iostream>
//#define MaxValue 10000
//#define MaxBit 4

#include "HuffmanTree.h"
#define MaxN 50
#include <cstdlib>
/*
 * HuffmanTree用于解决最优化问题
 * 用于构造代码总长最短的电文编码方案
 * 主要是计算WPL带权路径长度最小最佳
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    int i, j, n = 4 ;
    int weight[] = {1, 3, 5, 7};
    HaffNode *myHaffTree = (HaffNode *)malloc(sizeof(HaffNode) * (2 * n - 1)) ;
    Code *myHaffCode = (Code *)malloc(sizeof(Code) * n) ;

    if (n > MaxN){
        printf("给出的n越界， 修改MaxN\n") ;
        exit(1) ;
    }
    Haffman(weight, n, myHaffTree) ;
    HaffmanCode(myHaffTree, n, myHaffCode) ;
    //输出每个叶结点的哈夫曼编码
    for (int i = 0; i < n; ++i) {
        printf("Weight = %d    Code = ", myHaffCode[i].weight) ;
        for (int j = myHaffCode[i].start; j < n; ++j) {
            printf("%d", myHaffCode[i].bit[j]) ;
        }
        printf("\n") ;
    }
    return 0;
}