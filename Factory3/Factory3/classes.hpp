#include <iostream>

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
	static IPrintable* CreateByInterface(){
		return new Animal;
	}
};

class Fish : public IPrintable {
public:
	void Print() override {
		std::cout << "Fish" << std::endl;
	}
	static IPrintable* CreateByInterface() {
		return new Fish;
	}
};

class Bird : public IPrintable {
public:
	void Print() override {
		std::cout << "Bird" << std::endl;
	}
	static IPrintable* CreateByInterface() {
		return new Bird;
	}
};