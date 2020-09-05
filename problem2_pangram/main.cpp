#include <iostream>
#include <bits/stdc++.h>

std::string getMissingLetters(std::string s)
{
    for (auto& c: s)
    {
        c = ::toupper(c);
    }

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (auto& c: alphabet)
    {
        c = ::toupper(c);
    }

    std::set<char> alphabet_set(alphabet.begin(), alphabet.end());
    std::set<char> s_set(s.begin(), s.end());
    std::string res;
    res.reserve(alphabet.length());

    for (char letter : alphabet_set)
    {
        if (s_set.find(letter) == s_set.end())
        {
            res.push_back(letter);
        }
    }
    
    return std::move(res);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    assert(getMissingLetters("A quick brown fox jumps over the lazy dog") == "");
    assert(getMissingLetters("Pack my box with five dozen liquor jugs.") == "");
    assert(getMissingLetters("P1a2c3k4 5my box with five dozen liquor jugs.") == "");
    assert(getMissingLetters("abcdefghijklmnopqrstuvwxyz") == "");
    assert(getMissingLetters("abcfghijklmnopqrstuvwxyz") == "DE");
    assert(getMissingLetters("abcdefhijklnopqrtuvwxyz") == "GMS");
    assert(getMissingLetters("AbcdefghijklmNopqrstuvwxyz") == "");
    std::cout << "test passed" << std::endl;
    return 0;
}
