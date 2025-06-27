#include <iostream>
#include <memory>

enum OurType {animal, fish, bird};

class IPrintable {
public:
	virtual ~IPrintable() {}
	virtual void Print() = 0;
};

class Animal : public IPrintable {
public:
	void Print() override {
		std::cout << "Animal" << std::endl;
	}
};

class Fish : public IPrintable {
public:
	void Print() override {
		std::cout << "Fish" << std::endl;
	}
};

class Bird : public IPrintable {
public:
	void Print() override {
		std::cout << "Bird" << std::endl;
	}
};

class Factory{
public:
	static std::unique_ptr<IPrintable> Create(OurType type) {
		switch (type) {
		case 0:
			return std::make_unique<Animal>();
		case 1:
			return std::make_unique<Fish>();
		case 2:
			return std::make_unique<Bird>();
		}

	}
};