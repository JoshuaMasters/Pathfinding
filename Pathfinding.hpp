#pragma once

#include <array>
#include <memory>
#include <random>
#include <algorithm>

struct Vector2i
{
	int x;
	int y;
};

struct PathfindingNode
{
	PathfindingNode *parent;
	Vector2i location;
	int obstacleRating;
	int destinationCost, movementCost, totalCost;
};

class Pathfinding
{
public:
	Pathfinding(Vector2i size) :
		m_size{size}
	{		
		for(int i = 0; i < size.x; i++)
		{
			std::vector<int> temp;

			for(int j = 0; j < size.y; j++)
			{
				temp.push_back({randomAssignment()});
			}
			
			m_nodes.push_back(temp);
		}
	}

	int getNodeValue(Vector2i nodeAddress)
	{
		if(nodeAddress.x <= m_size.x && nodeAddress.y <= m_size.y)
		{
			return(m_nodes[nodeAddress.x][nodeAddress.y]);
		}
		else
		{
			throw("bad");
		}
	}

	void findPath(Vector2i start, Vector2i finish)
	{
		m_finish = finish;
		std::vector<Vector2i> path;
		
		if(start.x <= m_size.x && start.y <= m_size.y && 
			finish.x <= m_size.x && finish.y <= m_size.y)
		{
			m_openList.push_back({nullptr, {start.x, start.y}, m_nodes[start.x][start.y]});
			
			while(m_openList.end.location.x != finish.x && m_openList.end.location.y != finish.y)
			{
				std::for_each(m_openList.begin, m_openList.end, )
			}
			// after algorithm is done
		}
		else
		{
			throw("bad");
		}
	}

private:
	bool randomAssignment()
	{
		static std::default_random_engine e{};
		static std::uniform_int_distribution<int> d{0, 1};
		
		return d(e);
	}

	int assignDestinationCost(const Vector2i& current, const Vector2i& finish)
	{
		int cost = abs(current.x - finish.x) * 10;
		cost += abs(current.y - finish.y) * 10;

		return(cost);
	}

	Vector2i m_size;
	Vector2i m_finish;
	std::vector<std::vector<int>> m_nodes;
	std::vector<PathfindingNode> m_openList;
	std::vector <PathfindingNode> m_closedList;
};
