#include <bits/stdc++.h>
using namespace std;
const int N = 3;

int main() {
	vector<pair<int, int>> logos(N);
	for (int i = 0; i < N; i++) { scanf("%d%d", &logos[i].first, &logos[i].second); }
	long long area = 0;
	for (pair<int, int> p : logos) { area += p.first * p.second; }

	// If area is not a perfect square, then it's already invalid
	int len = 1;
	while (len * len < area) { len++; }

	if (len * len != area) {
		printf("-1");
		return 0;
	}
	// Loop through all rotations of each rectangle
	for (int rotate_mask = 0; rotate_mask < (1 << N); rotate_mask++) { // Ele cria um bitmask para saber se eh para ele rotacionar ou nao esse retangulo.
		vector<string> grid(len, string(len, 'Z'));  // Temporary grid
		// 'Z' represents an empty space in the grid
		int num_placed = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (grid[i][j] == 'Z') {
					if (num_placed == N) {
						// We have already placed all the logos
						goto outer;
					}

					int w = logos[num_placed].first;
					int h = logos[num_placed].second;

					if (rotate_mask & (1 << num_placed)) {
						// Rotate 90 degrees
						swap(w, h);
					}

					// Place configuration
					for (int r = i; r < i + h; r++) {
						for (int c = j; c < j + w; c++) {
							if (r >= len || c >= len || grid[r][c] != 'Z') {
								// Out of bounds or already a logo here
								goto outer;
							}
							grid[r][c] = num_placed + 'A';
						}
					}

					num_placed++;
				}
			}
		}

		// At this point, all logos must be placed
		assert(num_placed == N);

		printf("%d\n", len);
		for (int i = 0; i < len; i++) { printf("%s\n", grid[i].c_str()); }
		return 0;
		// Continue the iteration
	outer:;
	}
	printf("-1");
}