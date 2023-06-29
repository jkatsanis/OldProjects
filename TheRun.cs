using System;
using System.Threading;

Rock rock = new Rock();
Player player = new Player();

string welcome = Environment.NewLine + "||   ||  ||  ||||||  ||     ||||   ||||   |||  |||  |||||" + Environment.NewLine + " || |||| ||   ||===   ||    ||     ||  ||  || || ||  ||===" + Environment.NewLine + "  ||    ||    ||||||  |||||  ||||   ||||   ||    ||  |||||" + Environment.NewLine + "                        TO THE" + Environment.NewLine + "              |||||   ||   ||  ||||  ||   " + Environment.NewLine + "              ||  ||  ||   ||  || || ||  " + Environment.NewLine + "              ||==||| ||   ||  ||   ||| " + Environment.NewLine + "              ||   ||   |||    ||    || " + Environment.NewLine;

rock.top =    "  ---- ";
rock.mid  =   " |    |";
rock.buttom = "  ---- ";

player.head =  "  ----- ";
player.eyes =  " | o  o|";
player.mouth = " |  -- |";
player.neck2 = "  ----- ";
player.neck =  "    |   ";
player.arms =  " =-----=";
player.thigh = "   | |  ";
player.legs =  "  |   | ";


bool obejectPrinting = false;                            //Checkt ob das ojekt geprintet wird oder nicht z.b ein stein
bool playing = false;                                    //Um das game mit "esc" zu beenden
bool jump = false;
char input = ' ';
string start;                                            //Einlesen ob man started        
int fieldH = 1440;                                       //Wie viele Felder, das Feld hat 
int rocksBeginningPositionLeft = 45;                     //Anfangsposition des Rocks nach links
int rocksBeginningPositionTop = 19;                      //Anfangspostion wie hoch mehr oder weniger der erste Teil ist.                   
int printingCounterRock = 0;                             //Der printing counter countet wann man welchen "look" von den object printet
int printingCounterPlayer = 0;                           //für den player
int playersPosition = 14;
const int DELAY = 50;                                    //Das Delay wie schnell das Spiel geht
const int ROWS = 24;      
int COLUMNS = 60;

string[,] field = new string[COLUMNS, ROWS]; //Der Array Für das Feld

string[]rocksLook = new string[3];
rocksLook[0] = rock.buttom;
rocksLook[1] = rock.mid;
rocksLook[2] = rock.buttom;

string[] playersLook = new string[8];
playersLook[0] = player.head;
playersLook[1] = player.eyes;
playersLook[2] = player.mouth;
playersLook[3] = player.neck2;
playersLook[4] = player.neck;
playersLook[5] = player.arms;
playersLook[6] = player.thigh;
playersLook[7] = player.legs;


Console.WriteLine($"{welcome}");
Console.Write($"{string.Empty,14} press any key to continue: ");

start = Console.ReadLine(); playing = true;
Console.Clear();
while (true)
{
    input = Console.ReadKey(true).KeyChar;
    while (Console.KeyAvailable == false)
    {
        for (int i = 0; i < ROWS - 1; i++)            //Das ist die höhe
        {
            for (int j = 0; j < COLUMNS - 1; j++)     //Das sind die zeichen nach rechts
            {
                if (i == playersPosition && j == 5 && printingCounterPlayer < 8) //Hier wird der Player geprintet
                {
                    Console.Write(playersLook[printingCounterPlayer]);
                    ObjectCalculations(7);
                    playersPosition++;
                    printingCounterPlayer++;
                    jump = false;
                }

                if (i == rocksBeginningPositionTop && j == rocksBeginningPositionLeft && printingCounterRock < 3) //Hier wird der rock geprintet
                {
                    Console.Write(rocksLook[printingCounterRock]);
                    ObjectCalculations(14);                         //14, weil der player 7 char einnimmt und der rock auch 7
                    rocksBeginningPositionTop++;
                    printingCounterRock++;
                    jump = false;
                }

                if (i == 22)
                {
                    Console.Write(new string('_', 1));       //Der Border wird geprintet sozusagen wo der Spielder draufsteht
                    fieldH = 0;
                }
                if (fieldH > 1 && !obejectPrinting)
                {
                    Console.Write(field[j, i] + "h");
                    fieldH--;
                }
                obejectPrinting = false;

            }
            Console.WriteLine();
            COLUMNS = 60;

        }
        rocksBeginningPositionLeft = rocksBeginningPositionLeft - 1;
        Thread.Sleep(DELAY);
        fieldH = 1440;
        printingCounterRock = 0;
        printingCounterPlayer = 0;
        if (!jump)
        {
            playersPosition = 14;
        }
        rocksBeginningPositionTop = 19;
        Console.Clear();


    }
    if (input == 'w')
    {
        playersPosition = 8;
        jump = true;
    }
}


void ObjectCalculations(int temp)
{
    COLUMNS = 60;
    COLUMNS -= temp;
    obejectPrinting = true;
    fieldH -= temp;
    temp = 0;
}
public class Rock
{
    public string mid;
    public string top;
    public string buttom;
}
public class Player
{
    public string head;
    public string eyes;
    public string neck2; 
    public string neck;
    public string arms;
    public string thigh;
    public string legs;
    public string mouth;
   
}










