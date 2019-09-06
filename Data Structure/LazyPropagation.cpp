#include <stdio.h> 
#include <math.h> 
#define MAX 1000 
int tree[MAX] = {0};   
int lazy[MAX] = {0};  

/*  si -> index of current node in segment tree 
    ss and se -> Starting and ending indexes of elements for 
                 which current nodes stores sum. 
    us and ue -> starting and ending indexes of update query 
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) {
    if (lazy[si] != 0) {
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        }  
        lazy[si] = 0; 
    }  
    if (ss>se || ss>ue || se<us) 
        return ; 
    if (ss>=us && se<=ue) { 
        tree[si] += (se-ss+1)*diff; 
        if (ss != se) { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);  
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
  
void updateRange(int n, int us, int ue, int diff) { 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
/*  A recursive function to get the sum of values in given 
    range of the array. The following are parameters for 
    this function. 
    si --> Index of current node in the segment tree. 
           Initially 0 is passed as root is always at' 
           index 0 
    ss & se  --> Starting and ending indexes of the 
                 segment represented by current node, 
                 i.e., tree[si] 
    qs & qe  --> Starting and ending indexes of query 
                 range */
int getSumUtil(int ss, int se, int qs, int qe, int si) { 
    if (lazy[si] != 0) { 
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) { 
            // Since we are not yet updating children os si, 
            // we need to set lazy values for the children 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 
    if (ss>=qs && se<=qe) 
        return tree[si]; 
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
  
// Return sum of elements in range from index qs (quey 
// start) to qe (query end).  It mainly uses getSumUtil() 
int getSum(int n, int qs, int qe) { 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(0, n-1, qs, qe, 0); 
} 
  
// A recursive function that constructs Segment Tree for 
//  array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtil(int arr[], int ss, int se, int si) { 
    if (ss > se) 
        return ; 
    if (ss == se) { 
        tree[si] = arr[ss]; 
        return; 
    } 
    int mid = (ss + se)/2; 
    constructSTUtil(arr, ss, mid, si*2+1); 
    constructSTUtil(arr, mid+1, se, si*2+2); 
  
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 
  
void constructST(int arr[], int n) { 
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, 0); 
} 