#ifndef UNITTEST_LOG_H
#define UNITTEST_LOG_H

#include <iostream>

#define UNITTEST_LOG_DEBUG(debug) std::cout << debug << std::endl
#define UNITTEST_LOG_ERROR(error) std::cout << error << std::endl
#define UNITTEST_STDOUT std::cout

#endif // UNITTEST_LOG_H
