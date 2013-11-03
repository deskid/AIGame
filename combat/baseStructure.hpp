#ifndef COMBAT_BASE_STRUCTURE_H
#define COMBAT_BASE_STRUCTURE_H

#include <vector>
#include <cassert>

using namespace std;

namespace AIGAME {

/* The logic definition of map */

static const int maxMapLinkLimit = 4;

class combatLogicMapNode{
	combatLogicMapNode* neighbourNode[maxMapLinkLimit];
	Fighter* occupyFighter;
	int nodeID;
	combatLogicMapNode(int initID){
		nodeID = initID;
	}
}

struct combatGraphMapNode{
	pair<int, int> nodePosition;
	// Maybe More
}
class combatLogicMap{
	vector<combatLogicMapNode*> mapNode;
	int cntNode = 0;
	combatLogicMap(){
		mapNode.clear();
	}
	~combatLogicMap(){
		for(vector<combatLogicMapNode*>::iterator it = mapNode.begin(); it != mapNode.end(); ++it){
			delete it;
		}
	}
	Node* addNewNode(){
		Node* ret = new combatLogicMapNode(cntNode++);
		mapNode.push_back(ret);
		return ret;
	}
	void addNewRoad(combatLogicMapNode* sourceNode, combatLogicMapNode* targetNode, int direction){
		assert(direction >= 0 && direction < 4);
		sourceNode->neighbourNode[direction] = targetNode;
	}
	combatLogicMapNode* findNode(int nodeID){
		if(nodeID < 0 || nodeID >= mapNode.size()) return NULL;
		return mapNode[nodeID];
	}

	Fighter* senseDirection(combatLogicMapNode* sourceNode, int direction){
		assert(direction >= 0 && direction < 4);
		return sourceNode->neighbourNode[direction]->occupyFighter; // Null means nobody
	}

	combatLogicMapNode* findNearestFighter(combatLogicMapNode* sourceNode){

	}

	vector<Node*> findinDistance(Node* sourceNode){

	}
}

}

#endif