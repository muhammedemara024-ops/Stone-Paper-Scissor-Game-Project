// Project 1  stone - paper - scissor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
#include<cmath>
#include <string>
using namespace std;
enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner{Player , Computer , NoWinner };
struct stPlayChoice
{
    int Player;
    int Computer;    
};
int ReadaPostiveNumber()
{
    int Num;
    do
    {
        cout << "How manty round do you want ?" << endl;
        cin >> Num;
    } while (Num < 0);
    return Num;
}

int RandomNumber(int From , int To)
{
    int RandomNum = rand() % (To - From + 1) + From;
    return RandomNum;
}
stPlayChoice RoundBegins(int Num)
{
    stPlayChoice PlayChoice;
    cout << "Round " << Num << " begins : " << endl;
    do 
    {
        cout << "Your Choice : [1]:stone , [2]:paper , [3]scissor ? -->";
        cin >> PlayChoice.Player;
    } while (PlayChoice.Player > 3 || PlayChoice.Player < 1);
   
    PlayChoice.Computer = RandomNumber(1, 3);
    return (PlayChoice);
}

short WhoWinRound(stPlayChoice PlayChoice)
{
    if (PlayChoice.Player == PlayChoice.Computer)
        return enWinner::NoWinner; 

    if ((PlayChoice.Player == enChoice::Stone && PlayChoice.Computer == enChoice::Scissor) ||
        (PlayChoice.Player == enChoice::Paper && PlayChoice.Computer == enChoice::Stone) ||
        (PlayChoice.Player == enChoice::Scissor && PlayChoice.Computer == enChoice::Paper))
    {
        return enWinner::Player;
    }

    return enWinner::Computer;
}
string WhoIsWinner(stPlayChoice PlayChoice , short& PlayerWin, short& ComputerWin, short& Draw)
{
   // or switch/case
    if (WhoWinRound(PlayChoice) == enWinner::Player)
    {
        system("color 2F");
        PlayerWin++;
        return "Player";
    }
    else if (WhoWinRound(PlayChoice) == enWinner::Computer)
    {
        system("color 4F");
        ComputerWin++;
        return "Computer";
    }
    else if (WhoWinRound(PlayChoice) == enWinner::NoWinner)
    {
        system("color 6F");
        Draw++;
        return "No Winner";
    }
}
string PlayerChoiceToString(stPlayChoice PlayChoice)
{
        if (PlayChoice.Player == enChoice::Stone)
            return "Stone";
        else if (PlayChoice.Player == enChoice::Paper)
            return "Paper";
        else
            return "Scissor";
}
string ComputerChoiceToString(stPlayChoice PlayChoice)
{
    if (PlayChoice.Computer == enChoice::Stone)
        return "Stone";
    else if (PlayChoice.Computer == enChoice::Paper)
        return "Paper";
    else
        return "Scissor";
}
void RoundResult(int NumOfRound , short& PlayerWill, short& ComputerWin, short& Draw)
{
    stPlayChoice PlayChoice = RoundBegins(NumOfRound);
    cout << "___________________Round [" << NumOfRound << "] ___________________________\n";
    cout << "Player1 choice : "<< PlayerChoiceToString(PlayChoice) << endl;
    cout << "Computer choice : "<< ComputerChoiceToString(PlayChoice) << endl;
    cout << "Round Winner : "<< WhoIsWinner(PlayChoice,PlayerWill, ComputerWin, Draw) << endl;
    cout << "--------------------------------------------------------" << endl;
}

void LoopForPlayRounds( int NumOfRounds , short &PlayerWin, short &ComputerWin, short &Draw)
{
    for (int i = 1; i <= NumOfRounds; i++)
    {
         RoundResult(i, PlayerWin, ComputerWin, Draw) ;
    }
}
string WhoIsFinalWinner(short PlayerWin, short ComputerWin)
{
    if (PlayerWin > ComputerWin)
    {
        system("color 2F");
        return "Player";
    }
    if (PlayerWin < ComputerWin)
    {
        system("color 4F");
        return "Computer";
    }
    else
    {
        system("color 6F");
        return "Draw";

    }
}
void GameOver(int NumOfRounds,short PlayerWin, short ComputerWin, short Draw)
{
    cout << "\t\t\t______________________________________________________________________\n\n";
    cout << "\t\t\t\t\t   + + + G A M E  O V E R + + +\n";
    cout << "\t\t\t______________________________________________________________________\n\n";
    cout << "\t\t\t_________________________ [ Game Result ] ____________________________\n\n";
    cout << "\t\t\tGame Rounds \t   : " << NumOfRounds << endl;
    cout << "\t\t\tPlayer1 won Times  : "<< PlayerWin << endl;
    cout << "\t\t\tComputer won Times : "<< ComputerWin << endl;
    cout << "\t\t\tDraw Times \t   : "<< Draw << endl;
    cout << "\t\t\tFinal Winner \t   : "<< WhoIsFinalWinner( PlayerWin, ComputerWin) << endl;
    cout << "\t\t\t______________________________________________________________________\n\n";
}
void LoopForPlayGames()
{
    short PlayerWin , ComputerWin , Draw ;
    
    char StartNewGame ;

    do
    {
        PlayerWin = ComputerWin= Draw=0;
        system("color 0F");
        system("CLS");
        int NumOfRounds = ReadaPostiveNumber();
        LoopForPlayRounds( NumOfRounds, PlayerWin, ComputerWin,Draw);
        GameOver(NumOfRounds, PlayerWin, ComputerWin, Draw);
        cout << "Do you want to play another game? y/n --->";
        cin >> StartNewGame;
    } while (StartNewGame == 'y' || StartNewGame=='Y');

}

int main()
{
    srand((unsigned)time(NULL));
    LoopForPlayGames();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
