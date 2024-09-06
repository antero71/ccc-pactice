EXERCISES

5-1. You didn’t implement an accounting system in your Bank. Design an interface called AccountDatabase that can retrieve and set amounts in bank accounts (identified by a long id).  
5-2. Generate an InMemoryAccountDatabase that implements AccountDatabase.  
5-3. Add an AccountDatabase reference member to Bank. Use constructor injection to add an InMemoryAccountDatabase to the Bank.  
5-4. Modify ConsoleLogger to accept a const char* at construction. When ConsoleLogger logs, prepend this string to the logging output. Notice that you can modify logging behavior without having to modify Bank.  

Excerpt From
C++ Crash Course: A Fast-Paced Introduction
Josh Lospinoso
This material may be protected by copyright.