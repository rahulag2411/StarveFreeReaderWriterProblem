# StarveFreeReaderWriterProblem

In process synchronization,Readers-writers problem is one of the most prominent problem .

In such type of problem there are two type of users: 
- The Writers, who wants to modify the shared resources.
- The Readers, who wants to read the shared resources.

Also,There are three kinds of such problem.

### First readers–writers problem
In this kind,Readers are given priority.So,it allows that when some reader ia already accessing the resource,new readers can simultaneously enter the critical section and access that resource.However,since new readers may continiously enter to access the resource, the writer trying to modify the resource may lead to starvation.

### Second readers–writers problem
This is also similar to the above problem, however here the readers may starve.In this kind,Readers are given priority.When the last writer exits the critical section after modifying the resource and releases the lock,then readers would be allowed to acces the resource.Hence,Readers need to wait.

### Third readers–writers problem
This problem lies on the principle that no thread shall be allowed to starve.So,it overcomes the drawbacks of previous two problems of starvation.Hence,it is also known as the Starve-Free-Readers-Writers-Problem. It give priority to the resources in the order of their arrival.For example: If a writers need to wait untill the current readers execute their tasks for them to modify the resource.Meanwhile, other readers accessing the resourcse would not be allowed to do so.

## Explanation of the Code

### Integer
- **_readCnt_** : It stores the number of reader executing critical section.

### Semaphores
- **_rd_mutex_**: It is available only for READER'S method since it is only used while changing the redCnt.
- **_getAccess_**: If the writer is executing it's block ,and any reader tries to access the critical section,then it would get blocked and not allow the reader to access and vice versa.But In case of READER,if a reader is executing and another reader tries to access,then the reader would be allowed and this semaphore would get updated.The seamphore get updated:
  - When First reader arrives
  - When the Last reader leaves
  - When any writer modifies the resources
- **_turn_**: This is used at the entry section.This only checks if some other writer or reader is waiting for it's turn and if someone else is waiting it would block this reader or writer and if not it allows further execution of code and blocking others.Hence,It helps in preserving the order of process.

### READER'S METHOD:  
First calling the **_turn_** Semaphore this checks If any process is already in queue turn would be 1 and this process would be blocked. Otherwise it would make turn 1.Then **_rd_mutex_** Semaphore would be called and it checks if some other process is changing the **_readCnt_**. If this was the firstReader then it does not allow any writer to access the critical section. After this,both the semaphores  are released. After executing the critical section **_readCnt_** is decreased by getting hold of **_rd_mutex_**.And when **_readCnt_** is 0,it would allow writer to access the critical section.

### WRITER'S METHOD:  
First checking the **_turn_** Semaphore and when it allows the writer get access by calling the semaphore **_getAccess_**.Now it releases the **_turn_** semaphore since order is preserved.Here it get access to CRITICAL SECTION and after executing it releases **_getAccess_** semaphore.

