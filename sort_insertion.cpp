#include<iostream>
#include<ctime> // for time
#include<cstdlib>   // for rand() and srand()
using namespace std;



class insertion_sort
{
private:
    /* data */
public:
    insertion_sort(/* args */){}
    ~insertion_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }

    void sort_array(int *arr, int n){
        int j, temp;
        for(int i=1; i<n; i++){
            temp = arr[i];
            j=i-1;
            while(j>=0 && arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }

};

int main(int argc, char const *argv[])
{
    insertion_sort obj = insertion_sort();
    int arr[] = {130, 729, 166, 426, 20, 508, 750, 616, 165, 496, 117, 149, 846, 294, 259, 28, 42, 615, 888, 776, 327, 543, 828, 505, 891, 649, 500, 719, 779, 686, 332, 261, 767, 498, 687, 787, 7, 789, 755, 524, 638, 224, 25, 836, 518, 285, 217, 912, 252, 105};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    // cout<<rand()<<endl;
    // cout<<time(0)<<endl;
    // // srand(time(0));
    // cout<<rand()<<endl;
    // cout<<time(0)<<endl;
    return 0;
}


