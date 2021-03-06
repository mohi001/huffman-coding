#include<iostream>
#include "header.h"
struct Node
{
    letter ltr = {'0', 0};
    Node *right = nullptr;
    Node *left = nullptr;
    bool visited = false;
    void print(int level, std::string str)
    {
        if (this->ltr.chr != '0')
            // std::cout << " size: " << level << " | (" << ltr.chr << " ," << ltr.count << ") " << str << "\n";
            std::cout << "( " << ltr.chr << " ," << ltr.count << " ) "
                      << ": " << level << "\n";
    }
};
int min_i(Node *ltrs, int size)
{
    int min_ind = -1;
    int min = INT32_MAX;

    for (int i = 0; i < size; i++)
    {
        if (ltrs[i].ltr.count < min && !ltrs[i].visited)
        {
            min = ltrs[i].ltr.count;
            min_ind = i;
        }
    }
    return min_ind;
}
int sec_min_i(Node *ltrs, int min_ind, int size)
{

    int sec_min_ind = -1;
    int sec_min = INT32_MAX;

    for (int i = 0; i < size; i++)
    {
        if (ltrs[i].ltr.count < sec_min && i != min_ind && !ltrs[i].visited)
        {
            sec_min = ltrs[i].ltr.count;
            sec_min_ind = i;
        }
    }
    return sec_min_ind;
}
void sort(Node *a, int size)
{
    Node tmp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j].ltr.count > a[j + 1].ltr.count)
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void visit(Node *root, int level, std::string str)
{
    if (root)
    {
        level++;
        visit(root->left, level, str + "0");
        root->print(level, str);
        visit(root->right, level, str + "1");
    }
}
void bin_huffman(letter *a, int size)
{
    Node *N = new Node[size * 2];
    for (int i = 0; i < size; i++)
    {
        N[i].ltr = a[i];
    }
    //is sorting necessary???
    // sort(N, size);
    int m_i;
    int sec_m_i;
    Node new_node;
    int j = size;
    while (j > 1)
    {
        m_i = min_i(N, size);
        sec_m_i = sec_min_i(N, m_i, size);
        N[m_i].visited = true;
        N[sec_m_i].visited = true;
        new_node = {{'0', N[m_i].ltr.count + N[sec_m_i].ltr.count}, &N[sec_m_i], &N[m_i]};
        N[size] = new_node;
        size++;
        j--;
    }
    visit(&new_node, -1, "");
    delete[] N;
}