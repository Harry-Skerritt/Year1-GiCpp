#ifndef WHACKAMOLESFML_ENEMY_H
#define WHACKAMOLESFML_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
	private:
    sf::Sprite enemy_sprite;
    float points;
	float speed;
    sf::Texture texture;
    bool x_reverse;
    bool y_reverse;
    int enemy_id;
    bool is_visible;
    bool is_negative;


	public:
    //Constructor/Deconstructors
    Enemy();
    ~Enemy();

    //Initialisers
	void init(sf::Texture, float, float);           //Initialises an enemy

	//Getters
    sf::Sprite getSprite();                         //Returns the enemy sprite
	sf::Texture getTexture();                       //Returns the enemy texture
    float getPointValue();                          //Returns the points an enemy is worth
    float getSpeedModifier();                       //Returns the enemies speed modifier
    bool isXReversed();                             //Is X axis reversed
    bool isYReversed();                             //Is Y axis reversed
    int getId();                                    //Returns the enemies ID
    bool getIsVisible();                            //Returns visivility state
    bool getIsNegative();                           //Returns if this is a do not click enemy

	//Setters
    void setRandomPosition(sf::Vector2f);           //Sets the enemy to a random position within provided vector
    void setId(int);                                //Sets the enemies ID
    void setIsVisible(bool);                        //Sets visibility state
    void setEnemyScale(float, float);               //Sets the enemy scale
    void setIsNegative(bool);                       //Sets if this is a do not click enemy


	//Methods
    void enemyMove(float, float, sf::Vector2f);     //Moves the enemy
};

#endif