#include<iostream>
using namespace std;



class heap_sort
{
private:
    /* data */
public:
    heap_sort(/* args */){}
    ~heap_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }
    void max_heapify(int *arr, int n, int i){
        int largest = i;
        int left = (2*i)+1;
        int right = (2*i)+2;

        if(left<n && arr[left]>arr[largest]){
            largest = left;
        }

        if(right<n && arr[right]>arr[largest]){
            largest = right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            max_heapify(arr, n, largest);
        }

    }

    void build_heap(int *arr, int n){
        int non_leaf_node = n/2-1;
        for(int i=non_leaf_node; i>=0; i--){
            max_heapify(arr, n, i);
        }
    }

    void delete_heap(int *arr, int n){
        for(int i=n-1; i>0; i--){
            swap(arr[0], arr[i]);
            max_heapify(arr, i, 0);
        }
    }

    void sort_array(int *arr, int n){
        build_heap(arr,n);
        delete_heap(arr, n);
    }

};

int main(int argc, char const *argv[])
{
    heap_sort obj = heap_sort();
    int arr[] = {130, 729, 166, 426, 20, 508, 750, 616, 165, 496, 117, 149, 846, 294, 259, 28, 42, 615, 888, 776, 327, 543, 828, 505, 891, 649, 500, 719, 779, 686, 332, 261, 767, 498, 687, 787, 7, 789, 755, 524, 638, 224, 25, 836, 518, 285, 217, 912, 252, 105};
    // int arr[] = {4,2,5,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


