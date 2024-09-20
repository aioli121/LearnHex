#include <random>
#include <iostream>
#include <iomanip>

int main() {
    auto random_device = std::random_device();
    auto generator = std::mt19937(random_device());
    auto distribution_1_f = std::uniform_int_distribution(0x1, 0xf);

    auto correct_count = int(0x0);
    auto const total_questions = int(0x10);

    for (int i = 0x0; i < total_questions; i ++) {
        auto const num_1 = distribution_1_f(generator);

        auto lower_bound_2 = int(0x1);
        if (num_1 < 0x9) {
            lower_bound_2 = 0xa - num_1;
        }

        auto distribution_2 = std::uniform_int_distribution(lower_bound_2, 0xf);
        auto const num_2 = distribution_2(generator);

        std::cout << std::hex << num_1 << " + " << num_2 << " = ";
        auto guess = int();
        std::cin >> std::hex >> guess;

        auto const correct = (guess == num_1 + num_2);
        if (correct) {
            std::cout << "Correct\n";
            correct_count ++;
        } else {
            std::cout << "Wrong, " << std::hex << num_1 << " + " << num_2 << " = " << (num_1+num_2) << "\n";
        }
    }

    std::cout << "You got " << correct_count << "/" << total_questions << " (" << std::setprecision(2) << (100.*correct_count/total_questions) << "%) correct.\n";
}
/*
1 + 9 = a
2 + 8
3 + 7
4 + 6
5 + 5
6 + 4
7 + 3
8 + 2
9 + 1
a + 1
*/