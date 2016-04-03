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

// Vector Functions.
typedef vector<long> VI;
typedef vector<double> VD;
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
	int l, d, n;
	cin >> l;
	cin >> d;
	cin >> n;
	VS dic;
	string word;
	fori(d) {
		cin >> word;
		dic.pb(word);
	}
	string pattern;
	fori(n) {
		cin >> pattern;
		search_replace(pattern, "(", "[");
		search_replace(pattern, ")", "]");
		int ans = 0;
		forj(d) {
			if (is_match(pattern, dic[j])) {
				++ans;
			}
		}	
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
