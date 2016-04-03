#include "/users/gauravnanda/codejam/codejam.h"

int main() {
  int n, C, l, p;
  cin >> n;
  fori(n) {
  	cin >> C;
  	cin >> l;
 	 
		hash(int, int) map;
		forj(l) {
		  cin >> p;
			if (mfind(map, C-p)) {
			  cout << "Case #" << i+1 << ": " <<  map[C-p]+1 << " " << j+1 << std::endl;
			} else {
				map[p] = j;
			}
    }
  }
}
