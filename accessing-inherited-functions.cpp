#include<iostream>

using namespace std;

class A
{
public:
    A()
    {
        callA = 0;
    }

private:
    int callA;

    void inc()
    {
        callA++;
    }

protected:
    void func(int& a)
    {
        a = a * 2;
        inc();
    }

public:
    int getA()
    {
        return callA;
    }
};

class B
{
public:
    B()
    {
        callB = 0;
    }

private:
    int callB;

    void inc()
    {
        callB++;
    }

protected:
    void func(int& a)
    {
        a = a * 3;
        inc();
    }

public:
    int getB()
    {
        return callB;
    }
};

class C
{
public:
    C()
    {
        callC = 0;
    }

private:
    int callC;

    void inc()
    {
        callC++;
    }

protected:
    void func(int& a)
    {
        a = a * 5;
        inc();
    }

public:
    int getC()
    {
        return callC;
    }
};


// A a;
// B b;
// C c;
//
// int getA()
// {
//     return a.getA();
// }
//
// int getB()
// {
//     return b.getB();
// }
//
// int getC()
// {
//     return c.getC();
// }


class D: A, B, C
{
    int val;

public:
    //Initially val is 1
    D()
    {
        val = 1;
    }


    //Implement this function
    void update_val(const int new_val)
    {
        while (val < new_val)
        {
            if (mcp(val * 2, new_val) <= new_val)
            {
                A::func(val);
            }
            if (mcp(val * 3, new_val) <= new_val)
            {
                B::func(val);
            }
            if (mcp(val * 5, new_val) <= new_val)
            {
                C::func(val);
            }
        }
    }

    static int gcd(int a, int b)
    {
        if (b > a)
        {
            swap(a, b);
        }

        if (a == b)
        {
            return a;
        }

        return gcd(a - b, b);
    }

    static int mcp(const int a, const int b)
    {
        return a * b / gcd(a, b);
    }

    //For Checking Purpose
    void check(int); //Do not delete this line.
};


void D::check(const int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " <<
        getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}
