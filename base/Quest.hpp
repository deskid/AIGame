#ifndef QUEST_HPP_
#define QUEST_HPP_

namespace AIGame {

enum class QuestStatus {
	unassigned, // not visible to player.
	in_poll, // in Task List
	ready, // the task is taken, but still not happening.
	running, // the task is running. In combat!
	succeed, // task succeed
	failed // task failed
};

enum class QuestType {
	main_quest,
	side_quest
};

struct Quest {
	int id; // quest id
	QuestStatus status; // status of quest
};

}

#endif // QUEST_HPP