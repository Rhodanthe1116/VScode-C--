/*
    Procut of two array.

    @Author:       HAN-WEN, CHANG
    @ID:           B075050527
    @Department:   Engineering Science and Ocean Engineering
    @Affiliation:  National Taiwan University
*/
#include<iostream>
using namespace std;

int dotProduct(int a[], int b[], int n)
{
    int sum = 0;
    // Product
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
};
