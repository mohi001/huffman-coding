#include "pch.h"
struct letter
{
    char chr = 0;
    int count = 0;
};
void ternay_hoffman(letter *a, int size);
void bin_hoffman(letter *a, int size);
int main(int argc, char const *argv[])
{
    using namespace std;
    // std::cin >> n;
    // letter a[5] = {{'a', 5}, {'b', 10}, {'c', 2}, {'e', 50}, {'k', 25}};
    // letter a[7] = {{'a', 32}, {'b', 12}, {'c', 11}, {'d', 15}, {'e', 23}, {'f', 10}, {'g', 7}};
    letter a[6] = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45},
    };
    cout << "welcome\n";
    std::string input;
    int n;
    int i;
    while (1)
    {
        cout << "please chose a numebr\nor enter q to exit\n";
        cout << "1: binary\n";
        cout << "2: ternay\n";
        getline(std::cin, input);
        if (input == "q" || input == "exit")
        {
            std::cout << "bye...";
            break;
        }
        // cout << "thi" << input << "thi";
        // getchar();
        int a = std::stoi(input);
        if (std::system("clear"))
        {
            fprintf(stderr, "faild to clear \n");
        };
        cout << "enter number of letters\n";

        cin >> n;
        i = n;
        letter l[n];
        switch (a)
        {
        case 1:
            while (i--)
            {
                cin >> l[i].chr >> l[i].count;
            }
            bin_hoffman(l,n);
            break;
        case 2:
            while (i--)
            {
                cin >> l[i].chr >> l[i].count;
            }
            ternay_hoffman(l,n);
            break;
        default:
            std::cout << "\033[1;31minvalid \033[0m\n";
            std::cout << "\n";
            break;
        }
        getline(std::cin, input);
    }
    return 0;
}