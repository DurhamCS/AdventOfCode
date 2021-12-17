#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>

std::unordered_set<std::string> answer;

bool inside(std::string &vertex, std::vector<std::string> &curr_path)
{
    
    if (vertex == "start") 
        return true;
    if (vertex == "end" || isupper(vertex[0])) 
        return false;
    int n = curr_path.size();
    for (int i = 0; i < n; i++)
        if(curr_path[i] == vertex) {
            return true;
        }    
    return false;
} 

bool inside2(std::string &vertex, std::vector<std::string> &curr_path, bool &exists)
{
    if (vertex == "start") 
        return true;
    if (vertex == "end" || isupper(vertex[0])) 
        return false;
    int n = curr_path.size(), counter = 0;
    for (int i = 0; i < n; i++)
        if(curr_path[i] == vertex) {
            if (exists)
                return true;
            exists = true;
            counter++;
        }    
    return false;
} 

void bfs(std::vector<std::pair<std::string, std::string>> &edge, int &j, int &n, std::vector<std::string> curr_path) 
{
    std::string temp =  "";
    if (edge[j].first == "end") {
        temp =  "";
        for (int i = 0; i < curr_path.size(); i++) {
            temp += curr_path[i];
        }
        answer.insert(temp);
        return;
    }
    for (int i = 0; i < n; i++) 
    {
        if (edge[i].first == edge[j].second && !inside(edge[i].first, curr_path))
        {
            curr_path.push_back(edge[i].first);
            bfs(edge, i, n, curr_path);
            curr_path.pop_back();
        }
    }
}

void bfs2(std::vector<std::pair<std::string, std::string>> &edge, int j, int &n, std::vector<std::string> curr_path, bool exists) 
{
    std::string temp =  "";
    if (edge[j].first == "end") {
        temp = "";
        for (int i = 0; i < curr_path.size(); i++) {
            temp += curr_path[i];
        }
        answer.insert(temp);
        return;
    }
    for (int i = 0; i < n; i++) 
    {
        bool prexists = exists;
        if (edge[i].first == edge[j].second && !inside2(edge[i].first, curr_path, exists))
        {
            curr_path.push_back(edge[i].first);
            bfs2(edge, i, n, curr_path, exists);
            curr_path.pop_back();
            exists = prexists;
        }
    }
}

int main() {
    std::vector<std::pair<std::string, std::string>> edge;
    std::string temp, v1, v2;
    std::ifstream fd("input.txt");
    while(fd >> temp) 
    {
        std::stringstream ss(temp);
        int counter = 0;
        while(getline(ss, temp, '-'))
        {
            if (counter %2  == 0)
                v1 = temp;
            else 
            {
                v2 = temp;
            }
            counter++;
        }
        edge.push_back(std::make_pair(v1,v2));
        edge.push_back(std::make_pair(v2,v1));
    }
    int n = edge.size();

    std::vector<std::string> curr_path;
    for (int i = 0; i < n; i++)
    {
        if (edge[i].first == "start")
        {
            curr_path.push_back(edge[i].first);
            bfs(edge, i, n, curr_path);
            curr_path.clear();
        }
    }
    std::cout <<"Star 1: " <<answer.size() <<std::endl;
    answer.clear();
    for (int i = 0; i < n; i++)
    {
        if (edge[i].first == "start")
        {
            curr_path.push_back(edge[i].first);
            bfs2(edge, i, n, curr_path, false);
            curr_path.clear();
        }
    }
    std::cout <<"Star 2: " <<answer.size() <<std::endl;
    
    return 0;
}