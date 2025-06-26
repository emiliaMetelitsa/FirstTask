#include <vector>
#include "classes.hpp"

int main() {
	std::vector <IPrintable*> v;

	v.emplace_back(Factory::Create(animal));
	v.emplace_back(Factory::Create(animal));
	v.emplace_back(Factory::Create(fish));
	v.emplace_back(Factory::Create(fish));
	v.emplace_back(Factory::Create(fish));
	v.emplace_back(Factory::Create(bird));
	v.emplace_back(Factory::Create(bird));
	v.emplace_back(Factory::Create(bird));
	v.emplace_back(Factory::Create(bird));

	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}

	for (int i = 0; i < size(v); i++) {
		delete[] v[i];
	}

	v.erase(v.begin(), v.end());


}
