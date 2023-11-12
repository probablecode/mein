/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomExceptionTest.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:19:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/26 20:12:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "../../src/utils/CustomException.hpp"

// This function throws CustomException class which has exception type and
// message.
void DummyParsingFunction() {
  throw CustomException(CustomException::kExceptionConfigParsing,
                        "Parsing sucks");
}


int main(void) {
  try {
    DummyParsingFunction();
  } catch (const std::exception& e) {
    // std::cerr << e.What() << '\n';
    // CustomException::TerminationProcess(/*config object*/);
  }
}