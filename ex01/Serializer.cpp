
#include "Serializer.hpp"

//Constructor
Serializer::Serializer() {
}

//Destructor
Serializer::~Serializer() {
}

//Copy-Constructor
Serializer::Serializer(Serializer const &serializer) {
	*this = serializer;
}

//Copy-Assignment Operator Overload
Serializer&	Serializer::operator=(Serializer const &serializer){
	(void) serializer;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>((void *)ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}
