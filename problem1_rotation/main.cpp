#include <iostream>
#include <bits/stdc++.h>
#include <string_view>

bool is_rotation(const std::string& s1, const std::string& s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }

    for (size_t i = 0; i < s1.length(); i++)
    {
        bool restart = false;
        size_t k = 0;
        for (size_t j = i; j < s1.length() && !restart; j++, k++)
        {
            if (s1[j] != s2[k])
            {
                restart = true;
            }
        }

        for (size_t j = 0; j < i && !restart; j++, k++)
        {
            if (s1[j] != s2[k])
            {
                restart = true;
            }
        }

        if (!restart)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    assert(is_rotation("helloworld", "helloworld"));
    assert(is_rotation("helloworld", "elloworldh"));
    assert(is_rotation("helloworld", "loworldhel"));
    assert(is_rotation("loworldhel", "helloworld"));
    assert(!is_rotation("1oworldhel", "helloworld"));
    assert(!is_rotation("helloworld", "helloworl1"));
    assert(!is_rotation("helloworld", "helloworld1"));
    std::cout << "test passed" << std::endl;
    return 0;
}
