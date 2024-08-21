/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:12:19 by jtollena          #+#    #+#             */
/*   Updated: 2024/08/21 14:30:53 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
	Data *data = new Data;
	data->nombre = 5;
	data->string = "SALUT";
	uintptr_t ui = Serializer::serialize(data);
	Data *cpyData = Serializer::deserialize(ui);
	std::cout << cpyData->nombre << std::endl << cpyData->string << std::endl;

	Data originalData;
    originalData.nombre = 42;
    originalData.string = "Hello, world!";
    
    unsigned long raw = Serializer::serialize(&originalData);
    
    Data* deserializedData = Serializer::deserialize(raw);
    
    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Nombre: " << deserializedData->nombre << std::endl;
        std::cout << "String: " << deserializedData->string << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }
	
	return 0;
}