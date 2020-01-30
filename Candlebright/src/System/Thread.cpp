#include "Thread.hpp"

System::Thread::Thread(){ }
System::Thread::~Thread(){ }

void System::Thread::yield(){
    sched_yield();
}

void System::Thread::start(){
    int status = pthread_attr_init(&threadAttr);
    status = pthread_attr_setscope(&threadAttr, PTHREAD_SCOPE_SYSTEM);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Inicialização do atributo da thread." << std::endl;
    status = pthread_create(&threadID, &threadAttr, this->runThread, (void*)this);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Inicialização da thread." << std::endl;
    status = pthread_attr_destroy(&threadAttr);
    if(status != 0)
        std::cerr << "Falha inicialização de thread: Destruição do atributo da thread." << std::endl;
}

void System::Thread::join(){
    int status = pthread_join(threadID, NULL);
    if(status != 0)
        std::cerr << "Falha System::Thread::join()." << std::endl;
}

void* System::Thread::runThread(void* pThread){
    Thread* sThread = static_cast<Thread*>(pThread);
    if(sThread == NULL){
        std::cerr << "Falha System::Thread::runThread()." << std::endl;
    }else{
        sThread->run();
    }
    return NULL;
}