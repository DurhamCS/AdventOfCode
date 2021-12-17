#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

std::string Translate(char c)
{
    if (c == '0') return "0000";
    if (c == '1') return "0001";
    if (c == '2') return "0010";
    if (c == '3') return "0011";
    if (c == '4') return "0100";
    if (c == '5') return "0101";
    if (c == '6') return "0110";
    if (c == '7') return "0111";
    if (c == '8') return "1000";
    if (c == '9') return "1001";
    if (c == 'A') return "1010";
    if (c == 'B') return "1011";
    if (c == 'C') return "1100";
    if (c == 'D') return "1101";
    if (c == 'E') return "1110";
    if (c == 'F') return "1111";
}

long long int Binary2Dec(std::string bin, int &j)
{
    long long int ans = 0, n = bin.size();
    j += n;
    for (int i = 0; i < n; i++)
    {
        if (bin[i] == '1')
            ans += std::pow(2,n-1-i);
    }
    return ans;
}

long long int Binary2Dec(std::string bin)
{
    long long int ans = 0, n = bin.size();
    for (int i = 0; i < n; i++)
    {
        if (bin[i] == '1')
            ans += std::pow(2,n-1-i);
    }
    return ans;
}

long long int ReadLiteral(std::string &code)
{
    std::string literal = "";
    int i = 6;
    while (code[i] == '1')
    {
        i++;
        literal += code.substr(i,4);
        i += 4;
    }
    i++;
    literal += code.substr(i,4);
    i += 4;
    int n = code.size();
    code = code.substr(i, n-i);
    return Binary2Dec(literal);
}

int Solve(std::string code)
{
    int n = code.size(), i = 0;
    int versionSum = Binary2Dec(code.substr(i,3),i);
    int id = Binary2Dec(code.substr(i,3),i);
    int length;
    if (id != 4)
    {
        int lId = Binary2Dec(code.substr(i,1),i);
        if (lId == 1)
            length = Binary2Dec(code.substr(i,11),i);
        else
            length = Binary2Dec(code.substr(i,15),i);

        versionSum += Solve(code.substr(i, n-i));
    }
    else
    {
        while(code[i] == '1')
            i += 5;
        i += 5;
        int j = i;
        while (j < n && code[j] == '0')
            j++;
        if (i < n && j < n)
            versionSum += Solve(code.substr(i,n-i));
    }
    return versionSum;
}

long long int ALU(long long int prevAns, long long int nextAns, int op)
{
    if (op == 0)
        return prevAns + nextAns;
    if (op == 1)
        return prevAns * nextAns;
    if (op == 2)
        return std::min(prevAns, nextAns);
    if (op == 3)
        return std::max(prevAns, nextAns);
    if (op == 5)
        return (prevAns > nextAns);
    if (op == 6)
        return (prevAns < nextAns);
    if (op == 7)
        return (prevAns == nextAns);
}

long long int Solve2(std::string &code)
{
    int n = code.size(), i = 3, length;
    long long int ans = 0;
    int id = Binary2Dec(code.substr(i,3),i);

    if (id != 4)
    {
        if (Binary2Dec(code.substr(i,1),i) == 1)
        {
            length = Binary2Dec(code.substr(i,11),i);
            code = code.substr(i, n-i);
            ans = Solve2(code);
            for (int j = 1; j < length; j++)
                ans = ALU(ans, Solve2(code), id);
        }
        else
        {
            length = Binary2Dec(code.substr(i,15),i);
            code = code.substr(i, n-i);
            n = code.size();
            ans = Solve2(code);
            length -= (n-code.size());
            n = code.size();
            while (0 < length)
            {
                ans = ALU(ans, Solve2(code), id);
                length -= (n-code.size());
                n = code.size();
            }
        }
        return ans;
    }
    return ReadLiteral(code);
}

int main() 
{
    std::string line, code = "";
    std::ifstream fd("input.txt");
    std::vector<long long int> solves;
    getline(fd, line);

    int n = line.size();
    for (int i = 0; i < n; i++)
    {
        code += Translate(line[i]);
    }
    std::cout <<"Star 1: "<<Solve(code) <<std::endl;
    std::cout <<"Star 2: "<<Solve2(code) <<std::endl;
}