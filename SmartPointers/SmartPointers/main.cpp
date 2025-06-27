#include <vector>
#include "classes.hpp"
#include <memory>

int main() {
	using namespace std;

	std::vector <shared_ptr<IPrintable>> v;

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

	v.erase(v.begin(), v.end());


}
