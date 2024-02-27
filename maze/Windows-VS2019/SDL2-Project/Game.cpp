#include "Game.h"
#include "TextureUtil.h"
#include "AABB.h"

Game::Game()
{
	mainWindow = nullptr;
	gameRenderer = nullptr;

	backgroundTexture = nullptr;
	
	player = nullptr;
	npc = nullptr;
	testborder = nullptr;
	points = 0;
	ppf = 0;

	quit = false;
}
Game::~Game()
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = nullptr;

	delete player;
	player = nullptr;

	delete npc;
	npc = nullptr;

	delete testborder;
	testborder = nullptr;

	for (vector<Bullet*>::iterator it = bullets.begin();
		it != bullets.end();
		)
	{
		delete* it;
		*it = nullptr;
		it = bullets.erase(it);
	}


	SDL_DestroyRenderer(gameRenderer);
	gameRenderer = nullptr;

	SDL_DestroyWindow(mainWindow);
	mainWindow = nullptr;
}




void Game::init()
{

	//boilerplate SDL init
	mainWindow = SDL_CreateWindow("maze game",

		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_W,
		WINDOW_H,
		SDL_WINDOW_SHOWN);
	if (mainWindow != nullptr)
	{
		// if the window creation succeeded create our renderer
		gameRenderer = SDL_CreateRenderer(mainWindow, 0, 0);
		if (gameRenderer == nullptr)
		{
			throw std::runtime_error("Error - SDL could not create renderer\n");
			
		}
	}
	else
	{
		// could not create the window, so dont try
		// and create the renderer.
		throw std::runtime_error("Error - SDL could not create Window\n");
		
	}

	keyStates = SDL_GetKeyboardState(NULL);

	

	backgroundTexture = createTexture(gameRenderer, "assets/images/maze.png");

	//class initialisation

	player = new Player();
	player->init(gameRenderer);
	
	npc = new NPC();
	npc->init(gameRenderer);
	npc->setGame(this);
	
	testborder = new Border();
	testborder->init(gameRenderer);
	

}



void Game::draw()
{
	SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);

	SDL_RenderClear(gameRenderer);
	SDL_RenderCopy(gameRenderer, backgroundTexture, NULL, NULL);
	
	player->draw(gameRenderer);
	npc->draw(gameRenderer);
	testborder->draw(gameRenderer); 
	for (int i = 0; i < bullets.size(); i++)
		bullets[i]->draw(gameRenderer);

	SDL_RenderPresent(gameRenderer);
}

void Game::update( float timeDeltaInSeconds)
{
	player->update(timeDeltaInSeconds);
	npc->update(timeDeltaInSeconds);

	//Check bullet Timer and collision
	
	for (vector<Bullet*>::iterator it = bullets.begin();
		it != bullets.end();
		)
	{
		(*it)->update(timeDeltaInSeconds);



		if ((*it)->outOfTime())
		{
			delete* it;
			*it = nullptr;
			it = bullets.erase(it);
		}
		else
		{
			++it;
		}

	}
	for (vector<Bullet*>::iterator it = bullets.begin();
		it != bullets.end();
		)
	{

		if ((*it)->getAABB()->intersects(player->getAABB()))
		{
			player->takeDamage((*it)->getDamage());
			delete* it;
			*it = nullptr;
			it = bullets.erase(it);
		}
		else
		{
			it++;
		}
	}

	//Check player/NPC intersection

	if (npc->getAABB()->intersects(player->getAABB()))
	{
		player->takeDamage((npc)->getDamage());
		
		
	}

	//prototype death, simply exists and prints to console

	if (player->isDead())
	{
		printf("you died! you got %d points!", points);
		quit = true;

	}
	if (ppf > 10000
		)
	{
		points++;
		ppf = 0;
	}
	ppf++;
}
void Game::processInputs()
{
	
	
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;


			default:
				break;
			}
			


		default:
			break;
		}

	}
	player->processInput(keyStates);

	
}

void Game::runGameLoop()
{
	unsigned int currentTimeIndex;
	unsigned int timeDelta;
	float timeDeltaInSeconds;
	unsigned int prevTimeIndex;

	prevTimeIndex = SDL_GetTicks();


	while (!quit)
	{

		currentTimeIndex = SDL_GetTicks();
		timeDelta = currentTimeIndex - prevTimeIndex;
		timeDeltaInSeconds = timeDelta * 0.001f;

		prevTimeIndex = currentTimeIndex;


		processInputs();

		update(timeDeltaInSeconds);

		draw();


	}
}
Player* Game::getPlayer()
{
	return player;
}

void Game::createBullet(Vector2f* position, Vector2f* velocity)
{
	Bullet* bullet = new Bullet();


	bullet->init(gameRenderer, position, velocity);

	bullets.push_back(bullet);
	
}