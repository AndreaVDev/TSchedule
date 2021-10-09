#include "executeaction.h"
#include <Timer.h>
#include <iostream>
#include <fstream>

ExecuteAction::ExecuteAction()
{

}

void ExecuteAction::addMessage(WorkToDo workToDo)
{
    m_jobsList.push_back(workToDo);
}

void ExecuteAction::run()
{
    qDebug() << "RUN";
    //int size = m_jobsList.size();
    mutex.lock();

    for(unsigned int i = 0; i < m_jobsList.size(); i++)
    {
        qDebug() << "RUN for iteration number: " << i;
        if(m_jobsList[i].getDescription() == "P")
        {
            // PRINT
            qDebug() << "RUN CALLING PRINT JOB!";
            printDebug(m_jobsList[i]);
            qDebug() << "RUN PRINT JOB QUITTED!";

        }
        else if(m_jobsList[i].getDescription() == "W")
        {
            // WRITE TO FILE
            qDebug() << "RUN CALLING CHECK TEXT JOB!";

            checkFile(m_jobsList[i]);
            qDebug() << "RUN CHECK TEXT JOB QUITTED!";

        }
    }
    mutex.unlock();
}


void ExecuteAction::printDebug(WorkToDo workToDo)
{

    if(m_enqueJob)
    {
        qDebug() << "printDebug::JOB WAS EXECUTING, INTERRUPTED PREVIOUS JOB!";
        m_enqueJob = false;
    }
    // get the number of time
    int numberOfTime = 60 / workToDo.getDuration();
    qDebug() << "printDebug::JOB MUSTE BE DONE EACH:" << workToDo.getDuration() << " seconds, jobs times in 1 minute: " << numberOfTime;

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        while(t.elapsedSeconds() < workToDo.getDuration())
        {
            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
                // per ora aspetto che finisica il job in esecuzione devo modificare affinche se si incrociano cambia
                if(i == numberOfTime)
                {
                    qDebug() << "printDebug::SECOND JOB ADDED TO QUEUE RETURNIG TO RUN!" << i;
                    return;
                }

            }
        }
        t.stop();
        qDebug() << "printDebug::Hello, I'm the printing job! Execution number: " << i;
    }

    if(!m_enqueJob)
    {
        printDebug(workToDo);
    }
}

void ExecuteAction::checkFile(WorkToDo workToDo)
{
    if(m_enqueJob)
    {
        qDebug() << "checkFile::JOB WAS EXECUTING, INTERRUPTED PREVIOUS JOB!";
        m_enqueJob = false;
    }
    // get the number of time
    int numberOfTime = 60 / workToDo.getDuration();
    qDebug() << "checkFile::JOB MUSTE BE DONE EACH:" << workToDo.getDuration() << " seconds, jobs times in 1 minute: " << numberOfTime;

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        while(t.elapsedSeconds() < workToDo.getDuration())
        {
            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
                if(i == numberOfTime)
                {
                    qDebug() << "checkFile::SECOND JOB ADDED TO QUEUE RETURNIG TO RUN!" << i;
                    return;
                }

            }
        }
        t.stop();
        std::ofstream outfile ("test.txt");

        outfile << "File exists and I'm writing in it!" << std::endl;

        outfile.close();
        qDebug() << "checkFile::FILE CREATED!";
        qDebug() << "checkFile::Hello, I'm the printing job! Execution number: " << i;
    }

    if(!m_enqueJob)
    {
        checkFile(workToDo);
    }
}
