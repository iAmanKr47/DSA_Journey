long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long ans = 1;
        for(int x : arr) {
            if(ans < x)
                return ans;
            ans += x;
        }
        return ans;
    }
/*CP CONCEPT 

Institution (Key Points) : 🤷‍♂️
Problem Type: Classic algorithm problem in competitive programming.

Objective: Find the smallest positive integer that cannot be formed as the sum of any subset of given positive integers.

Key Concept: Utilizes greedy strategies for efficient calculation.

Learning Benefit: Enhances skills in array manipulation and algorithm design.

Practical Use: Relevant for optimizing resource allocation and combinations in real-world scenarios.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Approach : 🤦‍♂️
Initialization: Start by setting ans to 1. This variable represents the smallest positive integer we want to form using elements from the array.

Iteration: Loop through the sorted array:

If the current element is greater than ans, stop the loop. This indicates that ans cannot be formed using the numbers we've processed so far.
If the current element is less than or equal to ans, add it to ans. This means that we can now form all integers up to the new value of ans.
Return the Result: After checking all elements, the final value of ans will be the smallest positive integer that cannot be created by summing any subset of the given integers.

 

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 

Trick : 🤔
The key observation is that if you can create all integers from 1 to ans-1, adding a number that is less than or equal to ans will allow you to form all integers up to ans + arr[i] - 1. If you encounter a number greater than ans, it means you can't form ans, hence it's the answer.


*/
