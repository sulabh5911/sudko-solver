#include<iostream>
using namespace std;
#include<vector>
bool isvalid(vector<vector<char>>&boards,int row,int col,char c){
    for(int i=0;i<9;i++){
        if(boards[i][col]==c){
            return false;
        }
        if(boards[row][i]==c){
            return false;
        }
        if(boards[3*(row/3)+i/3][3*(col/3)+i%3]==c){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>&boards){
    for(int i=0;i<boards.size();i++){
        for(int j=0;j<boards[0].size();j++){
            if(boards[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(boards,i,j,c)){
                        boards[i][j]=c;
                        if(solve(boards)){
                            return true;
                        }
                        else{
                            boards[i][j]='.';
                        }
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}

int main(){
    vector<vector<char>>boards{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    
    solve(boards);	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<boards[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}