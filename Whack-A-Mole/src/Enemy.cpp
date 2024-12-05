#include "Enemy.h"
#include <iostream>


Enemy::Enemy(){}

Enemy::~Enemy() {}

void Enemy::init(
  sf::Texture enemy_texture, float enemy_points, float speed_modifier)
{
  texture = enemy_texture;
  points = enemy_points;
  speed  = speed_modifier;
  x_reverse = false;
  y_reverse = false;

  enemy_sprite.setTexture(texture);
  

}

//Getters
sf::Sprite Enemy::getSprite() 
{
  return Enemy::enemy_sprite;
}	
	
sf::Texture Enemy::getTexture() 
{
  return Enemy::texture;
}

float Enemy::getPointValue() 
{
  return Enemy::points;
}

float Enemy::getSpeedModifier() 
{
  return Enemy::speed;
}

bool Enemy::isXReversed() 
{
  return x_reverse;
}

bool Enemy::isYReversed()
{
  return y_reverse;
}

int Enemy::getId() 
{
  return enemy_id;
}

bool Enemy::getIsVisible() 
{
  return is_visible;
}

bool Enemy::getIsNegative()
{
  return is_negative;
}


//Setters
void Enemy::setRandomPosition(sf::Vector2f window_size)
{
  int window_x =
    window_size.x - (enemy_sprite.getGlobalBounds().width*2);
  int window_y = window_size.y - (enemy_sprite.getGlobalBounds().height *2) ;

  int rand_x = std::rand() % window_x;
  int rand_y = std::rand() % window_y;

  enemy_sprite.setPosition(sf::Vector2f(rand_x, rand_y));
}

void Enemy::setId(int id) {
  enemy_id = id;
}

void Enemy::setIsVisible(bool visible)
{
  is_visible = visible;
}

void Enemy::setEnemyScale(float x, float y) 
{
  enemy_sprite.setScale(x, y);
}

void Enemy::setIsNegative(bool negative) 
{
  is_negative = negative;
}

//Other
void Enemy::enemyMove(float base_speed, float dt, sf::Vector2f window_size)
{
  if ((enemy_sprite.getPosition().x >
     (window_size.x - enemy_sprite.getGlobalBounds().width)) ||
    (enemy_sprite.getPosition().x < 0))
  {
    x_reverse = !x_reverse;
  }

  if ((enemy_sprite.getPosition().y > 
      (window_size.y - enemy_sprite.getGlobalBounds().height)) ||
      (enemy_sprite.getPosition().y < 0))
  {
      y_reverse = !y_reverse;
  }


  if (x_reverse)
  {
    enemy_sprite.setTextureRect(sf::IntRect(
      enemy_sprite.getLocalBounds().width,
      0,
      -enemy_sprite.getLocalBounds().width,
      enemy_sprite.getLocalBounds().height));
    enemy_sprite.move(-1.0f * (base_speed * speed) * dt, 0);
  }
  else
  {
    enemy_sprite.setTextureRect(sf::IntRect(
      0,
      0,
      enemy_sprite.getLocalBounds().width,
      enemy_sprite.getLocalBounds().height));
    enemy_sprite.move(1.0f * (base_speed * speed) * dt, 0);
  }

  if (y_reverse)
  {
    enemy_sprite.move(0, -1.0f * (base_speed * speed) * dt);
  }
  else
  {
    enemy_sprite.move(0, 1.0f * (base_speed * speed) * dt);
  }
}



