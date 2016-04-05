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

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

// Unoredered_map functions.
#define hash unordered_map
typedef std::unordered_map<int, long> iimap;
typedef std::unordered_map<string, long> simap;
typedef std::unordered_map<long, string> ismap;
template <typename K, typename V>
bool mfind(std::unordered_map<K, V> map, K value) {
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
class dir {
public:
	hash<string, dir> dirs;
};

int main() {
	int t, n, m;
	cin >> t;
	fori(t) {
		int count = 0;		

		cin >> n;
		cin >> m;
		string path;
		hash<string, dir> root_dirs;

		forj(n) {
			cin >> path;
			vector<string> splits = split(path, '/');	
			dir* next_dir = NULL;

			if (mfind(root_dirs, splits[1])) {
				next_dir = &root_dirs[splits[1]];
			} else {
				root_dirs[splits[1]] = dir();
				next_dir = &root_dirs[splits[1]];
			}
	
			for(int xx=2; xx < splits.size(); ++xx) {
				string next_folder = splits[xx];
				if (mfind(next_dir->dirs, next_folder)) {
					next_dir = &(next_dir->dirs[next_folder]);
				}	else {
					next_dir->dirs[next_folder] = dir();
					next_dir = &(next_dir->dirs[next_folder]);
				}
			}
		}

		forj(m) {
			cin >> path;
			vector<string> splits = split(path, '/');	
			dir* next_dir = NULL;
			if (mfind(root_dirs, splits[1])) {
				next_dir = &root_dirs[splits[1]];
			} else {
				++count;
				root_dirs[splits[1]] = dir();
				next_dir = &root_dirs[splits[1]];
			}
			for(int xx=2; xx < splits.size(); ++xx) {
				string next_folder = splits[xx];
				if (mfind(next_dir->dirs, next_folder)) {
					next_dir = &(next_dir->dirs[next_folder]);
				}	else {
					++count;
					next_dir->dirs[next_folder] = dir();
					next_dir = &(next_dir->dirs[next_folder]);
				}
			}
		}
		cout << "Case #" << i+1 << ": " << count << endl;
	}	
}
