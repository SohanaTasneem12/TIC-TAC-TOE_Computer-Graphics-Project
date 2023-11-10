#include<bits/stdc++.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

using namespace std;
void drawLoadingBar(int width, int height, int p) {
    int w = 300;
    int h = 20;
    int x = (width - w) / 2;
    int y = (height - h) / 2;

    setcolor(15);
    rectangle(x, y, x + w, y + h);

    setfillstyle(SOLID_FILL, 15);
    int fillWidth = (w * p) / 100;
    bar(x, y, x + fillWidth, y + h);
}

void updateLoadingText(int width, int height, int p) {
    int textX = width / 2;
    int textY = height / 2 + 30;

    setcolor(15);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    char loadingText[20];
    sprintf(loadingText, "Loading: %d%%", p);

    outtextxy(textX - textwidth(loadingText) / 2, textY, loadingText);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm," ");
    int width = getmaxx();
    int height = getmaxy();

    // Display loading bar and text
    for (int i = 0; i <= 100; i++) {
        cleardevice();
        drawLoadingBar(width, height, i);
        updateLoadingText(width, height, i);
        delay(50);
    }

    cleardevice();

    // 0: red, 1: cyan, 2: empty
    int gameState[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    int c1[9] = {175, 175, 175, 325, 325, 325, 475, 475, 475};
    int c2[9] = {100, 250, 400, 100, 250, 400, 100, 250, 400};
    int color[2] = {12, 11};
    int numberOfTurns = 0;
    int activePlayer = 0;
    bool gameActive = true;
    int c;

    settextstyle(8, 0, 2);
    outtextxy(140, 180, "COMPUTER GRAPHICS PROJECT");
    outtextxy(240, 220, "TIC-TAC-TOE");
    delay(5000);
    cleardevice();

    line(100, 175, 550, 175);
    line(100, 325, 550, 325);
    line(250, 50, 250, 450);
    line(400, 50, 400, 450);

    settextstyle(0, 0, 0);

    outtextxy(235, 50, "0");
    outtextxy(235, 180, "1");
    outtextxy(235, 330, "2");
    outtextxy(385, 50, "3");
    outtextxy(385, 180, "4");
    outtextxy(385, 330, "5");
    outtextxy(535, 50, "6");
    outtextxy(535, 180, "7");
    outtextxy(535, 330, "8");

    char player1[40];
    char player2[40];

    cout << "Please Enter Your Name";
    cout << "\nPLAYER 1 : ";
    cin >> player1;
    cout << "PLAYER 2 : ";
    cin >> player2;

    settextstyle(0, 0, 0);
    outtextxy(10, 430, "Player 1: Red");
    outtextxy(10, 450, "Player 2: Cyan");
    cout << "ENTER YOUR CHOICE :\n";

    do
    {
        cin >> c;
        if (gameState[c] == 2 && gameActive)
        {
            gameState[c] = activePlayer;
            int x = c1[c];
            int y = c2[c];

            if (activePlayer == 0)
            {
                // Draw a circle for player 1 (Red)
                circle(x, y, 40);
                setfillstyle(LTBKSLASH_FILL, color[activePlayer]);
            }
            else
            {
                // Draw a square for player 2 (Cyan)
                rectangle(x - 30, y - 30, x + 30, y + 30);
                setfillstyle(LTBKSLASH_FILL, color[activePlayer]);
            }

            floodfill(x, y, 15);
            delay(500);

            activePlayer = activePlayer ? 0 : 1;
            ++numberOfTurns;
            int winningPositions[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
            int winningPosition[3];
            bool winnerCheck = true;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    winningPosition [j] = winningPositions[i][j];
                }

                if (gameState[winningPosition[0]] == gameState[winningPosition[1]] && gameState[winningPosition[1]] == gameState[winningPosition[2]] && gameState[winningPosition[0]] != 2)
                {
                    gameActive = false;
                    winnerCheck = false;

                    if (activePlayer == 1)
                    {
                        cleardevice();
                        settextstyle(8,0,2);
                        outtextxy(170,200,"The winner is ");
                        outtextxy(350,200,player1);
                        delay(3000);
                        getch();
                    }
                    else
                    {
                        cleardevice();
                        settextstyle(8,0,2);
                        outtextxy(170,200,"The winner is ");
                        outtextxy(350,200,player2);
                        delay(3000);
                        getch();
                    }

                }

            }
            if (numberOfTurns == 9 && winnerCheck)
            {
                gameActive = false;
                cleardevice();
                settextstyle(8,0,2);
                outtextxy(160,200,"MATCH TIED");
                delay(3000);
                getch();
            }
        }
    }
    while(gameActive);

    cleardevice();
    settextstyle(8,0,2);
    outtextxy(160,200,"THANK YOU FOR PLAYING");
    delay(5000);
    getch();
    closegraph();
    return 0;
}

