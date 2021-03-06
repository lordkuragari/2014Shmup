#include "Player.h"


Player::Player()
{
}

Player::Player(const char* a_path, float a_width, float a_height)
{
	spriteID = CreateSprite(a_path, a_width, a_height, true);
	fireDelay = .01;
	fireTime = 0;
}

Player::~Player()
{
}

void Player::Init(Vector2 a_pos, Vector2 a_vel, float a_radius, int a_health)
{
	pos = a_pos;
	velocity = a_vel;
	speed = 150;
	col.radius = a_radius;
	health = a_health;
	alive = true;
}
void Player::Input()
{
	velocity.Zero();

	if (IsKeyDown(GLFW_KEY_W))
	{
		velocity.y = 1;
	}
	if (IsKeyDown(GLFW_KEY_S))
	{
		velocity.y = -1;
	}
	if (IsKeyDown(GLFW_KEY_A))
	{
		velocity.x = -1;
	}
	if (IsKeyDown(GLFW_KEY_D))
	{
		velocity.x = 1;
	}
	if (IsKeyDown(GLFW_KEY_P))
	{
		if (fireTime >= fireDelay)
		BulletManager::SetBullet(PLAYER, pos, Vector2(0, 1), 200, 1);
		fireTime = 0;
	}


}

void Player::Update(float a_deltaTime)
{
	fireTime += a_deltaTime;
	Input();
	pos += velocity * speed * a_deltaTime;
	MoveSprite(spriteID, pos.x,pos.y);
}
void Player::Draw()
{
	DrawSprite(spriteID);
}