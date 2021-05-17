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
