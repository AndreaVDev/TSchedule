#ifndef EXECUTEACTION_H
#define EXECUTEACTION_H
#include <QThread>
#include <QMutex>
#include <worktodo.h>
#include <vector>
#include <QDebug>

class ExecuteAction : public QThread
{
public:
    ExecuteAction();
    void addMessage(WorkToDo workToDo);

    // QThread interface
protected:
    void run();
private:
    std::vector<WorkToDo> m_jobsList;
    QMutex mutex;
    void printDebug(WorkToDo workToDo);
    void checkFile(WorkToDo workToDo);
    bool m_enqueJob;
    void executeJobSeconds(int numberOfTime, int duration, std::string executAction);
    void executeJobHourly(int numberOfTime, int duration, std::string executAction);
    void executeJobDaily(int numberOfTime, int duration, std::string executAction);
    void executeJobWeekly(int numberOfTime, int duration, std::string executAction);
    void executePersonal(int numberOfTime, int duration);
};

#endif // EXECUTEACTION_H
