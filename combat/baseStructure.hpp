#ifndef COMBAT_BASE_STRUCTURE_H
#define COMBAT_BASE_STRUCTURE_H

#include <vector>
#include <cassert>
#include <algorithm>
#include "base/Fighter.hpp"

namespace AIGame {

namespace detail {
	static const int maxMapLinkLimit = 4;
}
/* The logic definition of map */

struct combatLogicMapNode{
	combatLogicMapNode* neighbourNode[detail::maxMapLinkLimit];
	Fighter* occupyFighter;
	int nodeID;

	combatLogicMapNode(int initID){
		nodeID = initID;
	}
};

struct combatGraphMapNode{
	std::pair<int, int> nodePosition;
	// Maybe More
};

class combatLogicMap{
public:
	typedef combatLogicMapNode Node;
private:
	std::vector<Node*> mapNode;
	static int cntNode; // TODO define it in .cpp file
public:
	combatLogicMap(){
		mapNode.clear();
	}
	~combatLogicMap(){
		std::for_each(mapNode.begin(), mapNode.end(), [](Node* node) {
			delete node;
		});
	}
	Node* addNewNode(){
		Node* ret = new Node(cntNode++);
		mapNode.push_back(ret);
		return ret;
	}
	void addNewRoad(Node* sourceNode, Node* targetNode, int direction){
		assert(direction >= 0 && direction < detail::maxMapLinkLimit);
		sourceNode->neighbourNode[direction] = targetNode;
	}
	Node* findNode(int nodeID){
		if(nodeID < 0 || nodeID >= mapNode.size()) return NULL;
		return mapNode[nodeID];
	}

	Fighter* senseDirection(Node* sourceNode, int direction){
		assert(direction >= 0 && direction < detail::maxMapLinkLimit);
		return sourceNode->neighbourNode[direction]->occupyFighter; // Null means nobody
	}

	Node* findNearestFighter(Node* sourceNode){

	}

	std::vector<Node*> findinDistance(Node* sourceNode){

	}
};

}

#endif