#include <bits/stdc++.h>
#define TASK "test"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b ; i++)
#define FOD(i,a,b) for(int i = a; i >= b ; i--)
#define task "test"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i) // đếm số bit đang bật
#define BIT(x, i) ((x) & MASK(i)) // trạng thái của bit thứ i trong x
#define SET_ON(x, i) ((x) | MASK(i)) // bật bit thứ i trong x
#define SET_OFF(x, i) ((x) & ~MASK(i)) //  tắt bit thứ i trong x
#define ll long long
#define vt vector
#define C make_pair
template<typename T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return true; } return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val) { res = val; return true; } return false; }
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
const int mod = 1e9 + 7;
const int LOG = 18;
const int N = 1e6 + 9;
const int MAXN = 16;
const ll INF = 1e18 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[N];
int n;

int a[N];

// Sắp xếp các phần tử có chỉ số từ left đến right của mảng data.
void mergeSort(int data[MAXN], int left, int right) {
    if (left == right) {
        // Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
        return ;
    }
    int mid = (left + right) / 2;
    // Sắp xếp 2 phần
    mergeSort(data, left, mid);
    mergeSort(data, mid+1, right);

    // Trộn 2 phần đã sắp xếp lại
    int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
    int cur = 0; // chỉ số trên mảng a

    while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
        if (i > mid) {
            // bên trái không còn phần tử nào
            a[cur++] = data[j++];
        } else if (j > right) {
            // bên phải không còn phần tử nào
            a[cur++] = data[i++];
        } else if (data[i] < data[j]) {
            // phần tử bên trái nhỏ hơn
            a[cur++] = data[i++];
        } else {
            a[cur++] = data[j++];
        }
    }

    // copy mảng a về mảng data
    for (int i = 0; i < cur; i++)
        data[left + i] = a[i];
}

int main()
{
    fast
    if(fopen(TASK".inp","r"))
    {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    //int t; cin >> t;
    cin >> n;
    FOR(i,1,n) cin >> arr[i];
    mergeSort(arr,1,n);

//     FOR(i,1,n) cout << arr[i] << " ";

    return 0;
}
