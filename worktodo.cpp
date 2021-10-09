#include "worktodo.h"

WorkToDo::WorkToDo(std::string name,std::string description,int duration)
{
    m_name = name;
    m_description = description;
    m_duration = duration;
}

const std::string &WorkToDo::getName() const
{
    return m_name;
}

void WorkToDo::setName(const std::string &newName)
{
    m_name = newName;
}

const std::string &WorkToDo::getDescription() const
{
    return m_description;
}

void WorkToDo::setDescription(const std::string &newDescription)
{
    m_description = newDescription;
}

int WorkToDo::getDuration() const
{
    return m_duration;
}

void WorkToDo::setDuration(int newDuration)
{
    m_duration = newDuration;
}

int WorkToDo::getNumberOfTime() const
{
    return numberOfTime;
}

void WorkToDo::setNumberOfTime(int newNumberOfTime)
{
    numberOfTime = newNumberOfTime;
}
