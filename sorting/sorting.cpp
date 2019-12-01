//实现归并排序、快速怕挨徐算法，要求输入不同长度的随机数列都可以得到正确的结果

#include<iostream>
#include<ctime>
using namespace std;


/*归并排序算法：*/

void Merge(int* numbers, int start, int mid, int end) {
     int* temp = new int[end - start + 1];                  //申请空间
     int firstSectionIndex = start;                          //序列1的起始位置索引
     int secondSectionIndex = mid + 1;                      //序列2的起始位置索引
     int tempIndex = 0;                                     //所申请的空间索引

     while(firstSectionIndex <= mid && secondSectionIndex <= end) {             //循环直到由一个序列达到终止位置
         if(numbers[firstSectionIndex] <= numbers[secondSectionIndex]) {
             temp[tempIndex] = numbers[firstSectionIndex];
             tempIndex ++;
             firstSectionIndex ++;
         }
         else{
             temp[tempIndex] = numbers[secondSectionIndex];
             tempIndex ++;
             secondSectionIndex ++;
         }
     }

     while(firstSectionIndex <= mid){
         temp[tempIndex] = numbers[firstSectionIndex];
         tempIndex ++;
         firstSectionIndex ++;
     }

     while(secondSectionIndex <= end){
         temp[tempIndex] = numbers[secondSectionIndex];
         tempIndex ++;
         secondSectionIndex ++;
     }

     for(int i=0; i < tempIndex; i++)                 //将排好序的元素父子回原来的数组中
         numbers[start + i] = temp[i];
    
     delete [] temp;
}

void MergeSort(int* numbers, int start, int end) {
    if(numbers == NULL || start >= end)
        return;
    
    int mid = (start + end) / 2;

    MergeSort(numbers, start, mid);                //递归排序从start到mid
    MergeSort(numbers, mid + 1 ,end);              //递归排序从mid + 1到end

    Merge(numbers, start, mid, end);
}

/*快速排序算法：*/

int classify(int array[], int low, int high) {                     //以最后一个元素为标准值，将比它大的放右边，比它小的放左边
    int pivot = array[high];
    int i = low;
    for (int j = low; j < high; ++j)
   {
      //j指向当前遍历元素，如果大于等于pivot，继续向前
      //如果小于当前元素，则和i指向的元素交换
      if (array[j] < pivot) {
        swap(array[j], array[i]);
        i++;
      }
    }
    swap(array[i], array[high]);
    return i;   
}

void quicksort(int a[], int low, int high){
    if (low < high)
    {
        int q = classify(a, low, high);
        quicksort(a, low, q-1);
        quicksort(a, q+1, high);
    }
    
}

int main() {
    int length;
    std::cout << "输入数组长度：";
    std::cin >> length;
    int* a = new int[length];
    int* b = new int[length];
    srand((int)time(0));
    for(int i=0; i<length; i++){
        a[i] = rand() % length;
        b[i] = rand() % length;
    }

    clock_t start, finish;
    double time1;
    start = clock();
    MergeSort(a, 0, length-1);
    finish = clock();
    time1 = (double)(finish - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "归并排序" << length << "个元素的时间： " << time1 << "ms\n";

    double time2;
    start = clock();
    quicksort(b, 0, length-1);
    finish = clock();
    time2 = (double)(finish - start) * 1000 / CLOCKS_PER_SEC;
    std::cout << "快速排序" << length << "个元素的时间： " << time2 << "ms\n";

}