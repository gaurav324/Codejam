// All the includes.
#include <deque>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

// Commons.
using namespace std;
#define pb push_back;
#define pf push_front;
#define popb pop_back;
#define popf pop_front;

// Loops.
#define fori(n) for(int i=0; i<n; ++i)
#define forj(n) for(int j=0; j<n; ++j)
#define fork(n) for(int k=0; k<n; ++k)

// String funtions.
typedef stringstream SS;

// Unoredered_map functions.
typedef std::unordered_map<int, long> iimap;
typedef std::unordered_map<string, long> simap;
typedef std::unordered_map<long, string> ismap;
template <typename K, typename V>
bool mfind(std::unordered_map<K, V> map, V value) {
	auto search = map.find(value);
	if (search == map.end()) {
	  return false;
	} else {
		return true;
  }
}

// Vector Functions.
typedef vector<long> VI;
typedef vector<double> VD;
typedef vector<long long> VL;
typedef vector<string> VS;
#define sortv(v) sort(v.begin(), v.end());
#define rsortiv(v) sort(v.begin(), v.end(), std::greater<long>());
#define rsortdv(v) sort(v.begin(), v.end(), std::greater<double>());
#define rsortlv(v) sort(v.begin(), v.end(), std::greater<long long>());

// Main Logic
int main() {
	int t, n;
  cin >> t;
  fori(t) {
		cin >> n;
		VL v1, v2;
		long no;
		forj(n) {
			cin >> no;
			v1.push_back(no);
		}
    forj(n) {
			cin >> no;
			v2.push_back(no);
		}
		sortv(v1);
		rsortlv(v2);
		long long ans = 0;
		forj(n) {
			ans += v1[j] * v2[j];
		}
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
