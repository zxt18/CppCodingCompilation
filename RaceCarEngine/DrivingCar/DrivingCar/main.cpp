#include <stack>
#include <iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


using namespace std;
// Override base class with your custom functionality
class OneLoneCoder_Maze : public olc::PixelGameEngine
{
public:
	OneLoneCoder_Maze()
	{
		// Name you application
		sAppName = "L Maze";
	}

private:
	int m_nMazeWidth;
	int m_nMazeHeight;
	int* m_maze;

	enum {
		CELL_PATH_N = 0x01,
		CELL_PATH_E = 0x02,
		CELL_PATH_S = 0x04,
		CELL_PATH_W = 0x08,
		CELL_VISITED = 0x10,
	};

	int m_nVisitedCells;
	int m_nPathWidth;
	stack<pair<int, int>> m_stack;


protected:
	virtual bool OnUserCreate() 
	{
		m_nMazeWidth = 32;
		m_nMazeHeight = 24;
		m_maze = new int[m_nMazeWidth * m_nMazeHeight];
		memset(m_maze, 0x0, m_nMazeWidth * m_nMazeHeight* sizeof(int));
		m_nPathWidth = 3;

		int x = rand() % m_nMazeWidth;
		int y = rand() % m_nMazeHeight;
		m_stack.push(make_pair(x, y));
		m_maze[y * m_nMazeWidth + x] = CELL_VISITED;
		m_nVisitedCells = 1;
		return true;
	}


	virtual bool OnUserUpdate(float fElapsedTime) 
	{//Maze Algorithm

		this_thread::sleep_for(100ms);
		auto offset = [&](int x, int y)
		{
			return (m_stack.top().first + x + ((m_stack.top().second + y )* m_nMazeWidth));
		};

		auto s_PushPair = [&](int a, int b)
		{ 
			return (m_stack.push(make_pair((m_stack.top().first + a), (m_stack.top().second + b))));

		};

		if (m_nVisitedCells < m_nMazeWidth * m_nMazeHeight)
		{	
			vector<int>neighbours;
			//Create a set to check for neighbours
			//North Neighbour
			if (m_stack.top().second > 0 &&(m_maze[offset(0, -1)] & CELL_VISITED)== 0)
				neighbours.push_back(0);
			//East Neighbour
			if (m_stack.top().first< m_nMazeWidth-1 && (m_maze[offset(1, 0)] & CELL_VISITED )== 0)
				neighbours.push_back(1);
			//South Neighbour
			if (m_stack.top().second < m_nMazeHeight -1 && (m_maze[offset(0, 1)] & CELL_VISITED) == 0)
				neighbours.push_back(2);
			//West Neighbour
			if (m_stack.top().first >0 && (m_maze[offset(-1, 0)] & CELL_VISITED)== 0)
				neighbours.push_back(3);

			if (!neighbours.empty()) 
			{
				int next_cell_dir = neighbours[rand() % neighbours.size()];
				//Create path between neighbour and current cell 

				switch (next_cell_dir)
				{
				case 0: //North
					m_maze[offset(0, 0)] |= CELL_PATH_N;
					m_maze[offset(0, -1)] |= CELL_PATH_S;
					s_PushPair(0, -1);
					break;
				case 1: //East
					m_maze[offset(0, 0)] |= CELL_PATH_E;
					m_maze[offset(1, 0)] |= CELL_PATH_W;
					s_PushPair(1, 0);
					break;
				case 2: //South
					m_maze[offset(0, 0)] |= CELL_PATH_S;
					m_maze[offset(0, 1)] |= CELL_PATH_N;
					s_PushPair(0, 1);
					break;
				case 3: //West
					m_maze[offset(0, 0)] |= CELL_PATH_W;
					m_maze[offset(-1, 0)] |= CELL_PATH_E;
					s_PushPair(-1, 0);
					break;
				}
				//New Cell Here	
				m_nVisitedCells++;
				m_maze[offset(0, 0)] |= CELL_VISITED;
			}
			else
			{
				m_stack.pop();// BackTrack

			}
		}


		//Clear Screen
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);


		for (int x = 0; x < m_nMazeWidth; x++) 
		{
			for (int y = 0; y < m_nMazeHeight; y++)
			{
				for (int py = 0; py < m_nPathWidth; py++) 
					for (int px = 0; px < m_nPathWidth; px++)
					{

						if (m_maze[y * m_nMazeWidth + x] & CELL_VISITED)
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, olc::WHITE);
						else
							Draw(x * (m_nPathWidth + 1) + px, y * (m_nPathWidth + 1) + py, olc::RED);

					}

				for (int p = 0; p < m_nPathWidth; p++) 
				{
						if (m_maze[y * m_nMazeWidth + x] & CELL_PATH_S)
							Draw(x * (m_nPathWidth + 1) + p, y * (m_nPathWidth + 1) + m_nPathWidth,olc::WHITE);

						if (m_maze[y * m_nMazeWidth + x] & CELL_PATH_E)
							Draw(x * (m_nPathWidth + 1) + m_nPathWidth, y * (m_nPathWidth + 1) + p,olc::WHITE);
				}
			}
		}
		for (int py = 0; py < m_nPathWidth; py++)
			for (int px = 0; px < m_nPathWidth; px++)
				Draw(m_stack.top().first * (m_nPathWidth + 1) + px, m_stack.top().second * (m_nPathWidth + 1) + py, olc::YELLOW); // Draw Cell

		return true;
		return true;
	}
};

int main()
{	
	OneLoneCoder_Maze game;
	game.Construct(128, 96 , 8, 8);
	game.Start();

	return 0;
}