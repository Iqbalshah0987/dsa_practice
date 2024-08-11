#include<iostream>
using namespace std;



class quick_sort
{
private:
    /* data */
public:
    quick_sort(/* args */){}
    ~quick_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }

    int partition(int *arr, int low, int high){
        int pivot = arr[low];
        int i=low+1, j = high;
        while(i<=j){
            while(i<=j && arr[i]<pivot){
                i++;
            }
            while(i<=j && arr[j]>pivot){
                j--;
            }

            if(i<j){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        swap(arr[low], arr[j]);
        return j;

    }

    void quick(int *arr, int low, int high){
        if(low < high){
            int pivot_loc = partition(arr, low, high);
            // cout<<"pivot="<<pivot_loc<<" "<<arr[pivot_loc]<<endl;
            quick(arr, low, pivot_loc-1);
            quick(arr, pivot_loc+1, high);
        }
    }
    void sort_array(int *arr, int n){
        quick(arr, 0, n-1);
    }

};

int main(int argc, char const *argv[])
{
    quick_sort obj = quick_sort();
    int arr[] = {130, 729, 166, 426, 20, 508, 750, 616, 165, 496, 117, 149, 846, 294, 259, 28, 42, 615, 888, 776, 327, 543, 828, 505, 891, 649, 500, 719, 779, 686, 332, 261, 767, 498, 687, 787, 7, 789, 755, 524, 638, 224, 25, 836, 518, 285, 217, 912, 252, 105};
    // int arr[] = {4,2,5,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


