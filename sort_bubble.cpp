#include<iostream>
using namespace std;


class bubble_sort
{
private:
    /* data */
public:
    bubble_sort(/* args */){}
    ~bubble_sort(){}

    void swap(int &a, int &b){
        int c;
        c=a;
        a=b;
        b=c;
    }

    void sort_array(int *arr, int n){
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    void sort_array_opt(int *arr, int n){
        bool flag=false;
        for(int i=0; i<n-1; i++){
            flag=false;
            for(int j=0; j<n-1-i; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    flag=1;
                }
            }

            if(!flag){
                break;
            }

        }
    }

};

int main(int argc, char const *argv[])
{
    bubble_sort obj = bubble_sort();
    int arr[] = {4,6,2,1,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    obj.sort_array_opt(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


