#ifndef WORKTODO_H
#define WORKTODO_H
#include <string>
#include <QTime>


// Class that contains all the data about the task
class WorkToDo
{
public:
    // First constructor for default taks
    WorkToDo(std::string name,std::string description,int duration,std::string timeUnit);
    // Second constructor for personalized tasks
    WorkToDo(std::string name,std::string description,std::string day,QTime time);

    // Getters and Setters
    std::string getName();
    void setName( std::string newName );

    std::string getDescription() ;
    void setDescription( std::string newDescription );

    int getDuration() ;
    void setDuration( int newDuration);

    std::string getTimeUnit() ;
    void setTimeUnit( std::string newTimeUnit);

    std::string getDay();
    void setDay(std::string day);

    QTime getTime();
    void setTime(QTime time);

private:
    std::string m_name;
    std::string m_description;
    int m_duration;
    std::string m_timeUnit;
    std::string m_day;
    QTime m_time;
};

#endif // WORKTODO_H
