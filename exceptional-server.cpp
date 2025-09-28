#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Server
{
    static int load;

public:
    static int compute(const long long A, const long long B)
    {
        load += 1;
        if (A < 0)
        {
            throw std::invalid_argument("A is negative");
        }
        const vector v(A, 0);
        int real = -1;
        if (B == 0) throw 0;
        real = (A / B) * real;
        const int ans = v.at(B);
        return real + A - B * ans;
    }

    static int getLoad()
    {
        return load;
    }
};

int Server::load = 0;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long A, B;
        cin >> A >> B;
    }
    try
    {
        cout << Server::getLoad() << "\n";
    }
    catch (const std::bad_alloc&)
    {
        cout << "Not enough memory\n";
    } catch (std::exception& e)
    {
        cout << "Exception: " << e.what();
    } catch (...)
    {
        cout << "Other Exception\n";
    }

    return 0;
}
