class Solution {
public:
    void merge(vector<int> &ar, int l, int m, int r, vector<int> &tempAr){
        int i;
        int j;
        int k = l;
        // copy elements of both halves into a temporary array
        for(i=l;i<=m;i++){
            tempAr[i] = ar[i];
        }
        
        for(j=m+1;j<=r;j++){
            tempAr[j] = ar[j];
        }
        
        i = l, j = m+1;
        while(i<=m && j<=r){
            if(tempAr[i] <= tempAr[j]){
                ar[k++] = tempAr[i++];
            }else{
                ar[k++] = tempAr[j++];
            }
        }
        while(i<=m){
            ar[k++] = tempAr[i++];
        }
        while(j<=r){
            ar[k++] = tempAr[j++];
        }
    }
    
    void mergeSort(vector<int> &ar, int l, int r, vector<int> &tempAr){
        if(l>=r)
            return;
        
        int m = (l+r)/2;
        // Sort first and second halves recursively
        mergeSort(ar, l, m, tempAr);
        mergeSort(ar, m+1, r, tempAr);
        
        // Merge the sorted halves
        merge(ar, l, m, r, tempAr);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int>tempAr(nums.size());
        mergeSort(nums, 0, nums.size() - 1, tempAr);
        return nums;
    }
}; 