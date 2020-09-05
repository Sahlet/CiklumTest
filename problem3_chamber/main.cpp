#include <iostream>
#include <bits/stdc++.h>

std::vector<std::string> animate(const std::string& init, int speed)
{
    const std::string empty_chamber(init.length(), '.');
    std::string left(empty_chamber), right(empty_chamber);

    for (size_t i = 0; i < init.length(); i++)
    {
        if (init[i] == 'L')
        {
            left[i] = 'X';
        }
        else if (init[i] == 'R')
        {
            right[i] = 'X';
        }
    }
    
    auto merge = [&]() -> std::string
    {
        std::string res(empty_chamber);
        for (size_t i = 0; i < init.length(); i++)
        {
            if (left[i] == 'X' || right[i] == 'X')
            {
                res[i] = 'X';
            }
        }
        
        return std::move(res);
    };

    std::string chamber;
    std::vector<std::string> res;
    res.reserve((init.length() / speed) + 2);
    
    while (true)
    {
        chamber = merge();
        res.push_back(chamber);

        if (chamber == empty_chamber)
        {
            break;
        }

        for (int i = 0; i < (int)left.length(); i++)
        {
            if (i - speed >= 0 && left[i] == 'X')
            {
                left[i - speed] = 'X';
            }
            left[i] = '.';
        }

        for (int i = (int)right.length() - 1; i >= 0; i--)
        {
            if (i + speed < right.length() && right[i] == 'X')
            {
                right[i + speed] = 'X';
            }
            right[i] = '.';
        }
    }
    
    return std::move(res);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    {
        std::vector<std::string> correct_res, resA;
        resA = animate("..R....", 2);
        correct_res = {
            "..X....",
            "....X..",
            "......X",
            "......."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resA.begin()));
    }

    {
        std::vector<std::string> correct_res, resB;
        resB = animate("RR..LRL", 3);
        correct_res = {
            "XX..XXX",
            ".X.XX..",
            "X.....X",
            "......."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resB.begin()));
    }

    {
        std::vector<std::string> correct_res, resC;
        resC = animate("LRLR.LRLR", 2);
        correct_res = {
            "XXXX.XXXX",
            "X..X.X..X",
            ".X.X.X.X.",
            ".X.....X.",
            "........."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resC.begin()));
    }

    {
        std::vector<std::string> correct_res, resD;
        resD = animate("RLRLRLRLRL", 10);
        correct_res = {
            "XXXXXXXXXX",
            ".........."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resD.begin()));
    }

    {
        std::vector<std::string> correct_res, resE;
        resE = animate("...", 1);
        correct_res = {
            "..."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resE.begin()));
    }

    {
        std::vector<std::string> correct_res, resF;
        resF = animate("LRRL.LR.LRR.R.LRRL.", 1);
        correct_res = {
            "XXXX.XX.XXX.X.XXXX.",
            "..XXX..X..XX.X..XX.",
            ".X.XX.X.X..XX.XX.XX",
            "X.X.XX...X.XXXXX..X",
            ".X..XXX...X..XX.X..",
            "X..X..XX.X.XX.XX.X.",
            "..X....XX..XX..XX.X",
            ".X.....XXXX..X..XX.",
            "X.....X..XX...X..XX",
            ".....X..X.XX...X..X",
            "....X..X...XX...X..",
            "...X..X.....XX...X.",
            "..X..X.......XX...X",
            ".X..X.........XX...",
            "X..X...........XX..",
            "..X.............XX.",
            ".X...............XX",
            "X.................X",
            "..................."
        };
        assert(std::equal(correct_res.begin(), correct_res.end(), resF.begin()));
    }
    std::cout << "test passed" << std::endl;
    return 0;
}
