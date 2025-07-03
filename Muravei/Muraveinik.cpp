#include <iostream>
#include <list>
#include <set>

using namespace std;

struct coords {
	unsigned int x;
	unsigned int y;

	bool operator<(const coords& other) const {
		if (x < other.x) {
			return true;
		}
		else if (x == other.x && y < other.y) {
			return true;
		}
		return false;
	}
};

int Sum(int a) {

	int sum = 0;

	while (a / 10 > 0) {
		sum += a % 10;
		a /= 10;
	}
	sum += a % 10;

	return sum;
}

bool IsAvaible(int x, int y) {
	int a = Sum(x) + Sum(y);
	if (a <= 25) {
		return true;
	}
	return false;
}

int Finding(unsigned int coord1, unsigned int coord2) {

	set<coords> visited;
	list<coords> q;
	

	unsigned int i = coord1;
	unsigned int j = coord2;

	q.push_back({ i,j });

	while (!q.empty()) {

		if (!visited.count({ i, j })) {

			if ((IsAvaible(i + 1, j))) {
				q.push_back({ i + 1,j });
			}
			if ((IsAvaible(i, j + 1))) {
				q.push_back({ i,j + 1 });
			}
			if ((i - 1 >= 0) && (IsAvaible(i - 1, j))) {
				q.push_back({ i - 1,j });
			}
			if ((j - 1 >= 0) && (IsAvaible(i, j - 1))) {
				q.push_back({ i,j - 1 });
			}

		}

		visited.insert(q.front());
		q.pop_front();

		if (!q.empty()) {
			i = q.front().x;
			j = q.front().y;
		}

	}

	return visited.size();
}

int main()
{
	int count = Finding(1000, 1000);
	cout << count << endl;
	return 0;
}
