/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:12:19 by jtollena          #+#    #+#             */
/*   Updated: 2024/09/20 11:53:56 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(){
    Base *i = generate();
    identify(i);
    identify(*i);
    std::cout << std::endl;
    A *a = new A();
	identify(a);
    identify(*a);
    std::cout << std::endl;
    B *b = new B();
	identify(b);
    identify(*b);
    std::cout << std::endl;
    C *c = new C();
	identify(c);
    identify(*c);

    delete i;
    delete a;
    delete b;
    delete c;
    
	return 0;
}