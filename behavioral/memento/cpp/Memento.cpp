#include <string>
#include <vector>
#include <iostream>

class Memento {
private:
    std::string savedText;
    explicit Memento(std::string savedText) : savedText(std::move(savedText)){}

    std::string getSavedText() {
        return savedText;
    }

    friend class Editor;
};

class Editor {
private:
    std::string text;
public:
    void write(const std::string& newText) {
        text += newText;
    }

    std::string getText() {
        return text;
    }

    [[nodiscard]] Memento save() const {
        return Memento(text);
    }

    void restore(Memento& memento) {
        text = memento.getSavedText();
    }
};

class History {
private:
    std::vector<Memento> states;
public:
    void save(const Editor& editor) {
        states.push_back(editor.save());
    }

    void undo(Editor editor) {
        editor.restore(states.back());
        states.pop_back();
    }
};

int main() {
    Editor editor;
    History history;

    editor.write("Hello");
    history.save(editor);

    editor.write("World\n");
    history.save(editor);

    std::cout << editor.getText();
    history.undo(editor);

    std::cout << editor.getText();
}
