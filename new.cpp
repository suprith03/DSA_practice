#include<bits/stdc++.h>
using namespace std;


void printArr(vector<int>&arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}

// selection sort

void selectionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i < n;i++) {
        int miniIndex = i;
        int j = i + 1;
        while(j < n) {
            if(arr[j] < arr[miniIndex]) {
                miniIndex = j;
            }
            j++;
        }
        swap(arr[miniIndex],arr[i]);
    }
}


/// merge sort

void mergeTwoSortedArrays(vector<int>&arr,int low,int mid,int high) {
    int i = low;
    int j = mid + 1;

    vector<int>temp;
    while( i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for(int i = low;i <= high; i++) {
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int>&arr,int low,int high) {
    if(low >= high) {
        return ;
    }
    int mid = (low + high)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,high);
    mergeTwoSortedArrays(arr,low,mid,high);
}


// insertion sort
void insertionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i < n;i++) {
        int j = i;
        while( j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j] , arr[j-1]);
            j--;
        }
    }
}


// bubble sort
void bubbleSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i<n ;i++) {
       for(int j = 0 ; j < n - i -1; j++) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j],arr[j+1]);
        }
    }
} 
}


// quick sort

int partition(vector<int>&arr,int low,int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while(arr[j] >= pivot && j >= low + 1) {
            j--;
        }

        if(i < j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>&arr,int low,int high) {
    if(low < high) {
        int pivotIndex = partition(arr,low,high);
        quickSort(arr,low,pivotIndex - 1);
        quickSort(arr,pivotIndex + 1, high);
    }
}

int powerXN(int x, int n) {
    if(n == 0) {
        return 1;
    }
    return powerXN(x,n-1) * x;
}

// brute force O(n^2);
int missingNumber(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return -1;
}

// using XOR O(n);
// xor of same number is always 0
// eg 3 ^ 3  = 0.

int XorMissingNumber(vector<int>& arr) {
    int n = arr.size();
    int Xor = 0;

    for (int i = 0; i < n; i++) {
         Xor ^= i^arr[i];
    }
    return Xor^n;
}

int SLargestElement(vector<int>& arr) {
    int n = arr.size();
 
    sort(arr.begin(), arr.end());

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != arr[n - 1]) {
            return arr[i];
        }
    }
    return -1;
}

int optiSLargest(vector<int>& arr) {
    int n = arr.size();
    int largestt = -1, sLargestt = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largestt) {
            sLargestt = largestt;
            largestt = arr[i];
        } else if (arr[i] < largestt && arr[i] > sLargestt) {
            sLargestt = arr[i];
        }
    }
    return sLargestt;
}

int kthLargestElement(vector<int>& arr, int k) {
    int n = arr.size();

    priority_queue<int> pq;
    // push ele
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    //pop until reaches k
    for (int i = 1; i < k; i++) {
        pq.pop();
    }
    // return top ele
    return pq.top();
}

int findDuplicates(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int dp_climbStairs(int n) {
    if (n <= 1) 
    return 1;

    vector<int> dp(n);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}
// best
int climbStairs(int n) {
    if (n <= 1)
        return 1;

    int prev1 = 1, prev2 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
// house robber using dp;
int houseRobber(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) 
        return 0;
    if (n == 1)
        return arr[0];

    vector<int> dp(n, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }
    return dp[n - 1];
}

int noDPHouseRobber(vector<int>& arr) {
    int n = arr.size();

    if (n == 0)
        return 0;
    if ( n == 1)
        return arr[0];

    int prev1 = arr[0];
    int prev2 = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int curr = max(prev1 + arr[i], prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int currSum = 0;
    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

// BFS Taversal

vector<int>bfsTraversal(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    vector<int> bfs;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it: adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// DFS Traversal

void dfs (int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res) {
    vis[node] = 1;
    res.push_back(node);

    for (int neighbour: adj[node]) {
        if(!vis[neighbour]) {
            dfs(neighbour, adj, vis, res);
        }
    }
}

int main() {
    // int n;
    // cin >> n;
    // vector<int>arr;
    // for(int i=0;i<n;i++) {
    //     int ele;
    //     cin >> ele;
    //     arr.push_back(ele);
    // }

    // quickSort(arr,0,n-1);
    // printArr(arr);

    // int x,n;
    // cin >> x >> n;
    // cout << powerXN(x,n);
    
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // cin >> k;
    // cout << kthLargestElement(arr, k);

    // vector<int> arr(n);

    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // cout << findDuplicates(arr);


    // int ways = dp_climbStairs(n);
    // cout << ways;

    // vector<int> arr(n);
 
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // cout << maxSubArray(arr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    vector<int> res;

    dfs(0, adj, vis, res);
    // bfs 
    // vector<int> res = bfsTraversal(n, adj);

    for (int node: res) {
        cout << node << " ";
    }

    return 0;
}