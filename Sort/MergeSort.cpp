/*
�鲢����
����˼�룺�����������С�0��n-1��������n������Ϊ1���������У������ڵ������ɶԹ鲢���õ�n/2������Ϊ2��������ٴι鲢���õ�n/4������Ϊ4�������
�������ƣ����õ�����Ϊn��1�������
���Թ鲢������ʵҪ�������£�
1���ȵݹ�ķֽ����У�
2���ٺϲ����о�����˹鲢����
����������κϲ���
ÿ�κϲ������ж�Ҫ��������������жν��кϲ���Ȼ������
���ϲ��������������жηֱ�Ϊ R[low, mid] �� R[mid+1, high]
�Ƚ����Ǻϲ���һ���ݴ�����R2���ϲ����ٽ�R2���ƻ�R1�С�
����һ�κϲ����������ˡ�
��á����ƽ��ʱ�临�Ӷȶ���O(nlogn)��
�ռ临�Ӷ���O(n)
eg.
//��һ��[ 98 | 1 | 23 | 4 | 2 | 9 | 8 | 18]
//�ڶ���[ 1   98 | 4   23 | 2   9 | 8   18]
//������[ 1   4   23   98 | 2   8   9   18]
//������[ 1   2    4    9    18    23   98]
*/
#include<stdio.h> 
#include<stdlib.h>
void merge(int data[], int low, int mid, int high) {
    int i, k;
    //����һ����ʱ�����Ŵ����������������ź���֮�������
    int *temp = (int *)malloc((high-low+1)*sizeof(int));
    //����������ֳ���������
    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;
    //���������бȽ�����С����ǰ
    for(k=0;left_low<=left_high && right_low<=right_high;k++) {
        if(data[left_low]<=data[right_low]) {
            temp[k] = data[left_low++];
        }
        else{
            temp[k] = data[right_low++];
        }
    }
    //�����������ʣ��Ԫ��δ���򣬼ӵ���ʱ�����ĩβ
    if(left_low <= left_high) {
        for(i=left_low;i<=left_high;i++) {
            temp[k++] = data[i];
        }
    }
    //�����������ʣ��Ԫ��δ���򣬼ӵ���ʱ�����ĩβ
    if(right_low <= right_high) {
        for(i=right_low;i<=right_high;i++) {
            temp[k++] = data[i];
        }
    }
    //���ź����С����ת�Ƶ�ԭ������
    for(i=0;i<high-low+1;i++) {
        data[low+i] = temp[i];
    }
    free(temp);
    return;
}
void mergeSort(int data[], int first, int last) {
    int mid = 0;
    //�����鲻ͣ�Ķ��ַ�������ϣ�ֱ��ÿ��ֻʣһ��Ԫ��
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
    printf("ԭ������:");
    for(i=0;i<10;i++) 
        printf("%d    ", data[i]);
    printf("�鲢����:");
    mergeSort(data, 0, 9);
    for(i=0;i<10;i++) 
        printf("%d    ", data[i]);
return 0;
}
