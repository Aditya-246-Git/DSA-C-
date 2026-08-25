class Solution {
public:
    int f(vector<vector<int>>& mat,int col,int n){
       int maxele=INT_MIN;
       int index=-1;
       for(int i=0;i<n;i++){
        if(mat[i][col]>maxele){
            maxele=mat[i][col];
            index=i;
        }
       }
       return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat[0].size();  //row
        int n=mat.size();  //col
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+((high-low)/2); //col
            int row=f(mat,mid,n);
            int left=mid-1>=0?mat[row][mid-1]:INT_MIN;
            int right=mid+1<m?mat[row][mid+1]:INT_MIN;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
       return {-1,-1};
    }
};