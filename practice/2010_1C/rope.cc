// All the includes.
#include <deque>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Commons.
using namespace std;
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

// Loops.
#define fori(n) for(int i=0; i<n; ++i)
#define forj(n) for(int j=0; j<n; ++j)
#define fork(n) for(int k=0; k<n; ++k)

// String funtions.
typedef stringstream SS;
void search_replace(string& original, string search_for, string replace_string) {
	size_t pos = 0;
	while ((pos = original.find(search_for, pos)) != string::npos) {
		original.replace(pos, search_for.length(), replace_string);
		pos += replace_string.length();			
	}
}

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

// Pair typedefs.
typedef pair<long, long> PII;
typedef pair<double, double> PDD;

// Vector Functions.
typedef vector<long> VI;
typedef vector<double> VD;
typedef vector<pair<long, long>> VPII;
typedef vector<pair<double, double>> VPDD;
typedef vector<long long> VL;
typedef vector<string> VS;
#define sortv(v) sort(v.begin(), v.end())
#define rsortiv(v) sort(v.begin(), v.end(), std::greater<long>())
#define rsortdv(v) sort(v.begin(), v.end(), std::greater<double>())
#define rsortlv(v) sort(v.begin(), v.end(), std::greater<long long>())

// Regular expression.
bool is_match(string pattern, string word) {
	regex rx(pattern);
	return regex_match(word, rx);
}

// Main Logic
int main() {
	int t, n;
	cin >> t;
	fori(t) {
		cin >> n;
		VPII points;
		int a, b;
		int ans = 0;
		forj(n) {
				cin >> a >> b;
				PII point(a, b);
				for (auto prev_p : points) {
					if ((prev_p.first - point.first) * (prev_p.second - point.second) < 0) {
				 		++ans;
					}
			  }
				points.pb(point);
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
} 
