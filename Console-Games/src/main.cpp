// SYSTEM LIBS
#include <iostream> 
#include <cstdlib>  // For RNG
#include <ctime>    // For time seed to assist RNG
#include <thread>   // For sleep fucntion
#include <cctype>   // For tolower and toupper function
#include <fstream>  // For file handling
#include <list>     // Allows a list to be used for storing file values



void sleep(int time) {
    /*  This functions allows a sleep to be implements more cleanly
        Takes time input in milliseconds
    */
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}


//GUESS THE NUMBER
void playGuessTheNumber() {
  /* GUESS THE NUMBER GAME
  Starts a game in which the player has 5 guesses to guess a random number between 1 and 10
  */

  system("cls"); 
  sleep(100); 

  std::srand(std::time(0)); 

  int player_guess = 0; 
  int target_number = 1 + (std::rand() % 10); 

  bool guess_is_running = true; 
  const int MAX_GUESSES = 5;    

  std::cout << "Welcome to guess the number!"
            << "\nYou have " << MAX_GUESSES << " guesses to figure it out!"
            << std::endl;
  sleep(2000);
  
  //Start of game loop
  while (guess_is_running)
  {
    // Guess Loop
    for (int guess = 1; guess < MAX_GUESSES + 2; guess++)
    {
      // Checks if the max number of guesses has been had
      if (guess == MAX_GUESSES + 1)
      {
          //Lose message
          std::cout << "\nYou Lose!" << std::endl;
          guess_is_running = false;
      }
      else
      {
        //system("cls");
        std::cout << "\nGuess: " << guess << "/" << MAX_GUESSES << std::endl;
        std::cout << "Guess the number between 1 and 10: " << std::endl;   
        std::cin >> player_guess;   

        if (player_guess == target_number)
        {
            //Win State
            std::cout << "You have guessed correctly and won the game!" << std::endl;
        
            // Asks the user if they want to play again and handles input
            char play_again = '\0';  
            std::cout << "\nWould you like to play again? Y/N" << std::endl;
            std::cin >> play_again;

            if (std::tolower(play_again) == 'y')
            {
              guess_is_running = false;     
              playGuessTheNumber();    
              break;    
            }
            else
            {
              std::cout << "Thank you for playing!";
              sleep(500);
              guess_is_running = false;
              break;
            }
            break; 
        }
        else if (player_guess < target_number)
        {
          std::cout << "Your guess is less than the number!" << std::endl;
          sleep(800);
        }
        else
        {
          std::cout << "Your guess is greater than the number!" << std::endl;
          sleep(800);
        }
      }
    }
  }
}


//ROCK PAPER SCISSORS
int getUserGuessAndCompare(char computer_guess)
{
    /*
    This function takes in the computers guess.
    It then asks the player for their move.
    It then calculates the winner and returns the value as an integer
    */
    char player_guess = '\0'; 

    //bool valid_input = false;
    do
    {
        std::cout << "Enter your move [R, P, S]: ";
        std::cin >> player_guess;
        player_guess = std::toupper(player_guess);  
        if ((player_guess != 'R') && (player_guess != 'P') &&
            (player_guess != 'S') && (player_guess != 'Q'))
        {
            std::cout << "Please enter a valid input!" << std::endl;
        } 

    } 
    while ((player_guess != 'R') && (player_guess != 'P') &&
           (player_guess != 'S') && (player_guess != 'Q'));


    if (player_guess == 'Q')
    {
        return 2;
    }
    else if (player_guess == computer_guess)
    {
        //Draw
        return 0;
    }
    else if (computer_guess == 'R')
    {
        //Handles Rock
        switch (player_guess)
        {
            case 'P':
                return 1;
                break;
            case 'S':
                return -1;
                break;
        }
    }
    else if (computer_guess == 'P')
    {
        // Handles Paper
        switch (player_guess)
        {
            case 'R':
                return -1;
                break;

            case 'S':
                return 1;
                break;
        }
    }
    else if (computer_guess == 'S')
    {
        // Handles Scissors
        switch (player_guess)
        {
            case 'R':
                return 1;
                break;
            case 'P':
                return -1;
                break;
        }
    } 
}

char convertComputersGuess(int computer_guess_int)
{
    /*
    This function converts the randomly generated int between 1 and 3
    into the corresponding character for that guess
    
    */
    char computer_guess = '\0';
    switch (computer_guess_int)
    {
        case 1:
            computer_guess = 'R';
            break;
        case 2:
            computer_guess = 'P';
            break;
        case 3:
            computer_guess = 'S';
            break;
    }

    return computer_guess;
}

void calculateRoundWinner(
  int round_winner, int comp_win_tally, int player_win_tally, int message_delay_time,
    int* add_comp_tally, int* add_player_tally, bool* add_quit)
{
    /*
    This function takes in the result of the winning round, calculates the winner
    and assigns points to the appropriate tally. These tallies are then returned.
    Another boolean value is also returned which is only ever true if the player has
    chosen to quit the game.
    */
    
    //Get working with these as args
    bool q = false;
    switch (round_winner)
    {
        case -1:
            comp_win_tally += 1;
            std::cout << "The computer wins this round!" << std::endl;
            sleep(message_delay_time);
            break;

        case 0:
            comp_win_tally += 1;
            player_win_tally += 1;
            std::cout << "This round was a draw!" << std::endl;
            sleep(message_delay_time);
            break;

        case 1:
            player_win_tally += 1;
            std::cout << "You win this round!" << std::endl;
            sleep(message_delay_time);
            break;

        case 2:
            q = true;
            break;
    }

    *add_comp_tally = comp_win_tally;
    *add_player_tally = player_win_tally;
    *add_quit         = q;
}

int getLastWinner(int round_winner)
{
    /*
    This function is used in the strategy game mode
    It returns the value to be ammeneded to the winner_history list
    */
    if (round_winner == 1)
    {
        // Player won
        return 'P';
    }
    else if (round_winner == 0)
    {
        // Draw
        return 'D';
    }
    else if (round_winner == -1)
    {
        // Comp won
        return 'C';
    }
}

char findPlayersGuess(int round_winner, char computer_guess) 
{
    /*
    This function is used within the strategy gamemode
    To avoid cluttering the getUserGuessAndCompare function, or disregarding it
    entirely to store the players guess, this functions calculates the players guess
    based off of who won, and what the computer played.
    */
    //-1 Comp Wins, 0 Draw, 1 Player wins
    if (computer_guess == 'R')
    {
        //If the computer played rock.
        switch (round_winner)
        {
            case -1:
                //Computer won
                return 'S';
                break;

            case 0:
                //Draw
                return 'R';
                break;

            case 1:
                //Player won
                return 'P';
                break;
        }
    }
    else if (computer_guess == 'P')
    {
        // If the computer played rock.
        switch (round_winner)
        {
            case -1:
                // Computer won
                return 'R';
                break;

            case 0:
                // Draw
                return 'P';
                break;

            case 1:
                // Player won
                return 'S';
                break;
        }
    }
    else if (computer_guess == 'S')
    {
        // If the computer played rock.
        switch (round_winner)
        {
            case -1:
                // Computer won
                return 'P';
                break;

            case 0:
                // Draw
                return 'S';
                break;

            case 1:
                // Player won
                return 'R';
                break;
        }
    }
}

void playRockPaperScissors() 
{
    //*****VARIABLES FOR GAME MODE CHOICE*****
    char game_mode_entry = '\0'; 
    int use_strategy = 0;

    //*****VARIABLES FOR EVERY GAME MODE*****
    int comp_win_tally   = 0;
    int player_win_tally = 0;
    bool player_quit     = false;

    const int DISPLAY_MESSAGE_TIME = 1000;

    bool rps_is_running = true; 

    char computer_guess = '\0'; 

    //*****VARIABLES FOR THE FILE GAME MODE*****
    bool file_opened = false;
    int guess_amount = 0;    
    std::list<char> guesses; //Initisliases an empty list
    std::list<char>::iterator guess_iterator = guesses.begin(); 

    //*****VARIABLES FOR THE STARTEGY GAME MODE*****
    char last_player_guess         = '\0';
    char last_comp_guess           = '\0';
    int rounds_played              = 0;
    char last_winner               = '\0';
     
    // ROCK PAPER SCISSORS GAME - MENU
    system("cls"); 
    sleep(100);    

    std::srand(std::time(0)); 
    
    std::cout << "Welcome to Rock, Paper, Scissors!"
              << "\nWould you like to to play with a file [F] or play against the computer [C]?"
              << "\nEnter Q at anytime to quit" //Implement this if game hasnt started.
              << std::endl;
    
    std::cout << "Option: ";
    std::cin >> game_mode_entry;

    //Resets variables regarding strategy
    use_strategy = 0;

    //Main Game
    while (rps_is_running == true)
    {
        if (std::tolower(game_mode_entry) == 'q')
        {
            rps_is_running = false;
            break;
        }
        else if (std::tolower(game_mode_entry) == 'f')
        {
            // IF PLAYING AGAINST A PREGEN FILE
            if (file_opened == false)
            {
                std::ifstream rps_file;
                // File located in src/RPS.txt
                rps_file.open("../../../src/RPS.txt"); 

                // Var used for iterating through the chars in the file
                char file_guess = '\0'; 

                // Checks the file is open successfully
                if (rps_file.is_open()) 
                {
                    while (rps_file >> file_guess)
                    {
                        guess_amount++;
                        guesses.insert(guess_iterator, 1, file_guess);
                    }

                    rps_file.close();
                    file_opened = true;
                }
                else
                {
                    // File failed to open
                    std::cout << "File failed to open!" << std::endl;
                    sleep(500); 
                    rps_is_running = false;  
                    playRockPaperScissors(); 
                }
            }

            // Checks if all guesses have been used
            if ((guesses.size() <= guess_amount) && (guesses.size() != 0))
            {
                system("cls");
                std::cout << "Playing against the file!" << std::endl;

                char current_file_guess = guesses.front();
                int round_winner = getUserGuessAndCompare(current_file_guess);

                // Remove the most recent first(just used) guess from the list
                guesses.pop_front();

                 
                calculateRoundWinner(round_winner, comp_win_tally, player_win_tally, DISPLAY_MESSAGE_TIME,
                    &comp_win_tally, &player_win_tally, &player_quit);


                // Handles if the player chooses to quit
                if (player_quit == true)
                {
                    rps_is_running = false;
                    break;
                }
            }
            else if (guesses.size() == 0)
            {
                std::cout << "All the file goes have been played!" << std::endl;
                //Reset the file opened stat to allow another game against the file to be played
                file_opened = false;

                // End the game when all the file generated guesses have been used.
                rps_is_running = false;
            }
        }
        else if (std::tolower(game_mode_entry) == 'c')
        {
            //MENU FOR CHOOSING GAME MODE
            system("cls");

            if (use_strategy == 0)
            {
                //STRAT OPTION NOT CHOSEN
                //Outputs message to player to allow them to choose if strategy is used.
                std::cout << "You have chosen to play again the computer!"
                          << "\nWould you like to add strategy? Y/n" << std::endl;

                char temp_strat = '\0'; 
                std::cout << "Option: ";
                std::cin >> temp_strat;

                // Processes players prompt and assigns the value to the bool declared earlier
                if (toupper(temp_strat) == 'Y')
                {
                    use_strategy = 2;
                }
                else
                {
                    use_strategy = 1;
                }
            }
            
            if (use_strategy == 1)
            {
                // Not using strategy
                system("cls"); 

                int computer_guess_int = 1 + (std::rand() % 3); // Generate a random number between 1 and 3
                computer_guess = convertComputersGuess(computer_guess_int);

                int round_winner = getUserGuessAndCompare(computer_guess);

                calculateRoundWinner(round_winner, comp_win_tally, player_win_tally, DISPLAY_MESSAGE_TIME,
                  &comp_win_tally, &player_win_tally, &player_quit);

                //Handles if the player wants to quit
                if (player_quit == true)
                {
                    rps_is_running = false;
                    break;
                }
                
            }
            else if (use_strategy == 2)
            {
                //Using Strategy
                system("cls");
                sleep(100);

                rounds_played += 1; //Increment the amount of rounds played

                if (rounds_played == 1)
                {
                    //If this is the first round - play 'as normal'

                    int computer_guess_int = 1 + (std::rand() % 3);
                    computer_guess = convertComputersGuess(computer_guess_int);

                    last_comp_guess = computer_guess;

                    int round_winner = getUserGuessAndCompare(computer_guess);
                    calculateRoundWinner(round_winner, comp_win_tally, player_win_tally, DISPLAY_MESSAGE_TIME,
                      &comp_win_tally, &player_win_tally, &player_quit);

                    //Handles if the player chooses to quit
                    if (player_quit == true)
                    {
                        rps_is_running = false;
                        break;
                    }

                    //Add the corresponding winner to the winner history
                    last_winner = getLastWinner(round_winner);
                   

                    last_player_guess = findPlayersGuess(round_winner, computer_guess);
                }
                else
                {
                    //Not the first go
                    if (last_winner == 'C')
                    {
                        //The computer won the last game - play whatever the player just played

                        int round_winner = getUserGuessAndCompare(last_player_guess);
                        calculateRoundWinner(round_winner, comp_win_tally, player_win_tally, DISPLAY_MESSAGE_TIME,
                          &comp_win_tally, &player_win_tally, &player_quit);
                        
                        // Handles if the player chooses to quit
                        if (player_quit == true)
                        {
                          rps_is_running = false;
                          break;
                        }

                        // Add the corresponding winner to the winner history
                        last_winner = getLastWinner(round_winner);
                        
                        last_comp_guess = last_player_guess;
                        last_player_guess = findPlayersGuess(round_winner, computer_guess);
                    }
                    else if (
                      (last_winner == 'P') || (last_winner == 'D'))
                    {
                        //The player won the last game - play whatever would've won against the player

                        if (last_comp_guess == 'R')
                        {
                            //Player played paper
                            computer_guess = 'S';
                        }
                        else if (last_comp_guess == 'P')
                        {
                            //Player played scissors
                            computer_guess = 'R';
                        }
                        else if (last_comp_guess == 'S')
                        {
                            //Player played rock
                            computer_guess = 'P';
                        }

                        int round_winner = getUserGuessAndCompare(last_player_guess); //Plays the move
                        calculateRoundWinner(round_winner, comp_win_tally, player_win_tally, DISPLAY_MESSAGE_TIME,
                          &comp_win_tally, &player_win_tally, &player_quit);

                        // Handles if the player chooses to quit
                        if (player_quit == true)
                        {
                            rps_is_running = false;
                            break;
                        }

                        // Add the corresponding winner to the winner history
                        last_winner = getLastWinner(round_winner);
                        
                        last_comp_guess = computer_guess;
                        last_player_guess = findPlayersGuess(round_winner, computer_guess);
                    }
                }
            }
        }
    }

    //This section is not within the loop as in every scenario this needs to be output at the end of a game
    system("cls");
    std::cout << "Thank you for playing!" << std::endl; 

    std::cout << "The results for this game are: "
              << "\nComputer: " << comp_win_tally
              << "\nPlayer: " << player_win_tally << std::endl;

    std::cout << "\nPress Enter to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}


//MAIN MENU
int main()
{
    //MAIN LOOP
  
    char user_entry = '\0';  
    bool is_running = true;
  
    // Main menu loop
    while (is_running) 
    {
        system("cls");
    
        std::cout << "Hello, Welcome to Console Games!\n"
                  << "> Type G to play Guess the Number\n"
                  << "> Type R to play Rock Paper Scissors\n" 
                  << "> Type Q to quit" << std::endl;

        std::cout << "Option: "; 
        std::cin >> user_entry; 

        // Processing user input to select correct game.
        if (std::tolower(user_entry) == 'g')
        {
          playGuessTheNumber();
        }
        else if (std::tolower(user_entry) == 'r')
        {
          playRockPaperScissors();
        }
        else if (std::tolower(user_entry) == 'q')
        {
          is_running = false;
          std::cout << "\nThank you for playing!" << std::endl;
          sleep(2000); 
          break;
        }
        else
        {
          // Error handling
          std::cout << "Please enter a valid input!" << std::endl;
          sleep(900); 
        }
    }

  return 0;
}
