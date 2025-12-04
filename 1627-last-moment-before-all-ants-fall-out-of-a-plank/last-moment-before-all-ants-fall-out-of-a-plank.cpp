class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
      sort(left.begin(),left.end());
      sort(right.begin(),right.end());
      int m=left.size();
      int k=right.size();
      if(m==0)
      {
        return n-right[0];
      }
      if(k==0)
      {
        return left[m-1];
      }
    else
   { int rt=n-right[0];
  int lt=left[m-1];
    return rt>lt?rt:lt;
}
        
    }
};