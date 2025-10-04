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

    // Available_Workshops() = default;

    explicit Available_Workshops(const int n) : n(n)
    {
        w = new Workshop[n];
    }
};


Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops aw(n);

    for (int i = 0; i < n; ++i)
    {
        aw.w[i] = Workshop(start_time[i], duration[i], start_time[i] + duration[i]);
    }


    return &aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
};

int main(int argc, char* argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
