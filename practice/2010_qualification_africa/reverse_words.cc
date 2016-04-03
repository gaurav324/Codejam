#include "/users/gauravnanda/codejam/codejam.h"

int main() {
	int n;
	cin >> n;

	// This is required to clear the last trailing endofline.
	string s;
	getline(cin, s);

	fori(n) {
		std:deque<string> result;
		string line;
		getline(cin, line);
		SS ss(line);
		string word;
		while (ss >> word) {
	    result.push_front(word);  		
		}
		cout << "Case #" << i+1 << ": ";
		for (auto w : result) {
			cout << w << " ";
		}
	  cout << std::endl;
	}
}
