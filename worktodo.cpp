#include "worktodo.h"

WorkToDo::WorkToDo(std::string name,std::string description,int duration,std::string timeUnit)
{
    m_name = name;
    m_description = description;
    m_duration = duration;
    m_timeUnit = timeUnit;
}

const std::string &WorkToDo::getName() const
{
    return m_name;
}

void WorkToDo::setName(const std::string &newName)
{
    m_name = newName;
}

 std::string WorkToDo::getDescription()
{
    return m_description;
}

void WorkToDo::setDescription( std::string newDescription)
{
    m_description = newDescription;
}

int WorkToDo::getDuration() const
{
    return m_duration;
}

void WorkToDo::setDuration(const int &newDuration)
{
    m_duration = newDuration;
}

std::string WorkToDo::getTimeUnit() const
{
    return m_timeUnit;
}

void WorkToDo::setTimeUnit(const std::string &newTimeUnit)
{
    m_timeUnit = newTimeUnit;
}

int WorkToDo::getNumberOfTime() const
{
    return m_numberOfTime;
}

void WorkToDo::setNumberOfTime(int newNumberOfTime)
{
    m_numberOfTime = newNumberOfTime;
}
