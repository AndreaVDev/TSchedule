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
    void printDebug();
    bool checkFile();
    bool m_enqueJob;
    void executeJobSeconds(int numberOfTime, int duration, std::string executeAction);
    void executeJobHourly(int numberOfTime, int duration, std::string executeAction);
    void executeJobDaily(int numberOfTime, int duration, std::string executeAction);
    void executeJobWeekly(int numberOfTime, int duration, std::string executeAction);
    void executePersonal(int numberOfTime, int duration);
    void launcJob(WorkToDo);
};

#endif // EXECUTEACTION_H
