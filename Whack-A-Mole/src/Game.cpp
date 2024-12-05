#include "Game.h"
#include "Enemy.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
    // init font
    if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
    {
      std::cout << "Font did not load" << std::endl;
    }

    // Menu
    in_menu = true;

    menu_text.setString("Welcome to Whack-A-Mole. Select and option:");
    menu_text.setFont(font);
    menu_text.setCharacterSize(30);
    menu_text.setFillColor(sf::Color(145, 242, 223, 255));
    menu_text.setPosition(
      window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
      window.getSize().y / 4 - menu_text.getGlobalBounds().height / 2);

    play_option.setString("Play");
    play_option.setFont(font);
    play_option.setCharacterSize(50);
    play_option.setFillColor(sf::Color(145, 242, 223, 255));
    play_option.setPosition(
      window.getSize().x / 2 - play_option.getGlobalBounds().width / 2,
      window.getSize().y / 2 - play_option.getGlobalBounds().height / 2 - 50);

    quit_option.setString("Quit");
    quit_option.setFont(font);
    quit_option.setCharacterSize(50);
    quit_option.setFillColor(sf::Color(145, 242, 223, 255));
    quit_option.setPosition(
      window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2,
      window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2 + 50);

    //Optional Extras
    menu_instructions.setString(
      "Try to get " + std::to_string(WIN_SCORE) + " points in " +
      std::to_string(REMAINING_TIME) + "s");
    menu_instructions.setFont(font);
    menu_instructions.setCharacterSize(30);
    menu_instructions.setFillColor(sf::Color(145, 242, 223, 255));
    menu_instructions.setPosition(
      window.getSize().x / 2 - menu_instructions.getGlobalBounds().width / 2,
      window.getSize().y / 2 - menu_instructions.getGlobalBounds().height / 2 +
        150);

    // Main Game

    // Score
    score_text.setFont(font);
    score_text.setCharacterSize(30);
    score_text.setFillColor(sf::Color(255, 0, 0, 255));

    // Background Text
    title_text.setString("Whack-a-mole");
    title_text.setFont(font);
    title_text.setCharacterSize(100);
    title_text.setFillColor(sf::Color(255, 255, 255, 128));
    title_text.setPosition(
      window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
      window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);

    //Background sprite
    if (!background_texture.loadFromFile("../Data/Images/background.png"))
    {
      std::cout << "Background texture did not load" << std::endl;
    }
    background.setTexture(background_texture);

   
    //Enemies
    enemies_on_screen = 0;

    //Initialise all the enemies in the array
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
      enemy_array[i].setId(i);
      enemy_array[i].setIsVisible(false);
      enemy_array[i].setIsNegative(false);
    }


    //init texture and values
    if (!bird_texture.loadFromFile("../Data/Images/bird.png"))
    {
      std::cout << "Bird texture did not load" << std::endl;
    }

    enemy_texutures[0] = bird_texture;
    enemy_values[0][0] = 1.0;
    enemy_values[0][1] = 1.0;

    if (!cat_texture.loadFromFile("../Data/Images/Cat_Right.png"))
    {
      std::cout << "Cat Texture did no load" << std::endl;
    }
    enemy_texutures[1] = cat_texture;
    enemy_values[1][0] = 2.0;
    enemy_values[1][1] = 1.2;

    if (!chick_texture.loadFromFile("../Data/Images/Chick_Right.png"))
    {
      std::cout << "Chick Texture did no load" << std::endl;
    }
    enemy_texutures[2] = chick_texture;
    enemy_values[2][0] = 4.0;
    enemy_values[2][1] = 1.4;

    if (!fox_texture.loadFromFile("../Data/Images/Fox_Right.png"))
    {
      std::cout << "Fox Texture did no load" << std::endl;
    }
    enemy_texutures[3] = fox_texture;
    enemy_values[3][0] = 5.0;
    enemy_values[3][1] = 1.6;

    if (!pig_texture.loadFromFile("../Data/Images/Pig_Right.png"))
    {
      std::cout << "Pig Texture did no load" << std::endl;
    }
    enemy_texutures[4] = pig_texture;
    enemy_values[4][0] = 6.0;
    enemy_values[4][1] = 1.8;

    if (!rabbit_texture.loadFromFile("../Data/Images/Rabbit_Right.png"))
    {
      std::cout << "Rabbit Texture did no load" << std::endl;
    }
    enemy_texutures[5] = rabbit_texture;
    enemy_values[5][0] = 8.0;
    enemy_values[5][1] = 2.2;

    //Load Good Character Textures
    if (!mouse_texture.loadFromFile("../Data/Images/Mouse_Right.png"))
    {
      std::cout << "Mouse Texture did no load" << std::endl;
    }
    enemy_texutures[6] = mouse_texture;
    enemy_values[6][0] = 5.0;
    enemy_values[6][1] = 0.75;


    //Optional Extras Text
    level_complete_text.setFont(font);
    level_complete_text.setCharacterSize(50);
    level_complete_text.setFillColor(sf::Color(255, 210, 0, 255));
    level_complete_text.setPosition(
      (window.getSize().x / 2 - level_complete_text.getGlobalBounds().width/2),
      60);


    //Timer
    game_timer = 0;
    
    timer = timer_clock.getElapsedTime();
    timer_text.setFont(font);
    timer_text.setCharacterSize(30);
    timer_text.setFillColor(sf::Color::Black);
    timer_text.setPosition(
      window.getSize().x / 2 - timer_text.getGlobalBounds().width / 4, 20);
    
    //Win
    win_text.setFont(font);
    win_text.setCharacterSize(30);
    win_text.setFillColor(sf::Color(255, 226, 92, 255));
    timer_paused = false;
    win_time     = 0;
    in_win       = false;

    //Lose
    in_lose = false;

    win_continue.setString("Play On");
    win_continue.setFont(font);
    win_continue.setCharacterSize(50);
    win_continue.setFillColor(sf::Color(145, 242, 223, 255));
    win_continue.setPosition(
      window.getSize().x / 2 - win_continue.getGlobalBounds().width / 2 - 200,
      window.getSize().y / 2 - win_continue.getGlobalBounds().height / 2 + 60);

    win_quit.setString("Quit");
    win_quit.setFont(font);
    win_quit.setCharacterSize(50);
    win_quit.setFillColor(sf::Color(145, 242, 223, 255));
    win_quit.setPosition(
      window.getSize().x / 2 - win_quit.getGlobalBounds().width / 2 + 200,
      window.getSize().y / 2 - win_quit.getGlobalBounds().height / 2 + 60);

   
    spawn(); //spawns initial bird.
    //score = 90; //<-TESTING
    return true;
}

void Game::update(float dt)
{

    //For enemies
    for (int i = 0; i < std::size(enemy_array); i++)
    {
      // For X direction
      enemy_array[i].enemyMove(speed, dt, sf::Vector2f(window.getSize()));
    }

    sf::Sprite sprite = enemy_array[0].getSprite();
    
    float sx = sprite.getPosition().x;
    float sy = sprite.getPosition().y;

    if (time_to_display == 0)
    {
      in_lose = true;
  
        //lose state
      win_text.setString(
        "You failed to get " + std::to_string(WIN_SCORE) + " points in " + std::to_string(REMAINING_TIME) + "s");

      win_text.setPosition(
        (window.getSize().x / 2) - (win_text.getGlobalBounds().width / 2),
        (window.getSize().y / 2) - (win_text.getGlobalBounds().height / 2));

      level_complete_text.setString("You Lose!");
      level_complete_text.setPosition(
        (window.getSize().x / 2) -
          (level_complete_text.getGlobalBounds().width / 2),
        (window.getSize().y / 2) -
          (level_complete_text.getGlobalBounds().height / 2) - 60);
    }

    if (score >= WIN_SCORE && play_on == false)
    {
      // Win State
      in_win = true;
      win_text.setString(
        "You got " + std::to_string(score) + " points in " +
        std::to_string(win_time) + "s");

      win_text.setPosition(
        (window.getSize().x / 2) - (win_text.getGlobalBounds().width / 2),
        (window.getSize().y / 2) - (win_text.getGlobalBounds().height / 2));

      level_complete_text.setString("You Win!");
      level_complete_text.setPosition(
        (window.getSize().x / 2) -
          (level_complete_text.getGlobalBounds().width / 2),
        (window.getSize().y / 2) -
          (level_complete_text.getGlobalBounds().height / 2) - 60);

      if (timer_paused == false)
      {
        win_time     = game_timer;
        timer_paused = true;
      }
    }

}
//x 139.5 y 131.5
void Game::render()
{
    if (in_menu == true) 
    {
      window.clear(sf::Color(44, 62, 82, 255)); //Check allowed
      window.draw(menu_text);
      window.draw(play_option);
      window.draw(quit_option);
      window.draw(menu_instructions);
    }
    else
    {
      window.draw(background);
      window.draw(title_text);
      window.draw(level_complete_text);


      //Timer Clock
      timer       = timer_clock.getElapsedTime();
      game_timer = (int)timer.asSeconds();
      time_to_display = REMAINING_TIME - game_timer;
      timer_text.setString(std::to_string(time_to_display) + "s");
      window.draw(timer_text);


      // Draws all enemies
      for (int i = 0; i < MAX_ENEMIES; i++) 
      {
        if (enemy_array[i].getIsVisible())
        {
          window.draw(enemy_array[i].getSprite());
        }
      }

      score_text.setString("Score: " + std::to_string(score));
      score_text.setPosition(
        (window.getSize().x - score_text.getGlobalBounds().width - 20), 20);
      window.draw(score_text);

      if (in_lose == true && play_on == false)
      {
        window.clear(sf::Color(44, 62, 82, 255));
        window.draw(win_text);
        window.draw(level_complete_text);
        window.draw(win_continue);
        window.draw(win_quit);
      }

      if ((score >= WIN_SCORE) && (in_win == true) && (play_on == false))
      {
        window.clear(sf::Color(44, 62, 82, 255));
        window.draw(win_text);
        window.draw(level_complete_text);
        window.draw(win_continue);
        window.draw(win_quit);
      }
    }
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);
   
    bool collision_found = false;

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
      if (enemy_array[i].getIsVisible())
      {
        sf::Sprite current_sprite = enemy_array[i].getSprite();
        if (collisionCheck(click, current_sprite))
        {
          int enemy_id       = enemy_array[i].getId();
          int collided_enemy = i;
          if (enemy_id != i)
          {
            // this is the wrong enemy
            collided_enemy = enemy_id;
          }
          else
          {
            enemy_array[collided_enemy].setIsVisible(false);
            if (enemy_array[collided_enemy].getIsNegative())
            {
              //Is a do not click
              score -= (int)enemy_array[collided_enemy].getPointValue();

            }
            else
            {
              //Is a regular enemy
              score += (int)enemy_array[collided_enemy].getPointValue();
            }

            enemies_on_screen--;
            spawn();
            collision_found = true;
            break;
          }
        }
        else
        {
          std::cout << "Collision not detected" << std::endl;
        }
      }
    }
}

void Game::keyPressed(sf::Event event)
{
    if (in_menu == true)
    {
      if ((event.key.code == sf::Keyboard::Left) ||
          (event.key.code == sf::Keyboard::Right))
      {
        play_selected = !play_selected;
        if (play_selected)
        {
          play_option.setString("> Play < ");
          play_option.setFillColor(sf::Color(0, 255, 179, 255));
          
          //Shoulnt need this
          play_option.setPosition(
            window.getSize().x / 2 - play_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - play_option.getGlobalBounds().height / 2 -
              50);

          quit_option.setString("Quit");
          quit_option.setFillColor(sf::Color(145, 242, 223, 255));

          // Shoulnt need this
          quit_option.setPosition(
            window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2 +
              50);
        }
        else
        {
          play_option.setString("Play");
          play_option.setFillColor(sf::Color(145, 242, 223, 255));
          play_option.setPosition(
            window.getSize().x / 2 - play_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - play_option.getGlobalBounds().height / 2 -
              50);

          quit_option.setString("> Quit <");
          quit_option.setFillColor(sf::Color(0, 255, 179, 255));
          quit_option.setPosition(
            window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2 +
              50);
        }
      }
      else if (event.key.code == sf::Keyboard::Enter)
      {
        if (play_selected)
        {
          in_menu = false;
        }
        else
        {
          window.close();
        }
      }
    }

    if (in_win == true || in_lose == true)
    {
      if (
        (event.key.code == sf::Keyboard::Left) ||
        (event.key.code == sf::Keyboard::Right))
      {
        continue_selected = !continue_selected;
        if (continue_selected)
        {
          win_continue.setString("> Play On < ");
          win_continue.setFillColor(sf::Color(0, 255, 179, 255));


          win_quit.setString("Quit");
          win_quit.setFillColor(sf::Color(145, 242, 223, 255));
        }
        else
        {
          win_continue.setString("Play On");
          win_continue.setFillColor(sf::Color(145, 242, 223, 255));

          win_quit.setString("> Quit <");
          win_quit.setFillColor(sf::Color(0, 255, 179, 255));
        }
      }
      else if (event.key.code == sf::Keyboard::Enter)
      {
        if (continue_selected)
        {
          play_on = true;
          timer_text.setColor(sf::Color::Transparent);
          level_complete_text.setColor(sf::Color::Transparent);
          spawn();
        }
        else
        {
          window.close();
        }
      }
    }
    
}

bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
    int collision_offset = 50;

    float centre_x = sprite.getPosition().x + (sprite.getGlobalBounds().width / 2);
    float centre_y = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
   
    if (((click.x >= (centre_x - collision_offset)) && (click.x <= (centre_x + collision_offset))) &&
        ((click.y >= (centre_y - collision_offset)) && (click.y <= (centre_y + collision_offset))))
    {
      return true;
    }
    else
    {
      return false;
    }
}

void Game::spawn()
{

    // Load Enemies
    // 0 - bird
    // 1 - cat
    // 2 - chick
    // 3 - fox
    // 4 - pig
    // 5 - rabbit

    /*
    Different difficuly based on score:
        Score below 10, 1 bird - Done
        Score between 10 and 25 multiple enemies 2 types upto 25% MAX enemies - Done
        Score between 25 and 50 multiple enemies 3 types up to 50% MAX enemies - Done
        Score between 50 and 75 multiple enemies 4 types  - Done | to do >+ 1 do not click upto 75% MAX enemies
        Score between 75 and WIN_SCORE multiple enemies 5 types  - Done | to do > + 2 do not click up to 100% MAX enemies
        Above WIN_SCORE: all enemies + do not clicks upto 100% MAX enemies (for now) - Done as play on
        WIN_SCORE = 150
    */



    int difficulty_1 = 2;
    int difficulty_2 = 3;
    int difficulty_3 = 4;
    int difficulty_4 = 5;

    //DIFFICULTY 0
    if (score < 10)
    {
      // Only allows 1 enemy on screen at a time
      if (enemies_on_screen == 0)
      {
        enemy_array[enemies_on_screen].init(
          enemy_texutures[0], enemy_values[0][0], enemy_values[0][1]);

        enemy_array[enemies_on_screen].setEnemyScale(0.5f, 0.5f);

        enemy_array[enemies_on_screen].setRandomPosition(
          sf::Vector2f(window.getSize()));

        enemy_array[enemies_on_screen].setIsVisible(true);

        enemies_on_screen++;
      }
    }
    //DIFFICULTY 1
    else if (score >= 10 && score < 25)
    {
      if (enemies_on_screen <= difficulty_1) 
      {
        int enemies_to_spawn = 1; // std::rand() % difficulty_1 + 1;

        if ((enemies_on_screen + enemies_to_spawn) >= difficulty_1)
        {
          // The amount to spawn + whats on screen is greater than the amount
          // allowed by the level
          enemies_to_spawn = enemies_to_spawn / 2;
          multiSpawn(enemies_to_spawn, 5);
        }
        else
        {
          multiSpawn(enemies_to_spawn, 5);
        }
      }
    }
  
    //DIFFICULTY 2
    else if (score >= 25 && score < 50)
    {
      if (enemies_on_screen <= difficulty_2)
      {
        int enemies_to_spawn = std::rand() % difficulty_2 + 1;


        if ((enemies_on_screen + enemies_to_spawn) >= difficulty_2)
        {
          // The amount to spawn + whats on screen is greater than the amount
          // allowed by the level
          enemies_to_spawn = enemies_to_spawn / 2;
          multiSpawn(enemies_to_spawn, 2);
        }
        else
        {
          multiSpawn(enemies_to_spawn, 2);
        }
      }
    }
    
    //DIFFICULTY 3
    else if (score >= 50 && score < 75)
    {
      if (enemies_on_screen <= difficulty_3)
      {
        int enemies_to_spawn = std::rand() % difficulty_3 + 1;

        if ((enemies_on_screen + enemies_to_spawn) >= difficulty_3)
        {
          // The amount to spawn + whats on screen is greater than the amount
          // allowed by the level
          enemies_to_spawn = enemies_to_spawn / 2;
          multiSpawn(enemies_to_spawn, 3);
        }
        else
        {
          multiSpawn(enemies_to_spawn, 3);
          spawnDNC();
        }
      }
    }
    
    //Difficulty 4
    else if ((score >= 75 && score <= WIN_SCORE) && (play_on == false) || (play_on == true))
    {
      if (enemies_on_screen <= difficulty_4)
      {
        int enemies_to_spawn = std::rand() % difficulty_4 + 1;

        if ((enemies_on_screen + enemies_to_spawn) >= difficulty_4)
        {
          // The amount to spawn + whats on screen is greater than the amount
          // allowed by the level
          enemies_to_spawn = enemies_to_spawn / 2;
          multiSpawn(enemies_to_spawn, 5);
        }
        else
        {
          multiSpawn(enemies_to_spawn, 5);
          spawnDNC();
        }
      }
    }
}

void Game::multiSpawn(int enemies_to_spawn, int enemy_types) 
{
    int enemies_spawned = 0;
    int i               = -1;
    while ((enemies_spawned != enemies_to_spawn) || (i != MAX_ENEMIES))
    {
      if ((enemies_spawned == enemies_to_spawn) || (i == 20))
      {
        break;
      }
      i++;
      if (enemy_array[i].getIsVisible() == false)
      {
        int enemy_to_create = std::rand() % enemy_types;

        enemy_array[i].init(
          enemy_texutures[enemy_to_create],
          enemy_values[enemy_to_create][0],
          enemy_values[enemy_to_create][1]);

        if (enemy_to_create == 0)
        {
          // If bird texture
          enemy_array[i].setEnemyScale(0.5f, 0.5f);
        }
        else
        {
          enemy_array[i].setEnemyScale(0.75f, 0.75f);
        }

        enemy_array[i].setRandomPosition(sf::Vector2f(window.getSize()));
        enemy_array[i].setIsNegative(false);
        enemy_array[i].setIsVisible(true);
        enemies_on_screen++;
        enemies_spawned++;
      }
    }
}

void Game::spawnDNC() 
{
    int chance_to_create_int = std::rand() % 100 + 1; //1-100
    float chance_to_create   = chance_to_create_int / 100; //0 - 1

    //Want a 40% chance
    if (chance_to_create >= 0.6f)
    {
        //Find a suitable enemy to spawn
      int enemies_spawned = 0;
      int i               = -1;
      while ((enemies_spawned != 1) || (i != MAX_ENEMIES))
      {
        if ((enemies_spawned == 1) || (i == 20))
        {
          break;
        }
        i++;
        if (enemy_array[i].getIsVisible() == false)
        {
          enemy_array[i].init(
            enemy_texutures[6],
            enemy_values[6][0],
            enemy_values[6][1]);

          enemy_array[i].setEnemyScale(0.75f, 0.75f);
          enemy_array[i].setRandomPosition(sf::Vector2f(window.getSize()));
          enemy_array[i].setIsNegative(true);
          enemy_array[i].setIsVisible(true);
          enemies_on_screen++;
          enemies_spawned++;
          break;
        }
      }
    }
}

void Game::checkOverlapping(int enemies_on_screen) 
{
    for (int i = 0; i < enemies_on_screen; i++)
    {
      enemy_array[enemies_on_screen].setRandomPosition(sf::Vector2f(window.getSize()));
      for (int j = 0; j < i - 1; j++)
      {
        sf::Sprite sprite_one = enemy_array[enemies_on_screen].getSprite();
        sf::Sprite sprite_two = enemy_array[enemies_on_screen - 1].getSprite();

        if (
          (sprite_one.getGlobalBounds().width) >= (sprite_two.getGlobalBounds().width - 50) &&
          (sprite_one.getGlobalBounds().width) <= (sprite_two.getGlobalBounds().width + 50) &&
          (sprite_one.getGlobalBounds().height) >= (sprite_two.getGlobalBounds().height - 50) &&
          (sprite_one.getGlobalBounds().height) <= (sprite_two.getGlobalBounds().height + 50))
        {
          enemy_array[enemies_on_screen].setRandomPosition(sf::Vector2f(window.getSize()));
        }
      }
    }


}
