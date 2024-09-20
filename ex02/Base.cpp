
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
	srand(time(0));
	int random = (rand() % (3 - 1 + 1)) + 1;
	switch (random){
		case 1: return new A;
		case 2: return new B;
		case 3: return new C;
	}
	return NULL;
}

void	identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NOT FOUND" << std::endl;
}

void	identify(Base &p){
	try {
		(void)(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	} catch(std::exception &e){
		try {
			(void)(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		} catch(std::exception &e){
			try {
				(void)(dynamic_cast<C&>(p));
				std::cout << "C" << std::endl;
			} catch(std::exception &e){
				std::cout << "NOT FOUND" << std::endl;
			}
		}	
	}
}