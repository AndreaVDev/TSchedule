#ifndef WORKTODO_H
#define WORKTODO_H
#include <string>


// Class that contains all the data about the task
class WorkToDo
{
public:
    WorkToDo(std::string name,std::string description,int duration,std::string timeUnit);

    // Getters and Setters
    const std::string &getName() const;
    void setName(const std::string &newName);

     std::string getDescription() ;
    void setDescription( std::string newDescription);

    int getDuration() const;
    void setDuration(const int &newDuration);

    std::string getTimeUnit() const;
    void setTimeUnit(const std::string &newTimeUnit);

    // delete probably
    int getNumberOfTime() const;
    void setNumberOfTime(int newNumberOfTime);

private:
    std::string m_name;
    std::string m_description;
    int m_duration;
    // delete probably
    int m_numberOfTime;
    std::string m_timeUnit;
};

#endif // WORKTODO_H
