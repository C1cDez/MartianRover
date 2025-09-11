#include <iostream>

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Easing_functions.h"

class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, unsigned char _tile_size);

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
	unsigned char tile_size;
	bool mRunning;
	unsigned int mScreenWidth, mScreenHeight;
	unsigned int mFPS;
	sf::RenderWindow* mWindow;
	sf::Event mEvent;

	Player* player;
	sf::CircleShape player_shape; // TEMP FOR TESTING ONLY

	sf::CircleShape test_shape;
	Vec2f test_pos = {500.f, 500.f};
	float ticks = 0.f;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time duration = sf::Time::Zero;
};

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, unsigned char _tile_size)
{
	player = new Player({ 150.f, 105.f });
	tile_size = _tile_size;
	mRunning = false;
	mScreenWidth = pWidth;
	mScreenHeight = pHeight;
	mFPS = pFPS;
	mWindow = new sf::RenderWindow{ sf::VideoMode{ mScreenWidth, mScreenHeight }, 
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close };

	player_shape.setPosition( { player->get_pos().x, player->get_pos().y } );
	player_shape.setFillColor(sf::Color::White);
	player_shape.setRadius(15);

	test_shape.setPosition({ test_pos.x, test_pos.y });
	test_shape.setFillColor(sf::Color::White);
	test_shape.setRadius(5);
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

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::W) { player->set_delta({ 0.0, -static_cast<float>(tile_size) }); }

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::S) { player->set_delta({ 0.0, static_cast<float>(tile_size) }); }

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::D) { player->set_delta({ static_cast<float>(tile_size), 0.0 }); }

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::A) { player->set_delta({ -static_cast<float>(tile_size), 0.0 }); }
	}
}
void Game::update()
{
	//std::cout << 5.f * Easing_functions::quadraticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f) << " || " << test_pos.x << " || " << duration.asSeconds() << std::endl;
	player->move();
	player_shape.setPosition({ player->get_pos().x, player->get_pos().y });

	duration += TimePerFrame;
	test_pos.x += -10.f * Easing_functions::quadraticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f);
	test_shape.setPosition({ test_pos.x, test_pos.y });
}	
void Game::render()
{
	mWindow->draw(player_shape);
	mWindow->draw(test_shape);
}


int main()
{
	Game game{ 1200, 800, 60, 30 };
	game.init();
	game.run();
	game.finish();
}
