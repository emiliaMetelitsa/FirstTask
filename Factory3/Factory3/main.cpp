#include <vector>
#include "classes.hpp"

int main() {
	std::vector <IPrintable*> v;

	v.emplace_back(Animal::CreateByInterface());
	v.emplace_back(Animal::CreateByInterface());
	v.emplace_back(Fish::CreateByInterface());
	v.emplace_back(Fish::CreateByInterface());
	v.emplace_back(Fish::CreateByInterface());
	v.emplace_back(Bird::CreateByInterface());
	v.emplace_back(Bird::CreateByInterface());
	v.emplace_back(Bird::CreateByInterface());
	v.emplace_back(Bird::CreateByInterface());

	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}

	for (int i = 0; i < size(v); i++) {
		delete[] v[i];
	}

	v.erase(v.begin(), v.end());


}
