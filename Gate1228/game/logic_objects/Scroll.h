#ifndef SCROLL_H
#define SCROLL_H
#include <map>
#include <bitset>
#include <functional>
#include <vector>


enum class skill_id
{
	power,smart,fast
};

template<typename T>
struct dyn_intersection
{
	std::vector<T> in;
	std::vector<T> out;
	
};

class skill_slot
{
	friend class scroll;
protected:
	bool locked_ = true;
	bool selected_ = false;
	dyn_intersection<skill_id> intersection_;
public:
	virtual ~skill_slot() = 0;
};

class power : public skill_slot
{
public:
	power()
	{
		//Base skills unlocked initially
		locked_ = false;
		//Skills that unlock this skill
		//-base

		//Skills that this skill unlocks
		intersection_.out[0] = skill_id::smart;
		intersection_.out[0] = skill_id::fast;

	}
};


class scroll
{
protected:
	std::map<skill_id, skill_slot> skill_map_;

public:

	bool select(const skill_id skill)
	{
		skill_slot& target = std::ref(skill_map_.at(skill));

		//cannot select a locked skill
		if(target.locked_)
			return false;

		target.selected_ = true;

		for (skill_id child : target.intersection_.out)
		{
			skill_map_.at(child).locked_ = false;
		}

		return true;
	};
	virtual ~scroll() = default;
};

class concrete_scroll : scroll
{
	concrete_scroll()
	{
		//add parent node to tree
		skill_map_[skill_id::power] = power();

	}
};

#endif

