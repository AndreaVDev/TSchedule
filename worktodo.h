#ifndef WORKTODO_H
#define WORKTODO_H
#include <string>

class WorkToDo
{
public:
    WorkToDo(std::string name,std::string description,int duration);

    // Getters and Setters
    const std::string &getName() const;
    void setName(const std::string &newName);

    const std::string &getDescription() const;
    void setDescription(const std::string &newDescription);

    int getDuration() const;
    void setDuration(int newDuration);



    int getNumberOfTime() const;
    void setNumberOfTime(int newNumberOfTime);

private:
    std::string m_name;
    std::string m_description;
    int m_duration;
    int numberOfTime;
};

#endif // WORKTODO_H
