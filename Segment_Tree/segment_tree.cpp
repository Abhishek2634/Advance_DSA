#include <bits/stdc++.h>
using namespace std;

vector<int>tree;
void init(int n) {
    tree = vector<int>(n*4);
}

int buildBst(vector<int>arr, int i, int st, int end) { // building a bst.     o(n)
    if(st == end) {
        return tree[i] = arr[st];
    }
    int mid = st + (end-st)/2;
    buildBst(arr, 2*i+1, st, mid);
    buildBst(arr, 2*i+2, mid+1, end);
    tree[i] = tree[2*i+1] + tree[2*i+2];
    return tree[i];
}

void updateUtil(int i, int si, int sj, int idx, int diff) {  // logn
    if(idx > sj || idx < si) {
        return ;
    }
    tree[i] += diff;

    if(si != sj) { // non leaf;
        int mid = (si + sj)/2;
        updateUtil(2*i+1, si, mid, idx, diff);
        updateUtil(2*i+2, mid+1, sj, idx, diff);
    }
}

void update(vector<int>&arr, int idx, int newVal) {
    int n = arr.size();
    int diff = newVal - arr[idx];
    arr[idx] = newVal;

    updateUtil(0, 0, n-1, idx, diff);
}


int getSumUtil(int i, int si, int sj, int qi, int qj) {       // logn
    if(qj < si || qi > sj) {  // non overlapping
        return 0;
    }else if(si >= qi && sj <= qj) { // complete overlapping
        return tree[i];
    }else{  // partial overlap.
        int mid = (si+sj)/2;
        int left = getSumUtil(2*i+1, si, mid, qi, qj);
        int right = getSumUtil(2*i+2, mid+1, sj, qi, qj);

        return left + right;
    }
}


int getSum(vector<int>arr, int qi, int qj) {
    int n = arr.size();
    return getSumUtil(0, 0, n-1, qi, qj);  // query index
}

int main() {
    vector<int>arr{1,2,3,4,5,6,7,8};

    int n = arr.size();
    init(n);
    buildBst(arr, 0, 0, n-1);

    for(int i = 0; i < tree.size(); i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
    cout << getSum(arr, 2, 6) << '\n';


    update(arr, 2, 2); // update 
    cout << getSum(arr, 2, 6) << '\n';


    // creation time = O(n);
    // total nodes = 2n -1 
    // total level = log Base 2 ki power n. (n is size of array).

}