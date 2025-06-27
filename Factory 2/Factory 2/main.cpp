#include <vector>
#include "classes.hpp"

int main() {
	std::vector <IPrintable*> v;

	v.emplace_back(Factory::CreateAnimal());
	v.emplace_back(Factory::CreateAnimal());
	v.emplace_back(Factory::CreateFish());
	v.emplace_back(Factory::CreateFish());
	v.emplace_back(Factory::CreateFish());
	v.emplace_back(Factory::CreateBird());
	v.emplace_back(Factory::CreateBird());
	v.emplace_back(Factory::CreateBird());
	v.emplace_back(Factory::CreateBird());

	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}

	for (int i = 0; i < size(v); i++) {
		delete[] v[i];
	}

	v.erase(v.begin(), v.end());


}
