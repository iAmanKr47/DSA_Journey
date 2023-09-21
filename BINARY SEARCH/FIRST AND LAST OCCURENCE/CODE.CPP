int firstOcc(int a[], int n, int x)
    {
        int start = 0, end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (a[mid] == x)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (x > a[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastOcc(int a[], int n, int x)
    {
        int start = 0, end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (a[mid] == x)
            {
                ans = mid;
                start = mid + 1;
            }
            else if (x > a[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first = firstOcc(arr,n,x);
        int last= lastOcc(arr,n,x);
        return{first,last};
    }
