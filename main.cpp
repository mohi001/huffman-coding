#include "pch.h"
struct letter
{
    char chr = 0;
    int count = 0;
};
void ternay_huffman(letter *a, int size);
void bin_huffman(letter *a, int size);
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