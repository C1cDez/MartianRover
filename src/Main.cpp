#define DEBUG

#include <iostream>
#include <memory>

#include "Renderer.h"
#include "Player.h"

#ifdef DEBUG
#define LOG(info) std::cout << info << std::endl
#endif


class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, float pTileSize);

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

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS, float pTileSize)
{
	mRunning = false;
	mRenderer.mScreenWidth = pWidth;
	mRenderer.mScreenHeight = pHeight;
	mRenderer.mFPS = pFPS;
	mRenderer.mProjectionMatrix = { pTileSize, 0.0f, 0.0f, -pTileSize };
	mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode{ mRenderer.mScreenWidth, mRenderer.mScreenHeight },
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close);
	mPlayerRenderer = std::make_unique<PlayerRenderer>(&mPlayer, 10);
}
void Game::init()
{
	mRunning = true;
	mWindow->setFramerateLimit(mRenderer.mFPS);
	
	mPlayer.setPos({ 0, 0 });
	mPlayerRenderer->link(mRenderer);
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
		if (mEvent.type == sf::Event::Closed || 
			(mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::Escape))
		{
			mRunning = false;
			mWindow->close();
		}

		if (!mPlayerRenderer->doesMoveAnimPlay())
		{
			if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::W)
			{
				mPlayerRenderer->triggerMoveAnimation();
				mPlayer.move({ 0, 1 });
			}
			if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::S)
			{
				mPlayerRenderer->triggerMoveAnimation();
				mPlayer.move({ 0, -1 });
			}
			if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::A)
			{
				mPlayerRenderer->triggerMoveAnimation();
				mPlayer.move({ -1, 0 });
			}
			if (mEvent.type == sf::Event::KeyPressed && mEvent.key.code == sf::Keyboard::D)
			{
				mPlayerRenderer->triggerMoveAnimation();
				mPlayer.move({ 1, 0 });
			}
		}
	}
}
void Game::update()
{
	
}
void Game::render()
{
	if (mPlayerRenderer->doesMoveAnimPlay()) mPlayerRenderer->updateAnimation(mRenderer);
	mWindow->draw(mPlayerRenderer->get());
}


int main()
{
	Game game{ 1200, 800, 60, 30 };
	game.init();
	game.run();
	game.finish();
}
