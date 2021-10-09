#ifndef WORKTODO_H
#define WORKTODO_H
#include <string>

class WorkToDo
{
public:
    WorkToDo(std::string name,std::string description,int duration,std::string timeUnit);

    // Getters and Setters
    const std::string &getName() const;
    void setName(const std::string &newName);

    const std::string &getDescription() const;
    void setDescription(const std::string &newDescription);

    int getDuration() const;
    void setDuration(const int &newDuration);

    std::string getTimeUnit() const;
    void setTimeUnit(const std::string &newTimeUnit);

    int getNumberOfTime() const;
    void setNumberOfTime(int newNumberOfTime);

private:
    std::string m_name;
    std::string m_description;
    int m_duration;
    int m_numberOfTime;
    std::string m_timeUnit;
};

#endif // WORKTODO_H
