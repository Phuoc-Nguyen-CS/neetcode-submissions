class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;

        for (int i = 0; i < tokens.size(); ++i) {
            const std::string& item = tokens[i];
            if (item == "+" || item == "-" || item == "/" || item == "*") {
                int num1 = nums.top(); nums.pop(); // Most recent number
                int num2 = nums.top(); nums.pop(); // Second number

                if (item == "+") {
                    nums.push(num2 + num1);    
                } else if (item == "-") {
                    nums.push(num2 - num1);    
                } else if (item == "*") {
                    nums.push(num2 * num1); 
                } else if (item == "/") {
                    nums.push(num2 / num1);    
                }

            } else {
                nums.push(stoi(item));
            }
        }

        return nums.top();
    }
};
