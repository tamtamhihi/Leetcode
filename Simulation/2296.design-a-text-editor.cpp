/*
https://leetcode.com/problems/design-a-text-editor/description/

Maintain 2 arrays for the text to the left and to the right of the cursor.
In all operations:
- Left array is only popped/added at the end
- Right array is only popped/added at the beginning

For ease, I use 2 strings (i.e 2 vectors), but the right string is stored in reversed so that operations at its end is equivalent to operations at the beginning of the actual string.
*/

class TextEditor {
    string left, rightReverse;
    string getLast10() {
        string result;
        for (int i = max(0, (int)left.size() - 10); i < (int)left.size(); ++i) {
            result += left[i];
        }
        return result;
    }
public:
    TextEditor() {
        left = rightReverse = "";
    }

    void addText(string text) {
        left += text;
    }
    
    int deleteText(int k) {
        int numDelete = min(k, (int)left.size());
        for (int i = 0; i < numDelete; ++i) {
            left.pop_back();
        }
        return numDelete;
    }
    
    string cursorLeft(int k) {
        int numMove = min(k, (int)left.size());
        for (int i = 0; i < numMove; ++i) {
            rightReverse += left.back();
            left.pop_back();
        }
        return getLast10();
    }
    
    string cursorRight(int k) {
        int numMove = min(k, (int)rightReverse.size());
        for (int i = 0; i < numMove; ++i) {
            left += rightReverse.back();
            rightReverse.pop_back();
        }
        return getLast10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
