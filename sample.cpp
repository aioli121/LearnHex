#include <random>
#include <iostream>
#include <iomanip>
#include <chrono>

void test_one_dig_complement_to_0x10(int const total_questions) {
    auto generator = std::mt19937(std::random_device()());
    auto distribution_1_f = std::uniform_int_distribution(0x1, 0xf);

    auto correct_count = int(0x0);

    for (int i = 0x0; i < total_questions; i ++) {
        auto const num = distribution_1_f(generator);

        std::cout << std::hex << "10 - " << num << " = ";
        auto const start_time = std::chrono::steady_clock::now();

        auto guess = int();
        std::cin >> std::hex >> guess;
        auto const end_time = std::chrono::steady_clock::now();
        auto const answer_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        auto const correct = (guess == 0x10 - num);
        if (correct) {
            std::cout << "Correct\n";
            correct_count ++;
        } else {
            std::cout << "Wrong, " << std::hex << "10 - " << num << " = " << (0x10 - num) << "\n";
        }
        std::cout << std::dec << answer_time_in_ms << "\n";
    }

    std::cout << "You got " << correct_count << "/" << total_questions << " (" << (100*correct_count/total_questions) << "%) correct.\n";
}

void test_one_dig_sums_adding_over_0xa(int const total_questions) {
    auto generator = std::mt19937(std::random_device()());
    auto distribution_1_f = std::uniform_int_distribution(0x1, 0xf);

    auto correct_count = int(0x0);

    for (int i = 0x0; i < total_questions; i ++) {
        auto const num_1 = distribution_1_f(generator);

        auto lower_bound_2 = int(0x1);
        if (num_1 < 0x9) {
            lower_bound_2 = 0xa - num_1;
        }

        auto distribution_2 = std::uniform_int_distribution(lower_bound_2, 0xf);
        auto const num_2 = distribution_2(generator);

        std::cout << std::hex << num_1 << " + " << num_2 << " = ";
        auto const start_time = std::chrono::steady_clock::now();

        auto guess = int();
        std::cin >> std::hex >> guess;
        auto const end_time = std::chrono::steady_clock::now();
        auto const answer_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        auto const correct = (guess == num_1 + num_2);
        if (correct) {
            std::cout << "Correct\n";
            correct_count ++;
        } else {
            std::cout << "Wrong, " << std::hex << num_1 << " + " << num_2 << " = " << (num_1+num_2) << "\n";
        }
        std::cout << std::dec << answer_time_in_ms << "\n";
    }

    std::cout << "You got " << correct_count << "/" << total_questions << " (" << (100*correct_count/total_questions) << "%) correct.\n";
}

int main() {
    test_one_dig_complement_to_0x10(0x10);
}
