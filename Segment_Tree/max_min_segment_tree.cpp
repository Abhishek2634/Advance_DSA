#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void init(int n) {
    tree = vector<int>(4 * n);
}

void buildTree(int i, int si, int sj, vector<int>& arr) {  // n
    if (si == sj) {
        tree[i] = arr[si];
        return;
    }

    int mid = (si + sj) / 2;
    buildTree(2 * i + 1, si, mid, arr);
    buildTree(2 * i + 2, mid + 1, sj, arr);

    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int getMaxUtil(int i, int si, int sj, int qi, int qj) {  // logn
    if (si > qj || sj < qi) {
        return INT_MIN; // No overlap
    } else if (si >= qi && sj <= qj) {
        return tree[i]; // Complete overlap
    } else {
        int mid = (si + sj) / 2;
        int leftAns = getMaxUtil(2 * i + 1, si, mid, qi, qj);
        int rightAns = getMaxUtil(2 * i + 2, mid + 1, sj, qi, qj);
        return max(leftAns, rightAns); // Partial overlap
    }
}

int getMax(vector<int>& arr, int qi, int qj) {
    int n = arr.size();
    return getMaxUtil(0, 0, n - 1, qi, qj);
}

void updateUtil(int i, int si, int sj, int idx, int newVal) { // logn
    if (si == sj) {
        tree[i] = newVal;
        return;
    }

    int mid = (si + sj) / 2;
    if (idx <= mid) {
        updateUtil(2 * i + 1, si, mid, idx, newVal);
    } else {
        updateUtil(2 * i + 2, mid + 1, sj, idx, newVal);
    }

    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

void update(vector<int>& arr, int idx, int newVal) {
    arr[idx] = newVal;
    int n = arr.size();
    updateUtil(0, 0, n - 1, idx, newVal);
}

int main() {
    vector<int> arr{6, 8, -1, 2, 17, 1, 3, 2, 4};
    int n = arr.size();
    init(n);
    buildTree(0, 0, n - 1, arr);

    cout << getMax(arr, 2, 5) << "\n"; // 17

    update(arr, 2, 20);
    cout << getMax(arr, 2, 5) << '\n'; // 20
}
