#include<iostream>
#include "header.h"
int main(int argc, char const *argv[])
{
    using namespace std;
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
        int a = std::stoi(input);
        if (std::system("clear"))
        {
            fprintf(stderr, "faild to clear \n");
        };
        cout << "enter number of letters\n";

        cin >> n;
        cout << "pleas enter alphabetes and their frequency\n";
        cout << "e.g: a 10\n";
        i = n;
        letter l[n];
        switch (a)
        {
        case 1:
            while (i--)
            {
                cin >> l[i].chr >> l[i].count;
            }
            bin_huffman(l, n);
            break;
        case 2:
            while (i--)
            {
                cin >> l[i].chr >> l[i].count;
            }
            ternay_huffman(l, n);
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
