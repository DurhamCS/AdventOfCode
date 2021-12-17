#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    int x1,x2,y1,y2;
    std::vector<int> xVec, yVec;
    std::ifstream fd("input.txt");
    std::string str;
    getline(fd, str);
    std::stringstream ss(str);
    int counter1 = 0;
    while (getline(ss, str, ' '))
    {
        if (counter1 == 2)
        {
            std::stringstream sss(str);
            int counter2 = 0;
            while (getline(sss, str, '.'))
            {
                if  (counter2 == 0)
                {
                    std::stringstream ssss(str);
                    int counter3 = 0;
                    while (getline(ssss, str, '='))
                    {
                        if (counter3 == 1)
                            x1 = stoi(str);
                        counter3++;
                    }
                }
                if (counter2 == 2)
                {
                    x2 = stoi(str);
                }
                counter2++;
            }
        }
        if (counter1 == 3)
        {
            std::stringstream sss(str);
            int counter2 = 0;
            while (getline(sss, str, '.'))
            {
                if  (counter2 == 0)
                {
                    std::stringstream ssss(str);
                    int counter3 = 0;
                    while (getline(ssss, str, '='))
                    {
                        if (counter3 == 1)
                            y1 = stoi(str);
                        counter3++;
                    }
                }
                if (counter2 == 2)
                {
                    y2 = stoi(str);
                }
                counter2++;
            }
        }
        counter1++;
    }

    int x = 0;
    while(x <= x2)
    {
        int c_x = x;
        double sum = x;
        while (sum <= x2 && c_x > 0)
        {
            if (sum >= x1 && sum <= x2)
            {
                xVec.push_back(x);
                break;
            }
            c_x--;
            sum += c_x;
        }
        x++;
    }

    int maxi = 0;
    bool hit = false;
    for (int i = y1; i < -y1; i++)
    {
        int high = i*(i+1)/2, c_high = high;
        int c_y = 0;
        hit = false;
        while(true)
        {
            if (high >= y1 && high <= y2)
                hit = true;
                
            if  (high < y1 && hit)
            {
                yVec.push_back(i);
                maxi = std::max(c_high, maxi);
                break;
            }
            c_y++;
            high -= c_y;
        }
    }

    int counter = 0;
    int n = xVec.size(), m = yVec.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = xVec[i], y = yVec[j];
            int curx = 0, cury = 0, c_x = x, c_y = y;
            while (curx <= x2 && cury >= y1)
            {
                curx += x;
                cury += y;
                if (x != 0)
                    x--;
                y--;
                if (curx >= x1 && curx <= x2 && cury >= y1 && cury <= y2)
                {                    
                    counter++;
                    break;
                }
            }
        }
    }


    std::cout <<"Star 1: " <<maxi <<std::endl;
    std::cout <<"Star 2: " <<counter <<std::endl;
}