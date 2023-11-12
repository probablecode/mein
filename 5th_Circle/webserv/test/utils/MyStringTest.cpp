/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyStringTest.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:14:07 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/25 22:17:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "../../src/utils/MyString.hpp"

int main(void) {
  for (size_t i = 0; i < 1000; i++) {
    std::cout << MyString::GetPreciseTime() << std::endl;
  }
}
