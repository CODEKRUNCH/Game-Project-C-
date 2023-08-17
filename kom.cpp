#include <iostream>
#include<conio.h>
using namespace std;
void clearScreen()// Function to clear the console screen
{
    system("cls");
}

int HardGame() {
	clearScreen();
    cout << "Starting the game..." << endl;
   	//User chooses which car to operate
	char option, car;
    cout << "\t\t\t  Choose Your CHARACTER :" << endl;                               //
    cout << "\n\n\t\t\ta - * " << endl;                                             //
    cout << "\n\n\t\t\tb - $ " << endl;                                             // This Will display The choices of charcter
    cout << "\n\n\t\t\tc-  # " << endl;                                            //
    cout << "\n\n\t\t\td - ^ " << endl;  
    cout << "\n\n\tEnter your choice: ";         
	option=_getch();//getch function is used so when the key is pressed it gives direct output without pressing enter key
	cout<<option;
	switch(option) {
		case 'a':
			car ='*';
			break;
		case 'b':
			car ='$';
			break;       //A set of choices from which the user can choose $,*,^,#
		case 'c':
			car ='#';
			break;
		case 'd':
			car ='^';
			break;
		default:
			cout<< "\t INVALID INPUT! \n";//if choice is not correct it will say invalid input 
			return 0;                     //and take u back to difficulty menu
			break;
	}
	clearScreen();
	cout<< "Your chosen car is: " << car << endl;
	cout<<"--------------------------GAME RULES-----------------------"<<endl; 
	cout<<"\nReach The destination  O to win the Game "<<endl;
	cout<<"\nIf u collide with any wall u will lose the Game"<<endl;
	cout<<"\nThe game may offer multiple difficulty levels, such as easy, medium, and hard."<<endl;
	cout<<"\n\n \t\t\t\t Enter Any key to continue to Game"<<endl;

const int mazeWidth = 22;   // width of the maze
const int mazeHeight = 22;  // height of the maze

char maze[mazeHeight][mazeWidth] = {
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|', ' ', ' ', ' ', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},    //single ' ' dashes make wall 
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},    //where there is no dash it is a way for the user to pass
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},    //It is Map of the Game.
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', '|', '|', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', ' ', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', 'O'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' }
};
    int x = 1; // x-coordinate of the object
    int y = 1; // y-coordinate of the object

    while (true)
    {
        {
            //character variable 'key' = key pressed in getch()
            char key = _getch();
            // Direct input without enter key
            // Handle different key inputs
            switch (key)
            {
                case 'w': // Move up
                    if (y > 1 && maze[y - 1][x] != '|','0') 
                        y--;
                    break;
                case 's': // Move down
                    if (y < mazeHeight - 2 && maze[y + 1][x] != '|','0')
                        y++;
                    break;
                case 'a': // Move left
                    if (x > 1 && maze[y][x - 1] != '-','0')
                        x--;
                    break;
                case 'd': // Move right
                    if (x < mazeWidth - 2 && maze[y][x + 1] != '-','0')
                        x++;
                    break;
            }

            // Check if the object hits the walls
            if (maze[y][x] == '-')
            {
                clearScreen();
                cout << "YOUR PAWN COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If ur object collides with '-' Game over
                return 0;
            }
            if (maze[y][x] == '|')
            {
                clearScreen();
             cout << "YOUR PAWN COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If your Object Collides with'|"Game Over
                return 0;
            }
            if (maze[y][x] == 'O')
            {
                clearScreen();
                cout << "VICTORY!" << endl;     //If you reach till O it will display Message Victory
                return 0;
            }

            // Clear the screen and redraw the object and maze at the new position
            clearScreen();
            for (int i = 0; i < mazeHeight; i++)
            {
                for (int j = 0; j < mazeWidth; j++)
                {
                    if (i == y && j == x)                    // This states that Map is Spread on The Screen in correct form endl in the end separates the dashes
                        cout << car; // Object (characterr)         //It also indicates how the car will move on the map
                    else                                     //Each movement regenerates the Map
                        cout << maze[i][j]; // Maze symbols
                }
                cout << endl;
            }
        }
}}
int MediumGame() {
	clearScreen();
    cout << "Starting the game..." << endl;
   	//User chooses which car to operate
	char option, car;
    cout << "\t\t\t  Choose Your CHARACTER :" << endl;                               //
    cout << "\n\n\t\t\ta - * " << endl;                                             //
    cout << "\n\n\t\t\tb - $ " << endl;                                             // This Will display The choices of charcter
    cout << "\n\n\t\t\tc-  # " << endl;                                            //
    cout << "\n\n\t\t\td - ^ " << endl;  
    cout << "\n\n\tEnter your choice: ";         
	option=_getch();//getch function is used so when the key is pressed it gives direct output without pressing enter key
	cout<<option;
	switch(option) {
		case 'a':
			car ='*';
			break;
		case 'b':
			car ='$';
			break;       //A set of choices from which the user can choose $,*,^,#
		case 'c':
			car ='#';
			break;
		case 'd':
			car ='^';
			break;
		default:
			cout<< "\t INVALID INPUT! \n";
			return 0;
			break;
	}
	clearScreen();
	cout<< "Your chosen car is: " << car << endl;
	cout<<"--------------------------GAME RULES-----------------------"<<endl; 
	cout<<"\nReach The destination  O to win the Game "<<endl;
	cout<<"\nIf u collide with any wall u will lose the Game"<<endl;
	cout<<"\nThe game may offer multiple difficulty levels, such as easy, medium, and hard."<<endl;
	cout<<"\n\n \t\t\t\t Enter Any key to continue to Game"<<endl;
const int mazeWidth = 12;  // New width of the maze
const int mazeHeight = 12; // New height of the maze

char maze[mazeHeight][mazeWidth] = {
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', ' ', '|'},
    {'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', '|'},
    {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', 'O'},
    {'|', ' ', '|', ' ', ' ', ' ', '|', '|', '|', '|', '|', 'O'},
    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}
};
    int x = 1; // x-coordinate of the object
    int y = 1; // y-coordinate of the object

    while (true)
    {
       
        {
            		//character variable 'key' = key pressed in getch()
            char key = _getch();
            // Direct input without enter key
            // Handle different key inputs
            switch (key)
            {
                case 'w': // Move up
                    if (y > 1 && maze[y - 1][x] != '|','0') 
                        y--;
                    break;
                case 's': // Move down
                    if (y < mazeHeight - 2 && maze[y + 1][x] != '|','0')
                        y++;
                    break;
                case 'a': // Move left
                    if (x > 1 && maze[y][x - 1] != '-','0')
                        x--;
                    break;
                case 'd': // Move right
                    if (x < mazeWidth - 2 && maze[y][x + 1] != '-','0')
                        x++;
                    break;
            }

            // Check if the object hits the walls
            if (maze[y][x] == '-')
            {
                clearScreen();
                cout << "YOUR OBJECT COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If ur object collides with '-' Game over
                return 0;
            }
            if (maze[y][x] == '|')
            {
                clearScreen();
                cout << "YOUR PAWN COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If your Object Collides with'|"Game Over
                return 0;
            }
            if (maze[y][x] == 'O')
            {
                clearScreen();
                cout << "VICTORY!\n U have Won the Game" << endl;     //If you reach till O it will display Message Victory
                return 0;
            }

            // Clear the screen and redraw the object and maze at the new position
            clearScreen();
            for (int i = 0; i < mazeHeight; i++)
            {
                for (int j = 0; j < mazeWidth; j++)
                {
                    if (i == y && j == x)                      // This states that Map is Spread on The Screen in correct form endl in the end separates the dashes
                        cout << car; // Object (character)           //It also indicates how the car will move on the map
                    else                                       //Each movement regenerates the Map
                        cout << maze[i][j]; // Maze symbols
                }
                cout << endl;
            }
        }
}}
int EasyGame() {
	clearScreen();
    cout << "Starting the game..." << endl;
   	//User chooses which car to operate
	char option, car;
    cout << "\t\t\t  Choose Your CHARACTER :" << endl;                               //
    cout << "\n\n\t\t\ta - * " << endl;                                             //
    cout << "\n\n\t\t\tb - $ " << endl;                                             // This Will display The choices of charcter
    cout << "\n\n\t\t\tc-  # " << endl;                                            //
    cout << "\n\n\t\t\td - ^ " << endl;  
    cout << "\n\n\tEnter your choice: ";          
	option=_getch();//getch function is used so when the key is pressed it gives direct output without pressing enter key
	cout<<option;
	switch(option) {
		case 'a':
			car ='*';
			break;
		case 'b':
			car ='$';
			break;       //A set of choices from which the user can choose $,*,^,#
		case 'c':
			car ='#';
			break;
		case 'd':
			car ='^';
			break;
		default:
			cout<< "\t INVALID INPUT! \n";
			return 0;
			break;
	}
	clearScreen();
	cout<< "Your chosen car is: " << car << endl;
	cout<<"--------------------------GAME RULES-----------------------"<<endl; 
	cout<<"\nReach The destination  O to win the Game "<<endl;
	cout<<"\nIf u collide with any wall u will lose the Game"<<endl;
	cout<<"\nThe game may offer multiple difficulty levels, such as easy, medium, and hard."<<endl;
	cout<<"\n\n \t\t\t\t Enter Any key to continue to Game"<<endl;

const int mazeWidth = 10; // Width of the maze
const int mazeHeight = 10; // Height of the maze

char maze[mazeHeight][mazeWidth] = {
{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
{'|', '.', '.', '.', '.', '.', '|', '.', '.', '|'},
{'|', '.', '|', '-', '-', '.', '|', '.', '|', '|'},
{'|', '.', '|', '.', '.', '.', '.', '.', '|', '|'},
{'|', '.', '|', '-', '-', '.', '|', '.', '|', '|'},
{'|', '.', '.', '.', '.', '.', '|', '.', '|', '|'},
{'|', '.', '|', '-', '-', '-', '-', '.', '|', '|'},
{'|', '.', '|', '.', '.', '.', '.', '.', '|', '|'},
{'|', '.', '|', '.', '|', '.', '|', '.', '.', 'O'},
{'-', '-', '-', '-', '-', '-', '-', '-', '-', 'O'}
};








    int x = 1; // x-coordinate of the object
    int y = 1; // y-coordinate of the object

    while (true)
    {
       
        {
            		//character variable 'key' = key pressed in getch()
            char key = _getch();
            // Direct input without enter key
            // Handle different key inputs
            switch (key)
            {
                case 'w': // Move up
                    if (y > 1 && maze[y - 1][x] != '|','0') 
                        y--;
                    break;
                case 's': // Move down
                    if (y < mazeHeight - 2 && maze[y + 1][x] != '|','0')
                        y++;
                    break;
                case 'a': // Move left
                    if (x > 1 && maze[y][x - 1] != '-','0')
                        x--;
                    break;
                case 'd': // Move right
                    if (x < mazeWidth - 2 && maze[y][x + 1] != '-','0')
                        x++;
                    break;
            }

            // Check if the object hits the walls
            if (maze[y][x] == '-')
            {
                clearScreen();
                cout << "YOUR OBJECT COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If ur object collides with '-' Game over
                return 0;
            }
            if (maze[y][x] == '|')
            {
                clearScreen();
                cout << "YOUR PAWN COLLIDED WITH A WALL! \nGAME OVER! " << endl;      //If your Object Collides with'|"Game Over
                return 0;
            }
            if (maze[y][x] == 'O')
            {
                clearScreen();
                cout << "VICTORY!\n U have Won the Game" << endl;     //If you reach till O it will display Message Victory
                return 0;
            }

            // Clear the screen and redraw the object and maze at the new position
            clearScreen();
            for (int i = 0; i < mazeHeight; i++)
            {
                for (int j = 0; j < mazeWidth; j++)
                {
                    if (i == y && j == x)                      // This states that Map is Spread on The Screen in correct form endl in the end separates the dashes
                        cout << car; // Object (characterr)           //It also indicates how the car will move on the map
                    else                                       //Each movement regenerates the Map
                        cout << maze[i][j]; // Maze symbols
                }
                cout << endl;
            }
        }
}}
int Difficulty()
{   clearScreen();
	    char choice;
    do {
    cout<<"\n--------------------------MazeRunner------------------------"<<endl; //
    cout << "\nDIFFICULTY:" << endl;                                               //
    cout << "\na. Easy " << endl;                                                //
    cout << "\nb. Medium " << endl;                                              // This is a Difficulty of The game it chooses a game from three functions 
    cout << "\nc. Hard " << endl;  
	cout << "\nPress Any key except (a b c)  to Return To main menu" << endl; //if choice is not correct it takes u back to the maimenu //
    cout << "\nEnter your choice: ";                                              //
        choice = _getch();
        switch (choice) {
            case 'a':
                EasyGame();
                break;
            case 'b':
                MediumGame();
                break;
            case 'c':
                HardGame();                       // This switch case is used in do while loop so it  // keeps repeating until exit option is pressed
                break; 
            default:
                cout << "Press Any key except (a b c)  to Return To main menu" << endl;//if choice is not correct it displays a message invalid choice
				return 0;
                break;
        }

        cout << endl;
    } while (choice != 1);//infinite loop

}
void Controls()  //A Function That Displays The Controls 
{
	clearScreen();
    cout << "Controls:" << endl;
    cout << "w - Move Up" << endl;
    cout << "s - Move Down" << endl;
    cout << "a - Move Left" << endl;
    cout << "d - Move Right" << endl;
}

int main() {
    char choice;
    do {
    cout<<"--------------------------MazeRunner------------------------"<<endl; //
    cout << "\t\t\t  Main Menu:" << endl;                                               //
    cout << "\n\n\t\t\ta. Play Game" << endl;                                             //
    cout << "\n\n\t\t\tb. Controls" << endl;                                              // This is a Main menu of The game 
    cout << "\n\n\t\t\tc. Exit" << endl;                                                  //
    cout << "\n\n\tEnter your choice: ";                                              //
        choice = _getch();
        switch (choice) {
            case 'a':
                Difficulty();
                break;
            case 'b':
                Controls();
                break;
            case 'c':
                cout << "Exiting the program..." << endl;                       // This switch case is used in do while loop so it
                return 0;                                                       // keeps repeating until exit option is pressed
                break; 
            default:
                cout << "Invalid choice. Please try again." << endl;//if choice is not correct it displays a message invalid choice
                break;
        }
        cout << endl;
    } while (choice != 1);//Infinite Loop

    return 0;
}
