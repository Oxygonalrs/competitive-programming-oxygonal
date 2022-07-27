//1299 Leetcode
vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> v(n, 0);
    int maxi = -1;
    v[n-1] = maxi;
    for(int i = n-2; i>=0; i--)
    {
        maxi = max(maxi, arr[i+1]);
        cout<<maxi<<" ";
        v[i] = maxi;
    }
    return v;
}