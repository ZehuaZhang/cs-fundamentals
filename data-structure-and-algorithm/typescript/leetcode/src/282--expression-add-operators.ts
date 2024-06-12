/*
282. Expression Add Operators

Given a string num that contains only digits and an integer target, return all possibilities to add the binary operators '+', '-', or '*' between the digits of num so that the resultant expression evaluates to the target value.



Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Example 4:

Input: num = "00", target = 0
Output: ["0*0","0+0","0-0"]
Example 5:

Input: num = "3456237490", target = 9191
Output: []


Constraints:

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
*/

function addOperators(num: string, target: number): string[] {
  const rslt: string[] = [];
  for (let i = 0; i < num.length; ++i) {
    const op = num.substring(0, i + 1);
    const val = Number(op);
    if (op !== String(val)) {
      break;
    }
    dfs(i + 1, 0, val, [op]);
  }
  return rslt;

  function dfs(start: number, op1: number, op2: number, path: string[]) {
    if (start === num.length && op1 + op2 === target) {
      rslt.push(path.join(''));
      return;
    }

    for (let i = start; i < num.length; ++i) {
      const op = num.substring(start, i + 1);
      const val = Number(op);
      if (op !== String(val)) {
        break;
      }
      path.push('+' + op);
      dfs(i + 1, op1 + op2, val, path);
      path.pop();

      path.push('-' + op);
      dfs(i + 1, op1 + op2, -val, path);
      path.pop();

      path.push('*' + op);
      dfs(i + 1, op1, op2 * val, path);
      path.pop();
    }
  }
}
