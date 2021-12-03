#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("day2input.txt");
    string line;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int aim = 0;
    while(getline(input, line)){
        int value = line.back() - '0';
        switch(line[0]){
            case 'f':
                x1+=value;
                x2+=value;
                y2+=aim*value; 
                break;
            case 'u':
                y1-=value;
                aim-=value;
                break;
            case 'd':
                y1+=value;
                aim+=value;
                break;
        }
    }
    cout << x1 * y1 << ' ' << x2 * y2 << '\n';
    return 0;
}
