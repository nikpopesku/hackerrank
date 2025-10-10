#include <iostream>
#include <string>
#include <utility>
#include <vector>

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

string SpellJournal::journal;

int longestCommonSubsequence(const string& text1, const string& text2)
{
    vector dp(text1.size() + 1, vector(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); ++i)
    {
        for (int j = 1; j <= text2.size(); ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[text1.size()][text2.size()];
}

void counterspell(Spell* spell)
{
    if (const auto* waterSpell = dynamic_cast<Waterbolt*>(spell); waterSpell != nullptr)
    {
        waterSpell->revealWaterpower();
    }
    else if (const auto* fireSpell = dynamic_cast<Fireball*>(spell); fireSpell != nullptr)
    {
        fireSpell->revealFirepower();
    }
    else if (const auto* thunderSpell = dynamic_cast<Thunderstorm*>(spell); thunderSpell != nullptr)
    {
        thunderSpell->revealThunderpower();
    }
    else if (const auto* frostSpell = dynamic_cast<Frostbite*>(spell); frostSpell != nullptr)
    {
        frostSpell->revealFrostpower();
    }
    else
    {
        const string s1 = SpellJournal::read();
        const string s2 = spell->revealScrollName();
        cout << longestCommonSubsequence(s1, s2) << "\n";
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
        delete spell;
    }
    return 0;
}
