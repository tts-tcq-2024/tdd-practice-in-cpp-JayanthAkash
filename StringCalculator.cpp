#include "StringCalculator.h"
#include <stdexcept>

int sum_numbers(std::vector<int> numbers)
{
    int sum = 0;
    for (int number : numbers)
    {
        if (number < 1000) {
            sum += number;
        }
    }
    return sum;
}

std::string get_negative_numbers(const std::vector<int> numbers) {
    std::string negativeNumbers;

    for (int number : numbers) {
        if (number < 0) {
            negativeNumbers += std::to_string(number) + " ";
        }
    }
    return negativeNumbers;
}

void check_negative_numbers(const std::vector<int> numbers) {
    std::string negativeNumbers;

    negativeNumbers = get_negative_numbers(numbers);

    if (!negativeNumbers.empty()) {
        throw std::runtime_error("Negative numbers found: " + negativeNumbers);
    }
}

std::string get_delimiter(std::string& input_str) {

    std::string delimiter = ",";
    std::string numbers_str = input_str;

    if (numbers_str.rfind("//", 0) == 0) {
        delimiter = numbers_str[2];
        input_str = numbers_str.substr(4);
    }
    else {
        input_str = numbers_str;
    }
    return delimiter;
}

bool is_delimter(char character, std::string delimiter)
{
    return (character != delimiter[0] && character != '\n');
}

std::vector<int> split_string_to_vector(const std::string& input_str) {
    std::vector<int> output_vector;
    int num = 0;
    std::string delimiter = get_delimiter((std::string&)input_str);

    for (char character : input_str) {
        if (is_delimter(character, delimiter)) {
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
    numbers = split_string_to_vector(input);
    return numbers;
}

int StringCalculator::add(const std::string &input) {
	if (input.empty())
		return 0;

	std::vector<int> numbers = parse_numbers(input);

    check_negative_numbers(numbers);

    return sum_numbers(numbers);
}
