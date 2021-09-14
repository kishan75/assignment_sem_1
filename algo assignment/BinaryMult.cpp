#include <iostream>
using namespace std;

void equalizeBits(string &x, string &y)
{
    int n = x.size();
    int m = y.size();

    if (n < m)
        for (int i = 0; i < m - n; i++)
            x = '0' + x;
    else
        for (int i = 0; i < n - m; i++)
            y = '0' + y;
}

string addBits(string x, string y, int n)
{
    string res;
    int carry = 0;

    equalizeBits(x, y);
    n = x.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int b1 = x[i] - '0';
        int b2 = y[i] - '0';

        int sum = (b1 + b2 + carry) % 2 + '0';
        res = (char)sum + res;

        carry = (b1 + b2 + carry) / 2;
    }
    if (carry)
        res = '1' + res;

    return res;
}

long int multiplyBits(string x, string y)
{
    equalizeBits(x, y);
    int n = x.size();

    if (n == 0)
        return 0;
    if (n == 1)
        return (x[0] - '0') * (y[0] - '0');

    int i = n / 2; //floor
    int j = n - i; //ceil
    string a = x.substr(0, i);
    string b = x.substr(i, j);
    string c = y.substr(0, i);
    string d = y.substr(i, j);

    long int ac = multiplyBits(a, c);
    long int bd = multiplyBits(b, d);
    long int ab_cd = multiplyBits(addBits(a, b, n), addBits(c, d, n));

    return ac * (1 << (2 * j)) + (ab_cd - ac - bd) * (1 << j) + bd;
}

int main()
{
    string x, y;
    cout << "x = \n";
    cin >> x;
    cout << "y = \n";
    cin >> y;

    cout << multiplyBits(x, y);

    return 0;
}
