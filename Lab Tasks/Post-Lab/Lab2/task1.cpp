#include <iostream>

int main(int argc, char* arg[]) {
        if (argc < 2) return 1;
        int* arr = new int[atoi(arg[1])];
        int sum = 0;
        for (int i = 0; i < atoi(arg[1]); i++) {
                arr[i] = atoi(arg[i+2]);
                sum += atoi(arg[i+2]);
        }
        std::cout << "Sum is " <<  sum << std::endl;
        std::cout << "Average is " << static_cast<float>(sum)/atoi(arg[1]);
        return 0;
}
