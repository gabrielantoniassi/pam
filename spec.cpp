#include <iostream>

class print {
public:
	template<int a, int b>
	void printAB(){
		std::cout << a << ";" << b << "\n";
	}

	template<>
	void printAB<4,4>(){
		std::cout << "Bunny\n";
	}

};

int main(){

	print a;
	
	a.printAB<5,5>();
	b.printAB<4,4>();


}
