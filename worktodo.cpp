#include "worktodo.h"

WorkToDo::WorkToDo(std::string name,std::string description,int duration,std::string timeUnit)
{
    m_name = name;
    m_description = description;
    m_duration = duration;
    m_timeUnit = timeUnit;
}

WorkToDo::WorkToDo(std::string name, std::string description, std::string day, QTime time)
{
    m_name = name;
    m_description = description;
    m_day = day;
    m_time = time;
}

std::string WorkToDo::getName()
{
    return m_name;
}

void WorkToDo::setName( std::string newName)
{
    m_name = newName;
}

std::string WorkToDo::getDescription()
{
    return m_description;
}

void WorkToDo::setDescription(std::string newDescription)
{
    m_description = newDescription;
}

int WorkToDo::getDuration()
{
    return m_duration;
}

void WorkToDo::setDuration(int newDuration)
{
    m_duration = newDuration;
}

std::string WorkToDo::getTimeUnit()
{
    return m_timeUnit;
}

void WorkToDo::setTimeUnit( std::string newTimeUnit)
{
    m_timeUnit = newTimeUnit;
}

std::string WorkToDo::getDay()
{
    return m_day;
}

void WorkToDo::setDay(std::string day)
{
    m_day = day;
}

QTime WorkToDo::getTime()
{
    return m_time;
}

void WorkToDo::setTime(QTime time)
{
    m_time = time;
}

