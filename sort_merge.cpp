#include<iostream>
using namespace std;



class merge_sort
{
private:
    /* data */
public:
    merge_sort(/* args */){}
    ~merge_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }

    int merge(int *arr, int low, int high){
        int mid = low + (high-low)/2;
        int i=low, j=mid+1, k=low;
        int b[high];
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                b[k] = arr[i];
                i++;
            }else{
                b[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            b[k] = arr[i];
            i++;
            k++;
        }
        while(j<=high){
            b[k] = arr[j];
            j++;
            k++;
        }

        for(i=low; i<=high; i++){
            arr[i]=b[i];
        }

    }

    void sort_merge(int *arr, int low, int high){
        if(low < high){
            int mid = low + (high-low)/2;
            sort_merge(arr, low, mid);
            sort_merge(arr, mid+1, high);
            merge(arr, low, high);
        }
    }
    void sort_array(int *arr, int n){
        sort_merge(arr, 0, n-1);
    }

};

int main(int argc, char const *argv[])
{
    merge_sort obj = merge_sort();
    int arr[] = {130, 729, 166, 426, 20, 508, 750, 616, 165, 496, 117, 149, 846, 294, 259, 28, 42, 615, 888, 776, 327, 543, 828, 505, 891, 649, 500, 719, 779, 686, 332, 261, 767, 498, 687, 787, 7, 789, 755, 524, 638, 224, 25, 836, 518, 285, 217, 912, 252, 105};
    // int arr[] = {4,2,5,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


