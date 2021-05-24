// A process Block.
struct processBlock{
    int* process_block;
    processBlock* next;
};

struct Queue{
    processBlock *front, *rear;
  
    void* push(int* val){
        processBlock* pBlock = new processBlock();
        pBlock->process_block = val;
        if(rear != nullptr){
            rear->next = pBlock;
            rear = pBlock;
         }
        else{
           front = rear = pBlock;  
        }
   }
    
    int* pop(){
        if(front == nullptr){
            cout << "Underflow Error";
            return nullptr;           
        }
        else{
            int* val = front->process_block;
            front = front->next;
            if(front == nullptr)rear = nullptr;
            return val;
        }
    }

    
};



class Semaphore{
    public:
        int value;
        Queue* Q; 
        Semaphore(int val){
            value = val;
            Q = new Queue();
        }
};
    
void wait(Semaphore* S,int* PID){
  S->value--;
  if(S->value < 0){
      S->Q->push(PID);
      block(); 
      /*
      *Using system calls,this function will block the process and then the process will be moved to the waiting queue and it will 
      remain in the waiting queue untill  wakeUp() system call wake it up.       */
  }
}
    
void signal(Semaphore* S){
  S->value++;
  if(S->value <= 0){
  int* PID = S->Q->pop();
  wakeup(PID); //Using the System calls,this function will wakeup the process with the specific pid
  }
};
















// // A process Block.
// struct processBlock{
//     int* process_block;
//     processBlock* next;
// };

// //Queue uses FIFO policy,hence useful.
// struct Queue{
//     processBlock *front, *rear;
  
//     void* push(int* val){
//         processBlock* pBlock = new processBlock();
//         pBlock->process_block = val;
//         if(rear != nullptrptrptr){
//             rear->next = pBlock;
//             rear = pBlock;
//          }
//         else{
//            front = rear = pBlock;  
//         }
//    }
    
//     int* pop(){
//         if(front == nullptrptrptr){
//             cout << "Underflow Error";
//             return nullptrptrptr;           
//         }
//         else{
//             int* val = front->process_block;
//             front = front->next;
//             if(front == nullptrptrptr)rear = nullptrptrptr;
//             return val;
//         }
//     }

    
// };



// class Semaphore{
//     public:
//         int value;
//         Queue* Q; 
//         Semaphore(int val){
//             value = val;
//             Q = new Queue();
//         }
// };
//    
//  
// void wait(Semaphore* S,int* PID){
//   S->value--;
//   if(S->value < 0){
//       S->Q->push(PID);
//       block();  
//      
//    }
// }
//     
// void signal(Semaphore* S){
//   S->value++;
//   if(S->value <= 0){
//   int* PID = S->Q->pop();
//   wakeUp(PID);   
//   }
// };


//  /*
//       *Using system calls,this function will block the process and then the process will be moved to the waiting queue and it will 
//       remain in the waiting queue untill  wakeUp() system call wake it up.
//       */



