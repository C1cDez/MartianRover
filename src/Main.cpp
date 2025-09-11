#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPSm, unsigned int pTileSize);

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

	struct RendererConstants
	{
		unsigned int mScreenWidth, mScreenHeight;
		unsigned int mFPS;
		unsigned int mTileSize;
	} mRenderer;

	sf::RenderWindow* mWindow;
	sf::Event mEvent;

	Player mPlayer;
};

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, unsigned int pTileSize)
{
	mRunning = false;
	mRenderer.mScreenWidth = pWidth;
	mRenderer.mScreenHeight = pHeight;
	mRenderer.mFPS = pFPS;
	mRenderer.mTileSize = pTileSize;
	mWindow = new sf::RenderWindow{ sf::VideoMode{ mRenderer.mScreenWidth, mRenderer.mScreenHeight },
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close };
}
void Game::init()
{
	mRunning = true;
	mWindow->setFramerateLimit(mRenderer.mFPS);
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

		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::W) std::cout << "AAA";
	}
}
void Game::update()
{
	
}
void Game::render()
{

}


int main()
{
	Game game{ 1200, 800, 60, 30 };
	game.init();
	game.run();
	game.finish();
}
