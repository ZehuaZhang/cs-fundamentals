// 224. Basic Calculator
// Difficulty: Hard

// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

// You may assume that the given expression is always valid.

// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23

// Time:  O(n)
// Space: O(n)

// Support +, -, *, /, (, ).

public class Solution {
    // using stack for the operand and operator respectivley.
    public int calculate(String s) {
        if (s == null) throw new NullPointerException();
        if (s.length() == 0) return 0;
        int i = 0;
        Stack<Integer> operandStk = new Stack<Integer>();
        Stack<Character> operatorStk = new Stack<Character>();
        while (i < s.length()) {
            while (i < s.length() && s.charAt(i) == ' ') ++i;
            if ( i >= s.length() ) break;

            if (Character.isDigit(s.charAt(i))) {
                int start = i;
                while (i < s.length() && Character.isDigit(s.charAt(i))) ++i;
                int value = Integer.parseInt(s.substring(start, i));
                operandStk.push(value);
                --i;
            } else if ( s.charAt(i) == '(' ) {
                operatorStk.push(s.charAt(i));
            } else if (s.charAt(i) == ')' ) {
                while (operatorStk.peek() != '(') {
                    calculate(operandStk, operatorStk);
                }
                operatorStk.pop(); // remove the openning bracket.
            } else { // s.charAt(i) == '+' or '-'
                while (!operatorStk.isEmpty() && operatorStk.peek() != '(') {
                    calculate(operandStk, operatorStk);                    
                }
                operatorStk.push(s.charAt(i));
            }
            ++i; // go to next character
        }
        while (!operatorStk.isEmpty()) calculate(operandStk, operatorStk);
        return operandStk.pop();
    }
    
    private void calculate(Stack<Integer> operandStk, Stack<Character> operatorStk) {
        char operator = operatorStk.pop();
        int operand1 = operandStk.pop(), operand2 = operandStk.pop(), cal = 0;
        switch (operator) {
            case '+':
                cal = operand2 + operand1;
                break;
            case '-':
                cal = operand2 - operand1;
                break;
        }
        operandStk.push(cal);
    }
}
