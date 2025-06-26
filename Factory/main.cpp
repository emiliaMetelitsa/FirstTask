#include <vector>
#include "classes.hpp"

int main() {
	std::vector <IPrintable*> v;

	Factory* animal = new CreateAnimal;
	Factory* fish = new CreateFish;
	Factory* bird = new CreateBird;

	v.emplace_back(animal->Create());
	v.emplace_back(animal->Create());
	v.emplace_back(fish->Create());
	v.emplace_back(fish->Create());
	v.emplace_back(fish->Create());
	v.emplace_back(bird->Create());
	v.emplace_back(bird->Create());
	v.emplace_back(bird->Create());
	v.emplace_back(bird->Create());

	delete[] animal;
	delete[] fish;
	delete[] bird;

	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}

	for (int i = 0; i < size(v); i++) {
		delete[] v[i];
	}

	v.erase(v.begin(), v.end());


}
