#include <iostream>
#include <thread>

void helloWorldAsync() {
    std::cout << "Hello world!" << std::endl;
}

int maein(){
    std::thread asyncHello(helloWorldAsync);
    asyncHello.join();
}