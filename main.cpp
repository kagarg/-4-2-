#define CATCH_CONFIG_RUNNER

#include "C:\Users\Иван\source\repos\libraries\catch.hpp"

#include "activities.h"

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    return result;
}