#include <vector>
#include <functional> // for std::function
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int step = 1; // Initialize the step size to 1
        bool leftToRight = true; // Indicates whether we are moving left to right or right to left
        int head = 1; // Initialize the head to 1

        while (n > 1) {
            if (leftToRight || n % 2 == 1) {
                head += step; // Update the head
            }
            step *= 2; // Double the step size
            n /= 2; // Halve n
            leftToRight = !leftToRight; // Toggle the direction
        }
        
        return head;
    }
};
