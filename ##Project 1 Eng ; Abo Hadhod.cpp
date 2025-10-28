// ##Project 1 Eng ; Abo Hadhod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
using namespace std;
enum enGameChoice { Stone = 1 , Paper =2 , Scissor = 3 };
enum enWinner {Player1 = 1 , Computer = 2 , NoWinner = 3};
struct stRoundInfo
{
    short NumberOfRound =0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string WinnerName;
};
struct stGameResult
{
    short GameRounds = 0;
    short Player1Wintimes=0;
    short ComputerWintimes=0;
    short Drawtimes=0;
    enWinner GameWinner;
    string WinnerName;

};
int RandomNumber(int From, int To)
{
    int RandomNum = rand() % (To - From + 1) + From;
    return RandomNum;
}
short HowManyRounds()
{
    int Rounds;
    do
    {
        cout << "How many Rounds do you Want ? [1]---->[10]\n";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds > 10);
    return Rounds;
}
enGameChoice Player1Choice()
{
    short Choice = 1;
    do
    {
        cout<< "Your Choice : [1]: Stone , [2]: Paper , [3]: Scissor ---->";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;

}
enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}
enWinner WhoWinRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::NoWinner;
    switch (RoundInfo.Player1Choice)
    {
    case (enGameChoice::Stone):
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
    }
    case (enGameChoice::Paper):
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
            return enWinner::Computer;
    }
    case (enGameChoice::Scissor):
    {
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
    }
    }
    return enWinner::Player1;
}
string WinnerName(enWinner Winner)
{
    string ArrWinnerName[3] = { "Player1","Computer", "No Winner" };
    return ArrWinnerName[Winner - 1];
}
string ChoiceName(enGameChoice GameCoice)
{
    string ArrChoiceName[3] = { "Stone" , "Paper", "Scissor" };
    return ArrChoiceName[GameCoice - 1];
}
void SetColorShow(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
    {
        system("color 2F");
        break;
    }
    case enWinner::Computer:
    {
        system("color 4F");
        cout << "\a";
        break;
    }
    case enWinner::NoWinner:
    {
        system("color 6F");
    }
        

    }
    
}
void FillRoundResult(stRoundInfo RoundInfo)
{
    cout << "_______________Round [" << RoundInfo.NumberOfRound << "]______________\n";
    cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Player1 Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Who is Winner  :" << WinnerName( RoundInfo.RoundWinner) << endl;
    cout << "_______________________________________\n";

    SetColorShow(RoundInfo.RoundWinner);
} 
enWinner WhoWinGame(short Player1Wintimes,short ComputerWintimes)
{
    if (Player1Wintimes > ComputerWintimes)
        return enWinner::Player1;
    else if (Player1Wintimes < ComputerWintimes)
        return enWinner::Computer;
    else
        enWinner::NoWinner;
}
stGameResult FillGameResults(short GameRound, short Player1Wintimes, short ComputerWintimes, short Drawtimes)
{
    stGameResult GameResult;
    GameResult.GameRounds = GameRound;
    GameResult.Player1Wintimes = Player1Wintimes;
    GameResult.ComputerWintimes = ComputerWintimes;
    GameResult.Drawtimes = Drawtimes;
    GameResult.GameWinner = WhoWinGame(Player1Wintimes, ComputerWintimes);
    GameResult.WinnerName = WinnerName(GameResult.GameWinner);
    return GameResult;
}
stGameResult PlayGame(int HowManyRounds)
{
    stRoundInfo RoundInfo;
      short Player1Wintimes = 0 , ComputerWintimes =0 , Drawtimes = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "round [" << GameRound << "] begins : \n";
        RoundInfo.NumberOfRound = GameRound;
        RoundInfo.Player1Choice = Player1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundWinner = WhoWinRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(WhoWinRound(RoundInfo));
        
        if (RoundInfo.RoundWinner == enWinner::Player1)
            Player1Wintimes++;
        else if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWintimes++;
        else
           Drawtimes++;

        FillRoundResult(RoundInfo);
    }
    return  FillGameResults(HowManyRounds, Player1Wintimes, ComputerWintimes, Drawtimes);
}
string Tabs(int NumOfTabs)
{
    string t = "";
    for (int i = 1; i <= NumOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}
void ShowGameOver()
{
    cout << Tabs(2) << "____________________________________________________________\n\n";
    cout << Tabs(2) << "           +  +  +  +   G a m e  O v e r  +  +  +  +         \n";
    cout << Tabs(2) << "____________________________________________________________\n\n";
}


void PrintGameResult(stGameResult GameResult)
{
    cout << Tabs(2) << "_________________[ Game Result ]___________________\n\n ";
    cout << Tabs(2) << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << Tabs(2) << "Player1 Won Times  : " << GameResult.Player1Wintimes << endl;
    cout << Tabs(2) << "Computer Won Times : " << GameResult.ComputerWintimes << endl;
    cout << Tabs(2) << "Draw Times         : " << GameResult.Drawtimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResult.WinnerName << endl;
    cout << Tabs(2) << "____________________________________________________\n\n ";

    SetColorShow(GameResult.GameWinner);
}
void NewScreen()
{
    system("cls");
    system("color 0F");
}
void StartGame()
{
    char PlayAgian = 'Y';
    do
    {
        NewScreen();
        stGameResult GameResult = PlayGame(HowManyRounds());
        ShowGameOver();
        PrintGameResult(GameResult);

        cout <<Tabs(3)<< "\n\n Do you want to play Again? Y/N ---->";
        cin >> PlayAgian;

    } while (PlayAgian == 'y' || PlayAgian == 'Y');

}

int main()
{
   srand((unsigned)time(NULL));
   StartGame();
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
