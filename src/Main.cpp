#include <iostream>

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS);

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
};

Game::Game(unsigned int pWidth, unsigned int pHeight, unsigned int pFPS)
{
	mRunning = false;
	mScreenWidth = pWidth;
	mScreenHeight = pHeight;
	mFPS = pFPS;
	mWindow = new sf::RenderWindow{ sf::VideoMode{ mScreenWidth, mScreenHeight }, 
		"Martian Rover", sf::Style::Titlebar | sf::Style::Close };
	mEvent = sf::Event{};
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
void Game::pollEvents()
{
	while (mWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::Closed)
		{
			mRunning = false;
			mWindow->close();
		}
	}
}

Game::~Game()
{
	delete mWindow;
}

void Game::update()
{
	
}
void Game::render()
{

}


int main()
{
	Game game{ 1200, 800, 60 };
	game.init();
	game.run();
	game.finish();
}
