#include <iostream>
#include<string>
using namespace std;
int checkUserMove(char,char,string);
int checkComputerMove(int,string);
bool checkWin(char,string);
void DisplayBox(string);
int whoMoveFirst();
void displayComputerMove(int);
int main()
{ //start of main
    srand(time(0));//to generate unique numbers
    char choice;
    do
    {
        bool check=true;
        int index;
        char input1,input2;
        cout<<endl;
        string storeMoves=" ";
        DisplayBox(storeMoves);
        int randNum=whoMoveFirst(); //to generate any random number
//if randomly generated number is even, computer will make first move
        if(randNum%2==0){
            int randomMove=rand()%9; //to generate random move for computer (0 to 8)

            randomMove=checkComputerMove(randomMove,storeMoves);
//function call: check and validate the move and return the index number
            storeMoves[randomMove]='O'; //against that move mark board box with O
            displayComputerMove(randomMove); //display computer move on screen against that board index
            DisplayBox(storeMoves); //display updated board
        }
        //untill check is true
        while(check)
        {
            cout<<"Enter your move: ";
            cin>>input1>>input2;//input the move from user
            index=checkUserMove(input1,input2,storeMoves);
//function call: check and validate the move and will return the board index number against that move
            storeMoves[index]='X'; //against that move mark board box with X
            cout<<endl;
            DisplayBox(storeMoves); //display updated board
            check=checkWin('X',storeMoves); //check if X is the winner or not
            //if check is true
            if(check){
                int randomMove=rand()%9; //to generate random move for computer (0 to 8)

                randomMove=checkComputerMove(randomMove,storeMoves);
//function call: check and validate the move and return the index number
                        storeMoves[randomMove]='O'; //against that move mark board box with O
                displayComputerMove(randomMove); //display computer move on screen against that board index
                DisplayBox(storeMoves); //display updated board
                check=checkWin('O',storeMoves); //check if O is the winner or not
            }
        }
        cout<<"Enter y OR Y to play again or anyother key to exit: "<<endl;
        cin>>choice; //ask the user if he/she wants to play another game or not
    }while(choice=='y' || choice=='Y'); //untill choice is y or y
    return 0;
}//end of main
/* displayComputerMove function will display the computer move
using computer
* randomly generated board index number and display the move in
the
* form of first Alphabet and second digit like A1 or B3 or C2
*/
void displayComputerMove(int randomMove){
    if(randomMove==0){
        cout<<"\nComputer Move: A1"<<endl;
    }else if(randomMove==1){
        cout<<"\nComputer Move: B1"<<endl;
    }else if(randomMove==2){
        cout<<"\nComputer Move: C1"<<endl;
    }else if(randomMove==3){
        cout<<"\nComputer Move: A2"<<endl;
    }else if(randomMove==4){
        cout<<"\nComputer Move: B2"<<endl;
    }else if(randomMove==5){
        cout<<"\nComputer Move: C2"<<endl;
    }else if(randomMove==6){
        cout<<"\nComputer Move: A3"<<endl;
    }else if(randomMove==7){
        cout<<"\nComputer Move: B3"<<endl;
    }else if(randomMove==8){
        cout<<"\nComputer Move: C3"<<endl;
    }
    cout<<endl;
}
//whoMoveFirst function will generate and return the random number
int whoMoveFirst(){
    srand(time(0));
    return rand();
}
/*checkUserMove function will check the user entered move if move
is valid
* it'll ask the user again to enter valid move and will check
again
* if move is valid or not, itt enter valid move.
*/
int checkUserMove(char input1,char input2,string storeMoves)
{
    while(true)
    {
        if(input1=='A' && input2=='1' && storeMoves.at(0)==' ')
        {
            return 0;
        }else if(input1=='B' && input2=='1' && storeMoves.at(1)==' '){
            return 1;
        }else if(input1=='C' && input2=='1' && storeMoves.at(2)==' '){
            return 2;
        }else if(input1=='A' && input2=='2' && storeMoves.at(3)==' '){
            return 3;
        }else if(input1=='B' && input2=='2' && storeMoves.at(4)==' '){
            return 4;
        }else if(input1=='C' && input2=='2' && storeMoves.at(5)==' '){
            return 5;
        }else if(input1=='A' && input2=='3' && storeMoves.at(6)==' '){
            return 6;
        }else if(input1=='B' && input2=='3' && storeMoves.at(7)==' '){
            return 7;
        }else if(input1=='C' && input2=='3' && storeMoves.at(8)==' '){
            return 8;
        }else{
            cout<<"Enter your move: ";
            cin>>input1>>input2;
        }
    }
    return 0;
}
/*checkComputerMove function will check the computer randomly
selected move if
* move is valid it'll ask the computer again to generate valid

* move and will check again if move is valid or not, itt generate
valid
* move.
*/
int checkComputerMove(int index,string storeMoves){
    srand(time(0));
    while(true)
    {
        if(storeMoves.at(index)==' '){
            return index;
        }else{
            index=rand()%9;
        }
    }
    return 0;
}
/*checkWin function will check if there's a winner it's a draw it'll
return true
*/
bool checkWin(char player,string storeMoves){
    bool check=false;
    if(storeMoves.at(0)!= ' ' && storeMoves.at(0) ==
                                 storeMoves.at(1) && storeMoves.at(0)==storeMoves.at(2)){
        check=true;
    }else if(storeMoves.at(3)!= ' ' && storeMoves.at(3) ==
                                       storeMoves.at(4) && storeMoves.at(3)==storeMoves.at(5)){
        check=true;
    }else if(storeMoves.at(6)!= ' ' && storeMoves.at(6) ==
                                       storeMoves.at(7) && storeMoves.at(6)==storeMoves.at(8)){
        check=true;
    }else if(storeMoves.at(0)!= ' ' && storeMoves.at(0) ==
                                       storeMoves.at(3) && storeMoves.at(0)==storeMoves.at(6)){
        check=true;
    }else if(storeMoves.at(1)!= ' ' && storeMoves.at(1) ==
                                       storeMoves.at(4) && storeMoves.at(1)==storeMoves.at(7)){
        check=true;
    }else if(storeMoves.at(2)!= ' ' && storeMoves.at(2) ==
                                       storeMoves.at(5) && storeMoves.at(2)==storeMoves.at(8)){
        check=true;
    }else if(storeMoves.at(0)!= ' ' && storeMoves.at(0) ==
                                       storeMoves.at(4) && storeMoves.at(0)==storeMoves.at(8)){
        check=true;
    }else if(storeMoves.at(2)!= ' ' && storeMoves.at(2) ==
                                       storeMoves.at(4) && storeMoves.at(2)==storeMoves.at(6)){
        check=true;
    }else{
        check=false;
    }
    if(check)
    {
        cout<<"\nPlayer "<<player<<" wins the game"<<endl<<endl;
        return false;
    }
    else if(storeMoves.at(0)!=' ' && storeMoves.at(1)!=' ' &&
            storeMoves.at(2)!=' ' && storeMoves.at(3)!=' ' &&
            storeMoves.at(4)!=' ' && storeMoves.at(5)!=' ' &&
            storeMoves.at(6)!=' ' && storeMoves.at(7)!=' ' &&
            storeMoves.at(8)!=' '){
        cout<<"\nNo one won, Draw"<<endl<<endl;
        return false;
    }else{
        return true;
    }
}
//DisplayBox function will display the whole board on screen
void DisplayBox(string storeMoves)
{
    cout<<"\t A B C "<<endl<<endl;
    cout<<"\t 1 "<<storeMoves.at(0)<<" | "<<storeMoves.at(1)<<" | "<<storeMoves.at(2)<<" "<<endl;
    cout<<"\t -----------"<<endl;
    cout<<"\t 2 "<<storeMoves.at(3)<<" | "<<storeMoves.at(4)<<" | "<<storeMoves.at(5)<<" "<<endl;
    cout<<"\t -----------"<<endl;
    cout<<"\t 3 "<<storeMoves.at(6)<<" | "<<storeMoves.at(7)<<" | "<<storeMoves.at(8)<<" "<<endl<<endl;
}