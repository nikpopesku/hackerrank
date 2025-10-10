#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Spell
{
    string scrollName;

public:
    Spell() = default;

    explicit Spell(string name) : scrollName(std::move(name))
    {
    }

    virtual ~Spell() = default;

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

int nextOccurrence(string s, int i, char c)
{
    for (int j = i; j < s.size(); ++j)
    {
        if (s[j] == c)
        {
            return j - i;
        }
    }

    return -1;
}

void counterspell(Spell* spell)
{
    if (auto* waterSpell = dynamic_cast<Waterbolt*>(spell); waterSpell != nullptr)
    {
        waterSpell->revealWaterpower();
    }
    else if (auto* fireSpell = dynamic_cast<Fireball*>(spell); fireSpell != nullptr)
    {
        fireSpell->revealFirepower();
    }
    else if (auto* thunderSpell = dynamic_cast<Thunderstorm*>(spell); thunderSpell != nullptr)
    {
        thunderSpell->revealThunderpower();
    }
    else if (auto* frostSpell = dynamic_cast<Frostbite*>(spell); frostSpell != nullptr)
    {
        frostSpell->revealFrostpower();
    }
    else
    {
        const string s1 = SpellJournal::read();
        const string s2 = spell->revealScrollName();
        int counter1 = 0, counter2 = 0;
        string common;

        while (counter1 < s1.size() && counter2 < s2.size())
        {
            if (s1[counter1] == s2[counter2])
            {
                common += s1[counter1];
                ++counter1;
                ++counter2;

                continue;
            }

            const int n1 = nextOccurrence(s1, counter1, s2[counter2]);
            const int n2 = nextOccurrence(s2, counter2, s1[counter1]);

            if (n1 == -1)
            {
                ++counter2;
                continue;
            }

            if (n2 == -1)
            {
                ++counter1;
                continue;
            }

            if (n1 < n2)
            {
                counter1 += n1;
            }
            else
            {
                counter2 += n2;
            }
        }

        cout << common.size() << "\n";
    }
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
