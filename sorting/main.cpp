#include <iostream>
#include <ctime>

using namespace std;

void Merge(int arr[], int first, int mid, int last) {
    int n = last - first + 1;//临时数组存合并后的有序序列,n为临时数组长度
    int* tmp = new int[n];
    int i = 0;
    int left = first;
    int right = mid + 1;
    while (left <= mid && right <= last){
        tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
    }
    while (left <= mid){
        tmp[i++] = arr[left++];
    }
    while (right <= last){
        tmp[i++] = arr[right++];
    }
    for (int j = 0; j < n; ++j){
       arr[first + j] = tmp[j];
    }
    delete[] tmp;//删掉堆区的内存
}
void MergeSort(int arr[], int l, int r) {
   if (l == r)
       return;  //递归基是让数组中的每个数单独成为长度为1的区间
   int q = (l + r) / 2;
   MergeSort(arr, l, q);
   MergeSort(arr, q + 1, r);
   Merge(arr, l, q, r);
}

int Parition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low;
    for (int j = low; j < high; ++j)
   {
      //j指向当前遍历元素，如果大于等于pivot，继续向前
      //如果小于当前元素，则和i指向的元素交换
      if (a[j] < pivot) {
        swap(a[j], a[i]);
        i++;
      }
    }
    swap(a[i], a[high]);
    return i;
}
void QuickSort(int a[], int low, int high) {
    if (low < high)
    {
      int q = Parition(a, low, high);
      QuickSort(a, low, q - 1);
      QuickSort(a, q + 1, high);
     }
}

int main()
{
    clock_t start,finish;
    int length;
    cout << "输入待排序数组长度，将自动生成随机数进行排序" << endl;
    
    while(cin>>length){
        int* a = new int[length];
        int* b = new int[length];
        srand((int)time(0));
        for (int i = 0; i <= length; i++)
        {
            a[i] = rand()%length;
            b[i] = rand()%length;
        }
        start=clock();
        MergeSort(a, 0, length - 1);
        finish=clock();
        long totaltime1=(double)(finish-start)*1000/CLOCKS_PER_SEC;
        cout<<"当排"<<length<<"个数时归并排序的运行时间为 "<<totaltime1<<" ms！"<<endl;
        start=clock();
        QuickSort(b, 0, length - 1);
        finish=clock();
        long totaltime2=(double)(finish-start)*1000/CLOCKS_PER_SEC;
        cout<<"当排"<<length<<"个数时快速排序的运行时间为 "<<totaltime2<<" ms！"<<endl;
    }
    return 0;
}
