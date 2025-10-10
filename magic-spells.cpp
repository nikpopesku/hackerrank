#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell
{
private:
    string scrollName;

public:
    Spell() : scrollName("")
    {
    }

    explicit Spell(const string& name) : scrollName(name)
    {
    }

    virtual ~Spell()
    {
    }

    string revealScrollName()
    {
        return scrollName;
    }
};

class Fireball final : public Spell
{
    int power;

public:
    explicit Fireball(const int power) : power(power)
    {
    }

    void revealFirepower() const
    {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite final : public Spell
{
    int power;

public:
    explicit Frostbite(const int power) : power(power)
    {
    }

    void revealFrostpower() const
    {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm final : public Spell
{
    int power;

public:
    explicit Thunderstorm(const int power) : power(power)
    {
    }

    void revealThunderpower() const
    {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell
{
    int power;

public:
    explicit Waterbolt(const int power) : power(power)
    {
    }

    void revealWaterpower() const
    {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal
{
public:
    static string journal;

    static string read()
    {
        return journal;
    }
};

string SpellJournal::journal = "";

void counterspell(Spell* spell)
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
}

class Wizard
{
public:
    Spell* cast()
    {
        Spell* spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire")
        {
            spell = new Fireball(power);
        }
        else if (s == "frost")
        {
            spell = new Frostbite(power);
        }
        else if (s == "water")
        {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder")
        {
            spell = new Thunderstorm(power);
        }
        else
        {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main()
{
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--)
    {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
