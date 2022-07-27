#include<iostream>
using namespace std;

int R=13, C=30;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void floodFill(char input[][50], int i, int j, char ch, char color)
{
    if(i<=0 || j<0 || i>=R || j>=C)
    {
        return;
    }
    if(input[i][j] != ch)
    {
        return;
    }
    input[i][j] = color;
    for(int k=0; k<4; k++)
    {
        floodFill(input, i+dx[k], j+dy[k], ch, color);
    }
    
}


int main()
{
    char R,C;
    cin>>R>>C;

    char input[13][50];
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>input[i][j];
        }
    }
    floodFill(input, 8,9, '.', 'r');
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<input[i][j];
        }
    }
}
/*
..............................
.............#####............
.............#...#............
.......#######...#######......
.....###.....#####.....###....
....##...................##...
....##...................##...
....##...................##...
......##...............##.....
........##...........##.......
..........##.......##.........
............##...##...........
..............###.............

*/