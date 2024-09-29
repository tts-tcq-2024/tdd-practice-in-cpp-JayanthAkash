#include "StringCalculator.h"
#include <stdexcept>

int addNumbers(std::vector<int> numbers)
{
    int sum = 0;
    for (int number : numbers)
    {
        sum += number;
    }
    return sum;
}

void check_negative_numbers(std::vector<int> numbers) {
    for (int number : numbers) {
        if (number < 0) {
            throw std::runtime_error("Negative number found");
        }
    }
}

std::vector<int> splitStringToVector(const std::string& input_str) {
    std::vector<int> output_vector;
    int num = 0;

    for (char character : input_str) {
        if (character != ',') {
            num = num * 10 + (character - '0');
        }
        else {
            output_vector.push_back(num);
            num = 0;
        }
    }

    output_vector.push_back(num);

    return output_vector;
}

std::vector<int> parse_numbers(const std::string& input) {
    
    std::vector<int> numbers;
    numbers = splitStringToVector(input);
    return numbers;
}

int StringCalculator::add(const std::string &input) {
	if (input.empty())
		return 0;

	std::vector<int> numbers = parse_numbers(input);

    check_negative_numbers(numbers);

    return addNumbers(numbers);
}
