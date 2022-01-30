#include "pch.h"
struct letter
{
    char chr = 0;
    int count = 0;
};
struct Node_3
{
    letter ltr = {'0', 0};
    Node_3 *right = nullptr;
    Node_3 *middle = nullptr;
    Node_3 *left = nullptr;
    bool visited = false;
    void print(int level, std::string str)
    {
        if (this->ltr.chr != '0')
            // std::cout << " size: " << level << " | (" << ltr.chr << " ," << ltr.count << ") " << str << "\n";
            std::cout << "( " << ltr.chr << " ," << ltr.count << " ) "
                      << ": " << level << "\n";
    }
};
int min_i(Node_3 *ltrs, int size)
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
int sec_min_i(Node_3 *ltrs, int min_ind, int size)
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
int third_min_i(Node_3 *ltrs, const int min_ind, const int sec_min_ind, int size)
{

    int third_min_ind = -1;
    int third_min = INT32_MAX;

    for (int i = 0; i < size; i++)
    {
        if (ltrs[i].ltr.count < third_min && i != min_ind && i != sec_min_ind && !ltrs[i].visited)
        {
            third_min = ltrs[i].ltr.count;
            third_min_ind = i;
        }
    }
    return third_min_ind;
}
void visit(Node_3 *root, int level, std::string str)
{
    if (root)
    {
        level++;
        root->print(level, str);
        visit(root->left, level, str + "0");
        visit(root->middle, level, str + "1");
        visit(root->right, level, str + "2");
    }
}
void ternay_huffman(letter *a, int size)
{
    Node_3 *N = new Node_3[size * 2];
    for (int i = 0; i < size; i++)
    {
        N[i].ltr = a[i];
    }
    int m_i;
    int sec_m_i;
    int third_m_i;
    Node_3 new_node;
    int j = size;
    if (!(size % 2))
    {
        //add a dummy leaf
        N[size] = {{'0', 0}};
        size++;
    }

    while (j > 1)
    {
        m_i = min_i(N, size);
        sec_m_i = sec_min_i(N, m_i, size);
        third_m_i = third_min_i(N, m_i, sec_m_i, size);
        new_node = {{'0', N[m_i].ltr.count + N[sec_m_i].ltr.count +
                              N[third_m_i].ltr.count},
                    &N[m_i],
                    &N[sec_m_i],
                    &N[third_m_i]};
        N[size] = new_node;
        N[m_i].visited = true;
        N[sec_m_i].visited = true;
        N[third_m_i].visited = true;
        size++;
        j -= 2;
    }
    visit(&new_node, -1, "");
    delete[] N;
}