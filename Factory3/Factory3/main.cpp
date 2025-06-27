#include <vector>
#include "classes.hpp"

int main() {
	std::vector <IPrintable*> v;

	v.emplace_back(Animal::Create());
	v.emplace_back(Animal::Create());
	v.emplace_back(Fish::Create());
	v.emplace_back(Fish::Create());
	v.emplace_back(Fish::Create());
	v.emplace_back(Bird::Create());
	v.emplace_back(Bird::Create());
	v.emplace_back(Bird::Create());
	v.emplace_back(Bird::Create());

	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}

	for (int i = 0; i < size(v); i++) {
		delete[] v[i];
	}

	v.erase(v.begin(), v.end());


}
