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
    // add action to the list
    void addMessage(WorkToDo workToDo);

protected:
    void run();
private:
    // list containing all the jobs
    std::vector<WorkToDo> m_jobsList;
    QMutex mutex;
    // Standard actions for the tasks
    void printDebug();
    bool checkFile();
    // bool to check if a job is running while another has been added to the tasks list
    bool m_enqueJob;
    // functions for execute task each X seconds/horu/day/personal interval
    void executeJobSeconds(int numberOfTime, int duration, std::string executeAction);
    void executeJobHourly(int numberOfTime, int duration, std::string executeAction);
    void executeJobDaily(int numberOfTime, int duration, std::string executeAction);
    void executePersonalDateTime(WorkToDo workTodo);
    void executePersonalTask();
    // handler and trigger for the job
    void launchJob(WorkToDo);
};

#endif // EXECUTEACTION_H
