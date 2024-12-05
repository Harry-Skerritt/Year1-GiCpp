
#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Game
{
	public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseClicked(sf::Event event);
	void keyPressed(sf::Event event);

	private:
	bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
	void spawn();

	sf::RenderWindow& window;
	sf::Sprite background;
	sf::Texture background_texture;
	sf::Sprite bird;
	sf::Texture bird_texture;
	sf::Font font;
	sf::Text title_text;

	sf::Text score_text;

	bool in_menu;
	sf::Text menu_text;
	sf::Text play_option;
	sf::Text quit_option;
	bool play_selected = true;

	bool reverse = false;
	float speed = 200;

	int score = 0;


	//***Optional Challenge Stuff***

	//Menu Text
    sf::Text menu_instructions;

	//Timer Related
    int game_timer;
    sf::Clock timer_clock;
    sf::Time timer;
	sf::Text timer_text;
    bool timer_paused;
    const static int REMAINING_TIME = 60;
    int time_to_display;
    int win_time;

	//Lose State
    bool in_lose;

	//Win State
	bool in_win;
    bool play_on = false;
	sf::Text win_continue;
    sf::Text win_quit;
    bool continue_selected = true;
    bool in_continue_mode  = false;
    const static int WIN_SCORE = 250;

	//Enemy related
	const static int MAX_ENEMIES = 10;
    Enemy enemy_array[MAX_ENEMIES]; // For storing the enemies

	sf::Texture enemy_texutures[7]; //For storing textures
    float enemy_values[7][7];			//For storing points and speed modifier

	int enemies_on_screen;			//How many enemies are currently spawned

	void checkOverlapping(int);

	//Spawns more than one enemy based on the number inputted
    void multiSpawn(int, int);
    void spawnDNC();

	//Text
    sf::Text level_complete_text;
	sf::Text win_text;
    sf::Text lose_text;

	//Enemy character Textures
    sf::Texture cat_texture;
    sf::Texture chick_texture;
    sf::Texture fox_texture;
    sf::Texture pig_texture;
    sf::Texture rabbit_texture;

	//Good character texture
    sf::Texture mouse_texture;
};

#endif // WHACKAMOLESFML_GAME_H
