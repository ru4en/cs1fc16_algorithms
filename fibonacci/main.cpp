#include <iostream>
#include <cstring>
#include <chrono> // timeing library used to mesure exicution time 

int fib = 0; // first second and thirds numbers of fibonacci.
int fib1 = 1;
int fib2 = 0;

int imp_fib(int count) { // function for Fibonacci Number using the imperative methord
    std::cout << count << " Fibonacci Number using the imperative methord." << std::endl;

    for(int i = 2; i < count; i++){ 
        fib = fib1 + fib2;
        std::cout << fib2 << std::endl;
        fib1 = fib2;
        fib2 = fib;
    }
    return fib2;
}

int rec_fib(int count) { // function for Fibonacci Number using the recursive methord
    if (count == 0)
        return 0;
    if (count == 1)
        return 1;
    return rec_fib(count-1)+rec_fib(count-2);
}

void help() { //help function to show how to used this program
    std::cout << "Useage: \n\t./fib [-i/-r] [count] [-t] \n\n\t-i\timperative\n\t-r\trecursive\n\t-t\toutput time taken" << std::endl;
}

int main(int argc, char * argv[]) { // main function

    int count;

    if(argc < 2){ // show help if arguments less then 2
        help();
        return 0;
    }    

    if (argv[2] == NULL){
        count = 30; // set count to 30 as default if user not set
    }else {
        count = strtol(argv[2], NULL, 10);
    }


    if (strcmp(argv[1], "-i") == 0){ // use -i to run the imperative methord
        auto start = std::chrono::high_resolution_clock::now(); // get the start time
        count = imp_fib(count);
        auto stop = std::chrono::high_resolution_clock::now(); // get the end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // measure the duration 
        std::cout << count << std::endl;
        std::cout << std::endl << "Execution Time: " << duration.count() << " microseconds" << std::endl; //print out the duration
    }
    else if(strcmp(argv[1], "-r") == 0){ // use -i to run the recursive methord
        auto start = std::chrono::high_resolution_clock::now(); // get the start time
        std::cout << strtol(argv[2], NULL, 10) << " Fibonacci Number using the Recursive methord." << std::endl;
        count = rec_fib(count);
        auto stop = std::chrono::high_resolution_clock::now(); // get the end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // measure the duration 
        std::cout << count << std::endl;
        std::cout << std::endl << "Execution Time: " << duration.count() << " microseconds" << std::endl; //print out the duration
    }else if(strcmp(argv[1], "-h") == 0){
        help();
    }
    else {
        help();
    }
    
    return 0;
}