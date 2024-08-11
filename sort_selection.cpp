#include<iostream>
using namespace std;



class selection_sort
{
private:
    /* data */
public:
    selection_sort(/* args */){}
    ~selection_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }

    void sort_array(int *arr, int n){
        int min;
        for(int i=0; i<n; i++){
            min = i;
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
            if(min!=i){
                swap(arr[i], arr[min]);
            }
        }
    }

};

int main(int argc, char const *argv[])
{
    selection_sort obj = selection_sort();
    int arr[] = {130, 729, 166, 426, 20, 508, 750, 616, 165, 496, 117, 149, 846, 294, 259, 28, 42, 615, 888, 776, 327, 543, 828, 505, 891, 649, 500, 719, 779, 686, 332, 261, 767, 498, 687, 787, 7, 789, 755, 524, 638, 224, 25, 836, 518, 285, 217, 912, 252, 105};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


