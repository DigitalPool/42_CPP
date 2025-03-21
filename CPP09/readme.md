// map, stack


1. **Extract the Number Part:**
   ```cpp
   std::string numberPart = token.substr(0, token.size() - 1);
   ```
   This line takes the substring of the token from the beginning (index 0) up to (but not including) the last character.
   - For `"9-"`, `numberPart` becomes `"9"`.

2. **Extract the Operator:**
   ```cpp
   char op = token.back();
   ```
   This retrieves the last character of the token.
   - For `"9-"`, `op` becomes `'-'`.

3. **Convert and Push the Number:**
   ```cpp
   int number = std::stoi(numberPart);
   stack.push(number);
   ```
   The number part (`"9"`) is converted to an integer (9) and then pushed onto the stack.

4. **Process the Operator:**
   ```cpp
   processOperatorToken(std::string(1, op), stack);
   ```
   The operator character is converted into a string (so `'-'` becomes `"-"`) and then passed to `processOperatorToken`, which handles the operation (by popping the necessary operands from the stack, applying the operator, and pushing the result back).

### Visual Diagram

Let's use a visual diagram with the token `"9-"`:

```
Input token: "9-"
   |
   V
+---------------------------+
|   token = "9-"            |
+---------------------------+
		 |
		 V
+------------------------------------+
| numberPart = token.substr(0, 1)    |
|               = "9"                |
+------------------------------------+
		 |
		 V
+------------------------------+
| op = token.back()            |
|    = '-'                     |
+------------------------------+
		 |
		 V
+--------------------------------+
| number = std::stoi("9")        |
|        = 9                     |
+--------------------------------+
		 |
		 V
+-------------------------------+
| Push 9 onto the stack         |
| Stack becomes: [9]            |
+-------------------------------+
		 |
		 V
+-------------------------------------+
| Call processOperatorToken with      |
| std::string(1, '-') i.e., "-"       |
| along with the current stack        |
+-------------------------------------+
```

### What Happens Next?

Inside `processOperatorToken`, the function will:
- Pop the top two numbers from the stack.
- Apply the operator (in this case, `-`) on them.
- Push the resulting value back onto the stack.

This refactored approach lets you handle tokens where a number and operator are attached together in one go, keeping your main evaluation loop neat and modular.
