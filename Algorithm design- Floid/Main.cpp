#include <cstdlib> 
#include <iostream> 
#include <time.h> 

int W[30][30];
int D[30][30];
int P[30][30];
int n;

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

void print(int k) {
	std::cout << "D(" << k << "): \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << D[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "-------------------------------------------------- \n";
}

void randomaize() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			P[i][j] = 0;
			if (i == j) {
				W[i][j] = 0;
				continue; 
			}
			W[i][j] = rand() % 150;
			if (W[i][j] == 0 || W[i][j] > 100)
				W[i][j] = 999;
		}
	}
}

void floyd() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
		}
		print(k);
	}
}

using namespace std;

void path(int q, int r) {
	if (P[q][r] != 0) {
		path(q, P[q][r]);
		cout << 'v' << P[q][r] << '\n';
		path(P[q][r], r);
	}
}

int main() {
	bool rnot;
	cout << "If want to have a randomized graph enter 1, else enter 0 \n";
	cin >> rnot;
	if (rnot)
	{
		srand(time(0));
		n = (rand() % 25) + 1;
		randomaize();
		
	}
	else {
		cout << "enter vertex count :";
		cin >> n;
		cout << "enter Adjacency matrix of graph : (for Infini enter a large number) \n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				P[i][j] = 0;
				if (i == j) {
					W[i][j] = 0;
					continue;
				}
				cout << "enter " << i << " ," << j << " number:";
				cin >> W[i][j];
			}
		}
	}

	cout << "W: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << W[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-------------------------------------------------- \n";
	floyd();

	while (true)
	{
		cout << "Please enter to vertex: (between 0 and " << n - 1 << " ) \n";
		int x, y;
		cin >> x >> y;
		cout << "result : " << D[x][y] << '\n';
		cout << "v" << x << endl;
		path(x, y);
		cout << 'v' << y << endl;
	}
	return 0;
}