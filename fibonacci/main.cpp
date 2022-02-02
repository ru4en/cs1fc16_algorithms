#include <iostream>
#include <cstring>
#include <chrono>

int fib = 0;
int fib1 = 1;
int fib2 = 0;

int imp_fib(int count) {
    std::cout << count << " Fibonacci Number using the imperative methord." << std::endl;

    for(int i = 2; i < count; i++){
        fib = fib1 + fib2;
        std::cout << fib2 << std::endl;
        fib1 = fib2;
        fib2 = fib;
    }
    return 0;
}

int rec_fib(int count) {
    if (count == 0)
        return 0;

    if (count == 1)
        return 1;
    std::cout << count << std::endl;
    return rec_fib(count-1)+rec_fib(count-2);
}

int main(int argc, char * argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    int count = strtol(argv[2], NULL, 10);
    
    if (strcmp(argv[1], "-i") == 0){
        imp_fib(count);
    }
    else if(strcmp(argv[1], "-r") == 0){
        std::cout << count << " Fibonacci Number using the imperative methord." << std::endl;
        rec_fib(count);
    }
    else {
        std::cout << "Useage: \n\t./fib [-i/-r] [count] [-t] \n\n\t-i\timperative\n\t-r\trecursive\n\t-t\toutput time taken" << std::endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << std::endl << "Execution Time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}