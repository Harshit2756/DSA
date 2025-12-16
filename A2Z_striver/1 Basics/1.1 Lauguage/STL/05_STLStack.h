// 05_Stack.h
#ifndef STLSTACK_H
#define STLSTACK_H

#include <iostream>
#include <stack>
using namespace std;

// ==========================================
// 5. STACK (LIFO - Last In First Out)
// ==========================================
class STLStack
{
public:
    void explain()
    {
        cout << "\n\n --- STACK DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A container adapter that follows the Last In, First Out (LIFO) principle.
        //   / HEADER: #include <stack>
        //   ~ WHY USE:
        //     ~ Ideal for dynamic data management where you only need access to the most recently added item.
        //     ~ Used in Recursion, Undo features, and Parsing.
        //   ~ CRITICAL FUNCTIONS (All O(1)):
        //    . .push(val)   -> Adds element to the top.
        //    . .emplace(val)-> Adds element (constructs in-place, more efficient).
        //    . .top()       -> Returns the top element (Does NOT remove it).
        //    . .pop()       -> Removes the top element (Returns void).
        //    . .size()      -> Returns number of elements.
        //    . .swap(st2)   -> Swaps content with another stack.
        //    . .empty()     -> Returns true if empty.
        // ==========================================

        // --- 1. Push vs Emplace ---
        BasicOps();

        // --- 2. accessing the elements  ---
        AccessDemo();

        // --- 3. Size of Stack ---
        SizeDemo();

        // --- 4. Swap Stacks ---
        SwapDemo();

        cout << "==========================================" << endl;
    }

    void BasicOps()
    {
        //. The push operation adds an element to the top.
        //. The emplace operation constructs the element in place (more efficient).
        stack<int> s;
        s.push(10);
        s.emplace(20);

        cout << "\n[Push/Emplace] Top element: " << s.top() << endl; // Expected: 20
    }

    void AccessDemo()
    {
        //. top() returns the element at the top without removing it.
        stack<int> s;
        s.push(10);
        s.push(20);

        cout << "[Top] Current Top: " << s.top() << endl; // Expected: 20

        //. pop() removes the top element.It returns void (nothing).
        s.pop();
        cout << "[Pop] New Top after pop: " << s.top() << endl; // Expected: 10

        s.push(30);
        s.push(40);
        s.push(50);
        s.push(60);
        s.push(70);

        //. to access all elements, we can pop until empty
        cout << "[Access All] Stack elements (top to bottom): ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    void SizeDemo()
    {
        //. Returns the number of elements.
        stack<int> s;
        s.push(10);
        s.push(20);

        cout << "[Size] Stack size: " << s.size() << endl; // Expected: 2
    }

    void SwapDemo()
    {
        //. Swaps the contents of two stacks efficiently.
        stack<int> s1, s2;
        s1.push(10); // s1 has {10}
        s2.push(20); // s2 has {20}

        s1.swap(s2);

        cout << "[Swap] s1 Top: " << s1.top() << " (Expected 20)" << endl;
        cout << "[Swap] s2 Top: " << s2.top() << " (Expected 10)" << endl;
    }
};

#endif // STLSTACK_H