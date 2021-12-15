#include <iostream>
#include <future>
#include <vector>
#include <string>
#include <algorithm>
#include <random>


struct Buddhist {
    std::string name;
    int64_t chi{};
};


Buddhist defineWinner(const Buddhist& first, const Buddhist& second) {
    std::cout << "Monk " + first.name + " with chi " + std::to_string(first.chi) + " fights with monk " +
    second.name + " with chi " + std::to_string(second.chi) + ".\n";
    Buddhist winner;
    if(first.chi > second.chi) {
        winner = first;
        winner.chi += second.chi;
    } else if(first.chi < second.chi){
        winner = second;
        winner.chi += first.chi;
    } else {
        if(rand() > 0.5) {
            winner = first;
            winner.chi += second.chi;
        } else {
            winner = second;
            winner.chi += first.chi;
        }
    }
    std::cout << "Monk " + winner.name + " won. Now he has " + std::to_string(winner.chi) + " chi.\n";
    return winner;
}


Buddhist getWinner(std::vector<Buddhist> a) {
    if (a.size() > 2) {
        auto rd = std::random_device {};
        auto rng = std::default_random_engine { rd() };
        std::shuffle(std::begin(a), std::end(a), rng);

        auto left_border = a.size() % 2 == 0 ? a.size() / 2 : a.size() / 2 + 1;

        std::vector<Buddhist> left(a.begin() + left_border, a.end());
        std::vector<Buddhist> right(a.begin(), a.begin() + left_border);

        auto left_winner = std::async(std::launch::async, getWinner, left);
        auto right_winner = std::async(std::launch::async, getWinner, right);

        return defineWinner(right_winner.get(), left_winner.get());

    } else if (a.size() == 2) {
        return defineWinner(a[0], a[1]);
    } else {
        a[0].chi *= 2;
        std::cout << "Monk " + a[0].name + " has rested. Now he has " << std::to_string( a[0].chi) + " chi.\n";
        return a[0];
    }
}

std::vector<Buddhist> getFromLine() {
    std::cout << "Enter the amount of monks:\n";
    std::string line;
    int number_of_monks;
    while (true) {
        try {
            std::cin >> line;
            number_of_monks = stoi(line);
            break;
        } catch (...) {
            std::cout << "Wrong format! Please, try again.\n";
        }
    }

    std::vector<Buddhist> monks;

    while (number_of_monks > 0) {
        try {
            std::cout << "Write name of the monk and his chi in a format <name> <chi>. Chi must be integer.\n";
            std::string name, string_chi;
            std::cin >> name >> string_chi;
            int64_t chi = stoi(string_chi);
            monks.push_back({name, chi});
            --number_of_monks;
        } catch (...) {
            std::cout << "Wrong format! Please, try again.\n";
        }
    }

    return monks;
}


// This method was taken at https://www.codegrepper.com/code-examples/cpp/random+string+c%2B%2B.
std::string  getRandomString(int len) {
    std::string s;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}


std::vector<Buddhist> getRandomly(int n) {

    std::vector<Buddhist> monks;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> random_chi(1, n);
    for (int i = 0; i < n; ++i) {
        monks.push_back({getRandomString(8), random_chi(mt)});
    }
    return monks;
}

int main(int argc, char *argv[]) {
    bool is_manually = false;
    int number_of_monks;
    if(argc == 1) {
        is_manually = true;
    }
    else if(argc == 2) {
        try {
            std::string arg = argv[1];
            number_of_monks = std::stoi(arg);
        } catch (...) {
            std::cout << "Wrong command line argument. You will be asked to enter data manually.\n";
            is_manually = true;
        }
    } else {
        std::cout << "Incorrect amount of command line arguments. You will be asked to enter data manually.\n";
        is_manually = true;
    }
    std::vector<Buddhist> monks;
    if(is_manually) {
        monks = getFromLine();
    } else {
        monks = getRandomly(number_of_monks);
    }
    if(monks.empty()) {
        std::cout << "There are no monks to fight.\n";
        return 0;
    }
    auto winner = getWinner(monks);

    std::cout << "\nAnd the winner is... Monk " << winner.name << " with chi " << winner.chi << "! Congratulations!\n";
}