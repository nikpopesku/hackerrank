#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end_time;

    Workshop() = default;

    Workshop(const int start_time, const int duration, const int end_time) : start_time(start_time), duration(duration),
                                                                             end_time(end_time)
    {
    }
};

struct Available_Workshops
{
    int n;
    // Workshop w[n];
    Workshop* w;

    explicit Available_Workshops(const int n) : n(n)
    {
        w = new Workshop[n];
    }
};


Available_Workshops* initialize(int start_time[], int duration[], const int n)
{
    auto* aw = new Available_Workshops(n);

    for (int i = 0; i < n; ++i)
    {
        aw->w[i] = Workshop(start_time[i], duration[i], start_time[i] + duration[i]);
    }

    return aw;
}

int CalculateMaxWorkshops(const Available_Workshops* ptr)
{
    // Sort by end_time ascending to apply greedy selection
    sort(ptr->w, ptr->w + ptr->n, [](const Workshop& a, const Workshop& b) {
        if (a.end_time == b.end_time) return a.start_time < b.start_time;
        return a.end_time < b.end_time;
    });

    int count = 0;
    int last_end = -1;
    for (int i = 0; i < ptr->n; ++i)
    {
        if (ptr->w[i].start_time >= last_end)
        {
            ++count;
            last_end = ptr->w[i].end_time;
        }
    }
    return count;
}

int main()
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    const auto start_time = new int[n];
    const auto duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    const Available_Workshops* ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;

    delete[] start_time;
    delete[] duration;
    delete ptr;

    return 0;
}
