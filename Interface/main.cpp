#include <vector>
#include "kek.hpp"

int main() {


	std::vector <IPrintable*> v;


	v.emplace_back((IPrintable*)new Animal);
	v.emplace_back((IPrintable*)new Animal);
	v.emplace_back((IPrintable*)new Fish);
	v.emplace_back((IPrintable*)new Fish);
	v.emplace_back((IPrintable*)new Fish);
	v.emplace_back((IPrintable*)new Bird);
	v.emplace_back((IPrintable*)new Bird);
	v.emplace_back((IPrintable*)new Bird);
	v.emplace_back((IPrintable*)new Bird);


	for (int i = 0; i < size(v); i++) {
		v[i]->Print();
	}


	for (int k = 0; k < size(v); k++) {
		delete[] v[k];
	}


	v.erase(v.begin(), v.end());


	return 0;
}
