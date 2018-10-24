/*
归并排序：
基本思想：将待排序序列【0，n-1】看成是n个长度为1的有序序列，将相邻的有序表成对归并，得到n/2个长度为2的有序表。再次归并，得到n/4个长度为4的有序表。
依次类推，最后得到长度为n的1个有序表。
所以归并排序其实要做两件事：
1、先递归的分解数列，
2、再合并数列就完成了归并排序。
先来考虑如何合并？
每次合并过程中都要对两个有序的序列段进行合并，然后排序
待合并的两个有序序列段分别为 R[low, mid] 和 R[mid+1, high]
先将它们合并到一个暂存数组R2，合并完再将R2复制回R1中。
这样一次合并排序就完成了。
最好、最坏和平均时间复杂度都是O(nlogn)，
空间复杂度是O(n)
eg.
//第一步[ 98 | 1 | 23 | 4 | 2 | 9 | 8 | 18]
//第二步[ 1   98 | 4   23 | 2   9 | 8   18]
//第三步[ 1   4   23   98 | 2   8   9   18]
//第三步[ 1   2    4    9    18    23   98]
*/
#include<stdio.h> 
#include<stdlib.h>
void merge(int data[], int low, int mid, int high) {
    int i, k;
    //定义一个临时数组存放传进来的无序数组排好序之后的数组
    int *temp = (int *)malloc((high-low+1)*sizeof(int));
    //将无序数组分成两个序列
    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;
    //将两个序列比较排序，小的排前
    for(k=0;left_low<=left_high && right_low<=right_high;k++) {
        if(data[left_low]<=data[right_low]) {
            temp[k] = data[left_low++];
        }
        else{
            temp[k] = data[right_low++];
        }
    }
    //左序列如果有剩下元素未排序，加到临时数组的末尾
    if(left_low <= left_high) {
        for(i=left_low;i<=left_high;i++) {
            temp[k++] = data[i];
        }
    }
    //右序列如果有剩下元素未排序，加到临时数组的末尾
    if(right_low <= right_high) {
        for(i=right_low;i<=right_high;i++) {
            temp[k++] = data[i];
        }
    }
    //将排好序的小分组转移到原数组中
    for(i=0;i<high-low+1;i++) {
        data[low+i] = temp[i];
    }
    free(temp);
    return;
}
void mergeSort(int data[], int first, int last) {
    int mid = 0;
    //将数组不停的二分分组再组合，直到每组只剩一个元素
    if(first < last) {
        mid = (first+last)/2;
        mergeSort(data, first, mid);
        mergeSort(data, mid+1, last);
        merge(data, first, mid, last);
    }
    return;
}

 int main() {
    int data[10] = {43, 65, 4, 23, 6, 98, 2, 65, 7, 79};
    int i;
    printf("原先数组:");
    for(i=0;i<10;i++) 
        printf("%d    ", data[i]);
    printf("归并排序:");
    mergeSort(data, 0, 9);
    for(i=0;i<10;i++) 
        printf("%d    ", data[i]);
return 0;
}
