#include<iostream>

void
happyNum(int32_t num) {
    auto copy = num;
    while (num != 1) {
        auto total = 0;
        while (num != 0) {
            uint64_t mod = num % 10;
            total += (mod * mod);
            num /= 10;
        }
        num = total;
        std::cout << "Value of num: " << num << "\n";
    }
    std::cout << "Happy Number: " << copy << "\n";
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Enter the number to be chcked\n";
        return 1;
    }
    uint32_t num = std::atoi(argv[1]);
    std::cout << "Processing " << num << "\n";
    happyNum(num);
}
