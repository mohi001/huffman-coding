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
            std::cout << " size: " << level << " | (" << ltr.chr << " ," << ltr.count << ") " << "\n";
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
Node_3 get_node(Node_3 *N, int m_i, int sec_m_i, int third_m_i)
{
    if (m_i != -1)
        N[m_i].visited = true;
    if (sec_m_i != -1)
        N[sec_m_i].visited = true;
    if (third_m_i != -1)
        N[third_m_i].visited = true;
    return {
        {'0',
         (m_i == -1 ? 0 : N[m_i].ltr.count) +
             (sec_m_i == -1 ? 0 : N[sec_m_i].ltr.count) +
             (third_m_i == -1 ? 0 : N[third_m_i].ltr.count)},
        m_i == -1 ? nullptr : &N[m_i],
        sec_m_i == -1 ? nullptr : &N[sec_m_i],
        third_m_i == -1 ? nullptr : &N[third_m_i]};
}
void ternay_hoffman(letter *a, int size)
{
    // letter a[5] = {{'a', 5}, {'b', 10}, {'c', 2}, {'e', 50}, {'k', 25}};
    // letter a[7] = {{'a', 32}, {'b', 12}, {'c', 11}, {'d', 15}, {'e', 23}, {'f', 10}, {'g', 7}};
    // int size = 5;
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
    while (j > 1)
    {
        m_i = min_i(N, size);
        sec_m_i = sec_min_i(N, m_i, size);
        third_m_i = third_min_i(N, m_i, sec_m_i, size);
        new_node = get_node(N, m_i, sec_m_i, third_m_i);
        N[size] = new_node;
        size++;
        j -= 2;
    }
    visit(&new_node, -1, "");
    delete[] N;
}