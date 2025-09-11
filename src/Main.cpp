#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, unsigned int pTileSize);

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void init();
	void run();
	void finish();

	void pollEvents();

	void update();
	void render();

	~Game();

private:
	bool mRunning;
	unsigned int mScreenWidth, mScreenHeight;
	unsigned int mFPS;
	sf::RenderWindow* mWindow;
	sf::Event mEvent;
	unsigned int mTileSize;

	Player mPlayer;
	sf::CircleShape player_shape; // TEMP FOR TESTING ONLY
};

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, unsigned int pTileSize)
{
	mRunning = false;
	mScreenWidth = pWidth;
	mScreenHeight = pHeight;
	mFPS = pFPS;
	mWindow = new sf::RenderWindow{ sf::VideoMode{ mScreenWidth, mScreenHeight }, 
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close };
	mTileSize = pTileSize;

	// TEMPORARY
	player_shape.setPosition( { mPlayer.getPos().x, mPlayer.getPos().y });
	player_shape.setFillColor(sf::Color::White);
	player_shape.setRadius(15);
}
void Game::init()
{
	mRunning = true;
	mWindow->setFramerateLimit(mFPS);
}
void Game::run()
{
	while (mRunning)
	{
		pollEvents();

		mWindow->clear();
		update();
		render();
		mWindow->display();
	}
}
void Game::finish()
{
}
Game::~Game()
{
	delete mWindow;
}

void Game::pollEvents()
{
	while (mWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::Closed)
		{
			mRunning = false;
			mWindow->close();
		}
		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::Escape)
		{
			mRunning = false;
			mWindow->close();
		}

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::W) 
			player->set_delta({ 0.0, -static_cast<float>(tile_size) });

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::S) 
			player->set_delta({ 0.0, static_cast<float>(tile_size) });

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::D) 
			player->set_delta({ static_cast<float>(tile_size), 0.0 });

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::A) 
			player->set_delta({ -static_cast<float>(tile_size), 0.0 });
	}
}
void Game::update()
{
	player->move();
	player_shape.setPosition({ player->get_pos().x, player->get_pos().y });

	duration += TimePerFrame;
	test_pos.x += -10.f * quadEaseInOut(1.f, 1.f, duration.asSeconds());
	test_shape.setPosition({ test_pos.x, test_pos.y });
}
void Game::render()
{
	mWindow->draw(player_shape);
}


int main()
{
	Game game{ 1200, 800, 60, 30 };
	game.init();
	game.run();
	game.finish();
}
