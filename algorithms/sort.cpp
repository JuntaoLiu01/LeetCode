#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//O(N^2) in-place
void insertSort(vector<int>& nums){
    int n = nums.size();
    if(n <= 1)
        return;
    for(int i = 1;i < n;i++){
        int a = nums[i];
        for(int j = i-1;j >= 0;j--){
            if(nums[j] > a)
                swap(nums[j],nums[j+1]);
        }
    }
}
//O(N^2) not in-place
void selectSort(vector<int>& nums){
    int n = nums.size();
    if(n <= 1)
        return;
    for(int i = 0;i < n;i++){
        int minNum = nums[i],index = i;
        for(int j = i+1;j < n;j++){
            if(nums[j] < minNum){
                minNum = nums[i];
                index = j;
            }
        }
        swap(nums[i],nums[index]);
    }
}
//O(N^2) in-place
void bubbleSort(vector<int>& nums){
    int n = nums.size();
    if(n <= 1)
        return;
    for(int i = 0;i < n-1;i++){
        for(int j = n-1;j > i;j--){
            if(nums[j] < nums[j-1])
                swap(nums[j],nums[j-1]);
        }
    }
}
//O(NlgN) in-place
void merge(vector<int>& nums,int l,int mid,int r){
    vector<int> tmp(r-l+1);
    int i = l,j = mid+1,k = 0;
    while(i <= mid && j <= r){
        if(nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    while(i <= mid)
        tmp[k++] = nums[i++];
    while(j <= r)
        tmp[k++] = nums[j++];
    for(i=l,k=0;i <= r;i++,k++)
        nums[i] = tmp[k];
}
void mergeSort(vector<int>& nums,int l,int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
}
//O(NlgN) not in-place
void maxHeapify(vector<int>& nums,int root,int n){
    int left = 2*root+1,right = left+1;
    int largest = root;
    if(left < n && nums[left] > nums[root])
        largest = left;
    if(right < n && nums[right] > nums[largest])
        largest = right;
    if(largest != root){
        swap(nums[root],nums[largest]);
        maxHeapify(nums,largest,n);
    }    
}
void buildHeap(vector<int>& nums){
    int n = nums.size();
    int mid = n/2-1;
    for(int i = mid;i >= 0;i--)
        maxHeapify(nums,i,n);
}
void heapSort(vector<int>& nums){
    buildHeap(nums);
    int n = nums.size();
    for(int i = n-1;i > 0;i--){
        swap(nums[0],nums[i]);
        maxHeapify(nums,0,i);
    }
}
// O(NlgN) not in-place
int partition(vector<int>& nums,int l,int r){
    int a = nums[r];
    int i = l-1;
    for(int j = l;j < r;j++){
        if(nums[j] <= a){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[++i],nums[r]);
    return i;
}
void quickSort(vector<int>& nums,int l,int r){
    if(l < r){
        int q = partition(nums,l,r);
        quickSort(nums,l,q-1);
        quickSort(nums,q+1,r);
    }
}

// self_designed compare function
struct TestStruct{
    int val;
    char ch;
    string s;
    TestStruct(int x,char c,string str):val(x),ch(c),s(str) {}
};

bool compare(const TestStruct& a,const TestStruct& b){
    return a.val < b.val;
}

int main(){
    int a[7] = {1,4,3,2,3,5,0};
    vector<int> test(a,a+7);
    // insertSort(test);
    // selectSort(test);
    // bubbleSort(test);
    // mergeSort(test,0,6);
    // heapSort(test);
    // quickSort(test,0,6);
    
    sort(test.begin(),test.end(),greater<int>());
    for(int i = 0;i < test.size();i++)
        cout<<test[i]<<"\t";


    TestStruct t1(1,'a',"aa"),t2(3,'c',"cc"),t3(2,'b',"bb");
    vector<TestStruct> t;
    t.push_back(t1),t.push_back(t2),t.push_back(t3);
    sort(t.begin(),t.end(),compare);
    for(auto _t: t)
        cout<<_t.val<<" ";


    
    return 0;
}