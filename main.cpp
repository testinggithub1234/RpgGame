#include <iostream>
#include "Engine.h"

using namespace std;

int main() {
    shared_ptr<Engine> engine(new Engine);

    try{
        engine->Go();
    }
    catch(char* end){
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}