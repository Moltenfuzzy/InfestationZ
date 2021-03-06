#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "../TileMap/tilemap.h"
#include "../player/player.h"
#include "../Camera/camera.h"
#include "../gun_graphic/gun.h"
#include <iomanip>


class GameState : public State {
public:
	typedef std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> GameMap;

	GameState(sf::RenderWindow* wdw);
	~GameState();
	void Update();
	void Render();
	void playMusic() {ambientNoise.play();}
	bool isDead() {return dead;}
	bool retry();
	bool quit();
	EntityPool zombie_pool;

private:
	void initMousePositions();
	void SpawnZombies();
	void initUISprites();
	void changeWeaponIcons();
	void SpawnHealth_Pack();
	void SpawnAmmo_Pack();
	void initDeathScreen();
	void drawDeathScreen();

	const float grid_multiplier = 1.4;
	const unsigned int spawn_amount = 10;
	unsigned int current_wave = 0;

	TileMap map;
	bool dead;
	Player p1;
	Gun g;
	Health health;
	Ammo_Box ammo;
	Camera camera;
	sf::Vector2i mouse_pos_screen;
	sf::Vector2i mouse_pos_window;
	sf::Vector2f mouse_pos_view;
	sf::Vector2u mouse_pos_grid;
	sf::Font font, csfont;
	Button Retry, Leave;
	//0 = Heatlh/Ammo, 1 = Zombies/Waves #
	sf::Text UI[2], cord_pos, deadText;
	std::stringstream ss;
	sf::Music ambientNoise;
	sf::Sprite crosshair, healthIcon, BulletIcon, GunIcon;
	sf::Texture CrosshairTexture, HealthTexture, BulletTexture, GunIconTexture;

	sf::Clock timer;
};
#endif // GAME_STATE_H