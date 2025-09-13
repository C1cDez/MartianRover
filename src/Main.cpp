#include <iostream>
#include <memory>

#include "Renderer.h"
#include "Player.h"

class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, int pTileSize);

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void init();
	void run();
	void finish();

	void pollEvents();

	void update();
	void render();

	~Game() = default;

private:
	bool mRunning;
	Renderer mRenderer;
	std::unique_ptr<sf::RenderWindow> mWindow;
	sf::Event mEvent;

	Player mPlayer;
	std::unique_ptr<PlayerRenderer> mPlayerRenderer;
};

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, int pTileSize)
{
	mRunning = false;
	mRenderer.mScreenWidth = pWidth;
	mRenderer.mScreenHeight = pHeight;
	mRenderer.mFPS = pFPS;
	mRenderer.mProjectionMatrix = { pTileSize, 0, 0, pTileSize };
	mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode{ mRenderer.mScreenWidth, mRenderer.mScreenHeight },
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close);
	mPlayerRenderer = std::make_unique<PlayerRenderer>(&mPlayer);
}
void Game::init()
{
	mRunning = true;
	mWindow->setFramerateLimit(mRenderer.mFPS);
	
	mPlayer.setPos({ 0, 0 });
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
			mPlayer.move({ 0, -1 });
		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::S)
			mPlayer.move({ 0, 1 });
		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::A)
			mPlayer.move({ -1, 0 });
		if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::D)
			mPlayer.move({ 1, 0 });
	}
}
void Game::update()
{

}
void Game::render()
{
	mPlayerRenderer->link(mRenderer);
	mWindow->draw(mPlayerRenderer->get());
}


int main()
{
	Game game{ 1200, 800, 60, 30 };
	game.init();
	game.run();
	game.finish();
}
