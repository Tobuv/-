void quicksort(int *a, int left, int right)
{//快速排序 
    if(left >= right)//递归结束条件
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[i];//挖i坑
    while(i < j) /*用基准数划分分区循环*/                             
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，i==j*/ 
        {
            j--;/*向前寻找*/
        }
         
        a[i] = a[j];//填i坑，挖出j坑
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/
         
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
         
        a[j] = a[i];//填j坑，挖出i坑
    }
     
    a[i] = key;/*基准数放到正确位置*/
    quicksort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quicksort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
}


