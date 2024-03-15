#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> a, int n){
    printf("{");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("}\n");

}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = 0, b = 0, c = 0;
    vector<int> arr;

    while(a < m && b < n && c < m+n){
        if(nums1[a] < nums2[b]){
            arr.push_back(nums1[a]);
            a++;
        }
        else{
            arr.push_back(nums2[b]);
            b++;
        }
        c++;
    }

    while(a < m && c < m+n){
        arr.push_back(nums1[a]);
        a++;
        c++;
    }

    while(b < n && c < m+n){
        arr.push_back(nums2[b]);
        b++;
        c++;
    }

    nums1.assign(arr.begin(), arr.end());
    printArray(nums1, m+n);
}



int main()
{
    vector<int> a={2,4,6,8,10,0,0,0};
    vector<int> b={1,3,5};
    merge(a, 5, b, 3 );

    vector<int> a1={2,4,0,0,0};
    vector<int> b1={3,5,7};
    merge(a1, 2, b1, 3 );

    vector<int> a2={12,14,16,18,20,0,0,0};
    vector<int> b2={1,3,5};
    merge(a2, 5, b2, 3 );

    vector<int> a3={2,0};
    vector<int> b3={3,};
    merge(a3, 1, b3, 1 );

    vector<int> a4={0,0,0};
    vector<int> b4={1,3,5};
    merge(a4, 0, b4, 3 );

    vector<int> a5={2,4,6,8,10,0,0,0};
    vector<int> b5={11,13,15};
    merge(a5, 5, b5, 3 );

    vector<int> a6={2,4,0,0,0,0,0,0};
    vector<int> b6={1,3,5,7,9,11};
    merge(a6, 2, b6, 6 );

    return 0;


}