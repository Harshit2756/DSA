// 06_Queue.h
#ifndef STLQUEUE_H
#define STLQUEUE_H

#include <iostream>
#include <queue>
using namespace std;

// ==========================================
// 6. QUEUE (FIFO - First In First Out)
// ==========================================
class STLQueue
{
public:
    void explain()
    {
        cout << "\n\n --- QUEUE DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A container that follows the First In, First Out (FIFO) principle.
        //   / HEADER: #include <queue>
        //   ~ WHY USE:
        //     ~ Ideal for scenarios like scheduling (jobs to printer), BFS (Graph traversal), or handling requests in order.
        //   ~ RESTRICTIONS:
        //     ~ NO Iterators: You cannot traverse a queue like a vector.
        //     ~ NO Random Access: You cannot do q[i].
        //   ~ CRITICAL FUNCTIONS (All O(1)):
        //    . .push(val)   -> Adds element to the BACK (Rear).
        //    . .emplace(val)-> Adds element to the BACK (More efficient).
        //    . .pop()       -> Removes element from the FRONT.
        //    . .front()     -> Returns the element at the FRONT.
        //    . .back()      -> Returns the element at the BACK.
        //    . .size()      -> Returns current number of elements.
        //    . .empty()     -> Returns true if empty.
        // ==========================================

        // --- 1. Push, Back, Front ---
        BasicOps();

        // --- 2. Pop (Removing from Front) ---
        AccesDemo();

        // --- 3. Size & Empty ---
        StatusDemo();

        cout << "==========================================" << endl;
    }

    void BasicOps()
    {
        queue<int> q;

        //. Push adds to the "End" of the line
        q.push(1);    // {1}
        q.push(2);    // {1, 2}
        q.emplace(4); // {1, 2, 4}

        //. Accessing ends
        cout << "\n[Back] Last person in line: " << q.back() << endl; // 4

        //. You can modify the back element directly
        q.back() += 5;
        cout << "[Back] Last person modified: " << q.back() << endl; // 9 ({1, 2, 9})

        cout << "[Front] First person in line: " << q.front() << endl; // 1
    }

    void AccesDemo()
    {
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);

        cout << "\n[Pop] Before pop, Front is: " << q.front() << endl; // 10

        //. Removes the element at the FRONT (10)
        q.pop();

        cout << "[Pop] After pop, Front is: " << q.front() << endl; // 20

        //. Access all elements by popping until empty
        cout << "[Access All] Queue elements (front to back): ";
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }

    void StatusDemo()
    {
        queue<int> q;

        cout << "\n[Empty] Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

        q.push(100);
        q.push(200);

        cout << "[Size] Current size: " << q.size() << endl; // 2
    }
};

#endif // STLQUEUE_H