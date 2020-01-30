#pragma once
#include <pthread.h>
#include <iostream>

namespace System {
    class Thread {
        private:
            pthread_t threadID;
            pthread_attr_t threadAttr;
            static void* runThread(void* _thread);

        protected:
            virtual void run() = 0;
        
        public:
            Thread();
            virtual ~Thread();

            void start();
            void join();
            void yield();
    };
}