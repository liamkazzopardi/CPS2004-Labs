#include <iostream>
#include <string>
#include <fstream>  // For file operations
#include <cctype>   // For character checks
using namespace std;

// Define a struct to store the expression (op1 operator op2)
struct binops {
    string expression;
};

// Function to evaluate an expression stored in the binops struct
float evaluate(const string& expression) {
    float op1 = 0.0, op2 = 0.0;
    char operation = '\0';
    size_t pos = 0;

    // Skip leading whitespaces
    while (pos < expression.length() && isspace(expression[pos])) {
        pos++;
    }

    // Read the first operand (check for negative)
    bool negative = false;
    if (expression[pos] == '-') {
        negative = true;
        pos++;
    }

    string numStr;
    while (pos < expression.length() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        numStr += expression[pos];
        pos++;
    }

    if (!numStr.empty()) {
        op1 = stof(numStr);
        if (negative) op1 = -op1;
    } else {
        throw runtime_error("Invalid expression: No first operand.");
    }

    // Skip whitespaces and read the operator
    while (pos < expression.length() && isspace(expression[pos])) {
        pos++;
    }
    if (pos < expression.length()) {
        operation = expression[pos++];
    } else {
        throw runtime_error("Invalid expression: No operator.");
    }

    // Skip whitespaces and read the second operand
    negative = false;
    while (pos < expression.length() && isspace(expression[pos])) {
        pos++;
    }
    if (expression[pos] == '-') {
        negative = true;
        pos++;
    }

    numStr.clear();
    while (pos < expression.length() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        numStr += expression[pos];
        pos++;
    }

    if (!numStr.empty()) {
        op2 = stof(numStr);
        if (negative) op2 = -op2;
    } else {
        throw runtime_error("Invalid expression: No second operand.");
    }

    // Perform the operation
    float result = 0.0;
    switch (operation) {
        case '+': result = op1 + op2; break;
        case '-': result = op1 - op2; break;
        case '*': result = op1 * op2; break;
        case '/':
            if (op2 == 0) {
                throw runtime_error("Division by zero.");
            }
            result = op1 / op2;
            break;
        default:
            throw runtime_error("Unknown operator.");
    }

    return result;
}

int main() {
    const int MAX_EXPRESSIONS = 5;  // Fixed size for the array
    binops* expressions = new binops[MAX_EXPRESSIONS];  // Allocate array on heap

    // Read expressions from user
    string exp;
    for (int i = 0; i < MAX_EXPRESSIONS; ++i) {
        cout << "Enter expression " << (i + 1) << ": ";
        getline(cin, expressions[i].expression);  // Directly store in array
    }

    // Open a file to write the results
    ofstream outFile("results.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        delete[] expressions;  // Clean up
        return 1;
    }

    // Traverse the array, evaluate each expression, and write to the file
    for (int i = 0; i < MAX_EXPRESSIONS; ++i) {
        try {
            float result = evaluate(expressions[i].expression);  // Evaluate the expression
            outFile << expressions[i].expression << " → " << result << endl;  // Write to file
        } catch (const exception& e) {
            outFile << "Error evaluating expression '" << expressions[i].expression 
                    << "': " << e.what() << endl;  // Handle any evaluation errors
        }
    }

    // Clean up resources
    outFile.close();
    delete[] expressions;  // Free dynamically allocated memory

    cout << "Results written to results.txt" << endl;

    return 0;
}
