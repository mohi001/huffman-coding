#pragma once
struct letter
{
    char chr = 0;
    int count = 0;
};
void ternay_huffman(letter *a, int size);
void bin_huffman(letter *a, int size);