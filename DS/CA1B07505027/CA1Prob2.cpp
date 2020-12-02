/*
    Show if a number is a prime.

    @Author:       HAN-WEN, CHANG
    @ID:           B075050527
    @Department:   Engineering Science and Ocean Engineering
    @Affiliation:  National Taiwan University
*/
#include<iostream>
#include <math.h>
using namespace std;

int a[2];

bool isPrime(int p)
{
    if (p <= 1)
        return 0;
    if (p == 2 || p == 3)
        return 1;

    // Divisibility Primality Test
    for (int i = 2; i <= sqrt(p) + 1; i++)
    {
        if (p % i == 0)
            return 0;
    }
    return 1;
}

int *showPrime(int p)
{

    if (isPrime(p))
    {
        a[0] = p;
        a[1] = 0;
    }
    else
    {
        // Find ps and pl
        int ps = p - 1;
        while (!isPrime(ps))
        {
            ps--;
        }
        int pl = p + 1;
        while (!isPrime(pl))
        {
            pl++;
        }
        a[0] = ps;
        a[1] = pl;
    }

    return a;
};
