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

void quickSort(int a[], int left, int right) {
        int i = left, j = right;
        int pivot = a[left + rng() % (right - left)];
        // chia dãy thành 2 phần
        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
    
            if (i <= j) {
                swap(a[i], a[j]);
                ++i;
                --j;
            }
        }
        // Gọi đệ quy để sắp xếp các nửa
        if (left < j) quickSort(a, left, j);
        if (i < right) quickSort(a, i, right);
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
    quickSort(arr,1,n);

    return 0;
}
