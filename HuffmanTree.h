//
// Created by antonio on 17-11-28.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H

#include <cstdlib>
#include <cstring>

#define MaxBit 4
#define MaxValue 10000


typedef struct {
    int weight ;//权重
    int flag ;//标记
    int parent ;//双亲结点
    int leftChild ;//左右孩子
    int rightChild ;
}HaffNode;

typedef struct {
    int bit[MaxBit] ;
    int start ;//编码起始下坐标
    int weight ;//字符权重
}Code;//哈夫曼编码的结构

void Haffman(int weight[], int n, HaffNode haffTree[]) ;
/*传入权重数组weight，以及哈夫曼树数组haffTree
 *建立哈夫曼回树并对哈夫曼树初始化
 */
void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[]) ;
/*哈夫曼编码
 *传入哈夫曼树，以及编码结构体
 * 利用创建好的哈夫曼树，进行哈夫曼树的编码操作
 */

#endif //HUFFMANTREE_HUFFMANTREE_H
